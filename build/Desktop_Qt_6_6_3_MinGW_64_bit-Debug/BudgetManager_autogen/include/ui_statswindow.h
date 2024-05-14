/********************************************************************************
** Form generated from reading UI file 'statswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATSWINDOW_H
#define UI_STATSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_StatsWindow
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *beautyEdit;
    QLabel *label_2;
    QLineEdit *chemistryEdit;
    QLabel *label_3;
    QLineEdit *comEdit;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_7;
    QLineEdit *entertainmentEdit;
    QLineEdit *grosseryEdit;
    QLineEdit *clothesEdit;
    QLineEdit *incomeEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *closeButton;
    QLabel *commentEdit;
    QPushButton *deeperButton;

    void setupUi(QDialog *StatsWindow)
    {
        if (StatsWindow->objectName().isEmpty())
            StatsWindow->setObjectName("StatsWindow");
        StatsWindow->resize(377, 500);
        StatsWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(197, 197, 147);\n"
"color: rgb(0, 0, 0);\n"
"font: 10pt \"Bahnschrift SemiCondensed\";"));
        formLayout = new QFormLayout(StatsWindow);
        formLayout->setObjectName("formLayout");
        label = new QLabel(StatsWindow);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        beautyEdit = new QLineEdit(StatsWindow);
        beautyEdit->setObjectName("beautyEdit");
        beautyEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        beautyEdit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, beautyEdit);

        label_2 = new QLabel(StatsWindow);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        chemistryEdit = new QLineEdit(StatsWindow);
        chemistryEdit->setObjectName("chemistryEdit");
        chemistryEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        chemistryEdit->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, chemistryEdit);

        label_3 = new QLabel(StatsWindow);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        comEdit = new QLineEdit(StatsWindow);
        comEdit->setObjectName("comEdit");
        comEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        comEdit->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, comEdit);

        label_4 = new QLabel(StatsWindow);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_6 = new QLabel(StatsWindow);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        label_5 = new QLabel(StatsWindow);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_7 = new QLabel(StatsWindow);
        label_7->setObjectName("label_7");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_7);

        entertainmentEdit = new QLineEdit(StatsWindow);
        entertainmentEdit->setObjectName("entertainmentEdit");
        entertainmentEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        entertainmentEdit->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, entertainmentEdit);

        grosseryEdit = new QLineEdit(StatsWindow);
        grosseryEdit->setObjectName("grosseryEdit");
        grosseryEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        grosseryEdit->setReadOnly(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, grosseryEdit);

        clothesEdit = new QLineEdit(StatsWindow);
        clothesEdit->setObjectName("clothesEdit");
        clothesEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        clothesEdit->setReadOnly(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, clothesEdit);

        incomeEdit = new QLineEdit(StatsWindow);
        incomeEdit->setObjectName("incomeEdit");
        incomeEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        incomeEdit->setReadOnly(true);

        formLayout->setWidget(7, QFormLayout::FieldRole, incomeEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(6, QFormLayout::LabelRole, verticalSpacer);

        closeButton = new QPushButton(StatsWindow);
        closeButton->setObjectName("closeButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setStyleSheet(QString::fromUtf8("border-color: rgb(0,0,0);\n"
"color: rgb(0, 0, 0);\n"
"border-width: 20px;\n"
"border-radius: 15px;\n"
"background-color: rgb(194, 194, 194);\n"
"font: 13pt \"Bahnschrift SemiCondensed\";"));

        formLayout->setWidget(9, QFormLayout::LabelRole, closeButton);

        commentEdit = new QLabel(StatsWindow);
        commentEdit->setObjectName("commentEdit");

        formLayout->setWidget(8, QFormLayout::LabelRole, commentEdit);

        deeperButton = new QPushButton(StatsWindow);
        deeperButton->setObjectName("deeperButton");
        sizePolicy.setHeightForWidth(deeperButton->sizePolicy().hasHeightForWidth());
        deeperButton->setSizePolicy(sizePolicy);
        deeperButton->setStyleSheet(QString::fromUtf8("border-color: rgb(0,0,0);\n"
"color: rgb(0, 0, 0);\n"
"border-width: 20px;\n"
"border-radius: 15px;\n"
"background-color: rgb(194, 194, 194);\n"
"font: 13pt \"Bahnschrift SemiCondensed\";"));

        formLayout->setWidget(9, QFormLayout::FieldRole, deeperButton);


        retranslateUi(StatsWindow);

        QMetaObject::connectSlotsByName(StatsWindow);
    } // setupUi

    void retranslateUi(QDialog *StatsWindow)
    {
        StatsWindow->setWindowTitle(QCoreApplication::translate("StatsWindow", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        label->setText(QCoreApplication::translate("StatsWindow", "\320\232\321\200\320\260\321\201\320\276\321\202\320\260 \320\270 \321\203\321\205\320\276\320\264 \320\267\320\260 \321\201\320\276\320\261\320\276\320\271", nullptr));
        label_2->setText(QCoreApplication::translate("StatsWindow", "\320\233\320\265\320\272\320\260\321\200\321\201\321\202\320\262\320\260 \320\270 \320\267\320\264\320\276\321\200\320\276\320\262\321\214\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("StatsWindow", "\320\232\320\276\320\274\320\274\321\203\320\275\320\270\320\272\320\260\321\206\320\270\320\270 \320\270 \321\201\320\262\321\217\320\267\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("StatsWindow", "\320\226\320\270\320\267\320\275\321\214 \320\270 \321\200\320\260\320\267\320\262\320\273\320\265\321\207\320\265\320\275\320\270\321\217", nullptr));
        label_6->setText(QCoreApplication::translate("StatsWindow", "\320\236\320\264\320\265\320\266\320\264\320\260, \321\202\320\276\320\262\320\260\321\200\321\213 \320\264\320\273\321\217 \320\264\320\276\320\274\320\260 \320\270 \320\277\321\200", nullptr));
        label_5->setText(QCoreApplication::translate("StatsWindow", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202\321\213", nullptr));
        label_7->setText(QCoreApplication::translate("StatsWindow", "\320\224\320\276\321\205\320\276\320\264", nullptr));
        closeButton->setText(QCoreApplication::translate("StatsWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        commentEdit->setText(QCoreApplication::translate("StatsWindow", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271", nullptr));
        deeperButton->setText(QCoreApplication::translate("StatsWindow", "\320\237\320\276\320\264\321\200\320\276\320\261\320\275\320\265\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatsWindow: public Ui_StatsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATSWINDOW_H
