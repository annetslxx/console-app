/**
 * @file kosaraju.hpp
 * @brief Kosaraju-Sharir algorithm for strongly connected components
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#ifndef KOSARAJU_HPP
#define KOSARAJU_HPP

#include "types.hpp"

/**
 * @brief Compute strongly connected components using Kosaraju's algorithm
 * @param matr Adjacency matrix
 * @return Set of strongly connected components
 */
components_t compute_components(const matrix_t& matr) noexcept;

#endif // KOSARAJU_HPP
