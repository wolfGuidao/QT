/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonLogin;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonRegister;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonQuit;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEditName;
    QLineEdit *lineEditpasswd;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName(QStringLiteral("LoginForm"));
        LoginForm->resize(400, 300);
        gridLayout = new QGridLayout(LoginForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(LoginForm);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 0, 2, 1, 4);

        label = new QLabel(LoginForm);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 2);

        label_2 = new QLabel(LoginForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(67, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        pushButtonLogin = new QPushButton(LoginForm);
        pushButtonLogin->setObjectName(QStringLiteral("pushButtonLogin"));

        gridLayout->addWidget(pushButtonLogin, 3, 1, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(15, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 3, 1, 1);

        pushButtonRegister = new QPushButton(LoginForm);
        pushButtonRegister->setObjectName(QStringLiteral("pushButtonRegister"));

        gridLayout->addWidget(pushButtonRegister, 3, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(15, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 5, 1, 1);

        pushButtonQuit = new QPushButton(LoginForm);
        pushButtonQuit->setObjectName(QStringLiteral("pushButtonQuit"));

        gridLayout->addWidget(pushButtonQuit, 3, 6, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 7, 1, 1);

        lineEditName = new QLineEdit(LoginForm);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));

        gridLayout->addWidget(lineEditName, 1, 2, 1, 4);

        lineEditpasswd = new QLineEdit(LoginForm);
        lineEditpasswd->setObjectName(QStringLiteral("lineEditpasswd"));

        gridLayout->addWidget(lineEditpasswd, 2, 2, 1, 4);


        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QApplication::translate("LoginForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("LoginForm", "user_name:", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginForm", "passwd:", Q_NULLPTR));
        pushButtonLogin->setText(QApplication::translate("LoginForm", "login", Q_NULLPTR));
        pushButtonRegister->setText(QApplication::translate("LoginForm", "register", Q_NULLPTR));
        pushButtonQuit->setText(QApplication::translate("LoginForm", "quit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
