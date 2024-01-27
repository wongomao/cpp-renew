// condition variables
// a condition variable is a synchronization primitive that allows
// threads to wait until a particular condition occurs
// Waiting without using CPU cycles, improving performance
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable> // for synchronization
 
std::mutex mutex;
// used to signal waiting threads/cars when the light turns green
std::condition_variable trafficLight;
// used to signal waiting threads/cars when pedestrians have crossed the road
std::condition_variable pedestriansCrossing;
bool isGreen = false; // initially, the light is red, no cars can cross
bool pedestriansPresent = true; // initially, pedestrians are present on the road

// car arrives at the traffic light
void carArrives(int carID)
{
    // acquire a unique lock on mutex to ensure that access to shared data
    // is synchronized within the carArrives function
    std::unique_lock<std::mutex> lock(mutex);
    while (!isGreen)
    {
        trafficLight.wait(lock);
    }

    while (pedestriansPresent)
    {
        pedestriansCrossing.wait(lock);
    }
    // when we get here, the light is green and no pedestrians are present
    std::cout << "Car " << carID << " is crossing safely!" << std::endl;
}
 
void changeLight()
{
    // simulate a delay of 3 seconds to simulate the time it takes
    // for the light to change
    std::this_thread::sleep_for(std::chrono::seconds(3));
    {
        std::lock_guard<std::mutex> lock(mutex);
        isGreen = true;
        std::cout << "Traffic light turned green." << std::endl;
    }

    // within the changeLight function, acquire a lock on the mutex
    // and set the isGreen flag to true, indicating that the light is
    // now green
    trafficLight.notify_all();
    std::this_thread::sleep_for(std::chrono::seconds(2));
 
    {
        std::lock_guard<std::mutex> lock(mutex);
        pedestriansPresent = false;
        std::cout << "Pedestrians have crossed the road." << std::endl;
        // notice the scope of the lock_guard is within the braces
    }
    // signal all waiting cars/threads using the pedestrriansCrossing variable
    // that pedestrians have crossed
    pedestriansCrossing.notify_all();
}
 
int main()
{
    // create a thread named lightThread that will execute the 
    // changeLight function to simulate changing the traffic light
    std::thread lightThread(changeLight);

    // Create three car threads that call the carArrives function
    // with unique car IDs
    std::thread car1(carArrives, 1);
    std::thread car2(carArrives, 2);
    std::thread car3(carArrives, 3);

    // use the join() function to wait for each car thread to finish
    // its execution before proceeding
    car1.join();
    car2.join();
    car3.join();

    // use the join() function to wait for the lightThread to complete
    // before ending the program
    lightThread.join();

    return 0;
}
/*
possible outcome:
Traffic light turned green.
Pedestrians have crossed the road.
Car 2 is crossing safely!
Car 3 is crossing safely!
Car 1 is crossing safely!
*/