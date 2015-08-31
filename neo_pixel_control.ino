// TO DO: Add variable resistors or sensors that connect to neo pixel parameters
//        Fabricate a control box 

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  

}

void loop() {
  
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(110, 10, 230), 50); // purple (is it possible?)
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  colorWipe(strip.Color(110, 10, 230), 50); // purple (is it possible?)

}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
