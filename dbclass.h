#ifndef DBCLASS_H
#define DBCLASS_H
#include <iostream>
#include "list.h"
#include <fstream>
#include <QDate>

// Константы для определения категории записи
enum class Category
{
    grossery,
    chemistry,
    beauty,
    communication,
    shopping,
    entertainment,
    income,
    nullCat
};

// Структура данных записи,
// включает класс категории, целую сумму атомарных рублей, дату записи
struct note_t {
    Category cat;
    uint32_t sum;
    QDate    date;
};



std::ostream& operator << (std::ostream&, note_t);

std::istream& operator >> (std::istream&, note_t&);

// Класс для взаимодействия с файлом для сохранения и загрузки данных
class DataBase {
private:
    static const int BadFile = 0;

    const char* dbPath = "../../data/db.csv";
public:
    List<note_t> rows;

    DataBase();

    void addNote(Category, uint32_t, int, int, int);

    void init();

    void printRows(std::ostream&) noexcept;

    void saveData(List<note_t>&);
};

#endif // DBCLASS_H
