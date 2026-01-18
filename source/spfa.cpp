/**
 * @file spfa.cpp
 * @brief SPFA algorithm implementation
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#include "spfa.hpp"
#include "converter.hpp"
#include <deque>
#include <optional>
#include <algorithm>

// Node data structure for SPFA algorithm
struct NodeSPFA {
  weight_t label = INF;
  std::size_t update_count = 0;
  bool in_queue = false;
  std::optional<node_name_t> previous;
};

// Queue Helper
class NodeQueue {
public:
  using graph_iterator = typename graph_t<NodeSPFA>::iterator;

  void push(graph_iterator it) {
    it->second.value().in_queue = true;
    m_queue.push_back(it);
  }

  graph_iterator pop() {
    auto it = m_queue.front();
    m_queue.pop_front();
    it->second.value().in_queue = false;
    return it;
  }

  bool empty() const { return m_queue.empty(); }

private:
  std::deque<graph_iterator> m_queue;
};

// SPFA step
bool spfa_step(graph_t<NodeSPFA>& g, NodeQueue& queue, std::size_t n) {
  auto current = queue.pop();
  node_name_t u = current->first;
  NodeSPFA& u_data = current->second.value();

  for (auto& [v, weight] : current->second) {
    auto v_it = g.find(v);
    NodeSPFA& v_data = v_it->second.value();

    weight_t new_label = u_data.label + weight;
    if (new_label < v_data.label) {
      v_data.label = new_label;
      v_data.previous = u;
      v_data.update_count++;

      // Negative cycle detection
      if (v_data.update_count >= n) {
        return false;  // Cycle detected
      }

      if (!v_data.in_queue) {
        queue.push(v_it);
      }
    }
  }

  return true;  // No cycle
}

// Reconstruct path
route_t reconstruct_path(const graph_t<NodeSPFA>& g,
                         node_name_t from, node_name_t to) {
  route_t path;
  std::optional<node_name_t> current = to;

  while (current.has_value()) {
    path.push_back(*current);
    if (*current == from) break;
    current = g.at(*current).previous;
  }

  std::reverse(path.begin(), path.end());
  return path;
}

std::pair<weight_t, route_t>
spfa(const matrix_t& matr, node_name_t from, node_name_t to) noexcept {
  graph_t<NodeSPFA> g = create_graph<NodeSPFA>(matr);
  std::size_t n = matr.rows();

  // Check for negative self-loop
  if (matr(from, from) < -EPS) {
    return {-INF, {from, to}};
  }

  // Initialize source
  g.at(from).label = 0;

  // Create queue and add source
  NodeQueue queue;
  queue.push(g.find(from));

  // Main loop
  while (!queue.empty()) {
    if (!spfa_step(g, queue, n)) {
      // Negative cycle detected
      return {-INF, {from, to}};
    }
  }

  // Get result
  weight_t weight = g.at(to).label;
  route_t path;

  if (weight < INF - EPS) {
    path = reconstruct_path(g, from, to);
  } else {
    path = {from, to};
  }

  return {weight, path};
}
