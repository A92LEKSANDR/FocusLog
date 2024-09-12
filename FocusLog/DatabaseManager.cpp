// #include "DatabaseManager.h"

// DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
// {
//     initDatabase();
// }

// void DatabaseManager::initDatabase()
// {
//     //db = QSqlDatabase::addDatabase("QSQLITE");
//     //db.setDatabaseName("focuslog.db");

//     // if (!db.open()) {
//     //     qWarning() << "Cannot open database!";
//     // }

//     // // Создание таблиц, если их нет
//     // QSqlQuery query;
//     // query.exec("CREATE TABLE IF NOT EXISTS sessions ("
//     //            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
//     //            "timestamp DATETIME)");
// }

// void DatabaseManager::logWorkSession(const QDateTime &timestamp)
// {
//     // QSqlQuery query;
//     // query.prepare("INSERT INTO sessions (timestamp) VALUES (:timestamp)");
//     // query.bindValue(":timestamp", timestamp.toString(Qt::ISODate));
//     // query.exec();
// }

// void DatabaseManager::logNotes(const QString &notes)
// {
//     // QSqlQuery query;
//     // query.prepare("INSERT INTO notes (content) VALUES (:content)");
//     // query.bindValue(":content", notes);
//     // query.exec();
// }

