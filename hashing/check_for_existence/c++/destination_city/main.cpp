// main.cpp
#include "destination_city.hpp"
#include <vector>
#include <iostream>
#include <string>

int main()
{
    std::vector<std::vector<std::string>> paths = {{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
    std::string destination = destCity(paths);

    std::cout << "Give the paths {";
    for (const auto &path : paths)
    {
        std::cout << "{";
        for (const auto &city : path)
        {
            std::cout << city << (&city != &path.back() ? ", " : "");
        }
        std::cout << "}" << (&path != &paths.back() ? ", " : "");
    }
    std::cout << "}, the destination city is " << destination << '\n';

    return 0;
}
