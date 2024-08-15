// visible_persons.hpp
#ifndef VISIBLE_PERSONS_HPP
#define VISIBLE_PERSONS_HPP
#include <vector>

/**
 * @brief Calculate the number of people each person can see to their right in a queue.
 *
 * This function uses a monotonic stack approach to determine how many people
 * each person in the queue can see to their right. A person can see another person
 * to their right if all people between them are shorter than both of them.
 *
 * @param heights A vector of distinct integers where each integer represents the height of a person standing in a queue
 * @return std::vector<int> A vector of integers where the ith element represents the number of people the ith person can see to their right in the queue
 */
std::vector<int> visiblePersons(const std::vector<int> &heights);

#endif
