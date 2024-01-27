/* timed mutex : only locking if possible within a time frame */
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::timed_mutex plateMutex; // declare a timed mutex

void eatFromSharedPlate(int catId, int eatingTime)
{
    // attempt to acquire  the timed lock on plateMutex for up to 3 seconds
    if (plateMutex.try_lock_for(std::chrono::seconds(3)))
    {
        // if the lock is acquired, create a unique_lock named uniqueLock
        // with an already acquired mutex
        std::unique_lock<std::timed_mutex> uniqueLock(plateMutex, std::adopt_lock);
        std::cout << "Cat " << catId << ": Meow! I'm eating from the shared plate." << std::endl;
        // sleep for the specified eatingTime to simulate eating
        std::this_thread::sleep_for(std::chrono::seconds(eatingTime));
        std::cout << "Cat " << catId << ": Meow! I'm done eating. Leaving the plate." << std::endl;
    }
    else
    {
        std::cout << "Cat " << catId << ": Meow! I could not access the plate within 3 seconds." << std::endl;
    }
}

int main()
{
    std::thread cat1(eatFromSharedPlate, 1, 2);
    std::thread cat2(eatFromSharedPlate, 2, 3);
    std::thread cat3(eatFromSharedPlate, 3, 4);

    cat1.join();
    cat2.join();
    cat3.join();

    return 0;
}
/*
Possible race conditions. std::cout statements are possibly being executed by 
multiple threads concurrently, leading to mixed up & inconsistent output.
Answer: use mutexes to protect the shared resource (std::cout) -- coutMutex

void eatFromSharedPlate(int catId, int eatingTime)
{
    if (plateMutex.try_lock_for(std::chrono::seconds(3))) 
    {
        std::unique_lock<std::timed_mutex> uniqueLock(plateMutex, std::adopt_lock); 
        {
            std::lock_guard<std::mutex> lock(coutMutex); 
            std::cout << "Cat " << catId << ": Meow! I'm eating from the shared plate." << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(eatingTime)); 
        {
            std::lock_guard<std::mutex> lock(coutMutex); 
            std::cout << "Cat " << catId << ": Meow! I'm done eating. Leaving the plate." << std::endl;
        }
    }
    else
    {
        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << "Cat " << catId << ": Meow! I couldn't access the plate within 3 seconds. Leaving hungry." << std::endl;
        }
    }
}
 
*/