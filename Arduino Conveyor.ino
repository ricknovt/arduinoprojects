#define btnPin 2
#define minPin 3
#define rstPin 4

int potVal = 0;
int btn_prev;
int minpinprev;
int rstpinprev;

void setup() {
  pinMode(btnPin, INPUT_PULLUP);
  pinMode(minPin, INPUT_PULLUP);
  
  btn_prev = digitalRead(btnPin);
  Serial.begin(9600);
}

void loop() {
 int btn = digitalRead(btnPin);
 int minbtn = digitalRead(minPin);
 int rstbtn = digitalRead(rstPin);
  
 if (btn == LOW && btn_prev == HIGH)
  {
    potVal++;
   Serial.println(potVal*1000);
 } else if (minbtn == LOW && minpinprev == HIGH)
   {
    potVal--;
   Serial.println(potVal*1000);
   }
   /*else if (rstbtn == LOW && rstpinprev == HIGH)
   {
    potVal*0;
   Serial.println(potVal*1000);
   } */
   
  btn_prev = digitalRead(btnPin);
  minpinprev = digitalRead(minPin);
  rstpinprev = digitalRead(rstPin);
}