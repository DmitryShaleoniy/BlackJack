/********************************************************************************
** Form generated from reading UI file 'makebetdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKEBETDIALOG_H
#define UI_MAKEBETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MakeBetDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QSpinBox *spinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MakeBetDialog)
    {
        if (MakeBetDialog->objectName().isEmpty())
            MakeBetDialog->setObjectName("MakeBetDialog");
        MakeBetDialog->resize(420, 132);
        gridLayout = new QGridLayout(MakeBetDialog);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(MakeBetDialog);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label = new QLabel(MakeBetDialog);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        spinBox = new QSpinBox(MakeBetDialog);
        spinBox->setObjectName("spinBox");

        verticalLayout->addWidget(spinBox);

        buttonBox = new QDialogButtonBox(MakeBetDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(MakeBetDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MakeBetDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MakeBetDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MakeBetDialog);
    } // setupUi

    void retranslateUi(QDialog *MakeBetDialog)
    {
        MakeBetDialog->setWindowTitle(QCoreApplication::translate("MakeBetDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("MakeBetDialog", "\320\222\320\260\321\210 \320\261\320\260\320\273\320\260\320\275\321\201:", nullptr));
        label->setText(QCoreApplication::translate("MakeBetDialog", "\320\241\320\264\320\265\320\273\320\260\320\271\321\202\320\265 \321\201\321\202\320\260\320\262\320\272\321\203:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MakeBetDialog: public Ui_MakeBetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKEBETDIALOG_H
