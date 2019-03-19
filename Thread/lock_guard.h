#pragma once

#include <iostream>
#include <mutex>
#include <thread>

volatile int counter(0);
std::mutex mtx;

void thread_task() {
    std::lock_guard<std::mutex> lck(mtx);
    ++counter;
}

void test_lock_guard() {
    std::thread threads[10];

    // spawn 10 threads:
    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(thread_task);
    }

    for (auto& th : threads) {
        th.join();
    }

    std::cout << "counter:" << counter << std::endl;
}