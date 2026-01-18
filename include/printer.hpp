/**
 * @file printer.hpp
 * @brief Output formatting and printing
 * @author Student
 * @date 2025-01-18
 * @version 1.0
 */

#ifndef PRINTER_HPP
#define PRINTER_HPP

#include "types.hpp"

/**
 * @brief Print shortest route result
 * @param weight Path weight (INF if no path, -INF if negative cycle)
 * @param route Node sequence
 */
void print_shortest_route(weight_t weight, const route_t& route);

/**
 * @brief Print strongly connected components
 * @param components Set of components
 */
void print_components(const components_t& components);

#endif // PRINTER_HPP
