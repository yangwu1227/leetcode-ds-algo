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
