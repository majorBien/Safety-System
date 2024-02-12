#define Pomp 12
#define left 2
#define velocity 3
#define right 4
#define Buzzer 7
 
 
 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,16,2);
const int analogInPin = A0; 
const int analogPin2 = A1;
int sensorValue = 0;
int outputValue = 0;
int sensorValue2 = 0;
int outputValue2 = 0;
 
 
 
 
 
void setup() {
  pinMode(Pomp, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(velocity, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("Pomiesczenie");
  lcd.setCursor(0,1);
  lcd.print("bezpieczne");
}
 
void loop() {
  motor_control();
  sensors_control();
  pomp_control();
 
}
 
void pomp_control()
{
 
 
  if(sensorValue>130)
  {
  digitalWrite(Pomp, LOW);
  digitalWrite(Buzzer, HIGH);
  lcd.clear();
  lcd.print("Zagrozenie");
  lcd.setCursor(0,1);
  lcd.print("pozarowe");
   delay(300);
  }
 
  if(sensorValue < 130)
  {
  digitalWrite(Pomp, HIGH);
  digitalWrite(Buzzer, LOW);
  lcd.clear();
  lcd.print("Pomiesczenie");
  lcd.setCursor(0,1);
  lcd.print("bezpieczne");
  delay(300);
 
  }
 
 
}
 
 
void sensors_control()
 
{
sensorValue = analogRead(A0);
outputValue = map(sensorValue, 0, 1023, 0, 255);
sensorValue2 = analogRead(A1);
outputValue2 = map(sensorValue2, 0, 1023, 0, 255);
 
 
 
  Serial.println("sensor1: ");
  Serial.println(sensorValue);
 
  Serial.println("sensor2: ");
  Serial.println(sensorValue2); 
 
  delay(100);
}
 
 
void motor_control()
 
 
{
  if(sensorValue2 > 150 && sensorValue2 < 250)
  {
  analogWrite(velocity, 170);
  digitalWrite(right, HIGH);
  digitalWrite(Buzzer, HIGH);
  delay(250);
  lcd.clear();
  lcd.print("Zagrozenie");
  lcd.setCursor(0,1);
  lcd.print("gazowe");
  Serial.println("speed1");
  }
 
  else if(sensorValue2 > 250 && sensorValue2 < 300)
  {
  analogWrite(velocity, 210);
  digitalWrite(right, HIGH);
  digitalWrite(Buzzer, HIGH);
  delay(250);
  lcd.clear();
  lcd.print("Zagrozenie");
  lcd.setCursor(0,1);
  lcd.print("gazowe");
  delay(300);
  Serial.println("speed2");
  }
  
  else if(sensorValue2 > 300)
  {
  analogWrite(velocity, 255);
  digitalWrite(right, HIGH);
  digitalWrite(Buzzer, HIGH);
  delay(250);
  lcd.clear();
  lcd.print("Zagrozenie");
  lcd.setCursor(0,1);
  lcd.print("gazowe");
  delay(300);
  Serial.println("speed3");
  }
  else if(sensorValue2 < 125)
  {
  digitalWrite(velocity, LOW);
  digitalWrite(right, LOW);
  digitalWrite(Buzzer, LOW);
  lcd.clear();
  lcd.print("Pomiesczenie");
  lcd.setCursor(0,1);
  lcd.print("bezpieczne");
  delay(300);
  }
 
}
