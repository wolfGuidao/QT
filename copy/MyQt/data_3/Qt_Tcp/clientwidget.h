#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class clientwidget;
}

class clientwidget : public QWidget
{
    Q_OBJECT

public:
    explicit clientwidget(QWidget *parent = 0);
    ~clientwidget();

private slots:
    void on_ButtonConnect_clicked();

    void on_ButtonSend_clicked();

    void on_ButtonClose_clicked();

private:
    Ui::clientwidget *ui;
    QTcpSocket* tcpsocket;
};

#endif // CLIENTWIDGET_H
