int s2 = 4;
int s3 = 5;
int R = A0, G =A1, B=A2;
void setup() {
  // put your setup code here, to run once:
  pinMode(s2, INPUT_PULLUP);
  pinMode(s3, INPUT_PULLUP);
  pinMode(R, INPUT_PULLUP);
  pinMode(G, INPUT_PULLUP);
  pinMode(B, INPUT_PULLUP);
}

void loop() {
  //R:
if(digitalRead(s2) == 0&&digitalRead(s3) ==0&&digitalRead(R)==0){
  digitalWrite(3, 1);
  delayMicroseconds(150);
  digitalWrite(3, 0);
  delayMicroseconds(250);
}
//G
if(digitalRead(s2) == 1&&digitalRead(s3) ==1&& digitalRead(G)==0){
  digitalWrite(3, 1);
  delayMicroseconds(150);
  digitalWrite(3, 0);
  delayMicroseconds(250);
}
//B
if(digitalRead(s2) == 0&&digitalRead(s3) ==1 && digitalRead(B)==0){
  digitalWrite(3, 1);
  delayMicroseconds(150);
  digitalWrite(3, 0);
  delayMicroseconds(250);
}
else{analogWrite(3, 0);}
}
