// main.cpp
#include "queue_deque.hpp"
#include <iostream>
#include <stdlib.h> // For rand() and srand()
#include <stdio.h>  // For NULL
#include <time.h>   // For time

int main()
{

    // Set random seed
    QueueDeque queue = QueueDeque();
    srand(time(NULL));
    int numElements = rand() % 1000 + 1;
    for (int i = 0; i < numElements; i++)
    {
        int x = rand() % 1000 + 1;
        queue.push(x);
    }
    std::cout << "Queue after pushing " << numElements << " random integers: " << queue << '\n';
    std::cout << "Popping the front of the queue: " << queue.pop() << '\n';
    std::cout << "Queue after popping the front: " << queue << '\n';
    std::cout << "Peek the front of the queue: " << queue.peek() << '\n';
    std::cout << "Popping the front of the queue: " << queue.pop() << '\n';
    std::cout << "Queue after popping the front: " << queue << '\n';
    std::cout << "Peek the front of the queue: " << queue.peek() << '\n';
    std::cout << "Check if the queue is empty: " << (queue.empty() ? "Empty" : "Not Empty") << '\n';
    std::cout << "Popping all elements at the front" << '\n';
    while (!queue.empty())
    {
        queue.pop();
    }
    std::cout << "Check if the queue is empty: " << (queue.empty() ? "Empty" : "Not Empty") << '\n';

    return 0;
}
