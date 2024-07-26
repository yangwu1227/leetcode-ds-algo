// simplify_path.hpp
#ifndef SIMPLIFY_PATH_HPP
#define SIMPLIFY_PATH_HPP
#include <string>

/**
 * @brief Given an absolute path for a Unix-style file system, which begins with a slash '/', transform
 * this path into its simplified canonical path.
 *
 * @param path A valid absolute Unix path
 * @return std::string The simplified canonical path
 */
std::string simplifyPath(const std::string &path);

#endif
