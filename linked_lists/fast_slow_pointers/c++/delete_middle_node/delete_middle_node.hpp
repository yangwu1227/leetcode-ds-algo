// delete_middle_node.hpp
#ifndef DELETE_MIDDLE_NODE_HPP
#define DELETE_MIDDLE_NODE_HPP
#include "node.hpp"

/**
 * @brief Given the `head` of a singly linked list, delete the middle node.
 *
 * @param head The sentinel head of the linked list
 * @return ListNode::Ptr The sentinel head of the modified linked list with the middle node removed
 */
ListNode::Ptr deleteMiddleNode(const ListNode::Ptr &head);

#endif
