#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>

namespace Ui {
class ServerWidget;
}

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServerWidget(QWidget *parent = 0);
    ~ServerWidget();

private slots:
    void on_ButtonSend_clicked();

    void on_ButtonClose_clicked();

private:
    Ui::ServerWidget *ui;
    QTcpServer* tcpserver;
    QTcpSocket* tcpsocket;
};

#endif // SERVERWIDGET_H
