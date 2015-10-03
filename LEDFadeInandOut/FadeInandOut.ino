int pin1 = 9;
int pin2 = 10;


void setup() {
}

void loop() {
  for(int i = 0; i < 255; i++){
    analogWrite(pin1, 0+i);
    delay(5);
  }
  for(int i = 0; i < 255; i++){
    analogWrite(pin1, 255-i);
    delay(5);
  }
  for(int i = 0; i < 255; i++){
    analogWrite(pin2, 255+i);
    delay(5);
  }
  for(int i = 0; i < 255; i++){
    analogWrite(pin2, 255-i);
    delay(5);
  }
}
