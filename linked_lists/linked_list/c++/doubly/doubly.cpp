// doubly.cpp
#include "doubly.hpp"
#include <memory>
#include <iostream>

DoublyLinkedList::DoublyLinkedList()
{
    head = std::make_shared<ListNode>(); // Sentinel head node
    tail = std::make_shared<ListNode>(); // Sentinel tail node
    head->next = tail;
    tail->prev = head;
}

void DoublyLinkedList::add_to_end(ListNode::Ptr node_to_add)
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

    ListNode::Ptr node_to_remove = tail->prev;
    node_to_remove->prev->next = tail;
    tail->prev = node_to_remove->prev;
}

void DoublyLinkedList::add_to_start(ListNode::Ptr node_to_add)
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

    ListNode::Ptr node_to_remove = head->next;
    node_to_remove->next->prev = head;
    head->next = node_to_remove->next;
}

void DoublyLinkedList::add_at_index(int index, ListNode::Ptr node_to_add)
{
    if (index < 0)
    {
        throw std::out_of_range("Index must be non-negative");
    }

    ListNode::Ptr current = head;
    int current_index = 0;

    while (current != nullptr && current_index < index)
    {
        current = current->next;
        ++current_index;
    }

    if (current == nullptr || current == tail)
    {
        throw std::out_of_range("Index out of bounds");
    }

    node_to_add->next = current->next;
    node_to_add->prev = current;
    current->next->prev = node_to_add;
    current->next = node_to_add;
}

void DoublyLinkedList::remove_at_index(int index)
{
    if (index < 0)
    {
        throw std::out_of_range("Index must be non-negative");
    }

    ListNode::Ptr current = head;
    int current_index = 0;

    while (current->next != nullptr && current_index < index)
    {
        current = current->next;
        ++current_index;
    }

    if (current->next == nullptr || current->next == tail)
    {
        throw std::out_of_range("Index out of bounds");
    }

    ListNode::Ptr node_to_remove = current->next;
    current->next = node_to_remove->next;
    node_to_remove->next->prev = current;
}

void DoublyLinkedList::display() const
{
    ListNode::Ptr current = head->next;
    while (current != tail)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "None" << std::endl;
}
