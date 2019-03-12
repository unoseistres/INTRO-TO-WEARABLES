/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 * Modified by Becky Stern 2013 to change the color of one RGB Neo Pixel based on touch input
 */
 
#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>

int PIN = 12; // Which pin on the Arduino is connected to the NeoPixels?
int NUMPIXELS = 3; // How many NeoPixels are attached to the Arduino?

CapacitiveSensor   cs_9_10 = CapacitiveSensor(9,10);// 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup()                    
{
   cs_9_10.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
   pixels.begin();
   pixels.show();
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_9_10.capacitiveSensor(30);
   
  //adjust according to your data
  if (total1 < 240){
    digitalWrite(7, HIGH);
    pixels.setPixelColor(0, pixels.Color(0,255,0));  
    pixels.setPixelColor(1, pixels.Color(0,255,0));  
    pixels.setPixelColor(2, pixels.Color(0,255,0));  
    pixels.show();
  } else {
    pixels.setPixelColor(0, pixels.Color(255,0,0)); 
    pixels.setPixelColor(1, pixels.Color(255,0,0)); 
    pixels.setPixelColor(2, pixels.Color(255,0,0)); 
  
    pixels.show();
  }
    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing
 
    Serial.println(total1);                  // print sensor output 1
    delay(10);                             // arbitrary delay to limit data to serial port 
}
