#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPicture picture;
    QPainter p;
    p.begin(&picture);

    p.drawPixmap(0,0,100,100,QPixmap("../1.JPG"));
    p.drawLine(100,100,100,500);

    p.end();
    picture.save("../pciture.JPG");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    //QPainter p(this);
    //p.drawPixmap(0,0,QPixmap("../1.JPG"));

    //p.drawPixmap(400,0,QBitmap("../1.JPG"));

    //QImage image(199,199,QImage::Format_RGB32);
    //QPainter p;
    //p.begin(&image);

    //p.drawImage(0,0,QImage("../1.JPG"));

    //p.end();

    //image.save("../image.JPG");

    QPicture pic;
    pic.load("../pciture.JPG");

    QImage img;
    img.load("../image.JPG");

    QPainter p;
    p.begin(this);


    p.drawPicture(0,0,pic);
    p.drawImage(100,100,img);





    p.end();


}
