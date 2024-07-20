// main.cpp
#include "random_flip_matrix.hpp"
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <iostream>

int main()
{
    std::map<std::pair<int, int>, std::vector<std::string>> testCases = {
        {std::make_pair(3, 3), {"flip", "flip", "flip", "flip", "flip", "flip", "flip", "flip", "flip", "flip", "reset", "flip"}},
        {std::make_pair(2, 4), {"flip", "flip", "flip", "flip", "flip", "reset", "flip"}}};

    for (const auto &[shape, actions] : testCases)
    {
        int m = shape.first, n = shape.second;
        std::cout << "Matrix has shape (" << m << ", " << n << ")\n";
        std::unique_ptr<RandomFlip> randomFlipPtr = std::make_unique<RandomFlip>(m, n);
        for (const auto &action : actions)
        {
            std::cout << "Action is - " << action << '\n';
            if (action == "flip")
            {
                std::vector<int> indices = randomFlipPtr->flip();
                std::cout << "{";
                for (const auto &index : indices)
                {
                    std::cout << index << (&index != &indices.back() ? ", " : "");
                }
                std::cout << "}\n";
                std::cout << "Available indices = " << randomFlipPtr->getAvailableIndices() << '\n';
            }
            else if (action == "reset")
            {
                std::cout << "Resetting\n";
                randomFlipPtr->reset();
                std::cout << "Available indices = " << randomFlipPtr->getAvailableIndices() << '\n';
            }
        }
        std::cout << "\n\n";
    }

    return 0;
}
