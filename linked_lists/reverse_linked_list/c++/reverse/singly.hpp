#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include "node.hpp"
#include <memory>
#include <iostream>

/**
 * @class SinglyLinkedList
 * @brief A class representing a singly linked list with a sentinel head node.
 */
class SinglyLinkedList
{
public:
    /**
     * @brief Constructs an empty singly linked list with a sentinel head node.
     */
    SinglyLinkedList();

    /**
     * @brief Adds a node to the end of the singly linked list.
     *
     * @param node_to_add The node to be added to the end of the list.
     */
    void add_to_end(ListNode::Ptr node_to_add);

    /**
     * @brief Removes a node from the end of the singly linked list.
     */
    void remove_from_end();

    /**
     * @brief Adds a node to the start of the singly linked list.
     *
     * @param node_to_add The node to be added to the start of the list.
     */
    void add_to_start(ListNode::Ptr node_to_add);

    /**
     * @brief Removes a node from the start of the singly linked list.
     */
    void remove_from_start();

    /**
     * @brief Adds a node at a specific index in the singly linked list.
     *
     * @param index The index at which the node should be added.
     * @param node_to_add The node to be added to the list.
     */
    void add_at_index(int index, ListNode::Ptr node_to_add);

    /**
     * @brief Removes a node at a specific index in the singly linked list.
     *
     * @param index The index of the node to be removed.
     */
    void remove_at_index(int index);

    /**
     * @brief Displays the values in the linked list from start to end.
     */
    void display() const;

    ListNode::Ptr head; // Pointer to the sentinel head node
    ListNode::Ptr tail; // Pointer to the tail node
};

#endif
