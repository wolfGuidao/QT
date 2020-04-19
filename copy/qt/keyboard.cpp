#include "keyboard.h"
#include "ui_keyboard.h"
#include <QDebug>
#include <QPainter>

keyboard::keyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::keyboard)
{
    ui->setupUi(this);
}

keyboard::~keyboard()
{
    delete ui;
}

void keyboard::on_pushButton_clicked()
{
    ui->lineEdit->insert("1");
}

void keyboard::on_pushButton_2_clicked()
{
    ui->lineEdit->insert("2");
}

void keyboard::on_pushButton_3_clicked()
{
    ui->lineEdit->insert("3");
}

void keyboard::on_pushButton_4_clicked()
{
    ui->lineEdit->insert("4");
}

void keyboard::on_pushButton_5_clicked()
{
    ui->lineEdit->insert("5");
}

void keyboard::on_pushButton_6_clicked()
{
    ui->lineEdit->insert("6");
}

void keyboard::on_pushButton_7_clicked()
{
    ui->lineEdit->insert("7");
}

void keyboard::on_pushButton_8_clicked()
{
    ui->lineEdit->insert("8");
}

void keyboard::on_pushButton_9_clicked()
{
    ui->lineEdit->insert("9");
}

void keyboard::on_pushButton_10_clicked()
{
    ui->lineEdit->insert("0");
}

void keyboard::on_pushButton_11_clicked()
{
    ui->lineEdit->insert("#");
}

void keyboard::on_pushButton_12_clicked()
{
    ui->lineEdit->insert("q");
}

void keyboard::on_pushButton_13_clicked()
{
    ui->lineEdit->insert("w");
}

void keyboard::on_pushButton_14_clicked()
{
    ui->lineEdit->insert("e");
}

void keyboard::on_pushButton_15_clicked()
{
    ui->lineEdit->insert("r");
}

void keyboard::on_pushButton_16_clicked()
{
    ui->lineEdit->insert("t");
}

void keyboard::on_pushButton_17_clicked()
{
    ui->lineEdit->insert("y");
}

void keyboard::on_pushButton_18_clicked()
{
    ui->lineEdit->insert("u");
}

void keyboard::on_pushButton_19_clicked()
{
    ui->lineEdit->insert("i");
}

void keyboard::on_pushButton_20_clicked()
{
    ui->lineEdit->insert("o");
}

void keyboard::on_pushButton_21_clicked()
{
    ui->lineEdit->insert("p");
}

void keyboard::on_pushButton_22_clicked()
{
    ui->lineEdit->insert("#");
}

void keyboard::on_pushButton_23_clicked()
{
    ui->lineEdit->insert("a");
}

void keyboard::on_pushButton_24_clicked()
{
    ui->lineEdit->insert("s");
}

void keyboard::on_pushButton_25_clicked()
{
    ui->lineEdit->insert("d");
}

void keyboard::on_pushButton_26_clicked()
{
    ui->lineEdit->insert("f");
}

void keyboard::on_pushButton_27_clicked()
{
    ui->lineEdit->insert("g");
}

void keyboard::on_pushButton_28_clicked()
{
    ui->lineEdit->insert("h");
}

void keyboard::on_pushButton_29_clicked()
{
    ui->lineEdit->insert("j");
}

void keyboard::on_pushButton_30_clicked()
{
    ui->lineEdit->insert("k");
}

void keyboard::on_pushButton_31_clicked()
{
    ui->lineEdit->insert("l");
}

void keyboard::on_pushButton_32_clicked()
{
    ui->lineEdit->insert(".");
}

void keyboard::on_pushButton_33_clicked()
{
    ui->lineEdit->insert("%");
}

void keyboard::on_pushButton_34_clicked()
{
    ui->lineEdit->insert("z");
}

void keyboard::on_pushButton_35_clicked()
{
    ui->lineEdit->insert("x");
}

void keyboard::on_pushButton_36_clicked()
{
    ui->lineEdit->insert("c");
}

void keyboard::on_pushButton_37_clicked()
{
    ui->lineEdit->insert("v");
}

void keyboard::on_pushButton_38_clicked()
{
    ui->lineEdit->insert("b");
}

void keyboard::on_pushButton_39_clicked()
{
    ui->lineEdit->insert("n");
}

void keyboard::on_pushButton_40_clicked()
{
    ui->lineEdit->insert("m");
}

void keyboard::on_pushButton_41_clicked()
{
    ui->lineEdit->insert("+");
}

void keyboard::on_pushButton_42_clicked()
{
    ui->lineEdit->insert("-");

}

void keyboard::on_pushButton_43_clicked()
{
    ui->lineEdit->insert("*");
}

void keyboard::on_pushButton_44_clicked()
{
    ui->lineEdit->insert("/");
}

void keyboard::on_pushButton_45_clicked()
{
    emit sin_back();
}

void keyboard::on_pushButton_47_clicked()
{
     ui->lineEdit->backspace();
}

void keyboard::paintEvent(QPaintEvent *)//添加背景图
{
     QPainter p(this);
  //  QPainter p;
    //p.begin(this);
    p.drawPixmap(0,0,width(),height(),QPixmap("://picture/jiaju2.jpg"));

  //  p.end();
}

void keyboard::on_pushButton_46_clicked()//把软键盘的内容输入到帐号秘密阿文本框
{
    QString buf;
    QString buf1;
    buf = ui->lineEdit->text();
    buf1 = this->type_t;
    qDebug()<<buf;
    qDebug()<<buf1;
    emit sin_in(buf,buf1);
    if(ui->lineEdit->text() != 0)
    {
        ui->lineEdit->clear();
    }

    this->close();

}

