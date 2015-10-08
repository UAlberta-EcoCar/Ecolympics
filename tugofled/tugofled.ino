int debounceDelay=100;
   int time1;
   int latch1=0;
   int time2;
   int latch2=0;
   int pos;
unsigned char ledControlCurve(int offset,int x);

void setup() {
  pinMode(4,INPUT);
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
   
   if (digitalRead(2) && (latch1==0)){
     time1=millis();
     latch1=1;
     pos+=20;
   }
   if (((time1-millis())>debounceDelay)&& !digitalRead(2)){
     latch1=0;
   }
   if (digitalRead(4) && (latch2==0)){
     time2=millis();
     latch2=1;
     pos-=20;
   }
   if (((time2-millis())>debounceDelay)&& !digitalRead(4)){
     latch2=0;
   }
   analogWrite(3,ledControlCurve(-1020,pos));
   analogWrite(5,ledControlCurve(-510,pos));
   analogWrite(6,ledControlCurve(0,pos));
   analogWrite(9,ledControlCurve(510,pos));
   analogWrite(10,ledControlCurve(1020,pos));
   if (pos < -1020 || pos > 1020){
     pos=0;
   }
}
unsigned char ledControlCurve(int offset, int x){
  if ((x+offset)>255){
    return 0;
  }
  if (((x+offset)>=0)&&((x+offset)<=255)){
    return -1*(x+offset)+255;
    
  }
  if (((x+offset)<0)&&((x+offset)>=-255)){
    return ((x+offset)+255);
    
  }
  if ((x+offset)<255){
    return 0;
    
  }
}


