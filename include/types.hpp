/**
 * @file types.hpp
 * @brief Type definitions for graph analyzer application
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#ifndef TYPES_HPP
#define TYPES_HPP

#include <vector>
#include <set>
#include <limits>
#include "matrix.h"
#include "graph.hpp"

using node_name_t = std::size_t;
using weight_t = double;
using matrix_t = linalg::Matrix;

template <typename TValue>
using graph_t = graph::Graph<node_name_t, TValue, weight_t>;

using route_t = std::vector<node_name_t>;
using components_t = std::set<std::set<node_name_t>>;

constexpr weight_t INF = std::numeric_limits<weight_t>::infinity();
constexpr weight_t EPS = 1e-9;

#endif // TYPES_HPP
