#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    udpsocket = new QUdpSocket(this);

    udpsocket->bind(9090);

    setWindowTitle("server port is 9090");

    connect(udpsocket,&QUdpSocket::readyRead,[=]()
    {
       char buf[1024] = {0};
       QHostAddress clientaddr;
       quint16 clientport;
       quint64 size = udpsocket->readDatagram(buf,sizeof(buf),&clientaddr,&clientport);

        if(size> 0)
        {
            QString str = QString("[%1 : %2] : %3").arg(clientaddr.toString()).arg(clientport).arg(buf);

            ui->textEdit->append(str);
        }

    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_ButtonSend_clicked()
{
    QString ip = ui->lineEditIP->text();
    quint16 port = ui->lineEditPort->text().toInt();

    QString str = ui->textEdit->toPlainText();

    udpsocket->writeDatagram(str.toUtf8(),QHostAddress(ip),port);
}
