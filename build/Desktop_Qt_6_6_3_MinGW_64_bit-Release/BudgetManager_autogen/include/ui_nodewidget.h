/********************************************************************************
** Form generated from reading UI file 'nodewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODEWIDGET_H
#define UI_NODEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NodeWidget
{
public:
    QGridLayout *gridLayout;
    QComboBox *category;
    QCheckBox *editable;
    QLabel *name;
    QLineEdit *sum;
    QDateEdit *dateEdit;

    void setupUi(QWidget *NodeWidget)
    {
        if (NodeWidget->objectName().isEmpty())
            NodeWidget->setObjectName("NodeWidget");
        NodeWidget->resize(464, 99);
        NodeWidget->setStyleSheet(QString::fromUtf8("border-color:rgb(0,0,0);\n"
"font: 11pt \"Bahnschrift SemiCondensed\";\n"
"border-width:20px;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color:rgb(0,0,0);"));
        gridLayout = new QGridLayout(NodeWidget);
        gridLayout->setObjectName("gridLayout");
        category = new QComboBox(NodeWidget);
        category->addItem(QString());
        category->addItem(QString());
        category->addItem(QString());
        category->addItem(QString());
        category->addItem(QString());
        category->addItem(QString());
        category->addItem(QString());
        category->setObjectName("category");
        category->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(category->sizePolicy().hasHeightForWidth());
        category->setSizePolicy(sizePolicy);
        category->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 185, 185);"));

        gridLayout->addWidget(category, 1, 1, 1, 1);

        editable = new QCheckBox(NodeWidget);
        editable->setObjectName("editable");
        editable->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(editable->sizePolicy().hasHeightForWidth());
        editable->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(editable, 0, 0, 1, 1);

        name = new QLabel(NodeWidget);
        name->setObjectName("name");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy2);
        name->setStyleSheet(QString::fromUtf8("color:rgb(0,0,0);"));

        gridLayout->addWidget(name, 0, 1, 1, 1);

        sum = new QLineEdit(NodeWidget);
        sum->setObjectName("sum");
        sum->setEnabled(true);
        sizePolicy1.setHeightForWidth(sum->sizePolicy().hasHeightForWidth());
        sum->setSizePolicy(sizePolicy1);
        sum->setReadOnly(true);

        gridLayout->addWidget(sum, 0, 2, 1, 1);

        dateEdit = new QDateEdit(NodeWidget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setEnabled(false);
        dateEdit->setReadOnly(true);
        dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit, 1, 2, 1, 1);


        retranslateUi(NodeWidget);

        QMetaObject::connectSlotsByName(NodeWidget);
    } // setupUi

    void retranslateUi(QWidget *NodeWidget)
    {
        NodeWidget->setWindowTitle(QCoreApplication::translate("NodeWidget", "Form", nullptr));
        category->setItemText(0, QCoreApplication::translate("NodeWidget", "\320\232\321\200\320\260\321\201\320\276\321\202\320\260 \320\270 \321\203\321\205\320\276\320\264 \320\267\320\260 \321\201\320\276\320\261\320\276\320\271", nullptr));
        category->setItemText(1, QCoreApplication::translate("NodeWidget", "\320\233\320\265\320\272\320\260\321\200\321\201\321\202\320\262\320\260 \320\270 \320\267\320\264\320\276\321\200\320\276\320\262\321\214\320\265", nullptr));
        category->setItemText(2, QCoreApplication::translate("NodeWidget", "\320\232\320\276\320\274\320\274\321\203\320\275\320\270\320\272\320\260\321\206\320\270\320\270 \320\270 \321\201\320\262\321\217\320\267\321\214", nullptr));
        category->setItemText(3, QCoreApplication::translate("NodeWidget", "\320\226\320\270\320\267\320\275\321\214 \320\270 \321\200\320\260\320\267\320\262\320\273\320\265\321\207\320\265\320\275\320\270\321\217", nullptr));
        category->setItemText(4, QCoreApplication::translate("NodeWidget", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202\321\213", nullptr));
        category->setItemText(5, QCoreApplication::translate("NodeWidget", "\320\224\320\276\321\205\320\276\320\264", nullptr));
        category->setItemText(6, QCoreApplication::translate("NodeWidget", "\320\236\320\264\320\265\320\266\320\264\320\260, \321\202\320\276\320\262\320\260\321\200\321\213 \320\264\320\273\321\217 \320\264\320\276\320\274\320\260 \320\270 \320\277\321\200\320\276\321\207\320\265\320\265", nullptr));

        editable->setText(QString());
        name->setText(QCoreApplication::translate("NodeWidget", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271", nullptr));
        sum->setPlaceholderText(QCoreApplication::translate("NodeWidget", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NodeWidget: public Ui_NodeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODEWIDGET_H
