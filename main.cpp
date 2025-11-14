#include <chrono>
#include <iostream>
#include <thread> 
#include "timerCoroutine.hpp"

int main()
{
    timerCoroutine();
    std::cout << "timerCoroutine завершена" << std:: endl;
    // auto _timepoint = std::chrono::steady_clock::now() + std::chrono::seconds(5);
    // std::cout << "Timepoint " << _timepoint.time_since_epoch().count() << " NOW: " << std::chrono::steady_clock::now().time_since_epoch().count() << std::endl;
    // std::this_thread::sleep_for(std::chrono::seconds(2));
    // std::cout << "Timepoint " << _timepoint.time_since_epoch().count() << " NOW: " << std::chrono::steady_clock::now().time_since_epoch().count() << std::endl;
    // auto res = _timepoint > std::chrono::steady_clock::now();
    // std::cout << "Diff " << res << std::endl;
    return 0;
}