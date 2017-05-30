#include "window.hpp"
#include "ship.hpp"
#include "ball.hpp"
#include "wall.hpp"
#include "victim.hpp"

int main(){
    /*
     * Dimensions of the screen, larger dimensions will increase clearing times and decrease 'F'PS
     */
    const int WIDTH = 128;
    const int HEIGHT = 64;
    
    window w( vector( WIDTH, HEIGHT ), 2 );

    /*
     * Thickness of the wall in pixels
     */
    const int WALL_SIZE = 4;
    
    /*
     * Top, bottom, right & left walls
     */
    Wall wallTop    (w, vector(0, 0),                  vector(WIDTH - 1, WALL_SIZE - 1),  vector(1, -1), 1);
    Wall wallRight  (w, vector(WIDTH - WALL_SIZE, 0),  vector(WIDTH - 1, HEIGHT - 1),     vector(-1, 1), 2);
    Wall wallBottom (w, vector(0, HEIGHT - WALL_SIZE), vector(WIDTH - 1, HEIGHT - 1),     vector(1, -1), 3);
    Wall wallLeft   (w, vector(0, 0),                  vector(WALL_SIZE - 1, HEIGHT - 1), vector(-1, 1));
    
    /*
     * Object ship that shoots the balls
     */ 
    Ship ship(w, vector(5, 5), vector(15, 10));
    
    /*
     * Victim the balls will (slowly) kill
     */
    Victim victim(w, vector(WIDTH * 0.75, HEIGHT - (35 + WALL_SIZE)), vector(WIDTH * 0.75 + 5, HEIGHT - WALL_SIZE));

    /*
     * Array of all the drawable objects we will use
     */
    drawable* objects[] = { &wallTop, &wallRight, &wallBottom, &wallLeft, &victim, &ship };

    while(true) {
        /*
         * Clear Window (makes all pixels white, ..slow)
         */
        w.clear();
        
        /*
         * Renders all objects that are inside the drawable objects[] array
         */
        for( auto & p : objects ){
            p->draw();
        }

        /*
         * Wait 100ms for the Window to clear
         */
        wait_ms( 100 );

        /*
         * Update all objects that are inside the drawable objects[] array
         */
        for( auto & p : objects ){
            p->update();
        }

        /*
         * Handle Object Collision
         */
        for( auto & p : objects ){
            for( auto & other : objects ){
                p->interact( *other );
            } 
        }
   }
}

