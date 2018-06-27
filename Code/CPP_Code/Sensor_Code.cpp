//The Sharp Distance Sensor is connected to the analog IN A0 port.
//For detailed [LOG] and [INFO] have a look at the Stable_Movement.cpp code.

//---------------------------------------------------------------------------


#define sensor A0

//Function is called by Control_Code.ino to judge distance between the Fish and the obstacles such as the walls of the boundary.

int SENSOR_READ() {
  float SensorReadingVolts=analogRead(sensor)*0.0048828125;
  int SensorReadingDistance=13*pow(SensorReadingVolts,-1);
  //Serial.print("Distance ");Serial.println(SensorReadingDistance);
  delay(10);
  return SensorReadingDistance;
}		