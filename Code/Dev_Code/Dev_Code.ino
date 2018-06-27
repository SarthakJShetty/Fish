/*[LOG] Date: 28/05/2018
[LOG] -Just wrote code.
[LOG] -Yet to implement on Arduino.
[LOG] -Will be doing that tomorrow.
LOG] -Need to add a README
[LOG] Date: 29/05/2018
[LOG] -Code now works with sensor
[LOG] -Added a piece of code to convert volts to distance*/
//Code to be run on the Robotic Fish

//Assume n=3 (number of joints), j=n+1=4(number of links).
//Two types of motions are possible here, C and S movement.
//Movements are classified based on top view of the fish.
//Refer README for more Documentation.
#include<Servo.h>
//Servo motors are being defined here from Servo.h instance
Servo motor_1,motor_2,motor_3;
#define sensor A0

//Functions, S and C are being defined here.
void func_s();
void func_c();

//Motors are attached to the pins here. 9,10,11 are analog pins.
void setup(){
analogReference(DEFAULT);
Serial.begin(9600);
motor_1.attach(9);
motor_2.attach(10);
motor_3.attach(11);

//Sharp Infrared Sensors are used for INPUT.

}

void loop(){
float volts = analogRead(sensor)*0.0048828125;  // value from sensor * (5/1024)
  int reading = 13*pow(volts, -1);
  //delay(1000);
  //Value from the sensor(s) is read here.
Serial.println(reading);
  //This condition checks if obstacle has been detected. In this case, no obstacle.
  if(reading>=5){

    //Function S has been triggered here.
    func_s();
  }

  //Obstacle has been detected by the sensor in this case.
  else if(reading<5){

    //Function C has been triggered in this case.
    func_c();
  }
}

//This is executed when the obstacle has been detected on the left.
//Each joint has been given an angle of 30 degrees. As we move away from n=1. each angle gets multiplied by 2

void func_s(){
  //Serial.println("You have entered the S function");
  int i=90,diff=0;
  for(i=90;i<=150;i++){
    diff=i-90;
    motor_1.write(i);

    //Diff is used so that relative value is applied to each joint.
    motor_2.write(90-diff);
    delay(10);
    //motor_3.write(i);
  }
  for(i=150;i>=90;i--){
    diff=i-90;
    motor_1.write(i);
    motor_2.write(90-diff);
    delay(10);
    //motor_3.write(i);
  }
 }

void func_c(){
  //Serial.println("You have entered the C function");
  int i=90;
  for(i=90;i<=150;i++){
    motor_1.write(i);
    motor_2.write(i);
   delay(10);
    //motor_3.write(i);
  }
  for(i=150;i>=90;i--){
    motor_1.write(i);
    motor_2.write(i);
    delay(10);
    //motor_3.write(i);
  }
  }
