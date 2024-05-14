#include "histogramstats.h"
#include "ui_histogramstats.h"

histogramStats::histogramStats(QWidget *parent, List<NodeWidget*> *data)
    : QDialog(parent)
    , ui(new Ui::histogramStats)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->rawData = new List<note_t>;
    bool ok;
    for (int i = 0; i < data->Len(); i++) {
        note_t n = data->getValue(i, ok)->getNode();
        if (ok) {
            rawData->append(n);
        }
    }
    series = nullptr;
    chart = nullptr;
    calcAndShowDeeperStats();
}

histogramStats::~histogramStats()
{
    delete ui;
}

void histogramStats::calcAndShowDeeperStats() {
    QStringList categories;
    series = new QBarSeries();
    grossery = new QBarSet("Продукты");
    grossery->setLabelColor(grossery->brush().color().darker());
    chemistry = new QBarSet("Лекарства и пр.");
    chemistry->setLabelColor(chemistry->brush().color().darker());
    beauty = new QBarSet("Красота и уход");
    beauty->setLabelColor(beauty->brush().color().darker());
    comms = new QBarSet("Коммуникации");
    comms->setLabelColor(comms->brush().color().darker());
    shopping = new QBarSet("Прочие покупки");
    shopping->setLabelColor(shopping->brush().color().darker());
    entertain = new QBarSet("Жизнь и развл.");
    entertain->setLabelColor(entertain->brush().color().darker());
    income = new QBarSet("Доход");
    income->setLabelColor(income->brush().color().darker());

    // Список для значений трат, привязанных к одной дате
    List<valuesPerDate> dates;
    bool ok;
    // Сортируем список записей, чтобы записи с одинаковыми
    // датами шли друг за другом (прокидываем в функцию лямбду)
    rawData->sortAsc([](note_t l, note_t r) {return l.date > r.date;});

    // Для прохода по данных заводим структуру, в которой будем накапливать
    // значения для одной даты. Когда итерация дойдет до записи с другой датой, передаем curr
    // в список dates, сбрасываем и заполняем снова
    valuesPerDate curr;
    memset(curr.values, 0, sizeof(curr.values));
    for (int i = 0; i < rawData->Len(); i++) {
        note_t val = rawData->getValue(i, ok);
        if (!i) {
            curr.date = val.date;
            curr.values[static_cast<int>(val.cat)] += val.sum;
        } else {
            if (val.date == curr.date) {
                curr.values[static_cast<int>(val.cat)] += val.sum;
            } else {
                dates.append(curr);
                curr.date = val.date;
                memset(curr.values, 0, sizeof(curr.values));
                curr.values[static_cast<int>(val.cat)] += val.sum;
            }
        }
    }
    // Добавляем оставшиеся данные
    dates.append(curr);

    // Обходим список собранных по датам значений,
    // чтобы записать их в BarSet
    for (int i = 0; i < dates.Len(); i++) {
        curr = dates.getValue(i, ok);
        categories << curr.date.toString(Qt::ISODate);
        *grossery << curr.values[0];
        *chemistry << curr.values[1];
        *beauty << curr.values[2];
        *comms << curr.values[3];
        *shopping << curr.values[4];
        *entertain << curr.values[5];
        *income << curr.values[6];
    }

    series->append(grossery);
    series->append(chemistry);
    series->append(beauty);
    series->append(comms);
    series->append(shopping);
    series->append(entertain);
    series->append(income);
    series->setLabelsVisible();
    series->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);

    chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);


    axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTheme(QChart::ChartThemeLight);

    view = new QChartView(chart);
    this->ui->frame->layout()->addWidget(view);

}



void histogramStats::on_closeButton_clicked()
{
    this->close();
}

void histogramStats::closeEvent(QCloseEvent *event) {
    delete view;
    delete rawData;
    QDialog::closeEvent(event);
}
