#define sensor A0

void setup() {
Serial.begin(9600);
}

void loop() {
  float SensorReadingVolts=analogRead(sensor)*0.0048828125;
  int SensorReadingDistance=13*pow(SensorReadingVolts,-1);
  Serial.print("Distance ");Serial.println(SensorReadingDistance);
  delay(100);
}
