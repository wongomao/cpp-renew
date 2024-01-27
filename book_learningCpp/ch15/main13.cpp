/*
std::barrier is used to synchronize a group of threads. Each worker
thread simulates some work, then they reach the barrier and wait for 
all threads to reach that point. Once they reach the barrier, they
proceed together -- enforcing synchronization.
*/
#include <iostream>
#include <thread>
#include <barrier> // !
#include <vector>
#include <mutex> 

const int num_threads = 4;
std::barrier barrier(num_threads); // create a barrier object with count of 4
std::mutex cout_mutex; // synchronize access to std::cout

void worker(int id)
{
    std::this_thread::sleep_for(std::chrono::seconds(id)); // simulate work

    {
        std::lock_guard<std::mutex> lock(cout_mutex); // lock cout - quick scope
        std::cout << "Worker " << id << " reached the barrier." << std::endl;
    }

    barrier.arrive_and_wait(); // wait until all 4 threads reach this point
    {
        std::lock_guard<std::mutex> lock(cout_mutex); // lock cout
        std::cout << "Worker " << id << " passed the barrier." << std::endl;
    }
}

int main()
{
    std::vector<std::thread> threads; // vector of threads

    for (int i = 0; i < num_threads; ++i)
    {
        threads.emplace_back(worker, i + 1); // create and add thread to vector
    }

    for (auto& thread : threads)
    {
        thread.join(); // join / wait for all threads to finish
    }

    std::cout << "All workers finished." << std::endl;

    return 0;
}
/*
output:
Worker 1 reached the barrier.
Worker 2 reached the barrier.
Worker 3 reached the barrier.
Worker 4 reached the barrier.
Worker 4 passed the barrier.
Worker 1 passed the barrier.
Worker 3 passed the barrier.
Worker 2 passed the barrier.
All workers finished.
*/