/********************************************************************************
** Form generated from reading UI file 'OptionMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONMENU_H
#define UI_OPTIONMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_OptionMenu
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;

    void setupUi(QDialog *OptionMenu)
    {
        if (OptionMenu->objectName().isEmpty())
            OptionMenu->setObjectName(QString::fromUtf8("OptionMenu"));
        OptionMenu->resize(315, 185);
        label = new QLabel(OptionMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 60, 61, 16));
        label_2 = new QLabel(OptionMenu);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 110, 47, 21));
        comboBox = new QComboBox(OptionMenu);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(130, 110, 111, 22));
        comboBox->setMaxVisibleItems(3);
        lineEdit = new QLineEdit(OptionMenu);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 60, 41, 20));
        lineEdit_2 = new QLineEdit(OptionMenu);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 60, 41, 20));
        label_3 = new QLabel(OptionMenu);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 60, 16, 20));

        retranslateUi(OptionMenu);

        comboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(OptionMenu);
    } // setupUi

    void retranslateUi(QDialog *OptionMenu)
    {
        OptionMenu->setWindowTitle(QApplication::translate("OptionMenu", "OptionMenu", nullptr));
        label->setText(QApplication::translate("OptionMenu", "\303\207\303\266z\303\274n\303\274rl\303\274k:", nullptr));
        label_2->setText(QApplication::translate("OptionMenu", "Format:", nullptr));
        label_3->setText(QApplication::translate("OptionMenu", " X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionMenu: public Ui_OptionMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONMENU_H
