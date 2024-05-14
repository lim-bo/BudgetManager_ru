/********************************************************************************
** Form generated from reading UI file 'addnodewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNODEWINDOW_H
#define UI_ADDNODEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddNodeWindow
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *categoryBox;
    QLabel *label_2;
    QLineEdit *sumEdit;
    QPushButton *addButton;
    QPushButton *cancelButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *currentRadio;
    QRadioButton *otherRadio;
    QDateEdit *dateEdit;

    void setupUi(QDialog *AddNodeWindow)
    {
        if (AddNodeWindow->objectName().isEmpty())
            AddNodeWindow->setObjectName("AddNodeWindow");
        AddNodeWindow->resize(400, 300);
        AddNodeWindow->setStyleSheet(QString::fromUtf8("font: 10pt \"Bahnschrift SemiCondensed\";\n"
"background-color: rgb(197, 197, 147);\n"
"color: rgb(0, 0, 0);"));
        formLayout = new QFormLayout(AddNodeWindow);
        formLayout->setObjectName("formLayout");
        label = new QLabel(AddNodeWindow);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        categoryBox = new QComboBox(AddNodeWindow);
        categoryBox->addItem(QString());
        categoryBox->addItem(QString());
        categoryBox->addItem(QString());
        categoryBox->addItem(QString());
        categoryBox->addItem(QString());
        categoryBox->addItem(QString());
        categoryBox->addItem(QString());
        categoryBox->setObjectName("categoryBox");

        formLayout->setWidget(0, QFormLayout::FieldRole, categoryBox);

        label_2 = new QLabel(AddNodeWindow);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        sumEdit = new QLineEdit(AddNodeWindow);
        sumEdit->setObjectName("sumEdit");
        sumEdit->setMaxLength(9);

        formLayout->setWidget(1, QFormLayout::FieldRole, sumEdit);

        addButton = new QPushButton(AddNodeWindow);
        addButton->setObjectName("addButton");
        addButton->setStyleSheet(QString::fromUtf8("border-color: rgb(0,0,0);\n"
"color: rgb(0, 0, 0);\n"
"border-width: 20px;\n"
"border-radius: 15px;\n"
"background-color: rgb(194, 194, 194);\n"
"font: 13pt \"Bahnschrift SemiCondensed\";"));

        formLayout->setWidget(2, QFormLayout::FieldRole, addButton);

        cancelButton = new QPushButton(AddNodeWindow);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setStyleSheet(QString::fromUtf8("border-color: rgb(0,0,0);\n"
"color: rgb(0, 0, 0);\n"
"border-width: 20px;\n"
"border-radius: 15px;\n"
"background-color: rgb(194, 194, 194);\n"
"font: 13pt \"Bahnschrift SemiCondensed\";"));

        formLayout->setWidget(3, QFormLayout::FieldRole, cancelButton);

        groupBox = new QGroupBox(AddNodeWindow);
        groupBox->setObjectName("groupBox");
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        currentRadio = new QRadioButton(groupBox);
        currentRadio->setObjectName("currentRadio");
        currentRadio->setChecked(true);

        verticalLayout->addWidget(currentRadio);

        otherRadio = new QRadioButton(groupBox);
        otherRadio->setObjectName("otherRadio");

        verticalLayout->addWidget(otherRadio);

        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setCalendarPopup(true);

        verticalLayout->addWidget(dateEdit);


        formLayout->setWidget(4, QFormLayout::SpanningRole, groupBox);


        retranslateUi(AddNodeWindow);

        QMetaObject::connectSlotsByName(AddNodeWindow);
    } // setupUi

    void retranslateUi(QDialog *AddNodeWindow)
    {
        AddNodeWindow->setWindowTitle(QCoreApplication::translate("AddNodeWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddNodeWindow", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        categoryBox->setItemText(0, QCoreApplication::translate("AddNodeWindow", "\320\232\321\200\320\260\321\201\320\276\321\202\320\260 \320\270 \321\203\321\205\320\276\320\264 \320\267\320\260 \321\201\320\276\320\261\320\276\320\271", nullptr));
        categoryBox->setItemText(1, QCoreApplication::translate("AddNodeWindow", "\320\233\320\265\320\272\320\260\321\200\321\201\321\202\320\262\320\260 \320\270 \320\267\320\264\320\276\321\200\320\276\320\262\321\214\320\265", nullptr));
        categoryBox->setItemText(2, QCoreApplication::translate("AddNodeWindow", "\320\232\320\276\320\274\320\274\321\203\320\275\320\270\320\272\320\260\321\206\320\270\320\270 \320\270 \321\201\320\262\321\217\320\267\321\214", nullptr));
        categoryBox->setItemText(3, QCoreApplication::translate("AddNodeWindow", "\320\226\320\270\320\267\320\275\321\214 \320\270 \321\200\320\260\320\267\320\262\320\273\320\265\321\207\320\265\320\275\320\270\321\217", nullptr));
        categoryBox->setItemText(4, QCoreApplication::translate("AddNodeWindow", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202\321\213", nullptr));
        categoryBox->setItemText(5, QCoreApplication::translate("AddNodeWindow", "\320\224\320\276\321\205\320\276\320\264", nullptr));
        categoryBox->setItemText(6, QCoreApplication::translate("AddNodeWindow", "\320\236\320\264\320\265\320\266\320\264\320\260, \321\202\320\276\320\262\320\260\321\200\321\213 \320\264\320\273\321\217 \320\264\320\276\320\274\320\260 \320\270 \320\277\321\200\320\276\321\207\320\265\320\265", nullptr));

        categoryBox->setPlaceholderText(QString());
        label_2->setText(QCoreApplication::translate("AddNodeWindow", "\320\241\321\203\320\274\320\274\320\260", nullptr));
        addButton->setText(QCoreApplication::translate("AddNodeWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddNodeWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        groupBox->setTitle(QString());
        currentRadio->setText(QCoreApplication::translate("AddNodeWindow", "\320\241\320\265\320\263\320\276\320\264\320\275\321\217", nullptr));
        otherRadio->setText(QCoreApplication::translate("AddNodeWindow", "\320\224\321\200\321\203\320\263\320\276\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddNodeWindow: public Ui_AddNodeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNODEWINDOW_H
