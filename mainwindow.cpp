#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this, QSqlDatabase::database());
    model->setTable("applications");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

MainWindow::~MainWindow() {
    delete ui;
}
