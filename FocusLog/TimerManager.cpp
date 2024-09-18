#include "TimerManager.h"

TimerManager::TimerManager(QObject *parent) : QObject(parent),remainingTime(0), isWorkSession(true){
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &TimerManager::updateRemainingTime);
}

void TimerManager::startWorkSession()
{
    remainingTime = 25 * 60 * 1000;
    timer->start(1000);
    isWorkSession = false;
}

void TimerManager::startBreakSession()
{
    remainingTime = 25 * 60 * 1000;
    timer->start(1000);
    isWorkSession = false;
}

void TimerManager::onTimerFinished()
{
    if (isWorkSession) {
        // Записываем завершение сессии в базу данных
        //dbManager->logWorkSession(QDateTime::currentDateTime());
        startBreakSession();  // Запуск перерыва
    } else {
        startWorkSession();   // Запуск новой рабочей сессии после перерыва
    }
}

void TimerManager::stopWorkSession()
{
    timer->stop();
    // Здесь можно завершить работу, записать последние данные или завершить сессию
}

void TimerManager::updateRemainingTime()
{
    if (remainingTime > 0) {
        remainingTime -= 1000;
        emit timeUpdated(remainingTime);
    } else {
        timer->stop();
        onTimerFinished();
        // Вызываем метод завершения таймера
    }
}
