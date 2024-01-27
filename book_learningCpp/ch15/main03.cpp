/* Passing ownership of a mutex using unique_lock */
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void functionA(std::unique_lock<std::mutex> lock)
{   // lock ownership is transferred to functionA
    std::cout << "Function A acquired the mutex" << std::endl;

    // perform some task within the critical section
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Function A completed the task" << std::endl;
}

void functionB(std::unique_lock<std::mutex> lock)
{   // lock ownership is transferred to functionB
    std::cout << "Function B acquired the mutex" << std::endl;

    // perform some task within the critical section
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Function B completed the task" << std::endl;
}

int main()
{
    std::unique_lock<std::mutex> lock(mtx);
    std::thread t1(functionA, std::move(lock)); // pass ownership of lock to t1/functionA

    std::thread t2(functionB, std::move(lock)); // pass ownership of lock to t2/functionB

    t1.join();
    t2.join();

    std::cout << "Main thread completed." << std::endl;
    return 0;
}
/* output
Function A acquired the mutex
Function B acquired the mutex
Function B completed the task
Function A completed the task
Main thread completed.
*/