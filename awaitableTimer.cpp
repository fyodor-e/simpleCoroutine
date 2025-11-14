#include "awaitableTimer.hpp"
#include <iostream>

namespace Timer {
    AwaitableTimer::AwaitableTimer (unsigned int seconds, Executor::Executor& executor) {
        std::cout << "AwaitableTimer ctor" << std::endl;
        _timepoint = std::chrono::steady_clock::now() + std::chrono::seconds(seconds);
        executor.enque(this);
    }

    bool AwaitableTimer::await_ready() {
        std::cout << "AwaitableTimer::await_ready" << std::endl;
        return _timepoint <= std::chrono::steady_clock::now();
    }
    
    void AwaitableTimer::await_suspend(std::coroutine_handle<> coroutine) {
        std::cout << "AwaitableTimer::await_suspend" << std::endl;
        _coroutine = coroutine;
    }
    void AwaitableTimer::await_resume() {
        std::cout << "AwaitableTimer::await_resume" << std::endl;
    }

    bool AwaitableTimer::is_expired() {
        return _timepoint <= std::chrono::steady_clock::now();
    }

    void AwaitableTimer::resume() {
        std::cout << "AwaitableTimer::resume" << std::endl;
        _coroutine.resume();
    }

    AwaitableTimer::~AwaitableTimer() {
        std::cout << "AwaitableTimer dtor" << std::endl;
    }
}