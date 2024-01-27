// reader-writer lock
// shared-mutex to manage access to shared data
// read is shared, write is exclusive
#include <iostream>
#include <thread>
#include <shared_mutex>
#include <mutex>

std::shared_mutex dataMutex; // declare a shared mutex for shared data
std::mutex printMutex; // mutex to protect std::cout
int sharedValue = 0;

void writeSharedValue(int writerId, int newValue)
{
    // acquire a unique lock on dataMutex - this lock blocks other threads from writing
    // while in scope
    std::unique_lock<std::shared_mutex> lock(dataMutex);
    sharedValue = newValue;

    // acquire a unique lock on printMutex - this lock blocks other threads from std::cout
    // avoiding interleaved output from multiple threads
    std::unique_lock<std::mutex> printLock(printMutex);
    std::cout << "Writer " << writerId << " writes SharedValue to " << sharedValue << std::endl;
}

void readSharedValue(int readerId)
{
    // acquire a shared lock on dataMutex - this lock allows other threads to read
    // without blocking
    std::shared_lock<std::shared_mutex> lock(dataMutex);

    // acquire a unique lock on printMutex - this lock blocks other threads from std::cout
    // avoiding interleaved output from multiple threads
    std::unique_lock<std::mutex> printLock(printMutex);
    std::cout << "Reader " << readerId << " reads SharedValue as " << sharedValue << std::endl;
}

int main()
{
    std::thread writer1(writeSharedValue, 1, 10);
    std::thread reader1(readSharedValue, 1);
    std::thread reader2(readSharedValue, 2);
    std::thread writer2(writeSharedValue, 2, 20);

    writer1.join();
    reader1.join();
    reader2.join();
    writer2.join();

    return 0;
}
/*
possible output:
Reader 2 reads SharedValue as 0
Writer 2 writes SharedValue to 20
Reader 1 reads SharedValue as 20
Writer 1 writes SharedValue to 10
*/