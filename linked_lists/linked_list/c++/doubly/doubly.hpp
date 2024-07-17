// doubly.hpp
#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include "node.hpp"
#include <memory>
#include <iostream>

/**
 * @class DoublyLinkedList
 * @brief A class representing a doubly linked list with sentinel head and tail nodes.
 */
class DoublyLinkedList
{
public:
    /**
     * @brief Constructs an empty doubly linked list with sentinel head and tail nodes.
     */
    DoublyLinkedList();

    /**
     * @brief Adds a node to the end of the doubly linked list.
     *
     * @param node_to_add The node to be added to the end of the list.
     */
    void add_to_end(ListNode::Ptr node_to_add);

    /**
     * @brief Removes a node from the end of the doubly linked list.
     */
    void remove_from_end();

    /**
     * @brief Adds a node to the start of the doubly linked list.
     *
     * @param node_to_add The node to be added to the start of the list.
     */
    void add_to_start(ListNode::Ptr node_to_add);

    /**
     * @brief Removes a node from the start of the doubly linked list.
     */
    void remove_from_start();

    /**
     * @brief Adds a node at a specific index in the doubly linked list.
     *
     * @param index The index at which the node should be added.
     * @param node_to_add The node to be added to the list.
     */
    void add_at_index(int index, ListNode::Ptr node_to_add);

    /**
     * @brief Removes a node at a specific index in the doubly linked list.
     *
     * @param index The index of the node to be removed.
     */
    void remove_at_index(int index);

    /**
     * @brief Displays the values in the linked list from start to end.
     */
    void display() const;

private:
    ListNode::Ptr head; // Pointer to the sentinel head node
    ListNode::Ptr tail; // Pointer to the sentinel tail node
};

#endif
