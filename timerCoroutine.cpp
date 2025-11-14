#include "timerCoroutine.hpp"
#include "awaitableTimer.hpp"
#include <iostream>

Coroutine::timerCoroutineHandler timerCoroutine(Executor::Executor& executor) {
    std::cout << "timerCoroutine: Начало работы" << std::endl;
    co_await Timer::AwaitableTimer(3, executor);
    std::cout << "timerCoroutine: Окнчание работы" << std::endl;
}

Coroutine::timerCoroutineHandler anotherTimerCoroutine(Executor::Executor& executor) {
    std::cout << "anotherTimerCoroutine: Начало работы" << std::endl;
    co_await Timer::AwaitableTimer(2, executor);
    std::cout << "anotherTimerCoroutine: Окончание работы" << std::endl;
}