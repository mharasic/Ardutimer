#include "fonts.h"

void printSmallFontAt(int x, int y, uint8_t* font, boolean invert ){
  for (int i = 0; i < 3; i++){
    int mask = 0x01;
    for (int j = 0; j < 5; j++){
      lmd.setPixel(x+i, y+j, (font[i] & mask) != 0);
      mask = mask << 1;
    }
  }
}


void printBigFontAt(int x, int y,uint8_t* font, boolean invert ){
  for (int i = 0; i < 7; i++){
    lmd.setPixel(x-1, y+i, invert );
    lmd.setPixel(x+5, y+i, invert);
  }
  for (int i = 0; i < 5; i++){
    int mask = 0x01;
    for (int j = 0; j < 7; j++){
      if (invert){
        lmd.setPixel(x+i, y+j, (font[i] & mask) == 0 );
      }
      else{
        lmd.setPixel(x+i, y+j, (font[i] & mask) !=0 );
      }
      mask = mask << 1;
    }
  }
}


void printSmallTime(int x, int y, unsigned long time, bool seconds, boolean invert){
  if((time % 1000) > 500){
    printSmallFontAt(x + 17,y, (uint8_t*) sm_doublePoint, invert); 
    if(seconds) printSmallFontAt(x+7,y,   (uint8_t*) sm_doublePoint, invert); 
  }
  else{
    printSmallFontAt(x + 17,y,   (uint8_t*) sm_blank, invert); 
    if(seconds)printSmallFontAt(x + 7,y,   (uint8_t*) sm_blank, invert); 
  }
  if(seconds){ 
    printSmallFontAt(x+20,y, (uint8_t*) smallNumbers[(time/10)%6],  invert);
    printSmallFontAt(x+ 24,y,   (uint8_t*) smallNumbers[time%10],  invert); 
  }
  time /= 60;
  
  printSmallFontAt(x+10 + ((seconds) ? 0 : 10),y, (uint8_t*) smallNumbers[(time/10)%6],  invert);
  printSmallFontAt(x+14 + ((seconds) ? 0 : 10),y,   (uint8_t*) smallNumbers[time%10],  invert); 

  time /= 60;
  printSmallFontAt(x + ((seconds) ? 0 : 10),y, (uint8_t*) smallNumbers[(time/10)%6],  invert);
  printSmallFontAt(x  +4 + ((seconds) ? 0 : 10),y,   (uint8_t*) smallNumbers[time%10],  invert);
  
}


void printBigTextAt(int x, int y, String text, boolean invert){
   text.toUpperCase();
  for(int i = 0; i < text.length(); i++){
    char character = text.charAt(i);
    uint8_t* font = NULL;
    if(character >= '0' && character <= '9'){
      font = (uint8_t*) bigNumbers[character-'0'];
    }
    else if (character == ' ') {
            font = (uint8_t*) bg_blank;
    }else {
          font = (uint8_t*) bigCharacters[character-'A'];
    }
    printBigFontAt(x+(i*6),y,font, invert);
  }
}


void printSmallText(int x, int y, int playerID, boolean invert){
  printSmallFontAt(x,y, (uint8_t*) sm_P,  invert);
  printSmallFontAt(x+4,y, (uint8_t*) sm_L,  invert);
  printSmallFontAt(x+8,y, (uint8_t*) sm_A,  invert);
  printSmallFontAt(x+12,y, (uint8_t*) sm_Y,  invert);
  printSmallFontAt(x+16,y, (uint8_t*) sm_E,  invert);
  printSmallFontAt(x+20,y, (uint8_t*) sm_R,  invert);
  printSmallFontAt(x+28,y, (uint8_t*) smallNumbers[playerID],  invert);
}


void printVeryBigFont(int x, int y, int value, boolean invert){
   uint8_t* font = (uint8_t*)veryBigNumbers[value];
   for (int i = 0; i < 10; i++){
    int mask = 0x01;
    for (int j = 0; j < 8; j++){
      int posx = ((y+i >= (8)) ? (LEDMATRIX_WIDTH/2) : 0) +   x+j ;
      int posy= (y+i >= 8 ? -8 : 0) + y+i ;
      lmd.setPixel(posx,posy, (font[i] & mask) != 0);
      mask = mask << 1;
    }
  }
  
}


void clearDisplay(){
  for(int y = 0; y< 8; y++){
      for (int x = 0; x < LEDMATRIX_WIDTH; x++){
        lmd.setPixel(x , y, false);
      }
   }
}
