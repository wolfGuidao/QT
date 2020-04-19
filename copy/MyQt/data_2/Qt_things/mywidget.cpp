#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>
#include <QEvent>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    id = startTimer(2000);
    timeid = startTimer(1000);

    connect(ui->pushButton,&MyButton::clicked,[]()
    {
        qDebug()<<"i an xia";
    });

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::keyPressEvent(QKeyEvent *event)
{
    //qDebug()<<(char)event->key();
    if(event->key() == Qt::Key_A)
    {
        qDebug()<<"i am A";
    }
    else if(event->key() == Qt::Key_Shift)
    {
        qDebug()<<"i am shift";
    }
    else if(event->key() == Qt::Key_0)
    {
        qDebug()<<"i am key_0";
    }
}

void MyWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
    {
        qDebug()<<"i am A";
    }
    else if(event->key() == Qt::Key_Shift)
    {
        qDebug()<<"i am shift";
    }
    else if(event->key() == Qt::Key_0)
    {
        qDebug()<<"i am key_0";
    }
}

void MyWidget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == id)
    {
        static int i = 0;
        i++;
        ui->label->setText(QString("<center><h1>timeout : [%1]</h1></center>").arg(i));

        if(i == 6)
        {
            killTimer(id);
        }

    }
    else if (event->timerId() == timeid)
    {
        static int i = 0;
        i++;
        ui->label_2->setText(QString("<center><h1>timeout : [%1]</h1></center>").arg(i));

        if(i == 6)
        {
            killTimer(timeid);
        }
    }
}

void MyWidget::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(this,"close","are you sure");
    if(ret == QMessageBox::Yes)
    {
        qDebug()<<"i am closed window";
        event->accept();
    }
     else if(ret == QMessageBox::No)
     {
         qDebug()<<"i am no close window";
         event->ignore();
     }
}

bool MyWidget::event(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::Close:
        qDebug()<<"i am close thing";
        closeEvent(static_cast<QCloseEvent*>(event));
       break;

    }
}
