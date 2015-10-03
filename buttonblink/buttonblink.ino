void setup() {
  pinMode(4,INPUT);
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  

}

void loop() {
  int debounceDelay=10;
  int time1;
  int latch=0;
  int time2;
  int latch2=0;
  int player1=0;
  int player2=0;
   if (digitalRead(2) && latch1==0){
     time1=millis();
     latch=1;
     player1++;
   }
   if (time1-millis()<latchDelay){
     latch=0;
     
   }
   analogWrite(3,player1);
  

}
