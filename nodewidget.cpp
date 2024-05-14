#include "nodewidget.h"
#include "ui_nodewidget.h"

NodeWidget::NodeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NodeWidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->category, &QComboBox::currentTextChanged, this, &NodeWidget::onCategoryChanged);
}

NodeWidget::~NodeWidget()
{
    delete ui;
}

// Метод для установки текста категории в label виджет
void NodeWidget::setName(QString newName) {
    this->ui->name->setText(newName);
}

// Метод для установки суммы в lineEdit виджет
void NodeWidget::setSum(uint32_t sum) {
    this->ui->sum->setText(QString::number(sum));
}

// Метод, открывающий элементы родительского виджета для изменения
void NodeWidget::prepareForEditing() {
    this->ui->editable->setEnabled(true);
    this->ui->category->setEnabled(true);
    this->ui->sum->setReadOnly(false);
}

// Метод, ограничивающий изменения элементов виджета
void NodeWidget::endEditing() {
    this->ui->editable->setEnabled(false);
    this->ui->category->setEnabled(false);
    this->ui->sum->setReadOnly(true);
    this->ui->editable->setChecked(false);
}

// Метод для изменения текущего значения категории
// comboBox в виджете
void NodeWidget::setCategory(Category cat) {
    switch (cat) {
    case Category::beauty:
        this->ui->category->setCurrentIndex(0);
        break;
    case Category::chemistry:
        this->ui->category->setCurrentIndex(1);
        break;
    case Category::communication:
        this->ui->category->setCurrentIndex(2);
        break;
    case Category::entertainment:
        this->ui->category->setCurrentIndex(3);
        break;
    case Category::grossery:
        this->ui->category->setCurrentIndex(4);
        break;
    case Category::income:
        this->ui->category->setCurrentIndex(5);
        break;
    case Category::shopping:
        this->ui->category->setCurrentIndex(6);
    }
}

// Слот, изменяющий текст в label при изменении текущего
// значения категории в comboBox
void NodeWidget::onCategoryChanged(QString newCat) {
    this->ui->name->setText(newCat);
}

// Метод, возвращающий число в lineEdit
uint32_t NodeWidget::getSum() {
    return this->ui->sum->text().toUInt();
}

// Метод, возвращающий класс категории в comboBox
Category NodeWidget::getCategory() {
    switch (ui->category->currentIndex()) {
    case 0:
        return Category::beauty;
        break;
    case 1:
        return Category::chemistry;
        break;
    case 2:
        return Category::communication;
        break;
    case 3:
        return Category::entertainment;
        break;
    case 4:
        return Category::grossery;
        break;
    case 5:
        return Category::income;
        break;
    case 6:
        return Category::shopping;
        break;
    default:
        return Category::nullCat;
    }
}

// Метод возвращает состояние checkBox виджета
// для его удаления в MainWindow
bool NodeWidget::isDeletable() {
    return this->ui->editable->isChecked();
}

// Валидатор значения суммы в lineEdit
// Если значение отрицательное, возвращает false
bool NodeWidget::validateSum() {
    bool ok;
    this->ui->sum->text().toUInt(&ok);
    return ok;
}

bool NodeWidget::validateDate() {
    QDate date = this->ui->dateEdit->date();
    return date.isValid();
}

QDate NodeWidget::getDate() {
    return ui->dateEdit->date();
}

void NodeWidget::setDate(QDate newDate) {
    this->ui->dateEdit->setDate(newDate);
}

note_t NodeWidget::getNode() {
    return {.cat = getCategory(), .sum = getSum(), .date = getDate()};
}
