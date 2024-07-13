// reverse_group.hpp
#ifndef REVERSE_GROUP_HPP
#define REVERSE_GROUP_HPP
#include "node.hpp"

/**
 * @brief Given the `startNode` of a group with `groupLength` nodes, reverse the ndoes in the group.
 *
 * @param startNode A shared pointer to the start of the group
 * @param groupLength The number of nodes in the group
 * @return ListNode::Ptr A shared pointer to the new first node of the group
 */
ListNode::Ptr reverseGroup(ListNode::Ptr &startNode, int groupLength);

#endif
