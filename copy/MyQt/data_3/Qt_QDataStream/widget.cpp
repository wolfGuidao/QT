#include "widget.h"
#include "ui_widget.h"
#include <QDataStream>
#include <QTextStream>
#include <QFile>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //writeDate();
    //readDate();
    writeTextDate();
    readTextDate();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::writeDate()
{
    QFile file("./1.txt");

    bool ret = file.open(QIODevice::WriteOnly);
    if(ret == true)
    {
        QDataStream stream(&file);

        stream << QString("i am wolf");
        file.close();
    }
}

void Widget::readDate()
{
    QFile file("./1.txt");

    bool ret = file.open(QIODevice::ReadOnly);
    if(ret == true)
    {
        QDataStream stream(&file);

        QString str;
        stream >> str;
        qDebug()<<str.toUtf8().data();
        file.close();
    }
}

void Widget::writeTextDate()
{
    QFile file;
    file.setFileName("./1.txt");

    bool ret = file.open(QIODevice::WriteOnly);
    if(ret == true)
    {
        QTextStream stream(&file);
        stream<<QString("i am text textStream");
        file.close();
    }
}

void Widget::readTextDate()
{
    QFile file;
    file.setFileName("./1.txt");
    readDate();
    bool ret = file.open(QIODevice::ReadOnly);
    if(ret == true)
    {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        QString str;
        stream>>str;
        qDebug()<<str.toStdString().c_str();
        file.close();
    }
}
