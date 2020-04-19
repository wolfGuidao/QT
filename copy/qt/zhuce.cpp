#include "zhuce.h"
#include "ui_zhuce.h"
#include "qcustomplot.h"
#include <QVector>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QString>
#include <string>
#include <string.h>
#include <QDateTimeEdit>
#include <QDataStream>
#include <QDebug>
#include <unistd.h>
#include <QImage>
#include <QPalette>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>


typedef struct msggt//消息队列 发数据
{
    long type;
    int q;
}msg_t;
msg_t mbuf;
typedef struct shared_st//共享内存 收数据
{

    int tem;
    int shidu;
    int hw;
    int dianya;
}buf_t;
 int msgid,shmid;

buf_t *globuf=NULL;


zhuce::zhuce(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zhuce)
{
    ui->setupUi(this);

 QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
       

        key_t key ;
        key_t key2 ;

        key = ftok("/",'y');
      msgid = msgget(key,0666|IPC_CREAT|IPC_EXCL);//消息队列
        if(msgid<0)
        {
            if(errno == EEXIST)
            {
                msgid = msgget(key,0666);
                printf("msg exist\n");
            }
            else
            {
                printf("msgget error\n");
            }
        }





        key2 = ftok("/",'s');
        shmid = shmget(key2,sizeof(buf_t),0666|IPC_CREAT|IPC_EXCL);//共享内存
        if(shmid<0)
        {
            if(errno == EEXIST)
            {
                shmid = shmget(key2,sizeof(buf_t),0666);
                printf("shm exist\n");
            }
            else
            {
                printf("shmget error\n");

            }
        }

        globuf = (buf_t *)shmat(shmid, NULL, 0);
        if(globuf == (buf_t *)(-1))
        {
            printf("shmat error\n");
        }

        setupRealtimeDataDemo(ui->customplot);
        ui->customplot->replot();
         ui->checkBox->setChecked(true);
         ui->checkBox_2->setChecked(true);

}

zhuce::~zhuce()
{
    delete ui;
}
//实现曲线
void zhuce::setupRealtimeDataDemo(QCustomPlot *customPlot)//添加曲线
{
        customPlot->addGraph();
        customPlot->graph(0)->setPen(QPen(Qt::blue));
        customPlot->graph(0)->setName("温度");
        customPlot->addGraph();
        customPlot->graph(1)->setPen(QPen(Qt::red));
        customPlot->graph(1)->setName("湿度");
        customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
        customPlot->xAxis->setDateTimeFormat("hh:mm:ss");
        customPlot->xAxis->setAutoTickStep(false);
        customPlot->xAxis->setTickStep(2);
        customPlot->axisRect()->setupFullAxesBox();
        connect(&dataTimer, SIGNAL(timeout()), this, SLOT(quxian()));
        dataTimer.start(1000);
        customPlot->legend->setVisible(true);
}


void zhuce::quxian()//接收三种数据
{


        QString temp;
       int a = globuf->tem;
        ui->label->setText(temp.setNum(a));

        QString temp2;
        int b = globuf->shidu;
        ui->label_2->setText(temp2.setNum(b));

        QString temp3;
        int c = globuf->dianya;
        ui->label_3->setText(temp3.setNum(c));


        double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000;
       // qsrand(QTime::currentTime().msec() + QTime::currentTime().second() * 10000);
        //double value0 = qrand() % 100;
        //double value1 = qrand() % 80;
        if (ui->checkBox->isChecked())
            ui->customplot->graph(0)->addData(key, a);
        if (ui->checkBox_2->isChecked())
            ui->customplot->graph(1)->addData(key, b);
        ui->customplot->graph(0)->removeDataBefore(key-16);//清除16秒之前等我信息
        ui->customplot->graph(1)->removeDataBefore(key-16);
        ui->customplot->yAxis->setRange(0,60);
        ui->customplot->graph(1)->rescaleValueAxis(true);//自动设置范围
        ui->customplot->xAxis->setRange(key+0.25, 16, Qt::AlignRight);
        ui->customplot->replot();//绘制图标
}


//实现曲线



void zhuce::on_pushButton_2_clicked()
{
    emit sin_back();
}
void zhuce::paintEvent(QPaintEvent *)//添加背景图
{
     QPainter p(this);
  //  QPainter p;
    //p.begin(this);

    p.drawPixmap(0,0,width(),height(),QPixmap("://picture/hai.png"));

  //  p.end();
}

void zhuce::on_pushButton_3_clicked()//跳到视屏界面
{
    emit sin_shiping();
}

void zhuce::on_pushButton_clicked()//打开灯
{
    mbuf.type=100;
    mbuf.q=1;
    if(msgsnd(msgid,&mbuf,sizeof(mbuf.q),0)==-1)
    {
       perror("fail to msgsend");
       exit(1);
    }

}

void zhuce::on_pushButton_4_clicked()//关闭灯
{
    mbuf.type=100;
    mbuf.q=0;
    if(msgsnd(msgid,&mbuf,sizeof(mbuf.q),0)==-1)
    {
       perror("fail to msgsend");
       exit(1);
    }
}
