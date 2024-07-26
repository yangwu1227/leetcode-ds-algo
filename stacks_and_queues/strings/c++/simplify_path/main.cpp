// main.cpp
#include "simplify_path.hpp"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> testPaths = {
        "/.../a/../b/c/../d/./",
        "/home/",
        "/home//foo/",
        "/home/user/Documents/../Pictures",
        "/.../a/../b/c/../d/./",
        "/../",
        "/"};

    for (const auto &path : testPaths)
    {
        std::string simplifiedPath = simplifyPath(path);
        std::cout << "Original path:\n";
        std::cout << path << '\n';
        std::cout << "Simplified path:\n";
        std::cout << simplifiedPath << '\n';
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
