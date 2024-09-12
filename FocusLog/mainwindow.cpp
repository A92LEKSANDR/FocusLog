#include "mainwindow.h"
#include "./ui_mainwindow.h"

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


void MainWindow::on_startButton_clicked(){
    timerManager->startWorkSession();// work 25 minutes
}

void MainWindow::on_stopButton_clicked()
{
    timerManager->stopWorkSession();  // Завершаем текущую сессию
    notesDialog.exec();  // Открываем окно для ввода заметок
}
