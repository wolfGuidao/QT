#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{


    MyButton* b3 = new MyButton(this);


    MyButton* b4 = new MyButton(this);
    qDebug()<<"b3,b4";

}

MyWidget::~MyWidget()
{

}
