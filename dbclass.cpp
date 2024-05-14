#include "dbclass.h"

// Определение оператора потокового вывода структуры записей
std::ostream& operator << (std::ostream& out, note_t note) {
    short catConst{};
    switch (note.cat) {
    case Category::grossery:
        catConst = 0;
        break;
    case Category::chemistry:
        catConst = 1;
        break;
    case Category::beauty:
        catConst = 2;
        break;
    case Category::communication:
        catConst = 3;
        break;
    case Category::shopping:
        catConst = 4;
        break;
    case Category::entertainment:
        catConst = 5;
        break;
    case Category::income:
        catConst = 6;
        break;
    }
    //Запись даты происходит в формате int(day); int(month); int(year)
    return out << catConst << "; " << note.sum << "; " << note.date.day() << "; " << note.date.month() << "; " << note.date.year() << std::endl;
}

// Определение оператора потокового ввода структуры записей
std::istream& operator >> (std::istream& in, note_t& note) {
    note_t newNote{};
    short got{};
    if (!(in >> got)) {
        return in;
    }
    switch (got) {
    case 0:
        newNote.cat = Category::grossery;
        break;
    case 1:
        newNote.cat = Category::chemistry;
        break;
    case 2:
        newNote.cat = Category::beauty;
        break;
    case 3:
        newNote.cat = Category::communication;
        break;
    case 4:
        newNote.cat = Category::shopping;
        break;
    case 5:
        newNote.cat = Category::entertainment;
        break;
    case 6:
        newNote.cat = Category::income;
    }
    //Пропускаем "; "
    in.ignore(2);
    if (!(in >> newNote.sum)) {
        return in;
    }
    in.ignore(2);

    QDate inDate;

    {
        int dayVal{};
        if (!(in >> dayVal)) return in;
        in.ignore(2);
        int monthVal{};
        if (!(in >> monthVal)) return in;
        in.ignore(2);
        int yearVal{};
        if (!(in >> yearVal)) return in;
        inDate.setDate(yearVal, monthVal, dayVal);
    }
    newNote.date = inDate;
    note = newNote;
    return in;
}

// Конструктор загружает данные из таблички
DataBase::DataBase() {
    init();
}
// TO-DO: Повторное освобождение памяти при удалении списка
// При вызове деструктора данные записей сохраняются в файл
// DataBase::~DataBase() {
// }

// Метод для добавления записи в базу и файл
void DataBase::addNote(Category cat, uint32_t sum, int year, int month, int day) {
    QDate date(year, month, day);
    note_t newNote = { cat, sum, date };
    this->rows.append(newNote);

    std::ofstream out(dbPath, std::ios_base::app);
    if (!out.is_open()) {
        out.close();
        throw BadFile;
    }
    out << newNote;
    out.close();
}

// Метод для загрузки данных из файла
void DataBase::init() {
    std::ifstream in(dbPath, std::ios_base::in);
    if (!in.is_open()) {
        in.close();
        throw BadFile;
    }
    while (in.good()) {
        if (in.eof()) {
            break;
        }
        note_t note{.cat = Category::nullCat};
        in >> note;
        if (note.cat != Category::nullCat)
            this->rows.append(note);
    }
    in.close();
}

// Метод для вывода всех записей в поток
void DataBase::printRows(std::ostream& out) noexcept {
    rows.getList(out);
}

// Метод для сохранения записей в файл, вызывается в конструкторе
void DataBase::saveData(List<note_t>& toSave) {
    std::ofstream out(dbPath, std::ios_base::out);
    if (!out.is_open()) {
        out.close();
        throw BadFile;
    }
    // Неэффективный, но гибкий вариант
    /*bool ok;
    for (int i = 0; i < toSave.Len(); i++) {
        note_t note = toSave.getValue(i, ok);
        if (ok) {
            out << note;
        }
    }*/

    // Быстрый вариант, но под сценарий применения
    // нужно писать свою структуру лямбды (замыкания передать в функцию не выйдет)
    toSave.mapCustomLambda(Lambda<note_t>{out});
    out.close();
}
