#pragma once
#include <chrono>
#include <coroutine>

namespace Timer {
    class AwaitableTimer {
        public:
            AwaitableTimer (unsigned int seconds);
            bool await_ready();
            void await_suspend(std::coroutine_handle<> coroutine);
            void await_resume();
        private:
            std::chrono::time_point<std::chrono::steady_clock> _timepoint;
            std::coroutine_handle<> _coroutine;
    };
}