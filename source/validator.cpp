/**
 * @file validator.cpp
 * @brief Validator implementation
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#include "validator.hpp"
#include <stdexcept>

void validate(const matrix_t& matr, node_name_t from, node_name_t to) {
  if (matr.empty()) {
    throw std::runtime_error("Matrix is empty");
  }

  if (matr.rows() != matr.columns()) {
    throw std::runtime_error("Matrix is not square");
  }

  if (from == to) {
    throw std::runtime_error("Source and target nodes must be different");
  }

  std::size_t n = matr.rows();
  if (from >= n) {
    throw std::runtime_error("Source node out of bounds");
  }
  if (to >= n) {
    throw std::runtime_error("Target node out of bounds");
  }
}
