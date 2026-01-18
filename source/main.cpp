/**
 * @file main.cpp
 * @brief Main entry point for graph analyzer application
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#include <iostream>
#include <exception>
#include "parser.hpp"
#include "loader.hpp"
#include "validator.hpp"
#include "kosaraju.hpp"
#include "router.hpp"
#include "printer.hpp"

int main(int argc, char* argv[]) {
  try {
    // 1. Parse Arguments
    auto [filename, from, to] = parse_arguments(argc, argv);

    // 2. Load Matrix
    matrix_t matr = load_matrix(filename);

    // 3. Validate
    validate(matr, from, to);

    // 4. Compute Route (Algorithm selected internally)
    auto [weight, route] = compute_route(matr, from, to);

    // 5. Compute Components
    components_t components = compute_components(matr);

    // 6. Print Results
    print_shortest_route(weight, route);
    print_components(components);

    return 0;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
}
