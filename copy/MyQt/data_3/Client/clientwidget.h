#pragma once
#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QPainter>

namespace Ui {
class clientwidget;
}

class clientwidget : public QWidget
{
    Q_OBJECT

public:
    explicit clientwidget(QWidget *parent = 0);
    ~clientwidget();

    signals:
    void Mysignal();//自定义的信号

private slots:
    void on_ButtonConnect_clicked();

    void on_ButtonSend_clicked();

    void on_ButtonClose_clicked();

protected:
    void paintEvent(QPaintEvent *event);

private:
    void SetEditorStyle();
    Ui::clientwidget *ui;
    QTcpSocket* tcpsocket;
};

#endif // CLIENTWIDGET_H
