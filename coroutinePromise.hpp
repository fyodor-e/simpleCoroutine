#pragma once
#include <iostream>
#include <coroutine>

namespace Coroutine {
    struct promise;

    struct timerCoroutineHandler : std::coroutine_handle<Coroutine::promise>
    {
        using promise_type = Coroutine::promise;
    };
    
    struct promise
    {
        timerCoroutineHandler get_return_object() {
            std::cout << "promise::get_return_object" << std::endl;
            return { timerCoroutineHandler::from_promise(*this) };
        }
        std::suspend_never initial_suspend() noexcept {
            std::cout << "promise::initial_suspend" << std::endl;
            return {};
        }
        std::suspend_never final_suspend() noexcept {
            std::cout << "promise::final_suspend" << std::endl;
            return {};
        }
        void return_void() {
            std::cout << "promise::return_void" << std::endl;
        }
        void unhandled_exception() {
            std::cout << "promise::unhandled_exception" << std::endl;
        }
    };
}