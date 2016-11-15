#include <DL1414.h>

/**
 * These are the pin names as in the DL1414 datasheet.
 * Define them as you have connected them on your circuit.
 */
int WR = 2;
int Addr0 = 12;
int Addr1 = 13;
int D0 = 3; // Pin 3 is PWM, change if you need PWM for other purposes. DL1414 does not need PWM.
int D1 = 4;
int D2 = 5; // Pin 5 is PWM, change if you need PWM for other purposes. DL1414 does not need PWM.
int D3 = 6; // Pin 6 is PWM, change if you need PWM for other purposes. DL1414 does not need PWM.
int D4 = 7;
int D5 = 8;
int D6 = 9; // Pin 9 is PWM, change if you need PWM for other purposes. DL1414 does not need PWM.

// Init Library with proper pin definitions
DL1414 dl1414(WR, Addr0, Addr1, D0, D1, D2, D3, D4, D5, D6);

void setup() {
  // After powerup some DL1414 modules show random characters
  dl1414.clear();
}

void loop() {
  // Display a scrolling text
  String str = "Hello World!";
  dl1414.writeStringScrolling(str, 133);

  // Display a fixed string
  str = "Hi";
  dl1414.writeStringFix(str);
  delay(2000);

  // clear previous text
  dl1414.clear();
  delay(1000);

  // address columns directly
  dl1414.writeByte('a',3);
  delay(500);
  dl1414.writeByte('c',1);
  delay(500);
  dl1414.writeByte('d',0);
  delay(500);
  dl1414.writeByte('b',2);
  delay(2000);

  // show some special characters (arrows)
  // DL1414 Modules do not use all of the ascii table, control characters are actually symbols
  dl1414.writeByte(4,0);
  dl1414.writeByte(3,1);
  dl1414.writeByte(2,2);
  dl1414.writeByte(1,3);
  delay(2000);
}

