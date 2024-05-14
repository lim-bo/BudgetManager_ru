#ifndef ADDNODEWINDOW_H
#define ADDNODEWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "nodewidget.h"
// Класс окна добавления записей на MainWindow
namespace Ui {
class AddNodeWindow;
}

class AddNodeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddNodeWindow(QWidget *parent = nullptr);
    ~AddNodeWindow();
signals:
    void toAddNode(NodeWidget*);
private:
    Ui::AddNodeWindow *ui;
    bool isToday;
private slots:
    void onCloseButton();
    void onAddButton();
    void onCurrentRadio(bool);
    void onOtherRadio(bool);
};

#endif // ADDNODEWINDOW_H
