const int trig1 = 2;  
const int echo1 = 3;
const int trig2 = 4;  
const int echo2 = 5;
const int trig3 = 6;  
const int echo3 = 7;

int duration1 = 0;
int distance1 = 0;
int duration2 = 0;
int distance2 = 0;
int duration3 = 0;
int distance3 = 0;
void setup() {
  pinMode(trig1, OUTPUT);  
	pinMode(echo1, INPUT);  
  pinMode(trig2, OUTPUT);  
	pinMode(echo2, INPUT);  
  pinMode(trig3, OUTPUT);  
	pinMode(echo3, INPUT);  
	Serial.begin(115200);  

}

void loop() {
  digitalWrite(trig1, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trig1, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trig1, LOW);  

  duration1 = pulseIn(echo1, HIGH);  
  distance1 = (duration1*.0343)/2;  
  Serial.print("distance1:");
  Serial.println(distance1);
  delay(1000);

  digitalWrite(trig2, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trig2, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trig2, LOW);  

  duration2 = pulseIn(echo2, HIGH);  
  distance2 = (duration2*.0343)/2;  
  Serial.print("distance2:");
  Serial.println(distance2);
  delay(1000);

  digitalWrite(trig3, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trig3, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trig3, LOW);  

  duration3 = pulseIn(echo3, HIGH);  
  distance3 = (duration3*.0343)/2; 
  Serial.print("distance3:");
  Serial.println(distance3);
  delay(1000);
}
