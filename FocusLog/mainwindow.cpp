#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),timerManager(new TimerManager(this)){

    ui->setupUi(this);

    // Связываем сигнал обновления времени с пользовательским интерфейсом
    connect(timerManager, &TimerManager::timeUpdated, this, &MainWindow::updateDisplayedTime);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    timerManager->startWorkSession();  // Старт рабочей сессии
}
void MainWindow::updateDisplayedTime(int remainingTime)
{
    // Преобразуем оставшееся время в минуты и секунды для отображения
    int minutes = remainingTime / (60 * 1000);
    int seconds = (remainingTime / 1000) % 60;

    // Обновляем метку с отображением времени на форме
    ui->displayTimer->setText(QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
}
