

void printSmallTime(int x, int y, unsigned long time, bool seconds, boolean invert){
  
  if((time % 1000) > 500){
    printSmallFontAt(x + 17,y, ':', invert); 
    if(seconds) printSmallFontAt(x+7,y, ':', invert); 
  }
  else{
    printSmallFontAt(x + 17,y, ' ', invert); 
    if(seconds)printSmallFontAt(x + 7,y, ' ', invert); 
  }
  time /= 1000;
  
  if(seconds){ 
    printSmallFontAt(x+20,y, ((time / 10) % 6) + '0',  invert);
    printSmallFontAt(x+ 24,y, (time % 10) + '0',  invert); 
  }
  time /= 60;
  
  printSmallFontAt(x+10 + ((seconds) ? 0 : 10),y, ((time / 10) % 6) + '0',  invert);
  printSmallFontAt(x+14 + ((seconds) ? 0 : 10),y, (time % 10) + '0',  invert); 

  time /= 60;
  printSmallFontAt(x + ((seconds) ? 0 : 10),y, ((time / 10) % 6) + '0',  invert);
  printSmallFontAt(x  +4 + ((seconds) ? 0 : 10),y, (time % 10)+ '0',  invert);
  lmd.display();
}

void printTime(int x, int y, unsigned long time, boolean invert){
    time /= 60000;

    int min = time % 60;
    printVeryBigFont(x,y, min / 10, invert);  
    printVeryBigFont(x + 8,y,min % 10, invert);  
    int hours = (time / 60) % 24;
  
    printVeryBigFont(x + 17,y, hours / 10, invert);  
    printVeryBigFont(x + 25,y, time % 10, invert);  
    
    lmd.display();
}
