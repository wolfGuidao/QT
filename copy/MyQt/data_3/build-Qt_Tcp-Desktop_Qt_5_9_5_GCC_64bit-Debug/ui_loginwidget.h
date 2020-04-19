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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogInWidget
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QLabel *label;
    QLineEdit *lineEditUserName;
    QLabel *label_2;
    QLineEdit *lineEditPasswd;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonLogIn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonRegister;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonQuit;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *LogInWidget)
    {
        if (LogInWidget->objectName().isEmpty())
            LogInWidget->setObjectName(QStringLiteral("LogInWidget"));
        LogInWidget->resize(400, 300);
        gridLayout = new QGridLayout(LogInWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(LogInWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 2, 1, 4);

        label = new QLabel(LogInWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 2);

        lineEditUserName = new QLineEdit(LogInWidget);
        lineEditUserName->setObjectName(QStringLiteral("lineEditUserName"));

        gridLayout->addWidget(lineEditUserName, 1, 2, 1, 4);

        label_2 = new QLabel(LogInWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 2);

        lineEditPasswd = new QLineEdit(LogInWidget);
        lineEditPasswd->setObjectName(QStringLiteral("lineEditPasswd"));

        gridLayout->addWidget(lineEditPasswd, 2, 2, 1, 4);

        horizontalSpacer = new QSpacerItem(64, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        pushButtonLogIn = new QPushButton(LogInWidget);
        pushButtonLogIn->setObjectName(QStringLiteral("pushButtonLogIn"));

        gridLayout->addWidget(pushButtonLogIn, 3, 1, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(16, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 3, 1, 1);

        pushButtonRegister = new QPushButton(LogInWidget);
        pushButtonRegister->setObjectName(QStringLiteral("pushButtonRegister"));

        gridLayout->addWidget(pushButtonRegister, 3, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 5, 1, 1);

        pushButtonQuit = new QPushButton(LogInWidget);
        pushButtonQuit->setObjectName(QStringLiteral("pushButtonQuit"));

        gridLayout->addWidget(pushButtonQuit, 3, 6, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 7, 1, 1);


        retranslateUi(LogInWidget);

        QMetaObject::connectSlotsByName(LogInWidget);
    } // setupUi

    void retranslateUi(QWidget *LogInWidget)
    {
        LogInWidget->setWindowTitle(QApplication::translate("LogInWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("LogInWidget", "UserName:", Q_NULLPTR));
        label_2->setText(QApplication::translate("LogInWidget", "Passwd:", Q_NULLPTR));
        pushButtonLogIn->setText(QApplication::translate("LogInWidget", "LogIn", Q_NULLPTR));
        pushButtonRegister->setText(QApplication::translate("LogInWidget", "Register", Q_NULLPTR));
        pushButtonQuit->setText(QApplication::translate("LogInWidget", "Quit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LogInWidget: public Ui_LogInWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
