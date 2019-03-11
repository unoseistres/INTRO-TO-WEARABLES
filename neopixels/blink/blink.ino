#include <Adafruit_NeoPixel.h> // include neopixel library

#define PIN 12 // Which pin on the Arduino is connected to the NeoPixels?
#define NUMPIXELS 3 // How many NeoPixels are attached to the Arduino?

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// runs when you turn on the Flora
void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  pixels.setPixelColor(0, pixels.Color(0,0,50));
  pixels.setPixelColor(1, pixels.Color(0,0,50));

  pixels.show();
  delay(250);

  pixels.setPixelColor(0, pixels.Color(0,50,50));
  pixels.setPixelColor(1, pixels.Color(0,50,50));

  pixels.show();
  delay(250);
  
}
