/**
 * @file spfa.hpp
 * @brief SPFA (Shortest Path Faster Algorithm) for graphs with negative weights
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#ifndef SPFA_HPP
#define SPFA_HPP

#include "types.hpp"

/**
 * @brief Find shortest path using SPFA algorithm
 * @param matr Adjacency matrix (may have negative weights)
 * @param from Source node
 * @param to Target node
 * @return Pair of (path weight, node sequence)
 * @note Returns (-INF, {from, to}) if negative cycle detected
 * @note Returns (INF, {from, to}) if no path exists
 */
std::pair<weight_t, route_t>
spfa(const matrix_t& matr, node_name_t from, node_name_t to) noexcept;

#endif // SPFA_HPP
