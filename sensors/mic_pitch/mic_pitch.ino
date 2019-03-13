#include <Adafruit_NeoPixel.h>

int NUMPIXELS = 5;  // Number of pixels in strand
int LED_PIN = 6;  // NeoPixel LED strand is connected to this pin
int MIC_PIN = 10;  // Microphone is attached to this analog pin

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

/* we choose a sample window of 50 milliseconds
 * because 1/50ms = 20 Hz = lower limit of human hearing
 */
int sampleWindow = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

float smoothFreq;
float smoothingFactor = 0.9;

void loop() {
  unsigned long startMillis = millis();
  int micReading;
  int prevMicReading;
  int maxReading = 0;
  int minReading = 1024;
  int numCrossings = 0;
  
  // find min and max reading during a sample window of 50ms  
  while (millis() - startMillis < sampleWindow){
    micReading = analogRead(MIC_PIN);

    // get min/max readings to measure amplitude
    if(micReading > maxReading){
        maxReading = micReading; 
    }
    else if (micReading < minReading) {
        minReading = micReading;
    }  

    // detect zero-crossings
    if ((micReading - 512) * (prevMicReading - 512) <= 0) {
      numCrossings += 1;
    }

    prevMicReading = micReading;
  }

  // calcultate amplitude
  int amplitude = (maxReading - minReading);
  // calculate frequency
  float avgInterval = (sampleWindow/1000.0) / numCrossings;
  float freq = 1 / (2.0 * avgInterval);

  smoothFreq = smoothFreq * smoothingFactor + freq * (1-smoothingFactor);

  if (amplitude > 40) {
    Serial.print(amplitude); Serial.print(" ");
    Serial.print(smoothFreq); Serial.print(" ");
    Serial.println();
  }

  // map data to neopixels
  int height = map(amplitude,0,350,0,NUMPIXELS);
  int pitch = map(smoothFreq,200,1500,0,255);

  for (int i = 0; i < NUMPIXELS; i++){
    if (i < height)
      strip.setPixelColor(i, strip.Color(pitch,0,255-pitch));
    else
      strip.setPixelColor(i, strip.Color(0,0,0));
  }

  strip.show();
}
