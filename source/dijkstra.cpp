/**
 * @file dijkstra.cpp
 * @brief Dijkstra algorithm implementation
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#include "dijkstra.hpp"
#include "converter.hpp"
#include <algorithm>
#include <optional>

// Node data structure for Dijkstra algorithm
struct NodeDijkstra {
  weight_t label = INF;
  bool visited = false;
  std::optional<node_name_t> previous;
};

// Priority Queue Helper
class NodesToBeVisited {
public:
  using graph_iterator = typename graph_t<NodeDijkstra>::iterator;

  explicit NodesToBeVisited(graph_t<NodeDijkstra>& g) {
    for (auto it = g.begin(); it != g.end(); ++it) {
      m_unvisited.push_back(it);
    }
  }

  graph_iterator pop_min_weight() {
    auto min_it = std::min_element(m_unvisited.begin(), m_unvisited.end(),
      [](const auto& a, const auto& b) {
        return a->second.value().label < b->second.value().label;
      });

    auto result = *min_it;
    result->second.value().visited = true;
    m_unvisited.erase(min_it);
    return result;
  }

  bool empty() const { return m_unvisited.empty(); }

private:
  std::vector<graph_iterator> m_unvisited;
};

// Dijkstra step
void dijkstra_step(graph_t<NodeDijkstra>& g, NodesToBeVisited& queue) {
  auto current = queue.pop_min_weight();
  node_name_t u = current->first;
  NodeDijkstra& u_data = current->second.value();

  // Relax edges
  for (auto& [v, weight] : current->second) {
    auto v_it = g.find(v);
    NodeDijkstra& v_data = v_it->second.value();

    if (!v_data.visited) {
      weight_t new_label = u_data.label + weight;
      if (new_label < v_data.label) {
        v_data.label = new_label;
        v_data.previous = u;
      }
    }
  }
}

// Reconstruct path
route_t reconstruct_path(const graph_t<NodeDijkstra>& g,
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
dijkstra(const matrix_t& matr, node_name_t from, node_name_t to) noexcept {
  graph_t<NodeDijkstra> g = create_graph<NodeDijkstra>(matr);

  // Initialize source
  g.at(from).label = 0;

  // Create queue
  NodesToBeVisited queue(g);

  // Main loop
  while (!queue.empty()) {
    dijkstra_step(g, queue);
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
