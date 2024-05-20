#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->isEditable = false;
    connect(ui->statButton, &QPushButton::clicked, this, &MainWindow::showStatsWindow);
    connect(this, &MainWindow::validateSignal, this, &MainWindow::validateSlot);

    this->outerDb = new PSQLrepo;
}

void MainWindow::showInitMessage() {
    if (this->outerDb->checkConnection()) {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Способ загрузки данных", "Загрузить данные с внешней бд?", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::No) {
            initDataFromFile();
        } else {
            initDataFromOuterDB();
        }
    } else {
        initDataFromFile();
    }
}

MainWindow::~MainWindow()
{
    delete outerDb;
    delete ui;
}

// Метод добавления NodeWidget в scroll area
void MainWindow::addWidget(NodeWidget* newNode) {
    this->nodes.append(newNode);
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(this->ui->scrollAreaWidgetContents->layout());
    layout->insertWidget(0, newNode);
}

// Метод для загрузки данных из объекта базы данных (файла)
// и последующего добавления NodeWidget в scroll area
void MainWindow::initDataFromFile() {
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(this->ui->scrollAreaWidgetContents->layout());
    for (int i = 0; i < this->data.rows.Len(); i++) {
        NodeWidget* newNode = new NodeWidget;
        this->nodes.append(newNode);

        bool ok;
        note_t row = this->data.rows.getValue(i, ok);
        if (!ok) {
            QMessageBox::critical(this, "Ошибка", "При загрузке данных произошла ошибка");
            return;
        }

        switch (row.cat) {
        case Category::beauty:
            newNode->setName("Красота и уход за собой");
            break;
        case Category::chemistry:
            newNode->setName("Лекарства и здоровье");
            break;
        case Category::communication:
            newNode->setName("Коммуникации и связь");
            break;
        case Category::entertainment:
            newNode->setName("Жизнь и развлечения");
            break;
        case Category::grossery:
            newNode->setName("Продукты");
            break;
        case Category::income:
            newNode->setName("Доход");
            break;
        case Category::shopping:
            newNode->setName("Одежда, товары для дома и прочее");
        }
        newNode->setCategory(row.cat);
        newNode->setSum(row.sum);
        newNode->setDate(row.date);
        layout->insertWidget(0, newNode);
    }
}

// Слот для action на вкл/выкл режима редактирования записей
void MainWindow::on_editAction_triggered(bool checked)
{
    bool ok;
    if (checked) {
        for (int i = 0; i < this->nodes.Len(); i++) {
            NodeWidget* current = this->nodes.getValue(i, ok);
            if (ok) {
                current->prepareForEditing();
            }
        }
        this->isEditable = true;
        return;
    } else {
        for (int i = 0; i < this->nodes.Len(); i++) {
            NodeWidget* current = this->nodes.getValue(i, ok);
            if (ok) {
                current->endEditing();
            }
        }
        this->isEditable = false;
    }
    emit validateSignal();
}

// Метод для сохранения записей в объект файловой базы данных
void MainWindow::saveChangesToFile() {
    List<note_t> newData;
    bool ok;
    for (int i = 0; i < this->nodes.Len(); i++) {
        note_t newNote;
        NodeWidget* node = this->nodes.getValue(i, ok);
        newNote.sum = node->getSum();
        newNote.cat = node->getCategory();
        newNote.date = node->getDate();
        newData.append(newNote);
    }
    this->data.saveData(newData);
}


// Слот для action на удаление отмеченных записей
void MainWindow::on_deleteAction_triggered()
{
    if (!isEditable) {
        QMessageBox::warning(this, "Ошибка", "Записи неизменяемы");
        return;
    }
    bool ok;
    for (int i = 0; i < this->nodes.Len(); i++) {
        NodeWidget* node = this->nodes.getValue(i, ok);
        if (!ok) {
            QMessageBox::critical(this, "Ошибка", "При удалении записей произошла ошибка");
            return;
        }

        if (!node->isDeletable()) continue;

        node->close();
        this->nodes.deleteAt(i);
        i--;
    }
}

// Слот для action на добавление записи, открывает
// окно AddNodeWindow
void MainWindow::on_addAction_triggered()
{
    if (this->nodes.Len() >= 500) {
        QMessageBox::critical(this, "Ошибка", "Слишком много записей");
        return;
    }
    AddNodeWindow* window = new AddNodeWindow(this);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->setModal(true);
    connect(window, &AddNodeWindow::toAddNode, this, &MainWindow::addWidget);
    window->show();
}

// Слот, открывающий StatsWindow окно со статистикой по записям
void MainWindow::showStatsWindow() {
    StatsWindow* window = new StatsWindow(this, &this->nodes);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->setModal(true);
    window->show();
    window->startCalc();
}

// Слот для проверки всех текущих записей в scroll area,
// выводит предупреждение пользователю
void MainWindow::validateSlot() {
    bool ok;
    for (int i = 0; i < this->nodes.Len(); i++) {
        if (!this->nodes.getValue(i, ok)->validateSum()) {
            QMessageBox::warning(this, "Ошибка", "Отрицательные значения сумм трат\nПри сохранении значения примут значение 0");
            return;
        }
    }
}

// Слот для выбора способа сохранения данных
void MainWindow::on_outerDbAction_triggered()
{
    if (!this->outerDb->checkConnection())
        QMessageBox::information(this, "Что-то не так", "Внешняя база данных недоступна");
    else
        QMessageBox::information(this, "Всё так", "Внешняя бд подключена.\nДоступно сохранение.");
}

// Метод загружает данные с внешней базы данных
void MainWindow::initDataFromOuterDB() {
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(this->ui->scrollAreaWidgetContents->layout());
    List<note_t> dataFromDb;
    this->outerDb->loadData(dataFromDb);
    bool ok;

    for (int i = dataFromDb.Len() - 1; i >= 0; i--) {
        note_t row = dataFromDb.getValue(i, ok);
        if (!ok) {
            QMessageBox::critical(this, "Ошибка", "При загрузке данных произошла ошибка");
            return;
        }

        NodeWidget* newNode = new NodeWidget;
        this->nodes.append(newNode);

        switch (row.cat) {
        case Category::beauty:
            newNode->setName("Красота и уход за собой");
            break;
        case Category::chemistry:
            newNode->setName("Лекарства и здоровье");
            break;
        case Category::communication:
            newNode->setName("Коммуникации и связь");
            break;
        case Category::entertainment:
            newNode->setName("Жизнь и развлечения");
            break;
        case Category::grossery:
            newNode->setName("Продукты");
            break;
        case Category::income:
            newNode->setName("Доход");
            break;
        case Category::shopping:
            newNode->setName("Одежда, товары для дома и прочее");
        }
        newNode->setCategory(row.cat);
        newNode->setSum(row.sum);
        newNode->setDate(row.date);
        layout->insertWidget(0, newNode);
    }
}

// Метод выгружает данные во внешнюю базу данных
void MainWindow::saveChangesToOuterDB() {
    List<note_t> forSave;
    bool ok;
    for (int i = 0; i < nodes.Len(); i++) {
        NodeWidget* wd = nodes.getValue(i, ok);
        note_t newNote;
        if (ok) {
            newNote.cat = wd->getCategory();
            newNote.sum = wd->getSum();
            newNote.date = wd->getDate();
            forSave.append(newNote);
        }
    }
    this->outerDb->saveData(&forSave);
}

// Отображает диалог с выбором способа
// сохранения данных
void MainWindow::showSaveMessage(){
    if (this->outerDb->checkConnection()) {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Способ сохранения данных", "Сохранить во внешнюю бд?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            saveChangesToOuterDB();
        } else {
            saveChangesToFile();
        }
    } else saveChangesToFile();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    showSaveMessage();
    QMainWindow::closeEvent(event);
}
