/**
 * @file router.cpp
 * @brief Router implementation
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#include "router.hpp"
#include "dijkstra.hpp"
#include "spfa.hpp"
#include <cmath>

bool has_negative_weights(const matrix_t& matr) noexcept {
  for (std::size_t i = 0; i < matr.rows(); ++i) {
    for (std::size_t j = 0; j < matr.columns(); ++j) {
      if (matr(i, j) < -EPS) return true;
    }
  }
  return false;
}

std::pair<weight_t, route_t>
compute_route(const matrix_t& matr, node_name_t from, node_name_t to) noexcept {
  if (has_negative_weights(matr)) {
    return spfa(matr, from, to);
  } else {
    return dijkstra(matr, from, to);
  }
}
