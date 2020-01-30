#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QtSql>
#include <QAbstractItemView>
#include <QStringList>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db_weddings.sqlite");
    if (!db.open()) {
        qDebug() << "SQLITE DATABASE DON'T OPEN";
        exit(1);
    }
    model = new QSqlTableModel(nullptr, db);
    model->setTable("information");

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0,true);
//    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
//    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
//    ui->tableView->resizeColumnsToContents();
//    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setShowGrid(true);
    model->select();
}

MainWindow::~MainWindow() {
    delete model;
    delete ui;
}

void MainWindow::on_pushButton_clicked() {

}

void MainWindow::on_radioButton_2_clicked()
{
    model->setTable("contact_info");
    ui->tableView->setModel(model);
    model->select();
}

void MainWindow::on_radioButton_clicked()
{
    model->setTable("information");
    ui->tableView->setModel(model);
    model->select();
}
