/********************************************************************************
** Form generated from reading UI file 'schedulemsy.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULEMSY_H
#define UI_SCHEDULEMSY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_scheduleMSY
{
public:

    void setupUi(QWidget *scheduleMSY)
    {
        if (scheduleMSY->objectName().isEmpty())
            scheduleMSY->setObjectName("scheduleMSY");
        scheduleMSY->resize(400, 300);

        retranslateUi(scheduleMSY);

        QMetaObject::connectSlotsByName(scheduleMSY);
    } // setupUi

    void retranslateUi(QWidget *scheduleMSY)
    {
        scheduleMSY->setWindowTitle(QCoreApplication::translate("scheduleMSY", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class scheduleMSY: public Ui_scheduleMSY {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULEMSY_H
