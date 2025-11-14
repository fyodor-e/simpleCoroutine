#pragma once
#include "coroutinePromise.hpp"
#include "executor.hpp"

Coroutine::simpleCoroutine timerCoroutine(Executor::Executor& executor);
Coroutine::simpleCoroutine anotherTimerCoroutine(Executor::Executor& executor);