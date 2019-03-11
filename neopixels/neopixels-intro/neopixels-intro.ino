#include <Adafruit_NeoPixel.h> // include neopixel library

int PIN = 12; // Which pin on the Arduino is connected to the NeoPixels?
int NUMPIXELS = 1; // How many NeoPixels are attached to the Arduino?

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// setup runs once when you turn on the Flora
void setup() {
  
  // initialize NeoPixel library
  pixels.begin();

  // set pixel colors
  // indices start at zero (FLORA -> PIXEL 0 -> PIXEL 1 -> PIXEL 2 -> ETC)
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(50,0,50));
  }

  // send color settings to neopixels
  pixels.show();
}

// loop runs infinitely after setup
void loop() {
  
}
