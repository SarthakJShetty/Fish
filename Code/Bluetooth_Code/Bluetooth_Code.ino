/*Date: 30/05/2018
This code was writen for the Robotic Predator-Fish Project.
[LOG] Date: 30/05/2018
[LOG] -Code is used to establish Bluetooth communication with the fish.
[BUG] -0 or 1 cannot be submitted successively. Causes overload and rebooting.
[LOG] -Header file containing EEPROM_FLUSH function is imported for better integration.*/

#include<Servo.h>
//#include<F:\Google Drive\IISc Files\Code\CPP_Code\EEPROM_Flush_Code.cpp>

char valueChecker[2];
Servo motor1, motor2, motor3;

void setup(){
  
  motor1.attach(9);
  motor2.attach(10);
  motor3.attach(11);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  //j=EEPROM_FLUSH();

}

void loop(){
  
  int angleIncrement;
  if(Serial.available()){
  //if(j>0)Serial.println("[INFO] EEPROM has been flushed");
  Serial.println("[INFO] Connection established");
  }
  
  char VAL;
  VAL=Serial.read();
  
  if(VAL=='1'){
         valueChecker[0]=VAL;
         Serial.println("[STATUS] LED is ON");
         digitalWrite(13,HIGH);
  for(angleIncrement=0;angleIncrement<=90;angleIncrement++){
    motor1.write(angleIncrement);
    motor2.write(angleIncrement);
    motor3.write(angleIncrement);
    delay(10);
    }
    }
    
  else if(VAL=='0'){
         valueChecker[0]=VAL;
         Serial.println("[STATUS] LED is OFF");
         digitalWrite(13,LOW);
  for(angleIncrement=90;angleIncrement>=0;angleIncrement--){
    motor1.write(angleIncrement);
    motor2.write(angleIncrement);
    motor3.write(angleIncrement);
    delay(10);
    }
    }
  }
