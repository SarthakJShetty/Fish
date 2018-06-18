/*
[INFO] -The code is organised into respective folders.
[INFO] -Other than CPP headers. They are kept seperately.

[LOG] Date: 28/05/2018
[LOG] -Just wrote code.
[LOG] -Yet to implement on Arduino.
[LOG] -Will be doing that tomorrow.
[LOG] -Need to add a README.

[LOG] Date: 29/05/2018
[LOG] -Code now works with sensor.
[LOG] -Added a piece of code to convert volts to distance.

[LOG] Date: 30/05/2018
[LOG] -Updated Bluetooth Code.
[LOG] -Bluetooth now works over COM4 port.
[LOG] -println statements look much cleaner now

[LOG] Date: 31/05/2018
[LOG] -Added EEPROM flush. Not much of an improvement.
[LOG] -Bluetooth has not been integrated here.
[LOG] -Bluetooth code has been introduced, albeit very buggy as of now.

[LOG] Date: 08/05/2018
[LOG] -Joystick can be used to control the fish now. Attempting on a wired controller though.
[LOG] -Intereference. Need to upload a SLAVE communication.

[LOG] Date: 09/06/2018
[LOG] -DualShock3 replaced with Xbox 360 Wireless knockoff controller.
[LOG] -Works much better now.
[LOG] -SLAVE protocol has been established. Works much better.

[LOG] Date: 10/06/2018
[LOG] -BLuetooth module has been converted into a one-way system, i.e. slave communication
[LOG] -RX/TX can be connected simultaneously, no obstruction to communication from controller.

[LOG] Date: 13/06/2018
[LOG] -Code has been successfully tested on fish.
[LOG] -This code has been converted into a .cpp libray, to make the Arduino code cleaner.

[LOG] Date: 15/06/2018
[LOG] -The thermocol has ripped. Adhesive applied and trying to fix it.
[LOG] -Code seems to be working well. Angles seem to be too big though.
------------------------------------------------------------------------------------------

CODE BELOW THIS, UPTO THE END OF COMMENTS IS ARDUINO CODE BEFORE CONVERSION TO CPP LIBRARY.

------------------------------------------------------------------------------------------
*/

//Code to be run on the Robotic Fish
//Assume n=3 (number of joints), j=n+1=4(number of links).
//Two types of motions are possible here, C and S movement.
//Movements are classified based on top view of the fish.
//Refer README for more Documentation.
//Servo motors are being defined here from Servo.h instance
/*Servo motor_1,motor_2,motor_3;
#define sensor A0

//Functions, S and C are being defined here.
void func_s();
void func_c();

//Motors are attached to the pins here. 9,10,11 are analog pins.

void setup(){

pinMode(13,OUTPUT);
j=EEPROM_FLUSH();
analogReference(DEFAULT);
Serial.begin(9600);
motor_1.attach(9);
motor_2.attach(10);
motor_3.attach(11);

//Sharp Infrared Sensors are used for INPUT.

}

void loop(){
  BLUE_COM();
float volts = analogRead(sensor)*0.0048828125;  // value from sensor * (5/1024)
  int reading = 13*pow(volts, -1);
  //delay(1000);
  //Value from the sensor(s) is read here.
  if(j>0)Serial.println("EEPROM has been flushed");
Serial.print("Distance: "); Serial.println(reading);
  //This condition checks if obstacle has been detected. In this case, no obstacle.
  if(reading>=10){

    //Function S has been triggered here.
    func_s();
  }

  //Obstacle has been detected by the sensor in this case.
  else if(reading<10){

    //Function C has been triggered in this case.
    func_c();
  }
}
---------------------------------------------------------------------------------------------

END OF REPLACED ARDUINO CODE.

---------------------------------------------------------------------------------------------

//This is executed when the obstacle has been detected on the left.
//Each joint has been given an angle of 30 degrees. As we move away from n=1. each angle gets multiplied by 2
//90 degrees is used as the median position, i.e. starting position.
//For S and C movements median is taken as 90 degrees.

/*Four types of movements are employed in this case:
1. S_MOVE()-Used for forward movement (Top view of the fish looks like an S)
2. C_MOVE()-Used for right movement, away from the obstacle
3. C_MOVE_RIGHT()-Same as C_MOVE()
4. C_MOVE_LEFT()-Used for left movement, away from the obstacle

----------------------------------------------------------------------------------------------*/

#include<Servo.h>
Servo motor_1,motor_2,motor_3;
void S_MOVE(){
  int angleIncrementer=90;
  for(angleIncrementer=90;angleIncrementer<=150;angleIncrementer++){
    motor_1.write(angleIncrementer);
    motor_2.write(angleIncrementer);
    motor_3.write(angleIncrementer);
    delay(10);
  }
for(angleIncrementer=150;angleIncrementer>=30;angleIncrementer--){
  motor_1.write(angleIncrementer);
  motor_2.write(angleIncrementer);
  motor_3.write(angleIncrementer);
  delay(10);
}
for(angleIncrementer=30;angleIncrementer<=90;angleIncrementer++){
  motor_1.write(angleIncrementer);
  motor_2.write(angleIncrementer);
  motor_3.write(angleIncrementer);
  delay(10);
}
}

void C_MOVE(){

  //Serial.println("You have entered the C - Right Function");

  int angleIncrementer=90;
  for(angleIncrementer=90;angleIncrementer<=150;angleIncrementer++){
    motor_1.write(angleIncrementer);
    motor_2.write(angleIncrementer);
    motor_3.write(angleIncrementer);
    delay(10);
  }
  
  for(angleIncrementer=150;angleIncrementer>=90;angleIncrementer--){
    motor_1.write(angleIncrementer);
    motor_2.write(angleIncrementer);
    motor_3.write(angleIncrementer);
    delay(10);
  }
  }

void C_MOVE_RIGHT(){

  //Serial.println("You have entered the C - Right Function");
  
  int angleIncrementer=90;
  for(angleIncrementer=90;angleIncrementer<=150;angleIncrementer++){
    motor_1.write(angleIncrementer);
    motor_2.write(angleIncrementer);
    motor_3.write(angleIncrementer);
    delay(10);
  }
  
  for(angleIncrementer=150;angleIncrementer>=90;angleIncrementer--){
    motor_1.write(angleIncrementer);
    motor_2.write(angleIncrementer);
    motor_3.write(angleIncrementer);
    delay(10);
  }
  }

void C_MOVE_LEFT(){
  
  //Serial.println("You have entered the C - Left Function");
  
  int angleIncrementer=90;
  for(angleIncrementer=90;angleIncrementer>=30;angleIncrementer--){
    motor_1.write(angleIncrementer);
    motor_2.write(angleIncrementer);
    motor_3.write(angleIncrementer);
    delay(10);
  }

  for(angleIncrementer=30;angleIncrementer<=90;angleIncrementer++){
    motor_1.write(angleIncrementer);
    motor_2.write(angleIncrementer);
    motor_3.write(angleIncrementer);
    delay(10);
  }
}