// shared data initialization
#include <iostream>
#include <thread>
#include <mutex>

std::mutex countMutex; // mutex for synchronizing access to the count
int itemCount = 0; // shared count of items sold

void sellItems(int numItems)
{
    for (int i = 0; i < numItems; ++i)
    {
        std::lock_guard<std::mutex> lock(countMutex);
        ++itemCount;
    }
}

int main()
{
    const int numThreads = 4;
    const int itemsPerThread = 10; // number of items each thread sells

    std::thread threads[numThreads]; // array of threads
    for (int i = 0; i < numThreads; ++i)
    {
        // create a thread that calls sellItems and passes in the number of items
        threads[i] = std::thread(sellItems, itemsPerThread);
    }

    // wait for threads to finish
    for (int i = 0; i < numThreads; ++i)
    {
        threads[i].join();
    }

    std::cout << "Items sold: " << itemCount << std::endl;

    return 0;
}