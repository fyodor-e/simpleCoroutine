#pragma once
#include <vector>
#include "awaitableTimer.hpp"

namespace Timer {
    class AwaitableTimer;
}

namespace Executor {
    class Executor {
        std::vector<Timer::AwaitableTimer*> _timers;
    public:
        void execute();
        void enque(Timer::AwaitableTimer* t);
        bool is_empty();
    };
}