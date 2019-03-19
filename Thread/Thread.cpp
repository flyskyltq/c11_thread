// Thread.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include "thread.h"
// #include "mutex.h"
//#include "time_mutex.h"
//#include "lock_guard.h"
#include "unique_lock.h"

using namespace std;

int main() {
    cout << "Main thread id:" << this_thread::get_id() << endl;
    //test_thread();
    //test_mutex();
    //test_time_mutex();
    //test_lock_guard();
    test_unique_lock();
    getchar();
    return 0;
}

