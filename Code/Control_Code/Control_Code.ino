/* Flow:
 * Autonomous Mode - without controller (not implemented in this phase).
 * Borrow functions from Stable_Code for S/C Movement for Bluetooth Controlled Motion.
 * Borrow fucntions from Stable_Code for S/C Movement for Autonomous Motion

[LOG] Date: 31/05/2018
[LOG] -EEPROM Code has been implemented.
[LOG] -Movement Code has been implemented.
[LOG] -Bluetooth Code has been implemented.
[LOG] -Sensor Code has been implemented.
[LOG] -Detection has been achieved.
[LOG] -Conditional Movement has been acheived.


[INFO] -Here, the number of joints is assumed as 3.
[INFO] -Wait for 5 seconds (approximate) before sending commands through controller. 
[INFO] -EEPROM Flush has to take place before operation.
[INFO] -COM4 is used as default communication port for bluetooth.
[INFO] -COM3 is used as default communicaation port for Serial Communication.
*/

#include<Servo.h>
#include<F:\Google Drive\IISc Files\Code\CPP_Code\EEPROM_Flush_Code.cpp>
//#include<F:\Google Drive\IISc Files\Code\CPP_Code\Bluetooth_Code.cpp>
#include<F:\Google Drive\IISc Files\Code\CPP_Code\Stable_Movement_Code.cpp>
#include<F:\Google Drive\IISc Files\Code\CPP_Code\Sensor_Code.cpp>
void setup() {
  Serial.begin(9600);
  motor_1.attach(9);
  motor_2.attach(10);
  motor_3.attach(11);
  EEPROM_FLUSH();
}

void loop() {
    int SENSOR_VAR=SENSOR_READ();
    if(SENSOR_VAR>=5){
    if(Serial.available()){
    int BLUETOOTH_VAR;
    BLUETOOTH_VAR=Serial.read();
    if(BLUETOOTH_VAR=='1'){
    S_MOVE();}
    else if(BLUETOOTH_VAR=='2'){
    C_MOVE_RIGHT();}
    else if(BLUETOOTH_VAR=='3'){
      C_MOVE_LEFT();}
    }
    /*else{
      S_MOVE();
    }*/
    }
  else if(SENSOR_VAR<5){
    C_MOVE();}
}
