#include "singly.hpp"

SinglyLinkedList::SinglyLinkedList()
{
    head = std::make_shared<ListNode>(); // Sentinel head node
    tail = head; // At the beginning, head and tail are the same
}

void SinglyLinkedList::add_to_end(ListNode::Ptr node_to_add)
{
    tail->next = node_to_add;
    tail = node_to_add;
}

void SinglyLinkedList::remove_from_end()
{
    if (head->next == nullptr)
    {
        return;
    }

    ListNode::Ptr current = head;
    while (current->next != tail)
    {
        current = current->next;
    }

    current->next = nullptr;
    tail = current;
}

void SinglyLinkedList::add_to_start(ListNode::Ptr node_to_add)
{
    node_to_add->next = head->next;
    head->next = node_to_add;

    if (tail == head)
    {
        tail = node_to_add;
    }
}

void SinglyLinkedList::remove_from_start()
{
    if (head->next == nullptr)
    {
        return;
    }

    ListNode::Ptr node_to_remove = head->next;
    head->next = node_to_remove->next;

    if (head->next == nullptr)
    {
        tail = head;
    }
}

void SinglyLinkedList::add_at_index(int index, ListNode::Ptr node_to_add)
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

    if (current == nullptr)
    {
        throw std::out_of_range("Index out of bounds");
    }

    node_to_add->next = current->next;
    current->next = node_to_add;

    if (node_to_add->next == nullptr)
    {
        tail = node_to_add;
    }
}

void SinglyLinkedList::remove_at_index(int index)
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

    if (current->next == nullptr)
    {
        throw std::out_of_range("Index out of bounds");
    }

    ListNode::Ptr node_to_remove = current->next;
    current->next = node_to_remove->next;

    if (node_to_remove == tail)
    {
        tail = current;
    }
}

void SinglyLinkedList::display() const
{
    ListNode::Ptr current = head->next;
    while (current != nullptr)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "None" << std::endl;
}
