#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);

    QWidget w;
    w.setWindowTitle("hello QT!!!");

    QPushButton b;
    b.setText("is me");
    b.setParent(&w);
    b.move(100,100);

    //QPushButton b1(&w);
    //b1.setText("also me");
    //b1.move(80,80);

    w.show();
    app.exec();
    return 0;
}
