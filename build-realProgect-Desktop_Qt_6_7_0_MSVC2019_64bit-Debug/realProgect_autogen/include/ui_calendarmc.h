/********************************************************************************
** Form generated from reading UI file 'calendarmc.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARMC_H
#define UI_CALENDARMC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calendarMC
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *calendarMC)
    {
        if (calendarMC->objectName().isEmpty())
            calendarMC->setObjectName("calendarMC");
        calendarMC->resize(400, 300);
        pushButton = new QPushButton(calendarMC);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(50, 240, 80, 18));
        pushButton_2 = new QPushButton(calendarMC);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 240, 80, 18));

        retranslateUi(calendarMC);

        QMetaObject::connectSlotsByName(calendarMC);
    } // setupUi

    void retranslateUi(QWidget *calendarMC)
    {
        calendarMC->setWindowTitle(QCoreApplication::translate("calendarMC", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("calendarMC", "\344\277\256\346\224\271\346\227\245\347\250\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("calendarMC", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calendarMC: public Ui_calendarMC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARMC_H