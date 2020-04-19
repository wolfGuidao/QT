#ifndef SHEXIANG_H
#define SHEXIANG_H

#include <QWidget>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QString>
#include <QImage>
#include <QMessageBox>

namespace Ui {
class shexiang;
}

class shexiang : public QWidget
{
    Q_OBJECT

public:
    explicit shexiang(QWidget *parent = 0);
    ~shexiang();
protected:
    void paintEvent(QPaintEvent *);

signals:
    void sin_back2();
private slots:
    void on_pushButton_clicked();
    void Tcp_rcv();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::shexiang *ui;
    QTcpSocket *tcp;
    bool enRcv;
    QByteArray imagebuf;
    char lastbyte;
    bool enPic;
};

#endif // SHEXIANG_H
