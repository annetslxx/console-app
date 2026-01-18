/**
 * @file loader.cpp
 * @brief Matrix loader implementation
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#include "loader.hpp"
#include <fstream>
#include <stdexcept>

matrix_t load_matrix(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("File not found: " + filename);
  }

  matrix_t matr;
  file >> matr;
  return matr;
}
