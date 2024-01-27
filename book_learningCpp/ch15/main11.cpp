/*
std::stop_token allows creation of a token that can be used to request cancellation of 
another thread.
Like a STOP button for threads, the power to stop threads whenever necessary.
*/
#include <iostream>
#include <thread>
#include <stop_token>

void printNumbers(const std::stop_token& stopToken)
{
    for (int i = 1; !stopToken.stop_requested(); ++i)
    {
        std::cout << "Number: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    std::jthread t1(printNumbers); // spawn new thread that calls printNumbers()
    std::this_thread::sleep_for(std::chrono::seconds(5)); // simulate work

    t1.request_stop(); // request thread to stop; it will finish its current iteration and stop
    t1.join(); // wait for t1 to finish

    return 0;
}