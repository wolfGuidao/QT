/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

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

class Ui_clientwidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditIP;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QTextEdit *textEditRead;
    QTextEdit *textEditWrite;
    QSpacerItem *horizontalSpacer;
    QPushButton *ButtonSend;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ButtonClose;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *ButtonConnect;

    void setupUi(QWidget *clientwidget)
    {
        if (clientwidget->objectName().isEmpty())
            clientwidget->setObjectName(QStringLiteral("clientwidget"));
        clientwidget->resize(400, 300);
        gridLayout = new QGridLayout(clientwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(clientwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        lineEditIP = new QLineEdit(clientwidget);
        lineEditIP->setObjectName(QStringLiteral("lineEditIP"));

        gridLayout->addWidget(lineEditIP, 0, 2, 1, 3);

        label_2 = new QLabel(clientwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        lineEditPort = new QLineEdit(clientwidget);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 1, 2, 1, 3);

        textEditRead = new QTextEdit(clientwidget);
        textEditRead->setObjectName(QStringLiteral("textEditRead"));
        textEditRead->setReadOnly(true);

        gridLayout->addWidget(textEditRead, 2, 0, 1, 6);

        textEditWrite = new QTextEdit(clientwidget);
        textEditWrite->setObjectName(QStringLiteral("textEditWrite"));

        gridLayout->addWidget(textEditWrite, 3, 0, 1, 6);

        horizontalSpacer = new QSpacerItem(67, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        ButtonSend = new QPushButton(clientwidget);
        ButtonSend->setObjectName(QStringLiteral("ButtonSend"));

        gridLayout->addWidget(ButtonSend, 4, 1, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 3, 1, 1);

        ButtonClose = new QPushButton(clientwidget);
        ButtonClose->setObjectName(QStringLiteral("ButtonClose"));

        gridLayout->addWidget(ButtonClose, 4, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(77, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 5, 1, 1);

        ButtonConnect = new QPushButton(clientwidget);
        ButtonConnect->setObjectName(QStringLiteral("ButtonConnect"));

        gridLayout->addWidget(ButtonConnect, 0, 5, 2, 1);


        retranslateUi(clientwidget);

        QMetaObject::connectSlotsByName(clientwidget);
    } // setupUi

    void retranslateUi(QWidget *clientwidget)
    {
        clientwidget->setWindowTitle(QApplication::translate("clientwidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("clientwidget", "server ip:", Q_NULLPTR));
        lineEditIP->setText(QApplication::translate("clientwidget", "127.0.0.1", Q_NULLPTR));
        label_2->setText(QApplication::translate("clientwidget", "server port:", Q_NULLPTR));
        lineEditPort->setText(QApplication::translate("clientwidget", "9090", Q_NULLPTR));
        ButtonSend->setText(QApplication::translate("clientwidget", "Send", Q_NULLPTR));
        ButtonClose->setText(QApplication::translate("clientwidget", "Close", Q_NULLPTR));
        ButtonConnect->setText(QApplication::translate("clientwidget", "connect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class clientwidget: public Ui_clientwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
