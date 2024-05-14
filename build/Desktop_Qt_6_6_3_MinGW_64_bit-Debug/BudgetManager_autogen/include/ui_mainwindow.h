/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *addAction;
    QAction *deleteAction;
    QAction *editAction;
    QAction *outerDbAction;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *statButton;
    QLabel *label_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(604, 750);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe Print")});
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(197, 197, 147);\n"
"color: rgb(0, 0, 0);"));
        MainWindow->setDocumentMode(false);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        addAction = new QAction(MainWindow);
        addAction->setObjectName("addAction");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgSrc/images/addIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        addAction->setIcon(icon);
        deleteAction = new QAction(MainWindow);
        deleteAction->setObjectName("deleteAction");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgSrc/images/deleteIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteAction->setIcon(icon1);
        editAction = new QAction(MainWindow);
        editAction->setObjectName("editAction");
        editAction->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imgSrc/images/editIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        editAction->setIcon(icon2);
        editAction->setMenuRole(QAction::NoRole);
        outerDbAction = new QAction(MainWindow);
        outerDbAction->setObjectName("outerDbAction");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imgSrc/images/dbIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        outerDbAction->setIcon(icon3);
        outerDbAction->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        statButton = new QPushButton(centralwidget);
        statButton->setObjectName("statButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statButton->sizePolicy().hasHeightForWidth());
        statButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift SemiCondensed")});
        font1.setPointSize(13);
        font1.setBold(false);
        font1.setItalic(false);
        statButton->setFont(font1);
        statButton->setStyleSheet(QString::fromUtf8("border-color: rgb(0,0,0);\n"
"border-width: 30px;\n"
"border-radius: 15px;\n"
"background-color: rgb(194, 194, 194);\n"
"font: 13pt \"Bahnschrift SemiCondensed\";"));

        gridLayout->addWidget(statButton, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift SemiCondensed")});
        label_2->setFont(font2);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 194, 194);\n"
"border-radius: 15 px;\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 536, 599));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 194, 194);"));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 556, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 2, 0, 1, 2);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 50));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Bahnschrift SemiCondensed")});
        font3.setPointSize(14);
        label->setFont(font3);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 604, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 194, 194);"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy2);
        toolBar->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 194, 194);"));
        toolBar->setMovable(false);
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);

        toolBar->addAction(addAction);
        toolBar->addAction(deleteAction);
        toolBar->addAction(editAction);
        toolBar->addAction(outerDbAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "BudgetManager", nullptr));
        addAction->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        deleteAction->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        editAction->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        outerDbAction->setText(QCoreApplication::translate("MainWindow", "OuterDb", nullptr));
#if QT_CONFIG(tooltip)
        outerDbAction->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\320\275\320\265\321\210\320\275\321\217\321\217 \320\221\320\224", nullptr));
#endif // QT_CONFIG(tooltip)
        statButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\270", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214 \321\200\320\260\321\201\321\205\320\276\320\264\320\276\320\262", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
