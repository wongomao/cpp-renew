#include <iostream>
#include <thread>

void threadFunction()
{
    std::cout << "Hello from thread!" << std::endl;
}

int main()
{
    std::thread t(threadFunction);
    t.join(); // start thread t and wait for it to finish
    std::cout << "Hello from main!" << std::endl;
    // t.join(); // cannot join again, will cause error
    return 0;
}