/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QPushButton *pushButtonQuit;
    QLabel *label_2;
    QPushButton *pushButtonLogIn;
    QLabel *label;
    QPushButton *pushButtonRegister;
    QLineEdit *lineEditUserName;
    QTextEdit *textEdit;
    QLineEdit *lineEditPasswd;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QStringLiteral("LoginWidget"));
        LoginWidget->resize(400, 300);
        pushButtonQuit = new QPushButton(LoginWidget);
        pushButtonQuit->setObjectName(QStringLiteral("pushButtonQuit"));
        pushButtonQuit->setGeometry(QRect(290, 250, 84, 28));
        label_2 = new QLabel(LoginWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 180, 63, 20));
        pushButtonLogIn = new QPushButton(LoginWidget);
        pushButtonLogIn->setObjectName(QStringLiteral("pushButtonLogIn"));
        pushButtonLogIn->setGeometry(QRect(60, 250, 84, 28));
        label = new QLabel(LoginWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 130, 91, 20));
        pushButtonRegister = new QPushButton(LoginWidget);
        pushButtonRegister->setObjectName(QStringLiteral("pushButtonRegister"));
        pushButtonRegister->setGeometry(QRect(170, 250, 84, 28));
        lineEditUserName = new QLineEdit(LoginWidget);
        lineEditUserName->setObjectName(QStringLiteral("lineEditUserName"));
        lineEditUserName->setGeometry(QRect(130, 130, 161, 28));
        textEdit = new QTextEdit(LoginWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(130, 0, 133, 121));
        textEdit->setReadOnly(true);
        lineEditPasswd = new QLineEdit(LoginWidget);
        lineEditPasswd->setObjectName(QStringLiteral("lineEditPasswd"));
        lineEditPasswd->setGeometry(QRect(130, 180, 161, 28));

        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QApplication::translate("LoginWidget", "LoginWidget", Q_NULLPTR));
        pushButtonQuit->setText(QApplication::translate("LoginWidget", "Quit", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginWidget", "Passwd:", Q_NULLPTR));
        pushButtonLogIn->setText(QApplication::translate("LoginWidget", "LogIn", Q_NULLPTR));
        label->setText(QApplication::translate("LoginWidget", "UserName:", Q_NULLPTR));
        pushButtonRegister->setText(QApplication::translate("LoginWidget", "Register", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
