#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    /*
    b1.setParent(this);
    b1.setText("close");
    b1.move(10,10);

    //b2->serParent(this);
    b2 = new QPushButton(this);
    b2->setText("99999");
    b2->move(99,99);

    connect(&b1,&QPushButton::pressed,this,&MainWidget::close);
    connect(b2,&QPushButton::released,this,&MainWidget::MySolt);
    connect(b2,&QPushButton::released,&b1,&QPushButton::hide);
    */

    setWindowTitle("i am main window");
    b3.setParent(this);
    b3.setText("get child window");
    b3.move(210,210);


    connect(&b3,&QPushButton::released,this,&MainWidget::ChengeWin);

    /*
    void (SubWidget::*sub)() = &SubWidget::Mysignal;
    connect(&w,sub,this,&MainWidget::dealsub);

    void (SubWidget::*subsignal)(int,QString) = &SubWidget::Mysignal;
    connect(&w,subsignal,this,&MainWidget::dealsold);
    */

    connect(&w,SIGNAL(Mysignal()),this,SLOT(dealsub()));
    connect(&w,SIGNAL(Mysignal(int,QString)),this,SLOT(dealsold(int,QString)));

    QPushButton* b4 = new QPushButton(this);
    b4->setText("i am lambda");
    b4->move(1,200);

    connect(b4,&QPushButton::clicked,[](bool check)
    {
       qDebug()<<"i am lambda";
       qDebug()<<check;
    });


    resize(400,400);
}

void MainWidget::dealsold(int num,QString arg)
{
    qDebug()<<num<<" "<<arg.toUtf8().data();
}
void MainWidget::dealsub()
{
    w.hide();
    this->show();
}

void MainWidget::ChengeWin()
{
    w.show();
    this->hide();
}

void MainWidget::MySolt()
{
    b2->setText("6666");
}

MainWidget::~MainWidget()
{
    delete b2;
}
