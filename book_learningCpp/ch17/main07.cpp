#include <iostream>
#include <new>
// the <new> header is required for std::bad_alloc

int main()
{
    size_t count = 0; // number of allocations

    try
    {
        while (true) // continuous allocation
        {
            new int[1000000ul]; // memory for one million integers
            // there is no deallocation; the memory is leaked

            ++count; // increment the number of allocations

            if (count % 1000 == 0) // print update for every 1000 allocations
            {
                // if the counter is divisible by 1000, print a message
                // indicating how much memory has been allocated so far
                std::cout << "Allocated " << (1000000ul * sizeof(int) * count) << " bytes so far" << std::endl;
            }
        }
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Error: " << e.what() << std::endl; // standard error stream
    }

    return 0;
}
/*
Output:
Allocated 4000000000 bytes so far
Allocated 8000000000 bytes so far
Allocated 12000000000 bytes so far
Allocated 16000000000 bytes so far
Allocated 20000000000 bytes so far
Allocated 24000000000 bytes so far
Allocated 28000000000 bytes so far
Allocated 32000000000 bytes so far
Allocated 36000000000 bytes so far
Allocated 40000000000 bytes so far
Allocated 44000000000 bytes so far
Allocated 48000000000 bytes so far
Allocated 52000000000 bytes so far
Error: std::bad_alloc
*/