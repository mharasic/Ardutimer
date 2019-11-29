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
  // init the display
  lmd.setEnabled(true);
  lmd.setIntensity(0);   // 0 = low, 10 = high
}

unsigned long timer = 0;

void loop() {
  clearDisplay();
  printSmallText(0,0, 2, false);
  if(timer == 0){
    timer =  millis()/1000;
  }
 unsigned long time = millis() / 1000 - timer;
  if( time >= 15){
    timer =  0;
  }
  else{
    if (time > 10){
      printBigTextAt(33,1,"READY", false);
    }
    else{
      printVeryBigFont(13,7, 9-time, false);  
    }
  }
  lmd.display();
  delay(100);
}
