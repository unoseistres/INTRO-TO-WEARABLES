#include <Adafruit_NeoPixel.h>

int NUMPIXELS = 5;  // Number of pixels in strand
int LED_PIN = 12;  // NeoPixel LED strand is connected to this pin
int MIC_PIN = 10;  // Microphone is attached to this analog pin

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

/* we chose a sample window of 50 milliseconds
 * because 1/50ms = 20 Hz = lower limit of human hearing
 */
int sampleWindow = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long startMillis = millis();
  int amplitude;
  int micReading;
  int maxReading = 0;
  int minReading = 1024;
  
  // find min and max reading during a sample window of 50ms
  while (millis() - startMillis < sampleWindow){
    micReading = analogRead(MIC_PIN);
    
    if(micReading > maxReading){
        maxReading = micReading; 
    }
    else if (micReading < minReading) {
        minReading = micReading;
    }  
  }

  // calcultate amplitude
  amplitude = (maxReading - minReading);

  // print data
  Serial.print("amplitude: ");
  Serial.println(amplitude);

  // how many neopixels should be lit?
  int height = map(amplitude,0,300,0,NUMPIXELS);

  for (int i = 0; i < NUMPIXELS; i++){
    if (i < height)
      strip.setPixelColor(i, strip.Color(0,100,100));
    else
      strip.setPixelColor(i, strip.Color(0,0,0)); 
  }

  strip.show();
}

