#include "victim.hpp"

Victim::Victim(window & w, const vector & start, const vector & end):
    rectangle(w, start, end)
{}

void Victim::update() {
    /*
     * Check to see if there's still something left to decrease/remove
     */ 
    if (hit && (end.x - location.x > 0 || end.y - location.y > 0)) {
        
        /*
         * Make our victim smaller in size
         */
        location.x++;
        location.y++;
        end.x--;
        end.y--;

        /*
         * Remove the last pixel
         */ 
        if (end.x - location.x <= 0) {
            end.x = location.x;
        } 
        
        if (end.y - location.y <= 0) {
            end.y = location.y;
        }

        top.setLocation(location);
        top.setEnd(vector(end.x, location.y));
        
        right.setLocation(vector(end.x, location.y));
        right.setEnd(end);
        
        bottom.setLocation(vector(location.x, end.y));
        bottom.setEnd(end);
    
        left.setLocation(location);
        left.setEnd(vector(location.x, end.y));
    }
}