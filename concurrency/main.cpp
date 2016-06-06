#include <iostream>
#include <thread>
// #include <assert.h>
#include <vector>
#include <numeric>
#include <list>
#include <mutex>
#include <algorithm>
#include <limits.h>
#include <future>
// #include <unistd.h>
#include <cmath>
#include <chrono>
#include <atomic>

using std::cout;
using std::endl;
using std::list;

std::atomic_flag lock = ATOMIC_FLAG_INIT;                               //初始化

void f(int n)
{
    while(lock.test_and_set())                                          //获取锁的状态
        std::cout << "Waiting ... " << std::endl;
    std::cout << "Thread " << n << " is starting working." << std::endl;
}

void g(int n)
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2s);
    std::cout << "Thread " << n << " is going to clear the flag." << std::endl;
    lock.clear();                                                       // 解锁
}

int main()
{
    lock.test_and_set();
    std::thread t1(f,1);
    std::thread t2(g,2);

    t1.join();
    t2.join();
}