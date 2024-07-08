// swap_node.hpp
#ifndef SWAP_NODE_HPP
#define SWAP_NODE_HPP
#include "node.hpp"

/**
 * @brief Given the `head` node of a linked list and an integer `k`, swap the values of the `kth` node from the start and the `kth` node from the end.
 *
 * @param head A shared pointer to the sentinel head of the linked list
 * @param k The index of the node for swapping the data values
 * 
 * @return ListNode::Ptr A shared pointer to the sentinel head of the modified linked list
 */
ListNode::Ptr swapNode(const ListNode::Ptr &head, int k);

#endif
