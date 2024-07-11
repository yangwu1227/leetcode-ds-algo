// pair_sum.hpp
#ifndef PAIR_SUM_HPP
#define PAIR_SUM_HPP
#include "node.hpp"

/**
 * @brief Given the `head` of a linked list with even length, return the maximum twin sum of the linked list.
 *
 * @param head A shared pointer to the sentinel head of the linked list
 * @return int The maximum twin sum
 */
int pairSum(const ListNode::Ptr &head);

#endif
