// reverse_even_length_group.hpp
#ifndef REVERSE_EVEN_LENGTH_GROUP_HPP
#define REVERSE_EVEN_LENGTH_GROUP_HPP
#include "node.hpp"

/**
 * @brief Given the `head` of a singly linked list, where the nodes are sequentially associated to non-empty groups whose lengths from the sequence of natural numbers
 * (1, 2, 3, 4, ...), reverse the nodes in each group with an even length.
 *
 * @param head A shared pointer to the sentinel head of the linked list
 * @return ListNode::Ptr A shared pointer to the sentinel head of the modified linked list
 */
ListNode::Ptr reverseEvenLengthGroup(ListNode::Ptr &head);

#endif
