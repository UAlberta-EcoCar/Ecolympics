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
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
   
   pos=-3*(analogRead(A0)-900);
   Serial.println(analogRead(A0));
   analogWrite(3,ledControlCurve(-255,pos));
   analogWrite(5,ledControlCurve(-765,pos));
   analogWrite(6,ledControlCurve(-1275,pos));
   analogWrite(9,ledControlCurve(-1785,pos));
   analogWrite(10,ledControlCurve(-2295,pos));
   
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


