#ifndef HISTOGRAMSTATS_H
#define HISTOGRAMSTATS_H

#include <QDialog>
#include "list.h"
#include "nodewidget.h"
#include "dbclass.h"
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QBarSet>
#include <QChart>
#include <QChartView>

namespace Ui {
class histogramStats;
}

class histogramStats : public QDialog
{
    Q_OBJECT

public:
    explicit histogramStats(QWidget *parent = nullptr, List<NodeWidget*> *data = nullptr);
    ~histogramStats();

private slots:
    void on_closeButton_clicked();

private:
    Ui::histogramStats *ui;
    List<note_t>* rawData;
    void calcAndShowDeeperStats();
    QBarSeries* series;
    QChart* chart;
    QChartView* view;
    QBarCategoryAxis* axis;
    QBarSet *grossery,
            *chemistry,
            *beauty,
            *comms,
            *shopping,
            *entertain,
            *income;
protected:
    void closeEvent(QCloseEvent*) override;
};

struct valuesPerDate {
    QDate date;
    // в массиве values индекс отображает константу
    // типа Category 0 - grossery, ..,  6 - income
    long long values[7];
};

#endif // HISTOGRAMSTATS_H
