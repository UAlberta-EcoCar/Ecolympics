int x=-256;
unsigned char ledControlCurve(int offset, int x);
void setup() {
  // put your setup code here, to run once:
    pinMode(3,OUTPUT);
}

void loop() {
  analogWrite(3,ledControlCurve(0,x));
  x++;
  if (x>255){
    x=-256;
  }
  Serial.println(x);
  delay(30);
  

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
