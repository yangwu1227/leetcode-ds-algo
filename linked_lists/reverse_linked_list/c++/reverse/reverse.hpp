// reverse.hpp
#ifndef REVERSE_HPP
#define REVERSE_HPP
#include "node.hpp"

/**
 * @brief Given the sentinel head of the node, reverse the linked list.
 *
 * @param head A shared pointer to the sentinel head of the linked list
 * @return ListNode::Ptr A shared pointer to the sentinel head of the reversed linked list
 */
ListNode::Ptr reverse(const ListNode::Ptr &head);

#endif
