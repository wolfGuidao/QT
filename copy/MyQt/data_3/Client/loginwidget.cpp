#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QtSql>
#include <QMessageBox>
#include <QPainter>
#include <QTime>
#include <QDateTime>
#include <QDebug>



LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    ////////////////////////
    //set lineEditorTime:
    time_clock = new QTimer(this);
    connect(time_clock,&QTimer::timeout,[=]()
    {
        SetLineEditorTime();
    });
    time_clock->start(90);

    //////////////////////
    //set lineEditorStyle
    SetEditorStyle();

    connect(&w1,&clientwidget::Mysignal,[=]()
    {

        this->show();
    });
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

////////
//editor time
void LoginWidget::SetLineEditorTime()
{
    QDateTime dt;
    QTime time;
    QDate date;
    dt.setTime(time.currentTime());
    dt.setDate(date.currentDate());
    QString currentDate = dt.toString("yyyy-MM-dd hh:mm:ss");
    ui->lineEditTime->setText(currentDate);
}

//editor style
void LoginWidget::SetEditorStyle()
{
    ui->lineEditTime->setStyleSheet("background-color:rgba(0,0,0,0);");
    ui->lineEditQQ->setStyleSheet("background-color:rgba(0,0,0,0);");
    ui->lineEditPass->setStyleSheet("background-color:rgba(0,0,0,0);");
    ui->pushButtonlogin->setFlat(true);
    ui->pushButtonRegister->setFlat(true);
}

//login
void LoginWidget::on_pushButtonlogin_clicked()
{
        QString b1 =   QString("select name from employee where name == '%1' and password == '%2' ; ").arg(ui->lineEditQQ->text()).arg(ui->lineEditPass->text());
        QString b2 =  QString("insert into employee values('%1','%2');").arg(ui->lineEditQQ->text()).arg(ui->lineEditPass->text());

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
                if((this->ui->lineEditQQ->text().trimmed()==NULL)||(this->ui->lineEditPass->text().trimmed()==NULL))
                        {
                            QMessageBox::warning(this,"登录","用户名或密码不能为空！",QMessageBox::Ok);
                            return;
                        }
                if(query.next())
                {
                    QMessageBox::warning (this,"登录","Login successful！!",QMessageBox::Ok);

                    this->ui->lineEditQQ->clear();
                    this->ui->lineEditPass->clear();

                    this->hide();

                    w1.show();

                }
                else//登录失败
                {
                  //  printf("用户名或密码错误");

                     QMessageBox::warning(this,"登录","用户名或密码错误！",QMessageBox::Ok);
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





//register
void LoginWidget::on_pushButtonRegister_clicked()
{
        QString b1 =   QString("select name from employee where name == '%1' and password == '%2' ; ").arg(ui->lineEditQQ->text()).arg(ui->lineEditPass->text());
        QString b2 =  QString("insert into employee values('%1','%2');").arg(ui->lineEditQQ->text()).arg(ui->lineEditPass->text());

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
                if((this->ui->lineEditQQ->text().trimmed()==NULL)||(this->ui->lineEditPass->text().trimmed()==NULL))
                        {
                            QMessageBox::warning(this,"注册","用户名或密码不能为空！",QMessageBox::Ok);
                            return;
                        }
            /* if(query.next())
                {
                    printf("用户名已存在");

                    QMessageBox::warning(this,"注册","用户名已存在！",QMessageBox::Cancel);

                }*/

                query.exec("select * from employee");
                   while(query.next())
                   {
                      if(query.value(0).toString() == this->ui->lineEditQQ->text().trimmed())
                      {
                          QMessageBox::warning(this,"注册","用户名已存在！",QMessageBox::Ok);
                          return;
                      }
                   }

                    if(query.exec(b2))
                    {
                        printf("注册成功");
                         QMessageBox::warning(this,"注册","注册成功！",QMessageBox::Ok);

                    }
                    else
                    {
                        printf("注册失败");
                         QMessageBox::warning(this,"注册","注册失败！",QMessageBox::Ok);
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

//painevent
void LoginWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(0,0,width(),height(),QPixmap("../1.JPG"));
}




