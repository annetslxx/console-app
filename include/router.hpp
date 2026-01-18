/**
 * @file router.hpp
 * @brief Algorithm selection and routing
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "types.hpp"

/**
 * @brief Detect if matrix has negative weights
 */
bool has_negative_weights(const matrix_t& matr) noexcept;

/**
 * @brief Compute shortest path using appropriate algorithm
 */
std::pair<weight_t, route_t>
compute_route(const matrix_t& matr, node_name_t from, node_name_t to) noexcept;

#endif // ROUTER_HPP
