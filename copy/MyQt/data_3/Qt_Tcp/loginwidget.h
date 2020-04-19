#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

namespace Ui {
class LogInWidget;
}

class LogInWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogInWidget(QWidget *parent = 0);
    ~LogInWidget();

private slots:
    void on_pushButtonLogIn_clicked();

private:
    Ui::LogInWidget *ui;
};

#endif // LOGINWIDGET_H
