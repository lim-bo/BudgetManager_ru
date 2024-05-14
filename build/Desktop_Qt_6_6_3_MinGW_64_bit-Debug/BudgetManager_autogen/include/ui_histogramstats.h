/********************************************************************************
** Form generated from reading UI file 'histogramstats.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMSTATS_H
#define UI_HISTOGRAMSTATS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_histogramStats
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *closeButton;

    void setupUi(QDialog *histogramStats)
    {
        if (histogramStats->objectName().isEmpty())
            histogramStats->setObjectName("histogramStats");
        histogramStats->resize(1005, 581);
        verticalLayout = new QVBoxLayout(histogramStats);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(histogramStats);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");

        verticalLayout->addWidget(frame);

        closeButton = new QPushButton(histogramStats);
        closeButton->setObjectName("closeButton");
        closeButton->setStyleSheet(QString::fromUtf8("border-color: rgb(0,0,0);\n"
"color: rgb(0, 0, 0);\n"
"border-width: 20px;\n"
"border-radius: 15px;\n"
"background-color: rgb(194, 194, 194);\n"
"font: 13pt \"Bahnschrift SemiCondensed\";"));

        verticalLayout->addWidget(closeButton);


        retranslateUi(histogramStats);

        QMetaObject::connectSlotsByName(histogramStats);
    } // setupUi

    void retranslateUi(QDialog *histogramStats)
    {
        histogramStats->setWindowTitle(QCoreApplication::translate("histogramStats", "\320\235\320\260\320\263\320\273\321\217\320\264\320\275\320\260\321\217 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        closeButton->setText(QCoreApplication::translate("histogramStats", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class histogramStats: public Ui_histogramStats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMSTATS_H
