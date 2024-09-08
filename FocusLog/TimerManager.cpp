#include "TimerManager.h"

TimerManager::TimerManager(QObject *parent) : QObject(parent), isWorkSession(true)
{
    timer = new QTimer(this);
    dbManager = new DatabaseManager();

    connect(timer, &QTimer::timeout, this, &TimerManager::onTimerFinished);
}

void TimerManager::startWorkSession()
{
    timer->start(25 * 60 * 1000); // 25 минут
    isWorkSession = true;
}

void TimerManager::startBreakSession()
{
    timer->start(5 * 60 * 1000); // 5 минут
    isWorkSession = false;
}

void TimerManager::onTimerFinished()
{
    if (isWorkSession) {
        // Записываем завершение сессии в базу данных
        dbManager->logWorkSession(QDateTime::currentDateTime());
        startBreakSession();  // Запуск перерыва
    } else {
        startWorkSession();   // Запуск новой рабочей сессии после перерыва
    }
}

void TimerManager::stopSession()
{
    timer->stop();
    // Здесь можно завершить работу, записать последние данные или завершить сессию
}
