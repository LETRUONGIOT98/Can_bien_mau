/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com  
*********/

// Định nghĩa các chân nối
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int ss1 =A0;
int ss2 =A1;
int rl1 = 9;
int rl2 = 10;
int rl3 = 11;
// Các tần số được đọc bởi các màu
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int m = 12;
int DO = 0, VANG = 0, XANH = 0;
LiquidCrystal_I2C lcd(0x27,20,4);
void setup() {
  // Cấu hình chân 
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(rl1, OUTPUT);
  pinMode(rl2, OUTPUT);
  pinMode(rl3, OUTPUT);
  pinMode(m, OUTPUT);
  // sensorOut là input
  pinMode(sensorOut, INPUT);
  pinMode(ss1, INPUT_PULLUP);
  pinMode(ss2, INPUT_PULLUP);
  // Thang đo tần số là  20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
   // Begins serial communication 
  Serial.begin(9600);
  lcd.setCursor(0, 1);
    lcd.print("D:            QUA");
    lcd.setCursor(4, 1);
    lcd.print(0);
    lcd.setCursor(0, 2);
    lcd.print("V:            QUA");
    lcd.setCursor(4, 2);
    lcd.print(0);
    lcd.setCursor(0, 3);
    lcd.print("X:            QUA");
    lcd.setCursor(4, 3);
    lcd.print(0);
}
void loop() {
set:
Serial.println("Bat Dau");
lcd.setCursor(0, 0);
  lcd.print("  DEM SAN PHAM  ");
  //Xi lanh đẩy quả ra
  digitalWrite(m, LOW);//Dừng lại đọc màu
  digitalWrite(rl1, LOW);//Xi lanh quay về
  Serial.println("DANG DAY QUA RA");
  delay(3000);
  digitalWrite(rl1, HIGH);//Xi lanh đẩy ra
  delay(1000);
  digitalWrite(m, HIGH); //Chạy motor băng tải
  Serial.println("DANG CHAY BANG TAI");
  delay(2000); 
  Serial.println("DANG DOC MAU");//Sửa thông số này để quả dùng đúng vị trí đọc màu
  digitalWrite(m, LOW);//Dừng lại đọc màu
  // Chọn đọc photodiodes đỏ (RED)
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Đọc tần số
  redFrequency = pulseIn(sensorOut, LOW);
   // Ghi ra Serial
  Serial.print("R = ");
  Serial.print(redFrequency);
  delay(100);
  // Chọn đọc photodiodes xanh (GREEN)
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Đọc tần số
  greenFrequency = pulseIn(sensorOut, LOW);
  // in ra GREEN (G)
  Serial.print(" G = ");
  Serial.print(greenFrequency);
  delay(100);
  // Chọn đọc photodiodes BLUE
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
   // Đọc tần số
  blueFrequency = pulseIn(sensorOut, LOW);
  // In ra giá trị BLUE (B)
  Serial.print(" B = ");
  Serial.println(blueFrequency);
  Serial.println("DA DOC XONG");
  delay(100);
for(int i = 1; i>0; i++){
  Serial.println("DANG CHAY BANG TAI");
digitalWrite(m, HIGH);
while(redFrequency >= 200){   //nếu là màu đỏ thì 
  Serial.println("PHAT HIEN MAU DO");
  if(digitalRead(ss1)==0){//đến cảm biến 1 sẽ dùng lại
    DO = DO+1;
    lcd.setCursor(0, 1);
    lcd.print("D:            QUA");
    lcd.setCursor(4, 1);
    lcd.print(DO);
    delay(200);
    digitalWrite(m, LOW);
    digitalWrite(rl2, HIGH);
    Serial.println("DANG DAY QUA RA");
    delay(1500);
    digitalWrite(rl2, LOW);
    delay(2000);
   redFrequency = 0 ;
   goto set;
  }
}
while(greenFrequency >= 200&& redFrequency >= 200){   //nếu là màu đỏ thì 
  Serial.println("PHAT HIEN MAU VANG");
  if(digitalRead(ss2)==0){//đến cảm biến 1 sẽ dùng lại
    VANG = VANG+1;
    lcd.setCursor(0, 2);
    lcd.print("V:            QUA");
    lcd.setCursor(4, 2);
    lcd.print(VANG);
    delay(200);
    digitalWrite(m, LOW);
    digitalWrite(rl3, HIGH);
    Serial.println("DANG  DAY QUA RA");
    delay(1500);
    digitalWrite(rl3, LOW);
    delay(2000);
   greenFrequency = 0; redFrequency=0;
   goto set;
  }
}
if( greenFrequency >= 200 ){
  Serial.println("PHAT HIEN MAU XANH");
    XANH = XANH+1;
    lcd.setCursor(0, 3);
    lcd.print("X:            QUA");
    lcd.setCursor(4, 3);
    lcd.print(XANH);}
if(digitalRead(ss2)==0){
  Serial.println("CHAY VE CUOI BANG TAI");
  delay(2000);
digitalWrite(m, LOW);
goto set;}

}}
