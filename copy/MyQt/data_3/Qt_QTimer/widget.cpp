#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mytime = new QTimer(this);

    connect(mytime,&QTimer::timeout,[=]()
    {
       static int i = 0;
       i++;
       ui->lcdNumber->display(i);

    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonStart_clicked()
{
    if(mytime->isActive() == false)
        mytime->start(100);
}

void Widget::on_pushButtonStop_clicked()
{
    if(mytime->isActive() == true)
        mytime->stop();
}
