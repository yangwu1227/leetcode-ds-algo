// k_node.hpp
#ifndef K_NODE_HPP
#define K_NODE_HPP
#include "node.hpp"

/**
 * @brief Given `head`, the sentinel head node, of a singly linked list and `k`, return the kth node from the end of the linked list.
 *
 * @param head A shared pointer to the sentinel head node of the linked list
 * @param k The node to return
 * @return ListNode::Ptr A shared pointer to the kth node of the linked list
 */
ListNode::Ptr kthNode(const ListNode::Ptr &head, int k);

#endif
