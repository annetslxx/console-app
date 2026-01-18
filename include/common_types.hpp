#ifndef COMMON_TYPES_HPP
#define COMMON_TYPES_HPP

#include <set>
#include <vector>
#include <limits>

using node_name_t = int;
using weight_t = double;
using matrix_t = std::vector<std::vector<weight_t>>;

template <typename T>
class Graph;
template <typename T>
using graph_t = Graph<T>;

using components_t = std::set<std::set<node_name_t>>;

using route_t = std::vector<node_name_t>;

constexpr weight_t INF = std::numeric_limits<weight_t>::infinity();
constexpr weight_t EPS = 1e-9;

#endif // COMMON_TYPES_HPP