#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    setMouseTracking(true);
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();

    if(ev->button() == Qt::LeftButton)
    {
        qDebug()<<"i am left";
    }
    else if(ev->button() == Qt::RightButton)
    {
        qDebug()<<"i am right";
    }
    else if(ev->button() == Qt::MidButton)
    {
        qDebug()<<"i am mid";
    }

    QString text = QString("<center><h1>Mouse Press : (%1,%2)</h1></center>").arg(i).arg(j);
    this ->setText(text);
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString text = QString("<center><h1>Mouse Release : (%1,%2)</h1></center>").arg(ev->x()).arg(ev->y());
    this ->setText(text);
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString text = QString("<center><h1>Mouse Move : (%1,%2)</h1></center>").arg(ev->x()).arg(ev->y());
    //this ->setText(text);

}

void MyLabel::enterEvent(QEvent *event)
{
    QString text = QString("<center><h1>Mouse enter window</h1></center>");
    this ->setText(text);
}

void MyLabel::leaveEvent(QEvent *event)
{
    QString text = QString("<center><h1>Mouse leave window</h1></center>");
    this ->setText(text);
}
