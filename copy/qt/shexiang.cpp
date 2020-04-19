#include "shexiang.h"
#include "ui_shexiang.h"
#include <QFileDialog>
#include <QPixmap>
#include <QByteArray>
#include <QDateTime>
#include <QDebug>
#include <QPainter>

int cout=0;

shexiang::shexiang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shexiang)
{
    ui->setupUi(this);
    enRcv = false;
    enPic = false;
    tcp = new QTcpSocket(this);
    tcp->connectToHost("172.25.1.253",8080);
    connect(tcp,SIGNAL(readyRead()),this,SLOT(Tcp_rcv()));
    tcp->write("GET /?action=stream\n\n");

    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    QObject::connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));
    QObject::connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(on_pushButton_4_clicked()));
}

shexiang::~shexiang()
{
    delete ui;
}

void shexiang::on_pushButton_clicked()//返回上一级
{

    emit sin_back2();
}

void shexiang::Tcp_rcv()//接收视频
{
    QByteArray qba = tcp->readAll();

   qDebug()<<qba.count()<<endl;
    for(int i=0;i<qba.count();i++)
    {
        if(enRcv)
            imagebuf += qba[i];//定义一个buf接收视频流
        if(lastbyte == (char)0xFF)
        {
            if(qba[i] == (char)0xD8)
            {
              // qDebug()<<"SOI";
                enRcv = true;
            }
            else if(qba[i] == (char) 0xD9)
            {
                qDebug() << "EOI"<<endl;
                QPixmap map;
                if(map.loadFromData(imagebuf,"JEPG"))
                {
                    ui->label->setPixmap(map); //显示视频
                    cout++;
                    if(enPic)      //如果enPic=true，则抓拍
                    {
                        qDebug()<<QDir::currentPath();
                        QDir::setCurrent("./picture/");   //设置抓拍保存路径
                        QDateTime current_time=QDateTime::currentDateTime();
                        QString time=current_time.toString("yyyy-MM-dd hh:mm:ss")+".jpg"; //抓拍时间
                        map.save(time);   //保存抓拍时间
                        ui->label_2->setPixmap(map);//显示抓拍的图片

                        enPic=false;  //把enPic置为失能状态
                    }

                    qDebug()<<"视频流:"<<QString::number(cout,10);
                }
                else
                   qDebug()<<"Error Format"<<endl;
                imagebuf.clear();
                imagebuf += 0xFF;
                imagebuf += 0xD8;
                enRcv = false;
            }
        }
        lastbyte = qba[i];
    }
}
void shexiang::on_pushButton_2_clicked()//查看照片位置
{
    QString path = QFileDialog::getOpenFileName(this,tr("Open Image"), ".", tr("Image Files(*.jpg *.png)"));
        if(path.length() == 0)
        {
            QMessageBox::information(NULL,tr("Path"),tr("You didn't select any files."));
        }
        else
        {
            QPixmap map;
            map.load(path);
            ui->label_2->setPixmap(map);
        }
}

void shexiang::on_pushButton_4_clicked()//启动拍照
{
    enPic=true;
}

void shexiang::paintEvent(QPaintEvent *)//添加背景图
{
    // QPainter l(this);
    QPainter p;
    p.begin(this);

    p.drawPixmap(0,0,width(),height(),QPixmap("://picture/jiaju5.jpg"));

    p.end();
}
