// has_cycle.hpp
#ifndef HAS_CYCLE_HPP
#define HAS_CYCLE_HPP
#include "node.hpp"

/**
 * @brief  Given `head`, the `head` of a linked list, determine if the linked list has a cycle in it.
 *
 * @param head  A shared pointer to the head of the linked list
 * @return bool `true` if there is a cycle, `false` otherwise
 */
bool hasCycle(const ListNode::Ptr &head);

#endif
