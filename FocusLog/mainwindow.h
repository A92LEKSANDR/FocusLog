#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TimerManager.h"
#include <QLabel>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_startButton_clicked();
    void updateDisplayedTime(int remainingTime);

private:
    Ui::MainWindow* ui;
    TimerManager* timerManager;
};
#endif // MAINWINDOW_H
