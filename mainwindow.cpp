#include <QLabel>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->info_ = ui->widget->findChild<QLabel *>();
    ui->widget->updatePuntuacion();
}

MainWindow::~MainWindow()
{
    delete ui;
}


