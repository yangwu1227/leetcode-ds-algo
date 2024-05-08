// intersection.hpp
#ifndef INTERSECTION_HPP
#define INTERSECTION_HPP
#include <vector>

class Intersection
{
public:
    /**
     * @brief Given a 2D array `nums` that contains `n` arrays of distinct integers, return a sorted array containing all the numbers that appear in all `n` arrays. This uses a
     * double loop to build the hash map.
     *
     * @param nums A 2D array containing `n` arrays of integers
     * @return std::vector<int>  A 1D array containing the intersection of all arrays
     */
    static std::vector<int> loop(const std::vector<std::vector<int>> &nums);
    
    /**
     * @brief Given a 2D array `nums` that contains `n` arrays of distinct integers, return a sorted array containing all the numbers that appear in all `n` arrays. This uses set intersections
     * to solve the problem.
     *
     * @param nums A 2D array containing `n` arrays of integers
     * @return std::vector<int>  A 1D array containing the intersection of all arrays
     */
    static std::vector<int> set(const std::vector<std::vector<int>> &nums);
};

#endif
