// main.cpp
#include "max_number_target_word.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <cassert>

int main()
{
    std::vector<std::string> testTexts = {"nlaebolko", "loonbalxballpoon", "leetcode", "balon"};
    std::string targetWord = "balloon";
    for (const auto &text : testTexts)
    {
        int maxNumberInstancesLoop = MaxNumberTargetWord::loop(text, targetWord);
        int maxNumberInstancesTransformReduce = MaxNumberTargetWord::transformReduce(text, targetWord);
        assert(maxNumberInstancesLoop == maxNumberInstancesTransformReduce);

        std::cout << "Given the input string " << text << (maxNumberInstancesLoop ? ", there can be at most " + std::to_string(maxNumberInstancesLoop) : ", there can be no")
                  << " instances of the word " << targetWord << " formed\n";
    }
    std::cout << std::endl;
    return 0;
}
