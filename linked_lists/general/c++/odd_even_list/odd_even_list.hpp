// odd_even_list.hpp
#ifndef ODD_EVEN_LIST_HPP
#define ODD_EVEN_LIST_HPP
#include "node.hpp"

/**
 * @brief Given the `head` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices. The first node is considered odd, and
 * the second is considered even, and so on.
 *
 * @param head A shared pointer to the sentinel head of the list
 * @return ListNode::Ptr A shared pointer to the sentinel head of the reordered list
 */
ListNode::Ptr oddEvenList(const ListNode::Ptr &head);

#endif
