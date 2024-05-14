#ifndef DBREPO_H
#define DBREPO_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "list.h"
#include "dbclass.h"
#include <QSqlError>

class PSQLrepo
{
public:
    bool checkConnection();
    PSQLrepo();
    ~PSQLrepo();

    void loadData(List<note_t>&);
    void saveData(List<note_t>*);
private:
    QSqlDatabase db;
    void clearData();
};

#endif // DBREPO_H
