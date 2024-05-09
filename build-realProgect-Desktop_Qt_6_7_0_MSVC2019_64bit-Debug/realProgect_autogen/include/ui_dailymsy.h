/********************************************************************************
** Form generated from reading UI file 'dailymsy.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAILYMSY_H
#define UI_DAILYMSY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dailyMSY
{
public:

    void setupUi(QWidget *dailyMSY)
    {
        if (dailyMSY->objectName().isEmpty())
            dailyMSY->setObjectName("dailyMSY");
        dailyMSY->resize(400, 300);

        retranslateUi(dailyMSY);

        QMetaObject::connectSlotsByName(dailyMSY);
    } // setupUi

    void retranslateUi(QWidget *dailyMSY)
    {
        dailyMSY->setWindowTitle(QCoreApplication::translate("dailyMSY", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dailyMSY: public Ui_dailyMSY {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAILYMSY_H
