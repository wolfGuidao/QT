#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar* mBar = menuBar();
    QMenu* pFile = mBar->addMenu("file");
    QAction* pNew =  pFile->addAction("new");

    connect(pNew,&QAction::triggered,[=]()
    {
        qDebug()<<"new is anxia";
    });


    pFile->addSeparator();
    QAction* pOpen =  pFile->addAction("open");


    QToolBar* toolBar = addToolBar("toolBar");
    toolBar->addAction(pNew);

    QPushButton* b = new QPushButton(this);
    b->setText("^_^");

    toolBar->addWidget(b);

    connect(b,&QPushButton::clicked,[=]()
    {
        b->setText("@_@");
    });


    QStatusBar* staBar = statusBar();
    QLabel* label = new QLabel(this);
    label->setText("Normal text file");

    staBar->addWidget(label);
    staBar->addWidget(new QLabel("999",this));
    staBar->addPermanentWidget(new QLabel("666",this));

    QTextEdit* textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);


    QDockWidget* dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,dock);

    QTextEdit* textEdit1 = new QTextEdit(dock);
    setCentralWidget(textEdit1);






}

MainWindow::~MainWindow()
{

}
