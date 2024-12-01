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
// Các tần số được đọc bởi các màu
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int m = 12;
int DO = 0, oldd=0, VANG = 0,oldv =0, XANH = 0, oldx =0;
LiquidCrystal_I2C lcd(0x27,20,4);
void setup() {
  // Cấu hình chân 
   pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
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
    lcd.print("DO:               ");
    lcd.setCursor(6, 1);
    lcd.print(0);
    lcd.setCursor(0, 2);
    lcd.print("VANG:             ");
    lcd.setCursor(6, 2);
    lcd.print(0);
    lcd.setCursor(0, 3);
    lcd.print("XANH:             ");
    lcd.setCursor(6, 3);
    lcd.print(0);
}
void loop() {
set:
Serial.println("Bat Dau");
Serial.println("CHO DOC TIEP");
delay(1000);
lcd.setCursor(0, 0);
  lcd.print("  DEM SAN PHAM  ");

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

if(redFrequency >= 200 && redFrequency != oldd && greenFrequency < 10 ){   
  Serial.println("PHAT HIEN MAU DO");
    DO = DO+1;
    lcd.setCursor(0, 1);
    lcd.print("DO:            ");
    lcd.setCursor(6, 1);
    lcd.print(DO);
    delay(2000);
    redFrequency = 0;
  }

if(greenFrequency >= 200 && redFrequency >= 200){ 
  Serial.println("PHAT HIEN MAU VANG");  
    VANG = VANG+1;
    lcd.setCursor(0, 2);
    lcd.print("VANG:            ");
    lcd.setCursor(6, 2);
    lcd.print(VANG);
    delay(2000);
    greenFrequency = 0;
    redFrequency = 0;
  }

if( blueFrequency >= 200 &&  redFrequency < 10){
  Serial.println("PHAT HIEN MAU XANH DUONG");
    XANH = XANH+1;
    lcd.setCursor(0, 3);
    lcd.print("XANH:            ");
    lcd.setCursor(6, 3);
    lcd.print(XANH);
    delay(2000);
    blueFrequency = 0;}

}
