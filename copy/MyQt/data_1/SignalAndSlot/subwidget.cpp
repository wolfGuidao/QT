#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("i am child window");
    b.setParent(this);
    b.move(80,80);
    b.setText("get main window");

    connect(&b,&QPushButton::clicked,this,&SubWidget::SendSolt);
     resize(400,400);
}
void SubWidget::SendSolt()
{
    emit Mysignal();
    emit Mysignal(250,"i am child window");
}
