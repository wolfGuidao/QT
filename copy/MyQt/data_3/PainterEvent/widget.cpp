#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    x = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    //QPainter p(this);
    QPainter p;
    p.begin(this);

    //p.drawPixmap(0,0,width(),height(),QPixmap("../1.JPG"));
    //p.drawPixmap(rect(),QPixmap("../1.JPG"));

    QPen pen;
    pen.setWidth(5);
    //pen.setColor(Qt::red);
    pen.setColor(QColor(14,9,234));
    pen.setStyle(Qt::DashLine);
    p.setPen(pen);

    QBrush brush;
    brush.setColor(QColor(Qt::red));
    brush.setStyle(Qt::SolidPattern);
    p.setBrush(brush);

    p.drawLine(50,50,150,50);
    p.drawLine(50,50,50,150);
    p.drawLine(150,50,150,150);
    p.drawLine(150,150,50,150);

    p.drawRect(200,200,200,200);

    p.drawEllipse(QPoint(212,122),50,50);

    p.drawPixmap(x,150,99,99,QPixmap("../1.JPG"));

    p.end();
}

void Widget::on_pushButton_clicked()
{
    x += 20;
    if(x > width())
    {
        x = 0;
    }

    update();
}
