// Seven-segment display to display numbers in order.

// Circuit follows usual seven-segment display pinout. From left to right:
// Top: 9 8 Ground 7 6
// Bottom: 11 10 Ground 5 4
// Use 220 ohm resistors for each line.

// Set pin control to digital I/O
// Represents A, B, C, D, E, F, G, DP bars on display
byte pins[8] = {7, 6, 5, 10, 11, 8, 9, 4};

byte seg_table[16][8] =      // Display encodings (DP unused)
  {{1, 1, 1, 1, 1, 1, 0, 0}, // 0
   {0, 1, 1, 0, 0, 0, 0, 0}, // 1
   {1, 1, 0, 1, 1, 0, 1, 0}, // 2
   {1, 1, 1, 1, 0, 0, 1, 0}, // 3
   {0, 1, 1, 0, 0, 1, 1, 0}, // 4
   {1, 0, 1, 1, 0, 1, 1, 0}, // 5
   {1, 0, 1, 1, 1, 1, 1, 0}, // 6
   {1, 1, 1, 0, 0, 0, 0, 0}, // 7
   {1, 1, 1, 1, 1, 1, 1, 0}, // 8
   {1, 1, 1, 1, 0, 1, 1, 0}, // 9
   {1, 1, 1, 0, 1, 1, 1, 0}, // A
   {0, 0, 1, 1, 1, 1, 1, 0}, // b
   {1, 0, 0, 1, 1, 1, 0, 0}, // C
   {0, 1, 1, 1, 1, 0, 1, 0}, // d
   {1, 0, 0, 1, 1, 1, 1, 0}, // E
   {1, 0, 0, 0, 1, 1, 1, 0}};// F

void display_num(byte num)
{
  // Display number based on pinout and display encoding table
  for (int i=0; i<8; i++)
  {
    digitalWrite(pins[i], seg_table[num][i]);
  }
}

void setup()
{
  // Enable pin output
  for (int p=4; p<=11; p++)
  {
    pinMode(p, OUTPUT);
  }
}

void cycle()
{
  // Cycle through the numbers
  for (int i=0; i<16; i++)
  {
    display_num(i);
    delay(500);
  }  
}

void looper()
{
  // Lights up segments in a fast clockwise loop
  // Endless variations: switch direction, figure 8 loop, etc.
  for (int i=0; i<6; i++)
  {
    for (int j=0; j<6; j++)
    {
      if (j==i) digitalWrite(pins[j], HIGH);
      else digitalWrite(pins[j], LOW);
    }
    delay(50);
  }
}
void loop() 
{
  cycle();
  //looper();
}
