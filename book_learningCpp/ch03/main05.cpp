#include <iostream>
#include <random>

unsigned int random(unsigned int min, unsigned int max) {
    // random number generator
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<unsigned int> uni(min, max); // guaranteed unbiased
    return uni(rng);
}

void show_all_1(unsigned int (&data)[500]) {
    for (int i = 0; i < 500; ++i) {
        std::cout << data[i] << std::endl;
    }
}

void show_all_2(unsigned int *data, size_t size) {
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << std::endl;
    }
}

unsigned int binary_search(unsigned int *arr, size_t size, unsigned int item) {
    unsigned int low = 0;
    unsigned int high = size - 1;

    int guessCount = 0;
    while (low <= high) {
        unsigned int mid = (low + high) / 2;
        unsigned int guess = arr[mid];
        ++guessCount;
        std::cout << "guess " << guessCount << " : " << guess << std::endl;
        if (guess == item) {
            std::cout << "guessCount: " << guessCount << std::endl;
            return mid;
        }
        if (guess > item) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int size = 500;
    unsigned int random_integer = random(0, size - 1);
    unsigned int a[size]{}; // initialize all elements to 0
    
    // std::cout << "size of a: " << sizeof(a) << std::endl;
    // unsigned int len = sizeof(a) / sizeof(a[0]);
    // std::cout << "len of a: " << len << std::endl;

    // populate array
    for (int i = 0; i < size; ++i)
    {
        a[i] = i;
    }
    unsigned int found = binary_search(a, size, random_integer);
    std::cout << "found: " << found << std::endl;
    return 0;
}