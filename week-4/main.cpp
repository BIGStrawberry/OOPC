#include "hwlib.hpp"

/**
 * @brief Blinks LEDs
 * @param leds Container with the leds
 * @param ms Delay in ms between shifts
 * 
 * @details
 * This function blinks LEDs in a specific pattern (KITT)
 *    
 *          X X - - 
 *          - X X - 
 *          - - X X
 *          - X X - 
 *          X X - - 
 *    
 *    X equals an active LED
 *    - equals an inactive LED
 */
 void kittOnce(hwlib::port_out& leds, const int& ms) {
    /*
     * Loop through LEDs from left to right. 
     * (excluding -1, because we turn two on at a time and the pattern is off otherwise)
     */
    for(unsigned int i = 0; i < leds.number_of_pins() - 1; ++i) {
        leds.set(0x03 << i);
        hwlib::wait_ms(ms);
    }

    /*
     * Loop through the LEDs from right to left, to get back to the first LED
     */
    for(unsigned int i = leds.number_of_pins() - 3; i > 0; --i) {
        leds.set(0x03 << i);
        hwlib::wait_ms(ms);
    }
}

/**
 * @brief Blinks LEDs in a pattern
 * @param leds Container with the 4 leds
 * @param ms Delay in ms before shifting the LEDs
 * @param intervals Number of times we want the pattern to be repeated (-1 is infinite)
 * 
 * @details This function uses the kittOnce function to repeat the kitt patern as many times as specified
 */
void kitt(hwlib::port_out& leds, const int& ms, int intervals = -1) {
    /*
     * If interval is -1, it will loop forever
     */
    if (intervals == -1) {
        while(true) {  
            /*
             * Re-use kittOnce function from earlier
             */       
            kittOnce(leds, ms);
        }
    /*
     * If the integer inteverals is set to > 0, it will loop the amount it is set to
     */ 
    } else if (intervals > 0) {
        for (unsigned int i = 0; i < (unsigned)intervals; ++i) {
            /*
             * Re-use kittOnce function from earlier
             */ 
            kittOnce(leds, ms);
        }
    }
    
    /*
     * Turn off all the LEDs after the loops (0x00 == 0)
     */
    leds.set(0x00);
}


/**
 * @brief Makes LED's controlable with buttons
 * @param leds Container with the leds
 * 
 * @details
 * Press both buttons to break the while loop
 * Press the left button to turn off most right LED
 * Press the right button to turn on the most right LED
 */
void buttons(hwlib::port_out& leds) {

    /*
     * Define the buttons as input & define their PIN numbers
     */ 
    auto buttonLeft = hwlib::target::pin_in_out(hwlib::target::pins::d31);
    buttonLeft.direction_set_input();

    auto buttonRight = hwlib::target::pin_in_out(hwlib::target::pins::d30);
    buttonRight.direction_set_input();
    
    unsigned int mode = 0x00;
    unsigned int num = 0;
    
    bool pressed = false;

    while(true) {
        if (!buttonLeft.get() && !buttonRight.get()) {
            break;
        } else if (!buttonRight.get() && num < leds.number_of_pins() && !pressed) {
            /*
             * Some debugging text to console
             */ 
            hwlib::cout << " MORE++; ";
           
            /*
             * Setting this variable will prevent the "double pressing" of buttons.
             */ 
            pressed = true;
            
            ++num;
            
            /*
             * Display more LEDs
             */
            mode <<= 1;
            mode |= 1; // set lsb to 1
            
            /*
             * A small delay to give the hardware time to catch up
             */
            hwlib::wait_ms(100);
        } else if (!buttonLeft.get() && num > 0 && !pressed) {
            /*
            * Some debugging text to console
            */ 
            hwlib::cout << " LESS--; ";
            
            /*
             * Setting this variable will prevent the "double pressing" of buttons.
             */ 
            pressed = true;
            
            --num;
            
            /*
             * Display less LEDs
             */
            mode >>= 1;
            
            /*
             * A small delay to give the hardware time to catch up
             */
            hwlib::wait_ms(100);
        }
        
        /*
         * Buttons released
         */
        if(pressed && buttonRight.get() && buttonLeft.get()) {
            /*
             * Some debugging text to the console
             */
            hwlib::cout << " RELEASED ";
            
            /*
             * Set the "double pressing" flag back to false
             */ 
            pressed = false;
        
            /*
             * We didn't actually set the LEDs yet, we just set a variable.
             * So we're going to do that here
             */
            leds.set(mode);
        }
    }
    
    /*
     * Turn off all the LEDs after everything
     */ 
    leds.set(0x00);
}

int main( void ){
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    
    /*
     * Define the LEDs & their PIN numbers
     */
    auto led0 = hwlib::target::pin_out(hwlib::target::pins::d2);
    auto led1 = hwlib::target::pin_out(hwlib::target::pins::d3);
    auto led2 = hwlib::target::pin_out(hwlib::target::pins::d4);
    auto led3 = hwlib::target::pin_out(hwlib::target::pins::d5);

    /*
     * Put the leds in a container
     */ 
    auto leds = hwlib::port_out_from_pins( led0, led1, led2, led3 );
    
    /*
     * Will run the pattern once, with a delay in ms.
     */ 
    //kittOnce(leds, 1000);
    
    /* 
     * 2.4.3
     * Will run the pattern as many times as specified (-1 for infinity) with a delay in ms.
     */ 
    kitt(leds, 50, -1);    
    
    /*
     * 2.4.4
     * Will turn on more or less LEDs based on which button gets pressed
     */ 
    //buttons(leds);   
}