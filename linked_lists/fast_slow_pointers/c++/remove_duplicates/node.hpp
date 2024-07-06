#ifndef NODE_HPP
#define NODE_HPP
#include <memory>
#include <iostream>

/**
 * @class ListNode
 * @brief A class representing a node in a singly linked list.
 */
class ListNode
{
public:
    using Ptr = std::shared_ptr<ListNode>;

    /**
     * @brief Constructs a new ListNode object.
     *
     * @param data An integer representing the data associated with the node instance
     */
    explicit ListNode(int data = 0);

    /**
     * @brief Overloads the << operator to print the node data.
     *
     * @param os The output stream
     * @param node The node to be printed
     * @return std::ostream& The output stream with the node data
     */
    friend std::ostream &operator<<(std::ostream &os, const ListNode &node);

    int data; // The data stored in the node
    Ptr next; // Pointer to the next node
};

#endif
