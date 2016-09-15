// Rainbow demo from RGB LED
// Uses three out-of-phase sine waves, as described here: http://krazydad.com/tutorials/makecolors.php

byte redpin = 9;
byte greenpin = 10; 
byte bluepin = 11;

unsigned int STEPS = 256;
unsigned int DELAY = 10;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  for (int i=0; i<STEPS; i++)
  { 
    float red   = sin((i/(float)STEPS)*2*PI) * 127 + 128;
    float green = sin((i/(float)STEPS)*2*PI + 2*PI/3) * 127 + 128;
    float blue  = sin((i/(float)STEPS)*2*PI + 4*PI/3) * 127 + 128;

    analogWrite(redpin, red);
    analogWrite(greenpin, green);
    analogWrite(bluepin, blue);

    // Print RGB values (see Serial Plotter for sine waves!) 
    Serial.print(red);
    Serial.print('\t');
    Serial.print(green);
    Serial.print('\t');
    Serial.println(blue);

    delay(DELAY);
  }
}
