#include <chrono>
#include <iostream>
#include <thread> 
#include "timerCoroutine.hpp"
#include "executor.hpp"

int main()
{
    Executor::Executor executor{};
    timerCoroutine(executor);
    std::cout << "После timerCoroutine" << std:: endl;

    anotherTimerCoroutine(executor);
    std::cout << "После anotherTimerCoroutine" << std:: endl;

    while(!executor.is_empty()) {
        executor.execute();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    std::cout << "Завершение программы" << std:: endl;
    // auto _timepoint = std::chrono::steady_clock::now() + std::chrono::seconds(5);
    // std::cout << "Timepoint " << _timepoint.time_since_epoch().count() << " NOW: " << std::chrono::steady_clock::now().time_since_epoch().count() << std::endl;
    // std::this_thread::sleep_for(std::chrono::seconds(2));
    // std::cout << "Timepoint " << _timepoint.time_since_epoch().count() << " NOW: " << std::chrono::steady_clock::now().time_since_epoch().count() << std::endl;
    // auto res = _timepoint > std::chrono::steady_clock::now();
    // std::cout << "Diff " << res << std::endl;
    return 0;
}