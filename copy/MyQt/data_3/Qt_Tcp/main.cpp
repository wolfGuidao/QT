#include "serverwidget.h"
#include <QApplication>
#include "loginwidget.h"
#include "clientwidget.h"
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LogInWidget login;

    login.show();

     return a.exec();
}
