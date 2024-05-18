#include <Servo.h>
#include <Adafruit_LiquidCrystal.h>

Servo servoA;
Servo servoB;
Adafruit_LiquidCrystal lcd(0);
const int echoPin = 8;
const int trigPin = 4;
int ledg = 5;
int ledr = 6;

float duration, distance;
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledr, OUTPUT);
  pinMode(ledg, OUTPUT);
  
  lcd.begin(16, 9);
  lcd.setCursor(2, 0);
  lcd.print("RADAR v1");
  servoA.attach(A0);
  servoB.attach(A1);
  delay(1000);
  lcd.clear();
  
}

void loop()
{
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  
  if(50<distance){
  digitalWrite(ledr, LOW);
  digitalWrite(ledg, HIGH);
      
  } else if(0<distance&&distance<50){
  digitalWrite(ledr, HIGH);
  digitalWrite(ledg, LOW);
  }
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  
  lcd.setCursor(4, 0);
  lcd.print("Distance");
  lcd.setCursor(4, 1);
  lcd.print(distance);
  lcd.setCursor(10, 1);
  lcd.print("cm");
  delay(100);
  
  servoA.write(90); 
  
  servoB.write(0);
  delay(400);
  servoB.write(100);
  delay(400);
  servoB.write(0);

}