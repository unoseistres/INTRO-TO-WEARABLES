#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_NeoPixel.h>

int NUMPIXELS = 5;
int PIN = 6;

Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Accelerometer Test"); Serial.println("");

  /* Initialise the sensor */
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }

  // initialize neopixels
  pixels.begin();
}

float x,y,z; // acceleration in 3 directions

boolean smooth = true; // do you want to smooth your data?
float oldX, oldY, oldZ;
float smoothingFactor = 0.9;

void loop(void)
{
  /* Get a new sensor event */
  sensors_event_t event;
  accel.getEvent(&event);

  // get values from the sensor
  x = event.acceleration.x;
  y = event.acceleration.y;
  z = event.acceleration.z;

  // smooth data with low pass filter algorithm
  if (smooth) {
    x = oldX * smoothingFactor + x * (1-smoothingFactor);
    y = oldY * smoothingFactor + y * (1-smoothingFactor);
    z = oldZ * smoothingFactor + z * (1-smoothingFactor);
    
    oldX = x;
    oldY = y;
    oldZ = z;
  }

  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("X: "); Serial.print(x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(z); Serial.print("  ");Serial.println("m/s^2 ");

  /* map data to a color value */
  int red = map(abs(y), 0, 15, 0, 200);
  int blue = map(abs(x), 0, 15, 0, 200);
  int green = map(abs(z), 0, 15, 0, 200);

  /* set all pixels to the same color */
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(red,green,blue));
  }

  pixels.show();

  /* Delay before the next sample */
  delay(20);
}
