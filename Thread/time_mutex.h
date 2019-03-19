#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

/*
*   std::timed_mutex
*/
std::timed_mutex time_mtx;

void fireworks() {
    while (!time_mtx.try_lock_for(std::chrono::milliseconds(200))) {
        std::cout << "-";
    }

    // got a lock! - wait for 1s, then this thread prints "*"
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "*\n";
    time_mtx.unlock();
}

int test_time_mutex() {
    std::thread threads[10];

    // spawn 10 threads:
    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(fireworks);
    }

    for (auto& th : threads) {
        th.join();
    }

    return 0;
}