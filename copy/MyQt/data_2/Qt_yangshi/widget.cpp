#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("QLabel{color:blue;background-color:red;}");
    ui->label->setStyleSheet("QLabel{border-image:url(:/new/prefix1/1.JPG)}");
}

Widget::~Widget()
{
    delete ui;
}
