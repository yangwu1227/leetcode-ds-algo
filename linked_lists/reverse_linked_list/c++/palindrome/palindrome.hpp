// palindrome.hpp
#ifndef PALINDROME_HPP
#define PALINDROME_HPP
#include "node.hpp"

/**
 * @brief Given the `head` of a singly linked list, determine if this is a palindrome.
 *
 * @param head A shared pointer to the sentinel head of the linked list
 * @return bool `true` if the list is a palindrome and `false` otherwise
 */
bool palindrome(const ListNode::Ptr &head);

#endif
