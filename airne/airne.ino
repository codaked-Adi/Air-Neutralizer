const int analogInPin = A0; // Analog input pin that the potentiometer is attached to of MQ2
int buzzer = 10;
int smokeA0 = A4;
int measurePin = A5;
int ledPower = 12;

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
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);
  int val=analogRead(0);
 
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  Serial.println(analogInPin);

  // Checks if it has reached the threshold value
  if (val < 50)
  {
    tone(buzzer, 1000, 200);
  }
  else
  {
    noTone(buzzer);
  }
  delay(100);
  
  
}
