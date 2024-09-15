#ifndef TIMERMANAGER_H
#define TIMERMANAGER_H

#include <QObject>
#include <QTimer>

class TimerManager:public QObject{
    Q_OBJECT
public:
    explicit TimerManager(QObject* obj = nullptr);
public slots:
    void startWorkSession();
    void stopWorkSession();
    void startBreakSession();

    void updateRemainingTime(); // Слот для обновления времени
signals:
    void timeUpdated(int remainingTime);
    void breaksSignal();
private:
    bool isWorkSession;
    QTimer* timer;
    int remainingTime;;
    //DatabaseManager* dbManager;

private slots:
    void onTimerFinished();
};

#endif // TIMERMANAGER_H
