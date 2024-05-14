#ifndef NODEWIDGET_H
#define NODEWIDGET_H

#include <QWidget>
#include "dbclass.h"
#include <QDate>

// Класс окна добавления записей
namespace Ui {
class NodeWidget;
}

class NodeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NodeWidget(QWidget *parent = nullptr);
    ~NodeWidget();

    void setName(QString);
    void setSum(uint32_t);
    void setDate(QDate);
    void setCategory(Category);

    uint32_t getSum();
    Category getCategory();
    QDate getDate();
    note_t getNode();

    bool isDeletable();
    bool validateSum();
    bool validateDate();

    void prepareForEditing();
    void endEditing();
private:
    Ui::NodeWidget *ui;
private slots:
    void onCategoryChanged(QString);
};

#endif // NODEWIDGET_H
