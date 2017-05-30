/* --------------------------- */
// Wouter Dijkstra
// 1700101
// Jorn Bunk
// Week 1 opdracht 2
/* --------------------------- */

#include "house.hpp"
#include <iostream>

house::house(window& w, int x, int y, int size):
    // Create house based on size
    w(w),
    x(x),
    y(y),
    door(w, 25, 30, 35, 50),
    base(w, x, y, 50, 50),
    c_window(w, 30, 20, size),
    l_roof(w, 0, 30, 30, 0),
    r_roof(w, 30, 0, 60, 30)
{}

void house::print() {
    // Print every part of the house
    door.print();
    base.print();
    c_window.print();
    l_roof.print();
    r_roof.print();
}
