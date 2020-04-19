#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QDateTime>
#include <QDataStream>
#include <QTextStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonRead_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"open","../");
    if(path.isEmpty() == false)
    {
        QFile file(path);
        bool ret = file.open(QIODevice::ReadOnly);
        if(ret == true)
        {
#if 0
            QByteArray arr = file.readAll();
            ui->textEdit->setText(arr);
#endif
            QByteArray arr;
            while(file.atEnd() == false)
            {
                arr += file.readLine();
            }
            ui->textEdit->setText(arr);
        }

        file.close();

        QFileInfo fileinfo(path);
        qDebug()<<"filename"<<fileinfo.fileName();
        qDebug()<<"filesufix"<<fileinfo.suffix();
        qDebug()<<"size"<<fileinfo.size();
        qDebug()<<"create time"<<fileinfo.created().toString("yyyy-MM-dd hh:mm:ss");

    }
}

void Widget::on_buttonWrite_clicked()
{
    QString path = QFileDialog::getSaveFileName(this,"save","../","TXT(.*txt");


    if(path.isEmpty() == false)
    {
        QFile file;
        file.setFileName("text");
        bool ret = file.open(QIODevice::WriteOnly);
        if(ret == true)
        {
            QString str = ui->textEdit->toPlainText();

            //file.write(str.toUtf8());
            file.write(str.toStdString().c_str());


        }
        file.close();
    }



}
