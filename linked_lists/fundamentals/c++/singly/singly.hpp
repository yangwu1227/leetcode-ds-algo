// singly.hpp
#ifndef SINGLY_HPP
#define SINGLY_HPP

class Nodes
{
public:
    /**
     * @brief Construct a new Nodes object.
     *
     * @param data An integer
     */
    Nodes(int data);

    /**
     * @brief Get the data of the node. This function does not modify the state of the object.
     *
     * @return The integer data of the node
     */
    int getData() const;

    /**
     * @brief Set the data of the node.
     *
     * @param data An integer to set the node's data to
     */
    void setData(int data);

    /**
     * @brief Get the next node. This function does not modify the state of the object.
     *
     * @return A pointer to the next Nodes object
     */
    Nodes *getNext() const;

    /**
     * @brief Set the 'next' pointer of this current node to point to the next node.
     *
     * @param nextNode A pointer to the next Nodes object
     */
    void setNext(Nodes *nextNode);

private:
    int data;
    Nodes *next;
};

#endif
