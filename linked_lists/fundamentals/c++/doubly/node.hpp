// node.hpp
#ifndef NODE_HPP
#define NODE_HPP
#include <memory>
#include <iostream>

/**
 * @class Node
 * @brief A class representing a node in a doubly linked list.
 */
class Node
{
public:
    using Ptr = std::shared_ptr<Node>;

    /**
     * @brief Constructs a new Node object.
     *
     * @param data An integer representing the data associated with the node instance
     */
    explicit Node(int data = 0);

    /**
     * @brief Overloads the << operator to print the node data.
     *
     * @param os The output stream
     * @param node The node to be printed
     * @return std::ostream& The output stream with the node data
     */
    friend std::ostream &operator<<(std::ostream &os, const Node &node);

private:
    int data; // The data stored in the node
    Ptr next; // Pointer to the next node
    Ptr prev; // Pointer to the previous node

    // Provide access to DoublyLinkedList class
    friend class DoublyLinkedList;
};

#endif
