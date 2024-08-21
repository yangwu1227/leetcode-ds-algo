// data_stream.cpp
#include "data_stream.hpp"
#include <deque>
#include <unordered_map>
#include <iostream>

int MAX_PRINT_ELEMENTS = 4;

DataStream::DataStream(int value, int k) : value(value), k(k) {};

bool DataStream::consec(int num)
{
    // Push to the back of the deque
    this->internalDeque.push_back(num);

    // If the number does not match the target value, increment its count
    if (num != this->value)
    {
        this->invalidValueCounts[num] += 1;
    }

    // Return early if the stream size is less than k
    if (this->internalDeque.size() < this->k)
    {
        return false;
    }

    if (this->internalDeque.size() > this->k)
    {
        // Pop the front of the deque
        int popped = this->internalDeque.front();
        this->internalDeque.pop_front();
        
        // If the popped value does not match the target value, update its count
        if (popped != this->value)
        {
            // If the count is equal to 1, delete the key as it is the last occurrance of num
            if (this->invalidValueCounts[popped] == 1)
            {
                this->invalidValueCounts.erase(popped);
            }
            else
            {
                // If the count is not equal to 1, then it has more than one ocurrences, simply decrement
                this->invalidValueCounts[popped] -= 1;
            }
        }
    }

    // Return 'true' if the hash map is empty, which means that all previous k numbers are equal to the target value
    return this->invalidValueCounts.empty();
}

std::ostream &operator<<(std::ostream &os, const DataStream &dataStream)
{
    os << "DataStream([";
    int size = dataStream.internalDeque.size();
    int numElementsToPrint = std::min(size, MAX_PRINT_ELEMENTS);

    for (int i = 0; i < numElementsToPrint; ++i)
    {
        os << dataStream.internalDeque[i];
        if (i < numElementsToPrint - 1)
        {
            os << ", ";
        }
    }
    if (size > MAX_PRINT_ELEMENTS)
    {
        os << ", ...";
    }
    os << "])";
    return os;
}
