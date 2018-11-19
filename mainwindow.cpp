#include <QLabel>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Tenemos que indicar al widget donde esta la etiqueta DESPUÉS de ser creada
    ui->widget->m_info = ui->widget->findChild<QLabel *>();
    ui->widget->updatePuntuacion();
}

MainWindow::~MainWindow()
{
    delete ui;
}


