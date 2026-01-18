/**
 * @file dijkstra.hpp
 * @brief Dijkstra shortest path algorithm
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "types.hpp"

/**
 * @brief Find shortest path using Dijkstra algorithm
 * @param matr Adjacency matrix (non-negative weights)
 * @param from Source node
 * @param to Target node
 * @return Pair of (path weight, node sequence)
 * @note Returns (INF, {from, to}) if no path exists
 */
std::pair<weight_t, route_t>
dijkstra(const matrix_t& matr, node_name_t from, node_name_t to) noexcept;

#endif // DIJKSTRA_HPP
