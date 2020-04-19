#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QMessageBox>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include "serverwidget.h"
#include "clientwidget.h"


LogInWidget::LogInWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogInWidget)
{
    ui->setupUi(this);
}

LogInWidget::~LogInWidget()
{
    delete ui;
}

void LogInWidget::on_pushButtonLogIn_clicked()
{
    //获得userNameLEd输入框的文本：userNameLEd->text()；
        //trimmed()去掉前后空格
        //tr()函数，防止设置中文时乱码

        if(ui->lineEditUserName->text().trimmed() == tr("wolf") && ui->lineEditPasswd->text() == tr("123456"))
        {
            this->hide();
            ServerWidget w;
            w.show();

            clientwidget w1;
            w1.show();


            //while(1);
        }
        else
        {                              //标题              内容                OK按钮
           QMessageBox::warning(this, tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);

        // 清空输入框内容
           ui->lineEditUserName->clear();
           ui->lineEditPasswd->clear();

           //光标定位
           ui->lineEditUserName->setFocus();
        }
}
