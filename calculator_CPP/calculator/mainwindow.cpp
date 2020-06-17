#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    exit(0);
}

void MainWindow::on_pushButton_quit_clicked()
{
    float ret = 0;
    float ev1 = ui->lineEdit_ev1->text().toFloat();
    float ev2 = ui->lineEdit_ev2->text().toFloat();
    char *op = ui->lineEdit_op->text().toUtf8().data();
    switch (*op) {
        case '+':
            ret = ev1 + ev2;
        break;
        case '-':
            ret = ev1 - ev2;
        break;
        case '*':
            ret = ev1 * ev2;
        break;
        case '/':
            ret = ev1 / ev2;
        break;
    }
    ui->lineEdit_res->setText(QString("%1").arg(ret));
}
