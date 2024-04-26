// main.cpp
#include "count_elements.hpp"
#include "custom_rng.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> array1 = generateRandomVector(7, 0, 15);
    std::vector<int> array2 = generateRandomVector(10, 12, 23);
    std::vector<int> array3 = generateRandomVector(25, 3, 40);
    std::vector<std::vector<int>> testArrays = {array1, array2, array3};
    for (const auto &array : testArrays)
    {
        int result = countElements(array);
        std::cout << "There are " << result << " elements in {";
        for (const auto &value : array)
        {
            std::cout << value << (&value != &array.back() ? ", " : "");
        }
        std::cout << "} that satisfy the condition" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
