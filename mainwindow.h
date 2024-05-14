#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "nodewidget.h"
#include "list.h"
#include "dbclass.h"
#include <QMainWindow>
#include <QMessageBox>
#include "addnodewindow.h"
#include "statswindow.h"
#include "dbrepo.h"

// Класс главного окна
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showInitMessage();
    void showSaveMessage();
signals:
    void validateSignal();
private:
    Ui::MainWindow *ui;

    List<NodeWidget*> nodes;
    bool isEditable;
    PSQLrepo* outerDb;
    DataBase data;

    bool isSavingToDb;
    bool isLoadFromDb;

    void initDataFromFile();
    void initDataFromOuterDB();

    void saveChangesToFile();
    void saveChangesToOuterDB();

private slots:
    void addWidget(NodeWidget*);
    void on_editAction_triggered(bool checked);
    void on_deleteAction_triggered();
    void on_addAction_triggered();
    void showStatsWindow();
    void validateSlot();
    void on_outerDbAction_triggered();

protected:
    void closeEvent(QCloseEvent*) override;
};
#endif // MAINWINDOW_H
