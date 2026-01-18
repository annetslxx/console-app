/**
 * @file loader.hpp
 * @brief Matrix file loader
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#ifndef LOADER_HPP
#define LOADER_HPP

#include "types.hpp"
#include <string>

/**
 * @brief Load adjacency matrix from file
 * @param filename Path to matrix file
 * @return Adjacency matrix
 * @throws std::runtime_error on file errors
 */
matrix_t load_matrix(const std::string& filename);

#endif // LOADER_HPP
