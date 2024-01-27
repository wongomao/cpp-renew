#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

// atomic variables are thread-safe without mutexes / locks
std::atomic<int> mice_caught_total(0);
std::mutex cout_mutex; // std::cout is not thread-safe so we need mutexes / locks

void cat(int id, int mice_target)
{
    int mice_caught = 0;
 
    while (mice_caught < mice_target)
    {
        int mice_left_to_catch = mice_target - mice_caught;
        int mice_caught_this_time = rand() % 5 + 1;
 
        if (mice_caught_this_time > mice_left_to_catch)
        {
            mice_caught_this_time = mice_left_to_catch;
        }
 
        mice_caught += mice_caught_this_time;
        mice_caught_total += mice_caught_this_time;
 
        std::unique_lock<std::mutex> lock(cout_mutex);
        std::cout << "Cat " << id << " caught " << mice_caught_this_time << " mice!" << std::endl;
        lock.unlock();
    }
 
    std::unique_lock<std::mutex> lock(cout_mutex); // lock cout
    std::cout << "Cat " << id << " caught all " << mice_target << " mice!" << std::endl;
    lock.unlock(); // unlock cout
}
 
int main()
{
    srand(time(nullptr));
 
    const int num_cats = 3;
    const int total_mice = 50;
 
    std::thread cats[num_cats];
 
    for (int i = 0; i < num_cats; ++i)
    {
        int mice_target = total_mice / num_cats;
        if (i == num_cats - 1)
        {
            mice_target += total_mice % num_cats;
        }
 
        cats[i] = std::thread(cat, i + 1, mice_target);
    }
 
    for (int i = 0; i < num_cats; ++i)
    {
        cats[i].join();
    }
 
    int mice_remaining = total_mice - mice_caught_total;
 
    std::unique_lock<std::mutex> lock(cout_mutex);
    std::cout << "All cats caught " << mice_caught_total << " mice!" << std::endl;
    std::cout << "There are " << mice_remaining << " mice left in the house!" << std::endl;
    lock.unlock();
 
    return 0;
}