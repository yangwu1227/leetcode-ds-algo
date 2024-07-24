// valid_parentheses.cpp
#include "valid_parentheses.hpp"
#include <string>
#include <unordered_map>
#include <stack>

bool validParentheses(const std::string &s)
{
    if (s.length() == 1)
    {
        return false;
    }

    std::stack<char> parenthesesStack;
    std::unordered_map<char, char> matchingBracket = {{'{', '}'}, {'[', ']'}, {'(', ')'}};

    for (const auto &currentBracket : s)
    {
        // If the current bracket is an open bracket, push it onto the stack 
        if (matchingBracket.find(currentBracket) != matchingBracket.end())
        {
            parenthesesStack.push(currentBracket);
        }
        else
        {
            // If the stack is empty, there is no open bracket to match the current closing bracket, so the string is invalid
            if (parenthesesStack.empty())
            {
                return false;
            }

            char lastOpenBracket = parenthesesStack.top();
            // Check if the current closing bracket matches the last open bracket in the stack
            if (matchingBracket[lastOpenBracket] != currentBracket)
            {
                return false;
            }
            parenthesesStack.pop();
        }
    }
    
    // If there are any remaining open brackets in the stack after the loop, the string is invalid
    return parenthesesStack.empty();
}
