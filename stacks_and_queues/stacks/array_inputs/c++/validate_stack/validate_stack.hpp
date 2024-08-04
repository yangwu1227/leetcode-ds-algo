// validate_stack.hpp
#ifndef VALIDATE_STACK_HPP
#define VALIDATE_STACK_HPP
#include <vector>

/**
 * @brief Determine if `pushed` and `popped` can be obtained from a series of stack push and pop operations.
 *
 * @param pushed A series of pushed elements in the specified order
 * @param popped A series of popped elements in the specified order
 * @return bool `true` if the sequences of operations are valid, `false` otherwise
 */
bool validateStack(const std::vector<int> &pushed, const std::vector<int> &popped);

#endif
