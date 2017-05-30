/* --------------------------- */
// Wouter Dijkstra
// 1700101
// Jorn Bunk
// Week 1 opdracht 2
/* --------------------------- */

#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "window.hpp"
#include "filled_rectangle.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "line.hpp"

/**
 * @class House
 * @author Wouter
 * @date 30-4-2017
 * @file house.hpp
 * @brief Printable house
 */
class house {
    const window& w;
    int x, y;
    filled_rectangle door;
    rectangle base;
    circle c_window;
    line r_roof, l_roof;
    
public:

    /**
     * @brief constructor
     * @param w window to draw on
     * @param x position
     * @param y position
     * @param size of house
     */
    house(window& w, int x, int y, int size);
    
    /**
     * @brief render house 
     */
    void print();
};

#endif // HOUSE_HPP
