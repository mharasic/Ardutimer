const uint8_t P1_PLUS_PIN = 8;
const uint8_t P1_MINUS_PIN = 7;
const uint8_t SET_PIN = 6;
const uint8_t P2_PLUS_PIN = 5;
const uint8_t P2_MINUS_PIN = 4;

void setUpPins(){
  pinMode(P1_PLUS_PIN, INPUT);
  pinMode(P2_PLUS_PIN, INPUT);
  pinMode(P1_MINUS_PIN, INPUT);
  pinMode(P2_MINUS_PIN, INPUT);
  pinMode(SET_PIN, INPUT);
}


boolean isP1PlusDown(){
  return digitalRead(P1_PLUS_PIN) == HIGH;
}


boolean isP2PlusDown(){
  return digitalRead(P2_PLUS_PIN) == HIGH;
}


boolean isP1MinusDown(){
  return digitalRead(P1_MINUS_PIN) == HIGH;
}


boolean isP2MinusDown(){
  return digitalRead(P2_MINUS_PIN) == HIGH;
}


boolean isSetButtonDown(){
  return digitalRead(SET_PIN) == HIGH;
}
