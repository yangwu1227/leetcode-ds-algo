// binary.hpp
#ifndef BINARY_HPP
#define BINARY_HPP
#include "node.hpp"

/**
 * @brief Given the `head` of a singly-linked list, the value of each node in the linked list is either 0 or 1. The list holds the binary (base 2)
 * representation of a decimal (base 10) number.
 *
 * @param head A shared pointer to the sentinel head of the linked list
 * @return int The decimal value of the number
 */
int getDecimal(const ListNode::Ptr &head);

#endif
