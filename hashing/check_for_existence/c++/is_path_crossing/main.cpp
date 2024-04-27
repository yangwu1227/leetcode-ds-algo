// main.cpp
#include "is_path_crossing.hpp"
#include <string>
#include <vector>
#include <iostream>

int main()
{
    std::vector<std::string> testPaths = {"NESWW", "SSWEN", "SNEWSNEW", "NES", "NNE"};
    for (const auto &path : testPaths)
    {
        bool crossed = isPathCrossing(path);
        std::cout << "The path '" << path << "' " << (crossed ? "crosses" : "does not cross") << " itself" << '\n';
    }
    std::cout << std::endl;
    return 0;
}
