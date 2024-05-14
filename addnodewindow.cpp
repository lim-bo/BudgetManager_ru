#include "addnodewindow.h"
#include "ui_addnodewindow.h"

AddNodeWindow::AddNodeWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddNodeWindow)
{
    ui->setupUi(this);

    connect(ui->cancelButton, &QPushButton::clicked, this, &AddNodeWindow::onCloseButton);
    connect(ui->addButton, &QPushButton::clicked, this, &AddNodeWindow::onAddButton);
    connect(ui->currentRadio, &QRadioButton::clicked, this, &AddNodeWindow::onCurrentRadio);
    connect(ui->otherRadio, &QRadioButton::clicked, this, &AddNodeWindow::onOtherRadio);

    // По умолчанию выбрана функция "Сегодня"
    this->ui->dateEdit->setDisabled(true);
    this->isToday = true;
}

AddNodeWindow::~AddNodeWindow()
{
    delete ui;
}

// Слот на закрытие окна (отмена добавления записи)
void AddNodeWindow::onCloseButton() {
    this->close();
}

// Слот для pushbutton валидирует введенные данные,
// добавляет NodeWidget на главное окно и закрывает текущее окно
void AddNodeWindow::onAddButton() {
    bool ok;
    uint32_t num = this->ui->sumEdit->text().toUInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Ошибка", "Некорректное значение для суммы траты");
        return;
    }
    if (!(this->ui->dateEdit->date().isValid())) {
        QMessageBox::critical(this, "Ошибка", "Некорректное значение для даты");
        return;
    }
    NodeWidget* newNode = new NodeWidget;
    Category cat;
    switch (ui->categoryBox->currentIndex()) {
    case 0:
        cat = Category::beauty;
        newNode->setName("Красота и уход за собой");
        break;
    case 1:
        cat = Category::chemistry;
        newNode->setName("Лекарства и здоровье");
        break;
    case 2:
        cat = Category::communication;
        newNode->setName("Коммуникации и связь");
        break;
    case 3:
        cat = Category::entertainment;
        newNode->setName("Жизнь и развлечения");
        break;
    case 4:
        cat = Category::grossery;
        newNode->setName("Продукты");
        break;
    case 5:
        cat = Category::income;
        newNode->setName("Доход");
        break;
    case 6:
        cat = Category::shopping;
        newNode->setName("Одежда, товары для дома и прочее");
        break;
    default:
        cat = Category::nullCat;
        newNode->setName("Неизвестно");
    }
    newNode->setCategory(cat);
    newNode->setSum(num);

    if (this->isToday)
        newNode->setDate(QDate::currentDate());
    else
        newNode->setDate(this->ui->dateEdit->date());
    emit toAddNode(newNode);
    this->close();
}

void AddNodeWindow::onCurrentRadio(bool checked) {
    if (checked) {
        this->isToday = true;
        this->ui->dateEdit->setDisabled(true);
    }
}

void AddNodeWindow::onOtherRadio(bool checked) {
    if (checked) {
        this->isToday = false;
        this->ui->dateEdit->setEnabled(true);
    }
}
