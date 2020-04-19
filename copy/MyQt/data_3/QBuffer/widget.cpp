#include "widget.h"
#include "ui_widget.h"
#include <QBuffer>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QBuffer buff;
    buff.open(QIODevice::WriteOnly);
    buff.write("wolf");
    buff.write("guidao");
    buff.close();

    qDebug()<<buff.buffer();
}

Widget::~Widget()
{
    delete ui;
}
