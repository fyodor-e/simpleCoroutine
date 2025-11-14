#include "executor.hpp"
#include <iostream>

namespace Executor {
    void Executor::execute() {
        std::erase_if(_timers, [](Timer::AwaitableTimer* t) {
            if (t->is_expired()) {
                t->resume();
                std::cout << "coroutine resumed" << std::endl;
                return true;
            }
            return false;
        });
    };

    void Executor::enque(Timer::AwaitableTimer* t) {
        _timers.push_back(t);
    }
    bool Executor::is_empty() {
        return _timers.empty();
    }
}