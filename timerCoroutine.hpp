#pragma once
#include "coroutinePromise.hpp"
#include "executor.hpp"

Coroutine::timerCoroutineHandler timerCoroutine(Executor::Executor& executor);
Coroutine::timerCoroutineHandler anotherTimerCoroutine(Executor::Executor& executor);