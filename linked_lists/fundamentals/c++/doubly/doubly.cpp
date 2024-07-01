// doubly.cpp
#include "doubly.hpp"
#include <memory>
#include <iostream>

DoublyLinkedList::DoublyLinkedList()
{
    head = std::make_shared<Node>(); // Sentinel head node
    tail = std::make_shared<Node>(); // Sentinel tail node
    head->next = tail;
    tail->prev = head;
}

void DoublyLinkedList::add_to_end(Node::Ptr node_to_add)
{
    node_to_add->next = tail;
    node_to_add->prev = tail->prev;
    tail->prev->next = node_to_add;
    tail->prev = node_to_add;
}

void DoublyLinkedList::remove_from_end()
{
    if (head->next == tail)
    {
        return;
    }

    Node::Ptr node_to_remove = tail->prev;
    node_to_remove->prev->next = tail;
    tail->prev = node_to_remove->prev;
}

void DoublyLinkedList::add_to_start(Node::Ptr node_to_add)
{
    node_to_add->prev = head;
    node_to_add->next = head->next;
    head->next->prev = node_to_add;
    head->next = node_to_add;
}

void DoublyLinkedList::remove_from_start()
{
    if (head->next == tail)
    {
        return;
    }

    Node::Ptr node_to_remove = head->next;
    node_to_remove->next->prev = head;
    head->next = node_to_remove->next;
}

void DoublyLinkedList::display() const
{
    Node::Ptr current = head->next;
    while (current != tail)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "None" << std::endl;
}
