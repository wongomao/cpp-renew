/*
Demonstrate two threads using a shared resource (vector)
*/
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex faxMutex; // control access to shared resources
std::vector<int> phoneNumbers; // holds fax numbers
// Is phoneNumbers part of faxMutex? No - not until we use lock_guard and
// use phoneNumbers within curly braces
/*
Mutex = Mutual Exclusion
*/

void sendFax()
{
    for (int i = 1; i <= 5; ++i)
    {
        // Use of lock_guard to acquire the mutex lock faxMutex
        // and protect the shared resource during
        // the fax sending process
        // .lock protects any resource between the curly braces
        std::lock_guard<std::mutex> lock(faxMutex);
        phoneNumbers.push_back(i);
        std::cout << "Sending fax: " << i << std::endl;
        // simulate fax being sent by sleeping
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    } // when lock_guard goes out of scope, mutex is released
}

void receiveFax()
{
    for (int i = 0; i < 5; ++i)
    {
        // Use of lock_guard to acquire the mutex lock faxMutex
        // and protect the shared resource during
        // the fax sending process
        std::lock_guard<std::mutex> lock(faxMutex);
        if (!phoneNumbers.empty())
        {
            // get the last element from the phoneNumbers vector
            int faxNumber = phoneNumbers.back();
            phoneNumbers.pop_back(); // popping it off
            std::cout << "Receiving fax: " << faxNumber << std::endl;
            // simulate fax being received by sleeping
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        else
        {
            std::cout << "No faxes to receive!" << std::endl;
        }
    }
}

int main()
{
    // create two threads competing for the shared resource (vector)
    std::thread senderThread(sendFax);
    std::thread receiverThread(receiveFax);

    // joining both threads to wait for them to finish before exiting
    senderThread.join();
    receiverThread.join();

    return 0;
}
/* example of output:
Sending fax: 1
Sending fax: 2
Sending fax: 3
Sending fax: 4
Receiving fax: 4
Sending fax: 5
Receiving fax: 5
Receiving fax: 3
Receiving fax: 2
Receiving fax: 1
*/