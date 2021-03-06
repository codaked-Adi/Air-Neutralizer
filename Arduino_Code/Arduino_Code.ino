int analogInPin = A0; 
int buzzer = 10;
int smokeA0 = A4;
int measurePin = A5;
int ledPower = 12;
int pump=7;

unsigned int samplingTime = 280;
unsigned int deltaTime = 40;
unsigned int sleepTime = 9680;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

//smoke threshhold value
int sensorThres = 250;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
  pinMode(ledPower,OUTPUT);
}

void loop() {
  int analogSensor = analogRead(smokeA0);
  int val=analogRead(0);
  digitalWrite(ledPower,LOW);
  delayMicroseconds(samplingTime);

  voMeasured = analogRead(measurePin);

  delayMicroseconds(deltaTime);
  //digitalWrite(ledPower,HIGH);
  delayMicroseconds(sleepTime);
  calcVoltage = voMeasured*(5.0/1024);
  dustDensity = 0.5*calcVoltage-0.1;
  if ( dustDensity < 0)
  {
    dustDensity = 0.00;
  }
 
  Serial.print("Harmful Gases: ");
  Serial.println(analogSensor);
  Serial.print("Water Level: ");
  Serial.println(val);
  Serial.print("Raw Signal Value (0-1023):");
  Serial.println(voMeasured);

  Serial.print("Voltage:");
  Serial.println(calcVoltage);

  Serial.print("Dust Density:");
  Serial.println(dustDensity);
  // Checks if it has reached the threshold value
  
  if (val < 200)
  {
    tone(buzzer, 1000, 200);
    
  }
  /*else
  {
    noTone(buzzer);
  }*/
  //digitalWrite(7,LOW);
  if(dustDensity)
  {
    digitalWrite(7,LOW);
  }
  if (analogSensor > sensorThres)
  {
    tone(buzzer, 1000, 200);
    digitalWrite(7,LOW);
    delay(1000);
  }
  else
  {
    digitalWrite(7,HIGH);
  }
  delay(1000);
  
  
}
