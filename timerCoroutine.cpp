#include "timerCoroutine.hpp"
#include "awaitableTimer.hpp"
#include <iostream>

Coroutine::simpleCoroutine timerCoroutine() {
    std::cout << "timerCoroutine: Начало работы" << std::endl;
    co_await Timer::AwaitableTimer(3);
    std::cout << "timerCoroutine: таймер зарешен" << std::endl;
}