void setup() {
  pinMode(7,OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  if (digitalRead(2)){
    digitalWrite(7,1);
  
  }
  else{
    digitalWrite(7,0);
  }
  

}
