// remove_duplicates_II.hpp
#ifndef REMOVE_DUPLICATES_II_HPP
#define REMOVE_DUPLICATES_II_HPP
#include "node.hpp"

/**
 * @brief Given the `head` of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 * @param head A shared pointer to the sentinel head of the linked list
 * @return ListNode::Ptr A shared pointer to the sentinel head of the deduplicated linked list
 */
ListNode::Ptr removeDuplicates(const ListNode::Ptr &head);

#endif
