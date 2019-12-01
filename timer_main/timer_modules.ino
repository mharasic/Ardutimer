void printCountDown(){
 
 clearDisplay();
  if(timer == 0){
    timer =  millis()/1000;
  }
 unsigned long time = millis() / 1000 - timer;
  if( time >= 15){
    timer =  0;
  }
  else{
    if (time >= 10){
      if (time >= 12 && millis()%500 > 250){ 
        clearDisplay();
      }
      else{
         printBigTextAt(33,1,"READY", false);
       }
    }
    else{
      printVeryBigFont(13,7, 9-time, false);  
      for (int i = 0; i < 6; i++){
        lmd.setPixel(35 + i,4, true);
        lmd.setPixel(35 + i,3, true);
        lmd.setPixel(55 + i,3, true);
        lmd.setPixel(55 + i,4, true);
      }
    }
  }
  printSmallPlayerText(0,0, 2, false);
  lmd.display();

}
