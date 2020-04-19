#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    void SendSolt();

signals:
    void Mysignal();
    void Mysignal(int,QString);

public slots:

private:
    QPushButton b;
};

#endif // SUBWIDGET_H
