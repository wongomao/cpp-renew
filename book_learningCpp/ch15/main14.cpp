#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex coutMutex;

void sousChefTask(int sousChefId)
{
    // ... tasks assigned to sous-chef

    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "Sous-Chef " << sousChefId << " is done preparing an ingredient." << std::endl;
    }
}

int main()
{
    const int NumSousChefs = 3;
    std::vector<std::thread> sousChefThreads;

    for (int i = 0; i < NumSousChefs; ++i)
    {
        sousChefThreads.emplace_back(sousChefTask, i);
    }

    // ... tasks assigned to master chef
    std::cout << "Master Chef is creating the final dish." << std::endl;

    for (auto& thread : sousChefThreads)
    {
        thread.join(); // wait for all sous-chef threads to finish
    }

    std::cout << "All sous-chefs have finished preparing the ingredients." << std::endl;
    std::cout << "Master Chef presents the delicious meal. Bon appétit!" << std::endl;

    return 0;
}
/*
output:
Master Chef is creating the final dish.
Sous-Chef 0 is done preparing an ingredient.
Sous-Chef 2 is done preparing an ingredient.
Sous-Chef 1 is done preparing an ingredient.
All sous-chefs have finished preparing the ingredients.
Master Chef presents the delicious meal. Bon app├⌐tit!
*/