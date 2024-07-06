// delete_k_node.hpp
#ifndef DELETE_K_NODE_HPP
#define DELETE_K_NODE_HPP
#include "node.hpp"

/**
 * @brief Given the `head` of a singly linked list, remove the `kth` node from the end of the list.
 *
 * @param head A shared pointer to the sentinel head of the linked list
 * @param k The node to remove
 *
 * @return ListNode::Ptr The sentinel head of the modified linked list with the kth node from the end removed
 */
ListNode::Ptr deleteKthNode(const ListNode::Ptr &head, int k);

#endif
