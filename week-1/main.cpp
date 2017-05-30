/* --------------------------- */
// Wouter Dijkstra
// 1700101
// Jorn Bunk
// Week 1 opdracht 1 & 2
/* --------------------------- */

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "house.hpp"
#include "filled_rectangle.hpp"

int main(int argc, char **argv){
    window w( 128, 64, 2 );

    house house1(w, 10, 10, 5);
    house1.print();
   
    return 0;
}
