//This code is uded to communicate over bletooth with the Arduino.
//loop and setup are commented out because the code is seen as C++ code by the Arduino compiler.
//For detailed [LOG] and [INFO] have a look at the Stable_Movement.cpp code.

//----------------------------------------------------------------------------------------------


#include<Servo.h>
//#include<F:\Google Drive\IISc Files\Code\EEPROM_Flush_Code\EEPROM_Flush_Code.cpp>
void BLUE_COM(){
Servo motor1, motor2, motor3;
//void setup(){
  motor1.attach(9);
  motor2.attach(10);
  motor3.attach(11);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  //j=EEPROM_FLUSH();
//}
//void loop(){
  int i;
if(Serial.available()){
  //if(j>0)Serial.println("[INFO] EEPROM has been flushed");
  //Serial.println("[INFO] Connection established");}
  char VAL;
  VAL=Serial.read();
  if(VAL=='1'){
        //Serial.println("[STATUS] LED is ON");
        digitalWrite(13,HIGH);
 for(i=0;i<=90;i++){

    motor1.write(i);
    motor2.write(i);
    motor3.write(i);
    delay(10);
    }
    }
  else if(VAL=='0'){
        digitalWrite(13,LOW);
        //Serial.println("[STATUS] LED is OFF");
   for(i=90;i>=0;i--){
    motor1.write(i);
    motor2.write(i);
    motor3.write(i);
    delay(10);
    }
    }}
  //}