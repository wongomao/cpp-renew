#include <iostream>
#include <iomanip>
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
    for (int i=0; i<size; ++i) {
        if (value < (i+1)) {
            bucket[i] += 1;
            break;
        }
    }
}

void display_bucket(unsigned int *bucket, int size, int iterations)
{
    std::cout << "-----------bucket:----" << std::endl;
    for (int i=0; i<size; ++i) {
        std::cout << std::setw (10) << bucket[i] << " ";
        double ratio = (double)bucket[i] / (double)iterations;
        int ratio_int = (int)(ratio * 1000.0);
        // std::cout << " (" << ratio_int << "%) ";
        for (int j=0; j<ratio_int; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << "----------------------" << std::endl;
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
    int iterations = 100000;
    for (int i=0; i<iterations; ++i) {
        float val = dis(seed) * 10.0;
        add_to_bucket(bucket, 10, val);
    }
    display_bucket(bucket, 10, iterations);

/*
The output typically shows a uniform distribution of values in the bucket array.
-----------bucket:----
      9895 **************************************************************************************************
     10051 ****************************************************************************************************
      9994 ***************************************************************************************************
     10016 ****************************************************************************************************
      9819 **************************************************************************************************
      9918 ***************************************************************************************************
     10119 *****************************************************************************************************
      9963 ***************************************************************************************************
     10146 *****************************************************************************************************
     10079 ****************************************************************************************************
----------------------
*/
    return 0;
}