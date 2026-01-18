/**
 * @file validator.hpp
 * @brief Input data validator
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include "types.hpp"

/**
 * @brief Validate matrix and node indices
 * @param matr Adjacency matrix
 * @param from Source node
 * @param to Target node
 * @throws std::runtime_error on validation failure
 */
void validate(const matrix_t& matr, node_name_t from, node_name_t to);

#endif // VALIDATOR_HPP
