#ifndef WALL_HPP
#define WALL_HPP
#include "rectangle.hpp"
#include "vector.hpp"

class Wall : public rectangle {
private:
    vector start;
    bool filled = true;
    int toggle_interval;
    int toggle_time = 0;
public:
    /**
     * @brief constructor
     * @param w Window to draw on
     * @param start Start vector
     * @param end End vector
     * @param bounce Bounce direction
     * @param toggle_interval Number of "frames" before the filled rectangle is inverted, 5 by default
     */
    Wall(window& w, const vector& start, const vector& end, const vector& bounce, const int& toggle_interval = 5);
    
    /**
     * @brief Draws a wall
     * @details
     *      Draws a rectangle at given coordinate vectors (start, end).
     *      If filled is true, it fills the rectangle.
     */
    void draw() override;
    
    /**
     * @brief Updates the wall
     * @details Increments the toggle_time & inverts the filled rectangle when its greater than the interval
     */    
    void update() override;
};

#endif // WALL_HPP
