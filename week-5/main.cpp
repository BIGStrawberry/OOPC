#include <hwlib.hpp>
#include "two_pin_in.hpp"
#include "pin_out_invert.hpp"
#include "pin_out_all.hpp"

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
    auto buttonLeft = hwlib::target::pin_in_out(hwlib::target::pins::d26);
    buttonLeft.direction_set_input();

    auto buttonRight = hwlib::target::pin_in_out(hwlib::target::pins::d27);
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
    
    auto led0 = hwlib::target::pin_out(hwlib::target::pins::d22);
    auto led1 = hwlib::target::pin_out(hwlib::target::pins::d23);
    auto led2 = hwlib::target::pin_out(hwlib::target::pins::d24);
    auto led3 = hwlib::target::pin_out(hwlib::target::pins::d25);

    auto ds   = hwlib::target::pin_out( hwlib::target::pins::d5 );
    auto shcp = hwlib::target::pin_out( hwlib::target::pins::d7 );
    auto stcp = hwlib::target::pin_out( hwlib::target::pins::d6 );
    auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
        shcp, 
        ds, 
        hwlib::pin_in_dummy 
    );
    auto hc595 = hwlib::hc595( spi, stcp );
    
    hc595.p0.set(0);
    hc595.p1.set(0);
    hc595.p2.set(0);
    hc595.p3.set(0);
    
    auto leds = hwlib::port_out_from_pins(hc595.p0, hc595.p1, hc595.p2, hc595.p3, led0, led1, led2, led3);
    
//    buttons(leds);
   
    auto led0Inverted = pin_out_invert(led0);
    auto led1Inverted = pin_out_invert(led1);
    auto led2Inverted = pin_out_invert(led2);
    auto led3Inverted = pin_out_invert(led3);

    auto out_all = pin_out_all(hc595.p0, hc595.p1, hc595.p2, hc595.p3, led0Inverted, led1Inverted, led2Inverted, led3Inverted);
//    auto out_all = pin_out_all(hc595.p0, hc595.p1, hc595.p2, hc595.p3, led0, led1, led2, led3);

    hwlib::blink(out_all);


}