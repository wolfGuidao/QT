#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QDebug>
#include <QAction>
#include <QPushButton>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(500,500);
    QMenuBar* mBar = menuBar();
    setMenuBar(mBar);
    QMenu* menu = mBar->addMenu("dui hua kuang");

    QAction* p1 = menu->addAction("mo tai dui hua kuang");
    connect(p1,&QAction::triggered,[=]()
    {
        QDialog dig;
        dig.exec();
        qDebug()<<"after QDialog";
    });

    QAction* p2 = menu->addAction("fei mo tai dui hua kuang");
    connect(p2,&QAction::triggered,[=]()
    {
        //QDialog dig;
        //dig.show();

        //QDialog* dig = new QDialog(this);
        //dig->show();

        QDialog* dig = new QDialog;
        dig->setAttribute(Qt::WA_DeleteOnClose);
        dig->show();
        qDebug()<<"after QDialog";
    });

    QAction* p3 = menu->addAction("guan yu dui hua kuang");
    connect(p3,&QAction::triggered,[=]()
    {
        QMessageBox::about(this,"about","guan yu QT");
    });

    QAction* p4 = menu->addAction("wen ti dui hua kuang");
    connect(p4,&QAction::triggered,[=]()
    {
        int ret = QMessageBox::question(this,"question","you ren ma?",QMessageBox::Ok,QMessageBox::Cancel,QMessageBox::No);
        switch(ret)
        {
            case QMessageBox::Ok:
                qDebug()<<"i am ok";
            break;

        case QMessageBox::No:
            qDebug()<<"i am no";
            break;

        case QMessageBox::Cancel:
            qDebug()<<"i am Cancel";
            break;

        default:
            break;
        }
    });

    QAction* p5 = menu->addAction("wen jian dui hua kuang");
    connect(p5,&QAction::triggered,[=]()
    {
        QString path = QFileDialog::getOpenFileName(this,"open","../","souce(*.cpp *.h);;Text(*.txt);;all(*.*)");
        qDebug()<<path;
    });

}

MainWindow::~MainWindow()
{

}
