/* --------------------------- */
// Wouter Dijkstra
// 1700101
// Jorn Bunk
// Week 1 opdracht 1
/* --------------------------- */

#include "filled_rectangle.hpp"

void filled_rectangle::print(){
  
   int x0 = start_x;
   int y0 = start_y;
   int x1 = end_x;
   int y1 = end_y;
   
   for (int x = x0; x < x1; ++x) {
       for (int y = y0; y < y1; ++y) {
           w.draw(x, y);
       }
   }
}
