/********************************************************************************
** Form generated from reading UI file 'clockhzj.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCKHZJ_H
#define UI_CLOCKHZJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clockHZJ
{
public:

    void setupUi(QWidget *clockHZJ)
    {
        if (clockHZJ->objectName().isEmpty())
            clockHZJ->setObjectName("clockHZJ");
        clockHZJ->resize(400, 300);

        retranslateUi(clockHZJ);

        QMetaObject::connectSlotsByName(clockHZJ);
    } // setupUi

    void retranslateUi(QWidget *clockHZJ)
    {
        clockHZJ->setWindowTitle(QCoreApplication::translate("clockHZJ", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clockHZJ: public Ui_clockHZJ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCKHZJ_H
