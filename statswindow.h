#ifndef STATSWINDOW_H
#define STATSWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "list.h"
#include "nodewidget.h"
#include "histogramstats.h"

// Класс для окна вывода статистики
// по имеющимся записям
namespace Ui {
class StatsWindow;
}

class StatsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StatsWindow(QWidget *parent = nullptr, List<NodeWidget*> *nodes = nullptr);
    ~StatsWindow();
    void startCalc();
private:
    Ui::StatsWindow *ui;
    bool calcStats();
    List<NodeWidget*> *mainWindowData;
private slots:
    void closeWindow();
    void on_deeperButton_clicked();
};

#endif // STATSWINDOW_H
