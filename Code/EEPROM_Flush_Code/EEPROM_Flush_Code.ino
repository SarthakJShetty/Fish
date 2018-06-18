/*[LOG] -Date: 31/05/2018
[LOG] -This code is used to flush the onboard EEPROM. 
[LOG] -The EEPROM tends to store the previous values.
[LOG] -These values tend to alter with the Bluetooth communication.
[LOG] -Once the values are flushed, an LED is made to glow.*/

#include<EEPROM.h>
void setup(){
pinMode(13,OUTPUT);
for(int i=0;i<EEPROM.length();i++)
EEPROM.write(i,0);
digitalWrite(13,HIGH);  
}

void loop(){
}

