#include <Adafruit_NeoPixel.h>
 
const int analogInPin = A10;  // Analog input pin that the potentiometer is attached to
Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, 12, NEO_GRB + NEO_KHZ800);
int sensorValue = 0;        // value read from the pot
   
void setup() {
    // initialize serial communications at 9600 bps:
    Serial.begin(9600);
   pinMode(analogInPin, INPUT_PULLUP); 
     strip.begin();
    strip.show(); // Initialize all pixels to 'off'
   
}

float alpha = 0.9;
float oldValue = 0;
float smoothValue = 0;
     
void loop() {
    // read the analog in value:
    sensorValue = analogRead(analogInPin);              
    // print the results to the serial monitor:
    

  smoothValue = oldValue * alpha + sensorValue * (1-alpha);
  oldValue = smoothValue;

      Serial.print("sensor = " );                       
    Serial.println(smoothValue);  
   
  
    int val = map(smoothValue,25,125,0,150);
    colorWipe(strip.Color(255-val, 0, val), 5);
                    
}
     
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
