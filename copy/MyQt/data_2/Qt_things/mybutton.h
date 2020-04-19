#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);

signals:

public slots:

protected:
    void mousePressEvent(QMouseEvent *e);
};

#endif // MYBUTTON_H
