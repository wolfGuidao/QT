#pragma once
#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QTimer>
#include "serverwidget.h"

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();

private slots:
    void on_pushButtonlogin_clicked();

    void on_pushButtonRegister_clicked();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::LoginWidget *ui;

private:
    void SetLineEditorTime();
    void SetEditorStyle();
    QTimer *time_clock;
    ServerWidget w2;
};

#endif // LOGINWIDGET_H
