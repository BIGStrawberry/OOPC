//#include "hwlib.hpp"
//
//int main( void ){	
//    
//   // kill the watchdog
//   WDT->WDT_MR = WDT_MR_WDDIS;
//   
//   namespace target = hwlib::target;
//   
//   auto scl = target::pin_oc( target::pins::scl );
//   auto sda = target::pin_oc( target::pins::sda );
//   
//   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
//   
//   auto display = hwlib::glcd_oled( i2c_bus, 0x3c );  
//     
//   display.clear();
//   
//   for (;;) {
//       for (uint16_t y = 0; y < display.size.y; y++) {
//           display.clear();
//           for( uint16_t x = 0; x < display.size.x; x++ ){
//               display.write( hwlib::location( x, y), hwlib::black );
//           }
//       }
//   }
//}

#include "hwlib.hpp"
#include "mirror.hpp"

int main( void ){	
   
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
      // wait for the PC console to start
   hwlib::wait_ms( 500 );   
   
   namespace target = hwlib::target;
   
   auto scl     = target::pin_oc( target::pins::scl );
   auto sda     = target::pin_oc( target::pins::sda );
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
   auto oled    = hwlib::glcd_oled( i2c_bus, 0x3c ); 
   
   auto font    = hwlib::font_default_8x8();
   auto display = hwlib::window_ostream( oled, font );
    
      
   for (int i = 0; i < 1000; ++i) {
      display 
          << "\f" << "Hello world" 
          << "\n" << ""
          << "\n" << "Hi Luke :)"
          << "\n" << ""
          << "\n" << "Counter: " << i
          << hwlib::flush; 
   }


}
