#pragma once
#include <iostream>
#include <thread>

inline void thread_task(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "thread:" << std::this_thread::get_id()
              << " paused " << n << "seconds" << std::endl;
}

inline void test_thread() {
    std::thread threads[5];
    std::cout << "Spawning 5 threads...\n";

    for (int i = 0; i < 5; i++) {
        threads[i] = std::thread(thread_task, i + 1);
    }

    for (auto& t : threads) {
        t.join();
    }
}
