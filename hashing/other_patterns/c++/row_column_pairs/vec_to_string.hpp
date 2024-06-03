// vec_to_string.hpp
#ifndef VEC_TO_STRING_HPP
#define VEC_TO_STRING_HPP
#include <string>

/**
 * @brief Convert an std::vector<int> to an std::string.
 *
 * @param vec A positive integer vector
 * @return std::string A string representation of the vector, making it hashable
 */
std::string vecToString(const std::vector<int> &vec);

#endif