#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>

clientwidget::clientwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientwidget)
{
    ui->setupUi(this);
    SetEditorStyle();
    tcpsocket = NULL;

    setWindowTitle("client");

    tcpsocket = new QTcpSocket(this);

    connect(tcpsocket,&QTcpSocket::connected,[=]()
    {
        ui->textEditRead->append("connect server is successful!!!");
    });

    connect(tcpsocket,&QTcpSocket::readyRead,[=]()
    {
        QByteArray array = tcpsocket->readAll();

        ui->textEditRead->append(array);
    });
}

clientwidget::~clientwidget()
{
    delete ui;
}

void clientwidget::on_ButtonConnect_clicked()
{
    QString ip = ui->lineEditIP->text();
    quint16 port = ui->lineEditPort->text().toInt();

    tcpsocket->connectToHost(QHostAddress(ip),port);
}

void clientwidget::on_ButtonSend_clicked()
{
    if(tcpsocket->isOpen() == false)
    {
        QString temp = QString("not connect,not send data!!!");
        ui->textEditRead->append(temp);
        return;
    }
    QString str1 = ui->textEditWrite->toPlainText();

    QString str2 = QString("[ip:%1][port:%2] -> [server]: ").arg(tcpsocket->peerAddress().toString()).arg(tcpsocket->peerPort());

    QString str3 = str2 + str1;
    tcpsocket->write(str3.toUtf8().data());


    ui->textEditRead->append(str3);

    ui->textEditWrite->clear();
}

void clientwidget::on_ButtonClose_clicked()
{
    if(tcpsocket->isOpen() == false)
    {
        QString temp = QString("not connect,not close!!!");
        ui->textEditRead->append(temp);
        emit Mysignal();
        this->hide();
        return;
    }
    tcpsocket->disconnectFromHost();
    tcpsocket->close();

}

void clientwidget::paintEvent(QPaintEvent *event)
{
    QPainter* painter = new QPainter(this);
    painter->drawPixmap(0,0,width(),height(),QPixmap("../1.JPG"));
}

void clientwidget::SetEditorStyle()
{
    ui->textEditRead->setStyleSheet("background-color:rgba(0,0,0,0);");
    ui->textEditWrite->setStyleSheet("background-color:rgba(0,0,0,0);");
    ui->lineEditIP->setStyleSheet("background-color:rgba(0,0,0,0);");
    ui->lineEditPort->setStyleSheet("background-color:rgba(0,0,0,0);");
    //ui->pushButtonlogin->setFlat(true);
    //ui->pushButtonRegister->setFlat(true);
}
