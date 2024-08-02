// main.cpp
#include "validate_stack.hpp"
#include <map>
#include <vector>
#include <iostream>

void printVector(const std::vector<int> &vector)
{
    std::cout << "{";
    for (const auto &element : vector)
    {
        std::cout << element << (&element != &vector.back() ? ", " : "");
    }
    std::cout << "}";
}

int main()
{
    std::map<std::vector<int>, std::vector<int>> testCases = {
        {{1, 2, 3, 4, 5, 6}, {4, 5, 6, 3, 2, 1}},
        {{1, 2, 3, 4, 5}, {4, 3, 5, 1, 2}},
        {{3}, {2}}};
    for (const auto &[pushed, popped] : testCases)
    {
        std::cout << "Given pushed = ";
        printVector(pushed);
        std::cout << " and popped = ";
        printVector(popped);
        bool valid = validateStack(pushed, popped);
        std::cout << ", the sequences of operations are " << (valid ? "valid" : "not valid") << '\n';
    }
    std::cout << std::endl;

    return 0;
}
