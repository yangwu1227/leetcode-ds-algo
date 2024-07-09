// swap_pairs.hpp
#ifndef SWAP_PAIRS_HPP
#define SWAP_PAIRS_HPP
#include "node.hpp"

/**
 * @brief Given a linked list, swap every two adjacent nodes. Only the nodes can be changed and not the values of the nodes.
 *
 * @param head A shared pointer to the sentinel head of the linked list
 * @return ListNode::Ptr A shared pointer to the sentinel head of the modified linked list
 */
ListNode::Ptr swapPairs(const ListNode::Ptr &head);

#endif
