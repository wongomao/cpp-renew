#include <iostream>
#include <future> // async(), future, promise
#include <thread>

// This performs the asynchronous computation. It takes a std::promis to store
// the result and two integer parameters to calculate the sum of.
void calculate_sum(std::promise<int> int_promise, int a, int b)
{
    int sum = a + b;
    int_promise.set_value(sum);
    std::cout << "Calculating the sum asynchronously..." << std::endl;
}

int main()
{
    int a, b;
    std::cout << "Welcome to the Future Teller Program!" << std::endl;
    std::cout << "Get ready to discover the hidden secrets of numbers!" << std::endl;
    std::cout << "Please enter two numbers: ";
    std::cin >> a >> b;

    // a promise to store the result of the sum
    // A promis is used to communicate from the producer thread to 
    // the consumer thread (main). It will hold the result of the sum calculation.
    std::promise<int> sum_promise;
    // a future to retrieve the result of the sum
    // Allows synchronization between two threads.
    std::future<int> sum_future = sum_promise.get_future();

    // The sum_promise is moved into the thread to transfer ownership.
    // This thread will run concurrently with the main thread, allowing the sum
    // calculation to be performed asynchronously.
    std::thread t(calculate_sum, std::move(sum_promise), a, b);
    // join() blocks the main thread until the thread t has finished executing. This
    // ensures that the main thread will not continue until the sum calculation has
    // finished.
    t.join();

    // Retrieve the calculated sum from the sum_future using get(). This will block
    // the main thread until the result is available.
    int sum = sum_future.get();

    std::cout << "You chose the numbers " << a << " and " << b << "." << std::endl;
    std::cout << "The Future Teller has foreseen that their sum is " << sum << "!" << std::endl;

    return 0;
}
/*
output:
Welcome to the Future Teller Program!
Get ready to discover the hidden secrets of numbers!
Please enter two numbers: 19 51
Calculating the sum asynchronously...
You chose the numbers 19 and 51.
The Future Teller has foreseen that their sum is 70!
*/