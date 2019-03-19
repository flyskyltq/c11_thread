#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

volatile int counter(0);
std::mutex mtx;

void attampt_10k_increase() {
    for (int i = 0; i < 10000; ++i) {
        mtx.lock();
        ++counter;
        mtx.unlock();
    }
}

void test_mutex() {
    std::thread threads[5];

    for (int i = 0; i < 5; ++i) {
        threads[i] = std::thread(attampt_10k_increase);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "counter:" << counter << "\n";
}



