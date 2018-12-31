/********************************************************************************
** Form generated from reading UI file 'YazLab3.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YAZLAB3_H
#define UI_YAZLAB3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YazLab3Class
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label;
    QProgressBar *progressBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *YazLab3Class)
    {
        if (YazLab3Class->objectName().isEmpty())
            YazLab3Class->setObjectName(QString::fromUtf8("YazLab3Class"));
        YazLab3Class->resize(544, 487);
        centralWidget = new QWidget(YazLab3Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 40, 75, 23));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(150, 40, 75, 23));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(260, 40, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 100, 301, 311));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setGeometry(QRect(380, 40, 101, 23));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        YazLab3Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(YazLab3Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        YazLab3Class->setStatusBar(statusBar);

        retranslateUi(YazLab3Class);

        QMetaObject::connectSlotsByName(YazLab3Class);
    } // setupUi

    void retranslateUi(QMainWindow *YazLab3Class)
    {
        YazLab3Class->setWindowTitle(QApplication::translate("YazLab3Class", "YazLab3", nullptr));
        pushButton->setText(QApplication::translate("YazLab3Class", "D\303\266n\303\274\305\237t\303\274r", nullptr));
        pushButton_4->setText(QApplication::translate("YazLab3Class", "Kaydet", nullptr));
        pushButton_5->setText(QApplication::translate("YazLab3Class", "Oynat", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class YazLab3Class: public Ui_YazLab3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YAZLAB3_H
