#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <chrono>

int main() 
{
    std::vector<int> v(1000000);
    std::generate(v.begin(), v.end(), []() { return std::rand() % 1000; });

    // measure time for std::ranges::sort
    auto start = std::chrono::high_resolution_clock::now();
    std::ranges::sort(v);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_ranges = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // measure time for std::sort
    std::generate(v.begin(), v.end(), []() { return std::rand() % 1000; });
    start = std::chrono::high_resolution_clock::now();
    std::sort(v.begin(), v.end());
    end = std::chrono::high_resolution_clock::now();
    auto elapsed_std = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "std::ranges::sort: " << elapsed_ranges << " ms" << std::endl;
    std::cout << "std::sort: " << elapsed_std << " ms" << std::endl;

    return 0;
}