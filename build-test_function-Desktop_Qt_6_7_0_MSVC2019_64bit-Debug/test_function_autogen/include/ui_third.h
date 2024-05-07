/********************************************************************************
** Form generated from reading UI file 'third.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIRD_H
#define UI_THIRD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_third
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *third)
    {
        if (third->objectName().isEmpty())
            third->setObjectName("third");
        third->resize(400, 300);
        buttonBox = new QDialogButtonBox(third);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(third);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, third, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, third, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(third);
    } // setupUi

    void retranslateUi(QDialog *third)
    {
        third->setWindowTitle(QCoreApplication::translate("third", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class third: public Ui_third {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRD_H
