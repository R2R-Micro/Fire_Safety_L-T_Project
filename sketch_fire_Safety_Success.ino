int Led = 6;                
int Buzzer = 8;
int FlamePin = 4;
#define Mq2 A0 

void setup() {                 
  Serial.begin(9600);                       
  pinMode(Led,OUTPUT);
  pinMode(Buzzer,OUTPUT);
  pinMode(Mq2,INPUT);
  pinMode(FlamePin,INPUT);
}

void loop() {                                 
  int GasSensor = analogRead(Mq2);
  int FlameSensor = digitalRead(FlamePin);

  Serial.print("GasSensor Value: ");
  Serial.print(GasSensor);
  Serial.print("   |   ");
  Serial.print("FlamePin Value: ");
  Serial.println(FlameSensor);
  delay(500);

  if ((GasSensor > 60)|| FlameSensor == 0){
    digitalWrite(Led, HIGH);
    digitalWrite(Buzzer, HIGH);
  }
  else {
    digitalWrite(Led, LOW);
    digitalWrite(Buzzer, LOW);
  }

}
