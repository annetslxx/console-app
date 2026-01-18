/**
 * @file parser.hpp
 * @brief Command line argument parser
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "types.hpp"
#include <tuple>

/**
 * @brief Parse command line arguments
 * @param argc Argument count
 * @param argv Argument values
 * @return Tuple of (filename, from_node, to_node)
 * @throws std::runtime_error on invalid arguments
 */
std::tuple<std::string, node_name_t, node_name_t>
parse_arguments(int argc, char* argv[]);

#endif // PARSER_HPP
