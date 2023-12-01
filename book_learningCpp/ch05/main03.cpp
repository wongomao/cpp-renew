#include <iostream>
#include <random>

void display_array(float *arr, int size)
{
    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        char trailing_char = (i < size - 1) ? ',' : ']';
        std::cout << arr[i] << trailing_char;
    }
    std::cout << std::endl;
}

void display_grid(float *grid, int size) // square grid
{
    std::cout << "[" << std::endl;
    for (int i=0; i<size; ++i) {
        std::cout << " ";
        display_array(grid + i*size, size);
    }
    std::cout << "]" << std::endl;
}

void add_to_bucket(unsigned int *bucket, int size, float value)
{
    // LEFT OFF HERE
}

int main()
{
    std::random_device rd;
    std::mt19937_64 seed(rd()); // seed the generator
    std::uniform_real_distribution<> dis(0.0, 1.0); // range [0, 1]

    int size = 3;
    float arr[size]{}; // initialize all elements to 0
    for (int i = 0; i < size; ++i)
    {
        arr[i] = dis(seed);
    }
    display_array(arr, size);

    float barr[size][size]{};
    for (int i=0; i<size; ++i) {
        for (int j=0; j<size; ++j) {
            barr[i][j] = dis(seed) * 1000.0;
        }
    }
    display_grid(*barr, size);

    unsigned int bucket[10]{};
    for (int i=0; i<1000; ++i) {
        float val = dis(seed);
        if (val < 1.0) {
            bucket[0] += 1;
        }
        else if (val < 2.0) {
            bucket[1] += 1;
        }
    }

    return 0;
}