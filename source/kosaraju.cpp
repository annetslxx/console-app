/**
 * @file kosaraju.cpp
 * @brief Kosaraju-Sharir algorithm implementation
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#include "kosaraju.hpp"
#include "converter.hpp"
#include <algorithm>
#include <stack>
#include <functional>

// Node data structure for Kosaraju algorithm
struct NodeKosaraju {
  bool visited = false;
};

// DFS-based topological sort
std::vector<node_name_t> topology_sort(graph_t<NodeKosaraju>& g) {
  std::vector<node_name_t> order;

  // Mark all as unvisited
  for (auto it = g.begin(); it != g.end(); ++it) {
    it->second.value().visited = false;
  }

  // Recursive DFS helper
  std::function<void(node_name_t)> dfs = [&](node_name_t node) {
    auto it = g.find(node);
    if (it == g.end()) return;

    it->second.value().visited = true;

    // Visit all neighbors
    for (auto& [neighbor, weight] : it->second) {
      auto neighbor_it = g.find(neighbor);
      if (neighbor_it != g.end() && !neighbor_it->second.value().visited) {
        dfs(neighbor);
      }
    }

    // Add to order after all neighbors are processed
    order.push_back(node);
  };

  // DFS from each unvisited node
  for (auto it = g.begin(); it != g.end(); ++it) {
    if (!it->second.value().visited) {
      dfs(it->first);
    }
  }

  std::reverse(order.begin(), order.end());
  return order;
}

// DFS to collect component
std::set<node_name_t> dfs_component(graph_t<NodeKosaraju>& g, node_name_t start) {
  std::set<node_name_t> component;

  // Recursive DFS helper
  std::function<void(node_name_t)> dfs = [&](node_name_t node) {
    auto it = g.find(node);
    if (it == g.end() || !it->second.value().visited) return;

    it->second.value().visited = false;  // Mark as visited for this pass
    component.insert(node);

    // Visit all neighbors
    for (auto& [neighbor, weight] : it->second) {
      dfs(neighbor);
    }
  };

  dfs(start);
  return component;
}

// Main algorithm
components_t components_by_dfs(graph_t<NodeKosaraju>& g,
                               const std::vector<node_name_t>& order) {
  components_t result;

  // Mark all nodes as visited initially (they will be marked false during DFS)
  for (auto it = g.begin(); it != g.end(); ++it) {
    it->second.value().visited = true;
  }

  for (node_name_t node : order) {
    auto it = g.find(node);
    if (it != g.end() && it->second.value().visited) {
      std::set<node_name_t> component = dfs_component(g, node);
      if (!component.empty()) {
        result.insert(component);
      }
    }
  }

  return result;
}

components_t compute_components(const matrix_t& matr) noexcept {
  // Step 1: Create graphs
  graph_t<NodeKosaraju> g_original = create_graph<NodeKosaraju>(matr);
  matrix_t matr_t = linalg::transpose(matr);
  graph_t<NodeKosaraju> g_inverted = create_graph<NodeKosaraju>(matr_t);

  // Step 2: Topological sort
  std::vector<node_name_t> sorted = topology_sort(g_inverted);

  // Step 3: Find components
  return components_by_dfs(g_original, sorted);
}
