/**
 * @file converter.hpp
 * @brief Matrix to graph converter
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include "types.hpp"
#include <cmath>

/**
 * @brief Convert adjacency matrix to graph
 * @tparam TValue Node value type
 * @param matr Adjacency matrix
 * @return Graph with nodes and edges
 */
template <typename TValue>
graph_t<TValue> create_graph(const matrix_t& matr) noexcept {
  graph_t<TValue> g;
  std::size_t n = matr.rows();

  // Create nodes
  for (std::size_t i = 0; i < n; ++i) {
    g.insert_node(i, TValue{});
  }

  // Create edges (skip zero weights and very large "infinity" weights)
  for (std::size_t i = 0; i < n; ++i) {
    for (std::size_t j = 0; j < n; ++j) {
      weight_t w = matr(i, j);
      // Skip edges with zero weight or weight > 1e100 (effectively infinity)
      if (std::abs(w) > EPS && std::abs(w) < 1e100) {
        g.insert_edge({i, j}, w);
      }
    }
  }

  return g;
}

#endif // CONVERTER_HPP
