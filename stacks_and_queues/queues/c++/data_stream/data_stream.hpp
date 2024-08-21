// data_stream.hpp
#ifndef DATA_STREAM_HPP
#define DATA_STREAM_HPP
#include <unordered_map>
#include <deque>
#include <iostream>

/**
 * @brief A class to represent a data stream and evaluate consecutive occurrences of a specific value.
 */
class DataStream
{
public:
    /**
     * @brief Construct a new Data Stream instance.
     *
     * @param value The target value to monitor in the data stream
     * @param k The number of consecutive occurrences to check for the target value
     */
    DataStream(int value, int k);

    /**
     * @brief Process a number from the stream and check if the last `k` values are equal to the target value.
     *
     * @param num The number to process from the stream
     *
     * @return `true` if the last `k` values in the stream are equal to the target value, `false` otherwise
     */
    bool consec(int num);

    /**
     * @brief Overloads the << operator to print the stream data.
     *
     * @param os The output stream
     * @param dataStream The DataStream instance to be printed
     *
     * @return std::ostream& The output stream with the stream data
     */
    friend std::ostream &operator<<(std::ostream &os, const DataStream &dataStream);

private:
    int k;
    int value;
    std::deque<int> internalDeque;                   // Internal deque to hold the most recent `k` values from the stream
    std::unordered_map<int, int> invalidValueCounts; // Hash map to count occurrences of values in the deque that do not match `value`
};

#endif
