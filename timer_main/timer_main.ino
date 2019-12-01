#include <LEDMatrixDriver.hpp>

// Define the ChipSelect pin for the led matrix (Dont use the SS or MISO pin of your Arduino!)
const uint8_t LEDMATRIX_CS_PIN = 9;






// Number of 8x8 segments you are connecting
const int LEDMATRIX_SEGMENTS = 8;
const int LEDMATRIX_WIDTH    = LEDMATRIX_SEGMENTS * 8;

// The LEDMatrixDriver class instance
LEDMatrixDriver lmd(LEDMATRIX_SEGMENTS, LEDMATRIX_CS_PIN);

void setup() {
  Serial.begin(9600);
  setUpPins();
  // init the display
  lmd.setEnabled(true);
  lmd.setIntensity(0);   // 0 = low, 10 = high
}

unsigned long timer = 0;

void loop() {
//  Serial.println(String(isP1PlusDown()));
//unsigned long time = millis();
//printTime(0,3,time, false);

Serial.println(selectModeMenu());

//printSmallTime(0,0,time,true,false);

//clearDisplay();

//printSmallFontAt(0,0,':',false);


 // printCountDown();

  //
  delay(50);
}
