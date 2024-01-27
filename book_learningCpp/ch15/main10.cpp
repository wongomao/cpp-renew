#include <iostream>
#include <thread>

void task()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Hello from thread " << std::this_thread::get_id() << " Loop " << i << std::endl;
    }
}

int main()
{
    std::jthread t1(task); // spawn new thread that calls task()

    // continue doing other work
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Hello from main thread " << std::this_thread::get_id() << " Loop " << i << std::endl;
    }

    t1.join(); // wait for t1 to finish
    return 0;
}
/*
possible outcome:
Hello from main thread 1 Loop 0
Hello from main thread 1 Loop 1
Hello from main thread 1 Loop 2
Hello from main thread 1 Loop 3
Hello from main thread Hello from thread 2 Loop 0
Hello from thread 21 Loop 4
 Loop 1
Hello from thread 2 Loop 2
Hello from thread 2 Loop 3
Hello from thread 2 Loop 4
Hello from thread 2 Loop 5
Hello from thread 2 Loop 6
Hello from thread 2 Loop 7
Hello from thread 2 Loop 8
Hello from thread 2 Loop 9

Notice that cout is interleaved because it was not locked.
*/