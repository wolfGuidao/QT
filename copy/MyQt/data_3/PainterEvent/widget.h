#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int x;
private:
    Ui::Widget *ui;

protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_clicked();

};

#endif // WIDGET_H
