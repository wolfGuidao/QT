#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "keyboard.h"
#include "zhuce.h"
#include <QString>
#include "shexiang.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

     bool eventFilter(QObject *,QEvent *);
      void zhuce_receiver(QString,QString);

private:
    Ui::Widget *ui;
    keyboard *key;
    zhuce *zhu;

    shexiang *shiping;
};

#endif // WIDGET_H
