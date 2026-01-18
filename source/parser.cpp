/**
 * @file parser.cpp
 * @brief Command line argument parser implementation
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#include "parser.hpp"
#include <stdexcept>
#include <string>
#include <optional>

std::tuple<std::string, node_name_t, node_name_t>
parse_arguments(int argc, char* argv[]) {
  if (argc != 7) {
    throw std::runtime_error("Usage: console_app --file <path> --from <N> --to <M>");
  }

  std::string filename;
  std::optional<node_name_t> from, to;
  bool file_set = false, from_set = false, to_set = false;

  for (int i = 1; i < argc; i += 2) {
    std::string flag = argv[i];

    if (flag == "--file") {
      if (file_set) throw std::runtime_error("Duplicate argument: --file");
      filename = argv[i + 1];
      file_set = true;
    } else if (flag == "--from") {
      if (from_set) throw std::runtime_error("Duplicate argument: --from");
      try {
        from = std::stoull(argv[i + 1]);
      } catch (const std::exception&) {
        throw std::runtime_error("Invalid number format for --from");
      }
      from_set = true;
    } else if (flag == "--to") {
      if (to_set) throw std::runtime_error("Duplicate argument: --to");
      try {
        to = std::stoull(argv[i + 1]);
      } catch (const std::exception&) {
        throw std::runtime_error("Invalid number format for --to");
      }
      to_set = true;
    } else {
      throw std::runtime_error("Unknown argument: " + flag);
    }
  }

  if (!file_set || !from || !to) {
    throw std::runtime_error("Missing required arguments");
  }

  return {filename, *from, *to};
}
