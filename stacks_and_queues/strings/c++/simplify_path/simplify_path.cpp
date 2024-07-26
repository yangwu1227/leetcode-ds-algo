// simplify_path.cpp
#include "simplify_path.hpp"
#include <string>
#include <vector>
#include <boost/algorithm/string/classification.hpp> // For boost::is_any_of
#include <boost/algorithm/string/split.hpp>          // For boost::split

std::string simplifyPath(const std::string &path)
{
    if (path.length() == 1)
    {
        return "/";
    }

    // Split string based on "/"
    std::vector<std::string> splitPaths;
    boost::split(splitPaths, path, boost::is_any_of("/"), boost::token_compress_on);

    std::vector<std::string> pathStack;
    pathStack.reserve(splitPaths.size());
    for (const auto &splitPath : splitPaths)
    {
        // If current directory, do nothing
        if (splitPath == ".")
        {
            continue;
        }
        // If ".." and stack is not empty, simulate moving one directory up by popping the top of the stack
        else if (!pathStack.empty() && splitPath == "..")
        {
            pathStack.pop_back();
        }
        // If not empty and not "..", push to the top of the stack
        else if (!splitPath.empty() && splitPath != "..")
        {
            pathStack.push_back(splitPath);
        }
    }

    // Join the string
    std::string output = "";
    for (const auto &path : pathStack)
    {
        output += "/" + path;
    }

    return (!output.empty() ? output : "/");
}
