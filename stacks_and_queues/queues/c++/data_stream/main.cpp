// main.cpp
#include "data_stream.hpp"
#include <vector>
#include <iostream>

using TestData = std::vector<std::tuple<std::tuple<int, int>, std::vector<int>>>;

int main()
{
    TestData data = {
        {{4, 3}, {4, 4, 3, 3, 4, 4, 4, 2, 4}},
        {{1, 2}, {1, 2, 1, 1, 1, 2, 2, 1, 1, 2}},
        {{7, 2}, {7, 12, 7, 7, 7, 17, 12, 7, 12, 12, 12}}};

    for (const auto &[input, stream] : data)
    {
        std::cout << "New data stream\n";
        int value = std::get<0>(input);
        int k = std::get<1>(input);
        DataStream dataStream = DataStream(value, k);
        for (const auto &num : stream)
        {
            std::cout << "Processing num = " << num << " in the stream";
            std::cout << ", the last " << k << " numbers " << (dataStream.consec(num) ? "do" : "do not") << " all match the target value " << value << '\n';
            std::cout << dataStream << '\n';
        }
        std::cout << std::endl;
    }

    return 0;
}
