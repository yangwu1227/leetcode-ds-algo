// remove_elements.hpp
#ifndef REVERSE_EVEN_LENGTH_GROUP_HPP
#define REVERSE_EVEN_LENGTH_GROUP_HPP
#include "node.hpp"

/**
 * @brief Given the `head` of a linked list and an integer `date`, remove all the nodes of the linked list that has `ListNode->data == data`.
 *
 * @param head A shared pointer to the sentinel head of the linked list
 * @param data An integer against which to check each node's data attribute
 *
 * @return ListNode::Ptr A shared pointer to the sentinel head of the modified linked list
 */
ListNode::Ptr removeElements(ListNode::Ptr &head, int data);

#endif
