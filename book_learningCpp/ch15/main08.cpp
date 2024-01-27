// ABBA pattern of lock/unlock:
// ensure exclusive access to shared data
#include <iostream>
#include <thread>
#include <mutex>
#include <random>
 
std::mutex microphoneMutex;
std::mutex guitarMutex;
 
void abbaConcert(const std::string& member)
{
    microphoneMutex.lock();
 
    std::cout << member << " has the microphone and is ready to perform at the ABBA concert!" << std::endl;
 
    guitarMutex.lock();
 
    std::cout << member << " has the guitar and is ready to perform at the ABBA concert!" << std::endl;
 
    std::cout << member << " is singing a popular ABBA song!" << std::endl;
 
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
 
    std::cout << member << " finished performing and leaves the stage." << std::endl;
 
    guitarMutex.unlock();
    microphoneMutex.unlock();
}
 
int main()
{
    std::cout << "Welcome to the ABBA Concert Simulator!" << std::endl;
    std::cout << "In this program, each member of the ABBA band will simulate their performances." << std::endl;
    std::cout << "They'll take turns, but sometimes they might try to perform when ABBA is already on stage!" << std::endl;
 
    int numIterations = 100;
 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);
 
    for (int i = 1; i <= numIterations; ++i)
    {
        std::cout << "Concert Iteration #" << i << std::endl;
 
        std::thread bjorn(abbaConcert, "Bjorn");
        std::thread agnetha(abbaConcert, "Agnetha");
        std::thread benny(abbaConcert, "Benny");
        std::thread frida(abbaConcert, "Frida");
 
        bjorn.join();
        agnetha.join();
        benny.join();
        frida.join();
 
        std::cout << std::endl;
 
        std::this_thread::sleep_for(std::chrono::milliseconds(dis(gen)));
    }
 
    std::cout << "ABBA Concert simulation is over. What a memorable experience!" << std::endl;
 
    return 0;
}