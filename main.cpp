#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QFile>
#include <QSqlQuery>

void initializeDatabase(QSqlDatabase &db) {
    if (!QFile::exists("karsa.db")) {
        QSqlQuery query(db);
        query.exec(R"(
            CREATE TABLE IF NOT EXISTS applications (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                company TEXT NOT NULL,
                position TEXT NOT NULL,
                status TEXT NOT NULL,
                date_applied TEXT,
                notes TEXT
            )
        )");
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("karsa.db");

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Database Error", db.lastError().text());
        return -1;
    }

    initializeDatabase(db);

    MainWindow window;
    window.show();
    return app.exec();
}
