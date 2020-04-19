#ifndef ZHUCE_H
#define ZHUCE_H

#include <QWidget>

#include <QRect>
#include <QPainter>
#include "qcustomplot.h"
#include <QTimer>

namespace Ui {
class zhuce;
}

class zhuce : public QWidget
{
    Q_OBJECT

public:
    explicit zhuce(QWidget *parent = 0);
    ~zhuce();
   void setupRealtimeDataDemo(QCustomPlot *customPlot);


protected:
    void paintEvent(QPaintEvent *);
signals:
void sin_back();
void sin_shiping();

private slots:
    void on_pushButton_2_clicked();

    void quxian();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::zhuce *ui;
     QTimer dataTimer;
};

#endif // ZHUCE_H
