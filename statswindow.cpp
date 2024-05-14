#include "statswindow.h"
#include "ui_statswindow.h"

StatsWindow::StatsWindow(QWidget *parent, List<NodeWidget*> *nodes)
    : QDialog(parent)
    , ui(new Ui::StatsWindow)
{
    ui->setupUi(this);
    connect(ui->closeButton, &QPushButton::clicked, this, &StatsWindow::closeWindow);
    this->mainWindowData = nodes;
}

StatsWindow::~StatsWindow()
{
    delete ui;
}

// Слот, закрывающий окно статистики
// и возвращающий фокус на MainWindow
void StatsWindow::closeWindow() {
    this->close();
}

// Метод, рассчитывающий статистику по записям,
// подгруженным с MainWindow, выводит результаты
// в lineEdit под каждую категорию.
// Выводит остаток (доход - расход) и комментарий :)))))
// Если имеются отрицательные значения в записях,
// расчёт останавливается, выводится предупреждение, StatsWindow закрывается
bool StatsWindow::calcStats() {
    uint32_t beautySum{}, chemistrySum{}, comSum{}, entertainSum{}, grosserySum{}, incomeSum{}, shoppingSum{};
    bool ok;
    for (int i = 0; i < this->mainWindowData->Len(); i++) {
        NodeWidget* node = this->mainWindowData->getValue(i, ok);
        if (!node->validateSum()) {
            QMessageBox::critical(this, "Ошибка", "Отрицательные значения сумм трат");
            return false;
        }
        switch (node->getCategory()) {
        case Category::beauty:
            beautySum += node->getSum();
            break;
        case Category::chemistry:
            chemistrySum += node->getSum();
            break;
        case Category::communication:
            comSum += node->getSum();
            break;
        case Category::entertainment:
            entertainSum += node->getSum();
            break;
        case Category::grossery:
            grosserySum += node->getSum();
            break;
        case Category::income:
            incomeSum += node->getSum();
            break;
        case Category::shopping:
            shoppingSum += node->getSum();
        }
    }
    this->ui->beautyEdit->setText(QString::number(beautySum));
    this->ui->chemistryEdit->setText(QString::number(chemistrySum));
    this->ui->comEdit->setText(QString::number(comSum));
    this->ui->entertainmentEdit->setText(QString::number(entertainSum));
    this->ui->grosseryEdit->setText(QString::number(grosserySum));
    this->ui->incomeEdit->setText(QString::number(incomeSum));
    this->ui->clothesEdit->setText(QString::number(shoppingSum));

    long long result = incomeSum;
    result -= (beautySum + chemistrySum + comSum + entertainSum + grosserySum + shoppingSum);
    if (result < 0) {
        this->ui->commentEdit->setText("Остаток: " + QString::number(result) + "\nВы тратите больше, чем зарабатываете.\nДля стабильного финансового "
                                                                               "положения необходимо жить \"по средствам\" (вы транжира)");
    } else {
        this->ui->commentEdit->setText("Остаток: " + QString::number(result) + "\nУ Вас стабильное финансовое положение.\n"
                                                                               "Продолжайте в том же духе! (вы не транжира)");
    }
    return true;
}

// Run-метод, вызывающийся при открытии окна
void StatsWindow::startCalc() {
    if (!calcStats()) this->close();
}

void StatsWindow::on_deeperButton_clicked()
{
    histogramStats *newWindow = new histogramStats(this, this->mainWindowData);
    newWindow->show();

}

