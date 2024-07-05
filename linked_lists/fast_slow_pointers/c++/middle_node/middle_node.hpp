// middle_node.hpp
#ifndef MIDDLE_NODE_HPP
#define MIDDLE_NODE_HPP
#include "node.hpp"

/**
 * @brief Given the `head` of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second node.
 * 
 * @param head A shared pointer to the first real node
 * @return ListNode::Ptr A shared pointer to the middle node of the linked list
 */
ListNode::Ptr middleNode(const ListNode::Ptr &head);

#endif
