#include "dbrepo.h"

PSQLrepo::PSQLrepo() {
   this->db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setPort(5432);
    db.setDatabaseName("test");
    db.setUserName("course");
    db.setPassword("course");
    db.open();
}

bool PSQLrepo::checkConnection() {
    return this->db.isOpen();
}

PSQLrepo::~PSQLrepo() {
    this->db.close();
}

void PSQLrepo::clearData() {
    if (!this->db.isOpen()) return;
    QSqlQuery q;
    q.exec("DELETE FROM nodes_data;");
}

void PSQLrepo::saveData(List<note_t>* toSave) {
    if (!this->db.isOpen()) return;
    clearData();
    QSqlQuery query;
    query.prepare("INSERT INTO nodes_data (cat, node_sum, node_date) "
                  "VALUES (:cat, :node_sum, :node_date);");
    bool ok;
    for (int i = toSave->Len() - 1; i >= 0; i--) {
        note_t n = toSave->getValue(i, ok);
        if (ok) {
            query.bindValue(":cat", static_cast<int>(n.cat));
            query.bindValue(":node_sum", n.sum);
            QString temp = n.date.toString(Qt::ISODate);
            query.bindValue(":node_date", temp);
            query.exec();
        }
    }
}

void PSQLrepo::loadData(List<note_t>& out) {
    if (!this->db.isOpen()) return;
    QSqlQuery query;
    query.exec("SELECT cat, node_sum, node_date FROM nodes_data;");
    while (query.next() && query.isActive()) {
        note_t got;
        got.cat = static_cast<Category>(query.value(0).toInt());
        got.sum = query.value(1).toUInt();
        got.date = QDate::fromString(query.value(2).toString(), Qt::ISODate);
        out.append(got);
    }
}
