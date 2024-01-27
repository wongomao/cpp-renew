/*
std::latch blocks all threads until a certain condition is met
*/
#include <iostream>
#include <thread>
#include <latch>
#include <chrono>
 
std::latch tasksLatch(3); // latch object with count of 3
void workerTask(int workerID)
{
    std::this_thread::sleep_for(std::chrono::seconds(workerID)); // simulate work
 
    std::cout << "Worker " << workerID << " completed their task." << std::endl;
    tasksLatch.count_down();
}
 
int main()
{
    std::thread workers[3]; // create 3 worker threads, equal to number of latches
 
    for (int i = 0; i < 3; ++i)
    {
        workers[i] = std::thread(workerTask, i + 1);
    }
 
    tasksLatch.wait(); // wait for all tasks to be completed using latch
 
    {
        std::cout << "All tasks completed. Supervisor can evaluate the work." << std::endl;
    }
 
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Joining worker thread " << i + 1 << std::endl;
        workers[i].join(); // what does this do? it appears necessary to prevent a crash
        // a thread must be joined or detached before it is destroyed
    }
 
    return 0;
}
/*
outcome:
Worker 1 completed their task.
Worker 2 completed their task.
Worker 3 completed their task.
All tasks completed. Supervisor can evaluate the work.
Joining worker thread 1
Joining worker thread 2
Joining worker thread 3
*/