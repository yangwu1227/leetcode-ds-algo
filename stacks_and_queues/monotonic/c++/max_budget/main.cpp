// main.cpp
#include "max_budget.hpp"
#include "custom_rng.hpp"
#include <vector>
#include <iostream>

// Assume that T has overloaded <<, which is true for all primitive types such as int, double, char, etc.
template <typename T>
void printVector(const std::vector<T> &vector)
{
    std::cout << "{";
    for (auto const &element : vector)
    {
        std::cout << element << (&element != &vector.back() ? ", " : "");
    }
    std::cout << "}";
}

using TestData = std::vector<std::tuple<std::vector<int>, std::vector<int>, long long>>;

int main()
{
    TestData data;
    data.emplace_back(std::vector<int>{12}, std::vector<int>{7}, 24);
    data.emplace_back(std::vector<int>{3, 6, 1, 3, 4}, std::vector<int>{2, 1, 3, 4, 5}, 25);
    for (int i = 0; i < 3; i++)
    {
        int size = generateRandomVector(1, 1, 15)[0];
        int min = generateRandomVector(1, 1, 10)[0];
        int max = generateRandomVector(1, min, 60)[0];
        long long budget = static_cast<long long int>(generateRandomVector(1, 10, 100)[0]);
        data.emplace_back(generateRandomVector(size, min, max), generateRandomVector(size, min, max), budget);
    }

    for (const auto &[chargeTimes, runningCosts, budget] : data)
    {
        int maxMachines = maxBudget(chargeTimes, runningCosts, budget);
        std::cout << "Given charge times = ";
        printVector(chargeTimes);
        std::cout << " | running costs = ";
        printVector(runningCosts);
        std::cout << " | budget = " << budget << " ---> max machine(s) = " << maxMachines << '\n';
    }
    std::cout << std::endl;

    return 0;
}
