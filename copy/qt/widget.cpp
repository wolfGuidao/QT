#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPainter>
#include <QString>
#include <QMouseEvent>
#include <QtSql/QSqlDatabase>
#include <QTextEdit>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDriverPlugin>
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    zhu = new zhuce();
    key = new keyboard();
    shiping = new shexiang();

    resize(1024,768);
    connect(shiping,&shexiang::sin_back2,//从监控界面返回到注册界面
            [=]()
    {

        shiping->close();
        zhu->show();
    }
            );
    connect(zhu,&zhuce::sin_shiping,//从注册界面进入到监控界面
            [=]()
    {
        zhu->close();
        shiping->show();
    }
            );

    connect(zhu,&zhuce::sin_back,//从注册界面返回主界面
            [=]()
    {
        zhu->close();

        this->show();

    });
    connect(key,&keyboard::sin_back,//从键盘界面返回主界面
            [=]()
    {
        key->close();


        this->show();

    });

   QObject::connect(key,SIGNAL(sin_in(QString,QString)),this,SLOT(zhuce_receiver(QString,QString)));


         ui->lineEdit->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
         ui->lineEdit_2->installEventFilter(this);
         ui->lineEdit_2->setEchoMode(QLineEdit::Password);//隐藏密码

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()//注册帐号密码  跳到注册界面
{
    //this->hide();
    //zhu->show();
        QString b1 =   QString("select name from employee where name == '%1' and password == '%2' ; ").arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text());
        QString b2 =  QString("insert into employee values('%1','%2');").arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text()) ;

        QSqlDatabase db;
        if(QSqlDatabase::contains("qt_sql_default_connection"))  //判断数据库是否存在
          db = QSqlDatabase::database("qt_sql_default_connection");  //存在则打开
        else
          db = QSqlDatabase::addDatabase("QSQLITE");  //使用数据库驱动

        db.setDatabaseName("text.db");//设置数据库名字
        bool ok = db.open();//打开数据库
        if(ok)
        {
            printf("success to open");
            QSqlQuery query;//创建一个实例
            if(query.exec("Create table if not exists employee(name VARCHAR(10),password VARCHAR(10))"))
            {
                printf("success create table");
                query.exec(b1);
                if((this->ui->lineEdit->text().trimmed()==NULL)||(this->ui->lineEdit_2->text().trimmed()==NULL))
                        {
                            QMessageBox::warning(this,"注册","用户名或密码不能为空！",QMessageBox::Cancel);
                            return;
                        }
           /*   if(query.next())
                {
                    printf("用户名已存在");

                    QMessageBox::warning(this,"注册","用户名已存在！",QMessageBox::Cancel);

                }*/
                query.exec("select * from employee");
                   while(query.next())
                   {
                      if(query.value(0).toString() == this->ui->lineEdit->text().trimmed())
                      {
                          QMessageBox::warning(this,"注册","用户名已存在！",QMessageBox::Cancel);
                          return;
                      }
                   }

                    if(query.exec(b2))
                    {
                        printf("注册成功");
                         QMessageBox::warning(this,"注册","注册成功！",QMessageBox::Cancel);

                    }
                    else
                    {
                        printf("注册失败");
                         QMessageBox::warning(this,"注册","注册失败！",QMessageBox::Cancel);
                       //  ui->lineEdit_2->setText("注册失败");
                    }

            }
            else
            {
                printf("fail to create");
            }
        }
        else{
            printf("fail to open");
        }


}

void Widget::on_pushButton_clicked()//登录界面
{
  //  this->hide();
    //zhu->show();
    QString b1 =   QString("select name from employee where name == '%1' and password == '%2' ; ").arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text());
        QString b2 =  QString("insert into employee values('%1','%2');").arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text()) ;

        QSqlDatabase db;
        if(QSqlDatabase::contains("qt_sql_default_connection"))  //判断数据库是否存在
          db = QSqlDatabase::database("qt_sql_default_connection");  //存在则打开
        else
          db = QSqlDatabase::addDatabase("QSQLITE");  //使用数据库驱动

        db.setDatabaseName("text.db");//设置数据库名字
        bool ok = db.open();//打开数据库
        if(ok)
        {
            printf("success to open");
            QSqlQuery query;//创建一个实例
            if(query.exec("Create table if not exists employee(name VARCHAR(10),password VARCHAR(10))"))
            {
                printf("success create table");
                query.exec(b1);
                if((this->ui->lineEdit->text().trimmed()==NULL)||(this->ui->lineEdit_2->text().trimmed()==NULL))
                        {
                            QMessageBox::warning(this,"登录","用户名或密码不能为空！",QMessageBox::Cancel);
                            return;
                        }
                if(query.next())
                {
                    this->hide();
                    zhu->show();
                    this->ui->lineEdit->clear();
                    this->ui->lineEdit_2->clear();


                }
                else//登录失败
                {
                  //  printf("用户名或密码错误");

                     QMessageBox::warning(this,"登录","用户名或密码错误！",QMessageBox::Cancel);
                }
            }
            else
            {
                printf("fail to create");
            }

        }
        else
        {
            printf("fail to open");
        }
 }




void Widget::paintEvent(QPaintEvent *)//添加背景图
{
     QPainter p(this);
  //  QPainter p;
    //p.begin(this);
    p.drawPixmap(0,0,width(),height(),QPixmap("://picture/hai.png"));

  //  p.end();
}

bool Widget::eventFilter(QObject *watched, QEvent *event)//点击帐号密码文本框跳到软键盘
{
   // ui->username->clearFocus();

    if(watched == ui->lineEdit)
    {
       if(event->type() == QEvent::FocusIn)
       {
           QString type = {"21"};
           key->type_t = type;
           key->show();

           ui->lineEdit->clearFocus();
       }
    }

    if(watched == ui->lineEdit_2)
    {
       if(event->type() == QEvent::FocusIn)
       {
           QString type = {"22"};
           key->type_t = type;
           key->show();
           ui->lineEdit_2->clearFocus();
       }
    }


    return QWidget::eventFilter(watched,event);
}


void Widget::zhuce_receiver(QString buf_t,QString buf_t1)//将软键盘的内容输入到登录的文本框
{
    this->show();
    if(buf_t1 == "21")
    {
        if(ui->lineEdit->text() != 0)
        {
            ui->lineEdit->clear();
        }
            ui->lineEdit->insert(buf_t);

    }
     if(buf_t1 == "22")
     {
         if(ui->lineEdit_2->text() != 0)
          {
              ui->lineEdit_2->clear();
          }
              ui->lineEdit_2->insert(buf_t);

     }

}

