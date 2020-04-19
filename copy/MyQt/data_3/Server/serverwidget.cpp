#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QPainter>

ServerWidget::ServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    SetEditorStyle();

    tcpserver = NULL;
    tcpsocket = NULL;

    tcpserver = new QTcpServer(this);

    tcpserver->listen(QHostAddress::Any,9090);
    setWindowTitle("server! port is 9090");

    connect(tcpserver,&QTcpServer::newConnection,[=]()
    {
        tcpsocket = tcpserver->nextPendingConnection();

        QString ip = tcpsocket->peerAddress().toString();
        quint16 port = tcpsocket->peerPort();

        QString temp = QString("[%1:%2]successful connect!").arg(ip).arg(port);

        ui->textEditRead->setText(temp);

        connect(tcpsocket,&QTcpSocket::readyRead,[=]()
        {
           QByteArray array = tcpsocket->readAll();
           ui->textEditRead->append(array);
        });

    });



}

ServerWidget::~ServerWidget()
{
    delete ui;
}

void ServerWidget::on_ButtonSend_clicked()
{
    if(tcpsocket == NULL)
    {
        QString temp = QString("not connect,not send data!!!");
        ui->textEditRead->append(temp);
        return;
    }
    QString str1 = ui->textEditWrite->toPlainText();

    QString ip = tcpsocket->peerAddress().toString();
    quint16 port = tcpsocket->peerPort();

    QString str2 = QString("[server] -> : [%1 : %2] : ").arg(ip).arg(port);

    QString str3 = str2 + str1;

    tcpsocket->write(str3.toUtf8().data());

    ui->textEditRead->append(str3);

    ui->textEditWrite->clear();
}

void ServerWidget::on_ButtonClose_clicked()
{
    if(tcpsocket == NULL)
    {
        QString temp = QString("not connect,not close!!!");
        ui->textEditRead->append(temp);
        return;
    }
    QString ip = tcpsocket->peerAddress().toString();
    quint16 port = tcpsocket->peerPort();
    QString temp = QString("[%1:%2]server is disconnectFromHost!").arg(ip).arg(port);
    ui->textEditRead->setText(temp);
    tcpsocket->disconnectFromHost();
    tcpsocket->close();
    tcpserver = NULL;
}

void ServerWidget::paintEvent(QPaintEvent *event)
{
    QPainter* painter = new QPainter(this);
    painter->drawPixmap(0,0,width(),height(),QPixmap("../1.JPG"));
}

//editor style
void ServerWidget::SetEditorStyle()
{
    ui->textEditRead->setStyleSheet("background-color:rgba(0,0,0,0);");
    ui->textEditWrite->setStyleSheet("background-color:rgba(0,0,0,0);");

    //ui->pushButtonlogin->setFlat(true);
    //ui->pushButtonRegister->setFlat(true);
}
