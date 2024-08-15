// main.cpp
#include <iostream>
#include <vector>
#include <random>
#include "combine_and_sort.hpp"
#include "custom_rng.hpp"

int main()
{

    size_t arr1N = 5, arr2M = 7;
    int max_arr1 = 35, max_arr2 = 60, min_arr1 = 5, min_arr2 = 25;

    // Generate random sorted integer vectors
    std::vector<int> arr1 = generateRandomVector(arr1N, min_arr1, max_arr1);
    std::vector<int> arr2 = generateRandomVector(arr2M, min_arr2, max_arr2);

    std::vector<int> res = combine(arr1, arr2);

    // Print output
    // The comparison &value != &arr1.back() checks if the current element's address is not the same as the address of the last element
    // If the current element is not the last element, add ", ", if it is, add nothing ""
    std::cout << "The inputs {";
    for (const auto &value : arr1)
    {
        std::cout << value << (&value != &arr1.back() ? ", " : "");
    }
    std::cout << "} + {";
    for (const auto &value : arr2)
    {
        std::cout << value << (&value != &arr2.back() ? ", " : "");
    }
    std::cout << "} = {";
    for (const auto &value : res)
    {
        std::cout << value << (&value != &res.back() ? ", " : "");
    }
    std::cout << "}" << std::endl;

    return 0;
}
