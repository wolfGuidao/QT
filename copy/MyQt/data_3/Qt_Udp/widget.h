#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_ButtonSend_clicked();

private:
    Ui::Widget *ui;

    QUdpSocket* udpsocket;
};

#endif // WIDGET_H
