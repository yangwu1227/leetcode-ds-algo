// remove_stars.hpp
#ifndef REMOVE_STARS_HPP
#define REMOVE_STARS_HPP
#include <string>

/**
 * @brief For a string `s` with stars (*), repeatedly remove each star and its closest
 * preceding character until no stars remain.
 *
 * @param s A string consisting of lower case english letters and "*"
 * @return std::string A new string with all characters preceding "*" removed
 */
std::string removeStars(const std::string &s);

#endif
