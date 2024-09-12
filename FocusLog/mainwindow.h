#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TimerManager.h"
#include "NotesDialog.h"
#include "DatabaseManager.h"

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

    void on_startButton_clicked(); //25 min start
    void on_stopButton_clicked();

private:
    Ui::MainWindow *ui;
    TimerManager* timerManager;
    NotesDialog notesDialog;
};
#endif // MAINWINDOW_H
