const uint8_t MODE_TIMER = 0;
const uint8_t MODE_MAGIC = 1;
const uint8_t MODE_CHESS = 2;

int selectModeMenu(){
  int selectedMode = 0;
  clearDisplay();
  for(;;){
    printBigTextAt(4,0,"MODE", false);
    printMode(selectedMode);
    lmd.display();

    if(isP1PlusDown() || isP2PlusDown()){
      selectedMode = (selectedMode < 2) ? selectedMode + 1 :  0;
      printMode(selectedMode);
      lmd.display();
      delay(500);
    }
    if(isP1MinusDown() || isP2MinusDown()){
      selectedMode = (selectedMode > 0) ? selectedMode - 1 :  2;
      printMode(selectedMode);
      lmd.display();
      delay(500);
    } 
    if(isSetButtonDown()){
      delay(500);
      return selectedMode;
    }
    delay(50); 
  }
}


void printMode(int mode){
  switch(mode){
    case MODE_TIMER:
                      printBigTextAt(33,0,"TIMER", false);
                      break;
    case MODE_MAGIC:
                      printBigTextAt(33,0,"MAGIC", false);
                      break;
    case MODE_CHESS:
                      printBigTextAt(33,0,"CHESS", false);
                      break;
  }
}
