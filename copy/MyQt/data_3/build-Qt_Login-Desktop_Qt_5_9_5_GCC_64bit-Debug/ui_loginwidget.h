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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QWidget *login_main_widget;
    QWidget *login_con_widget;
    QPushButton *pushButtonlogin;
    QLineEdit *lineEditPass;
    QCheckBox *checkBox_2;
    QLineEdit *lineEditQQ;
    QCheckBox *checkBox;
    QPushButton *pushButtonRegister;
    QLabel *labelQQ;
    QLabel *labelPasswd;
    QLabel *label;
    QLineEdit *lineEditTime;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QStringLiteral("LoginWidget"));
        LoginWidget->resize(470, 350);
        login_main_widget = new QWidget(LoginWidget);
        login_main_widget->setObjectName(QStringLiteral("login_main_widget"));
        login_main_widget->setGeometry(QRect(18, 9, 433, 332));
        login_main_widget->setMinimumSize(QSize(433, 332));
        login_main_widget->setMaximumSize(QSize(433, 332));
        login_main_widget->setStyleSheet(QStringLiteral(""));
        login_con_widget = new QWidget(login_main_widget);
        login_con_widget->setObjectName(QStringLiteral("login_con_widget"));
        login_con_widget->setGeometry(QRect(0, 180, 427, 150));
        login_con_widget->setMinimumSize(QSize(0, 150));
        login_con_widget->setMaximumSize(QSize(16777215, 150));
        pushButtonlogin = new QPushButton(login_con_widget);
        pushButtonlogin->setObjectName(QStringLiteral("pushButtonlogin"));
        pushButtonlogin->setGeometry(QRect(100, 100, 195, 32));
        pushButtonlogin->setMinimumSize(QSize(195, 32));
        lineEditPass = new QLineEdit(login_con_widget);
        lineEditPass->setObjectName(QStringLiteral("lineEditPass"));
        lineEditPass->setGeometry(QRect(100, 40, 195, 29));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lineEditPass->setFont(font);
        lineEditPass->setEchoMode(QLineEdit::Password);
        checkBox_2 = new QCheckBox(login_con_widget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(200, 70, 91, 21));
        lineEditQQ = new QLineEdit(login_con_widget);
        lineEditQQ->setObjectName(QStringLiteral("lineEditQQ"));
        lineEditQQ->setGeometry(QRect(100, 10, 195, 30));
        lineEditQQ->setFont(font);
        checkBox = new QCheckBox(login_con_widget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(100, 70, 81, 21));
        checkBox->setChecked(true);
        pushButtonRegister = new QPushButton(login_con_widget);
        pushButtonRegister->setObjectName(QStringLiteral("pushButtonRegister"));
        pushButtonRegister->setGeometry(QRect(330, 100, 84, 28));
        labelQQ = new QLabel(login_con_widget);
        labelQQ->setObjectName(QStringLiteral("labelQQ"));
        labelQQ->setGeometry(QRect(30, 20, 63, 20));
        labelPasswd = new QLabel(login_con_widget);
        labelPasswd->setObjectName(QStringLiteral("labelPasswd"));
        labelPasswd->setGeometry(QRect(30, 50, 63, 20));
        label = new QLabel(login_main_widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 110, 81, 31));
        lineEditTime = new QLineEdit(login_main_widget);
        lineEditTime->setObjectName(QStringLiteral("lineEditTime"));
        lineEditTime->setGeometry(QRect(262, 10, 161, 28));

        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QApplication::translate("LoginWidget", "LoginWidget", Q_NULLPTR));
        pushButtonlogin->setText(QApplication::translate("LoginWidget", "\347\231\273\345\275\225", Q_NULLPTR));
        lineEditPass->setText(QString());
        checkBox_2->setText(QApplication::translate("LoginWidget", "\350\207\252\345\212\250\347\231\273\345\275\225", Q_NULLPTR));
        lineEditQQ->setText(QString());
        checkBox->setText(QApplication::translate("LoginWidget", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        pushButtonRegister->setText(QApplication::translate("LoginWidget", "\346\263\250\345\206\214", Q_NULLPTR));
        labelQQ->setText(QApplication::translate("LoginWidget", "<html><head/><body><p><span style=\" font-weight:600; color:#4cbf40;\">\350\264\246\345\217\267:</span></p></body></html>", Q_NULLPTR));
        labelPasswd->setText(QApplication::translate("LoginWidget", "<html><head/><body><p><span style=\" font-weight:600; color:#4cbf40;\">\345\257\206\347\240\201:</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("LoginWidget", "<html><head/><body><p><span style=\" font-weight:600; font-style:italic; color:#cc0000;\">\346\254\242\350\277\216\345\205\211\344\270\264</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
