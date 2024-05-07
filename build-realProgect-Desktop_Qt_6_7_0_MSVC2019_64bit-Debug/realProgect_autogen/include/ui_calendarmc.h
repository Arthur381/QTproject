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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calendarMC
{
public:

    void setupUi(QWidget *calendarMC)
    {
        if (calendarMC->objectName().isEmpty())
            calendarMC->setObjectName("calendarMC");
        calendarMC->resize(400, 300);

        retranslateUi(calendarMC);

        QMetaObject::connectSlotsByName(calendarMC);
    } // setupUi

    void retranslateUi(QWidget *calendarMC)
    {
        calendarMC->setWindowTitle(QCoreApplication::translate("calendarMC", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calendarMC: public Ui_calendarMC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARMC_H
