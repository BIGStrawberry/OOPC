/* --------------------------- */
// Wouter Dijkstra
// 1700101
// Jorn Bunk
// Week 1 opdracht 1
/* --------------------------- */
#ifndef FILLED_RECTANGLE_HPP
#define FILLED_RECTANGLE_HPP

#include "window.hpp"
#include "line.hpp"


/**
 * @class filled_rectangle
 * @author Wouter
 * @date 30-4-2017
 * @file filled_rectangle.hpp
 * @brief Printable filled rectangle
 */
class filled_rectangle {
private:
   int start_x;
   int start_y; 
   int end_x;
   int end_y;
   window & w;
public:
    /**
     * @brief constructor
     * @param w window to draw on
     * @param start_x position X to start drawing
     * @param start_y position Y to start drawing
     * @param end_x   position X to end drawing
     * @param end_y   position Y to end drawing
     */
   filled_rectangle( window & w, int start_x, int start_y, int end_x, int end_y ):
      start_x( start_x ),
      start_y( start_y ),
      end_x( end_x ),
      end_y( end_y ),
      w( w )
   {}
   void print();
};

#endif // FILLED_RECTANGLE_HPP
