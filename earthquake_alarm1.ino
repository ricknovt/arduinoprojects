int rled = 11;
int gled = 10;
const int tilt = 13;
int state = 0;
const int buz = 8;

void setup()
{
  pinMode(rled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(state, INPUT);
  pinMode(buz, OUTPUT);
  Serial.begin(9600);
  
  
}

void loop()
{
  int state = 0;
  
  state = digitalRead(tilt);
  Serial.println(state);
  
  if(state == HIGH){
    digitalWrite(rled, HIGH);
    digitalWrite(gled, LOW);
    tone(buz, 1000);
    delay(500);
    tone(buz, 500);
  } else {
    digitalWrite(rled, LOW);
    digitalWrite(gled, HIGH);
    noTone(buz);
  }

  delay(1000);
}
