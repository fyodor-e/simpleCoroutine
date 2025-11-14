#pragma once
#include <chrono>
#include <coroutine>
#include "executor.hpp"

namespace Executor {
    class Executor;
}

namespace Timer {
    class AwaitableTimer {
        public:
            AwaitableTimer (unsigned int seconds, Executor::Executor& executor);
            bool await_ready();
            void await_suspend(std::coroutine_handle<> coroutine);
            void await_resume();
            bool is_expired();
            void resume();
            ~AwaitableTimer();
        private:
            std::chrono::time_point<std::chrono::steady_clock> _timepoint;
            std::coroutine_handle<> _coroutine;
    };
}