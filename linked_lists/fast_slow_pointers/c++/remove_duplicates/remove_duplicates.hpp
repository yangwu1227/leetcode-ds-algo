// remove_duplicates.hpp
#ifndef REMOVE_DUPLICATES_HPP
#define REMOVE_DUPLICATES_HPP
#include "node.hpp"

/**
 * @brief Given the `head` of a sorted linked list, delete all duplicates such that each element appears only once.
 *
 * @param head A shared pointer to the sentinel head of the singly linked list
 * @return ListNode::Ptr A shared pointer to the new sentinel head of the sorted, deduplciated linked list
 */
ListNode::Ptr removeDuplicates(const ListNode::Ptr &head);

#endif
