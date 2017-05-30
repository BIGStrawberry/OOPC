#ifndef SHIP_HPP
#define SHIP_HPP
#include <vector>
#include "window.hpp"
#include "vector.hpp"
#include "drawable.hpp"
#include "ball.hpp"

class Ship : public drawable {
private:
    std::vector<ball> bullets;
    const unsigned int MAX_BULLETS = 1000;
    int move_speed, attack_speed, attack_timer = 0;
    bool dir = false;
public:
    /**
     * @brief Constructor
     * @param w Window to draw on
     * @param location Position of ship
     * @param size Size of ship
     */
    Ship(window & w, const vector & location, const vector & size, const int& move_speed = 3, const int& attack_speed = 1);
    
    /**
     * @brief Draw the ship
     * @details Draw the ship at the given location
     */
    void draw();

    /**
     * @brief Updates ship & bullets
     * @details Updates the ship & bullets, moves their location.
     */
    void update() override;
    void interact( drawable & other ) override;
};

#endif // SHIP_HPP
