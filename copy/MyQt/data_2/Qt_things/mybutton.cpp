#include "mybutton.h"
#include <QMouseEvent>
#include <QDebug>

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}

void MyButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        qDebug()<<"i am left";
    }
    //else if(e->button() == Qt::RightButton)
    //{
      //  qDebug()<<"i am right";
    //}
    else
    {
        //QPushButton::mousePressEvent(e);
    }
    QPushButton::mousePressEvent(e);
}
