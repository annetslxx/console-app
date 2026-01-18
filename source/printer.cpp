/**
 * @file printer.cpp
 * @brief Printer implementation
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#include "printer.hpp"
#include <iostream>
#include <limits>
#include <cmath>

void print_shortest_route(weight_t weight, const route_t& route) {
  // Check for infinity (both actual and very large numbers)
  if ((std::isinf(weight) || weight > 1e100) && weight > 0) {
    std::cout << "There is no way from '" << route.front()
              << "' to '" << route.back() << "'" << std::endl;
  }
  else if (std::isinf(weight) && weight < 0) {
    std::cout << "There is negative cycle on the way from '" << route.front()
              << "' to '" << route.back() << "'" << std::endl;
  }
  else {
    std::cout << "Shortest route (weight " << weight << "):";
    for (auto node : route) {
      std::cout << " " << node;
    }
    std::cout << std::endl;
  }
}

void print_components(const components_t& components) {
  std::cout << "Strongly connected components:" << std::endl;
  std::size_t idx = 0;
  for (const auto& comp : components) {
    std::cout << idx << ")";
    for (auto node : comp) {
      std::cout << " " << node;
    }
    std::cout << std::endl;
    idx++;
  }
}
