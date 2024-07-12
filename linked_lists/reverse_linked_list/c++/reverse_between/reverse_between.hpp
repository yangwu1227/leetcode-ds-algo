// reverse_between.hpp
#ifndef REVERSE_BETWEEN_HPP
#define REVERSE_BETWEEN_HPP
#include "node.hpp"

/**
 * @brief Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`.
 *
 * @param head A shared pointer to the sentinel head of the linked list
 * @param left The start of the section of the linked list to be reversed
 * @param right The end of the section of the linked list to be reversed
 * @return ListNode::Ptr The sentinel head of the modified link list
 */
ListNode::Ptr reverseBetween(const ListNode::Ptr &head, int left, int right);

#endif
