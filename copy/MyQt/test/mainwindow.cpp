#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton* p1 = new QPushButton(this);
    p1->setText("i am test");
    connect(p1,&QPushButton::clicked,this,&MainWindow::hide);
}

MainWindow::~MainWindow()
{
    delete ui;
}
