//Date: 31/05/2018
//This code is a part of the robotic fish project.
//EEPROM (Electrically Erasable Programmable Read Only Memory) onboard the Arduino needs to be flushed.
//sometimes to get rid of values written in it.
//Values might hinder with the functioning of bluetooth-communications module.
//This code is called by the bluetooth module.

//For detailed [LOG] and [INFO] have a look at the Stable_Movement.cpp code.

//-----------------------------------------------------------------------------------------------------//

#include<EEPROM.h>
#include<stdlib.h>
#include<stdio.h>
int memoryIncrement;int incrementChecker=0;
int EEPROM_FLUSH(){
	pinMode(13,OUTPUT);
 // Serial.begin(9600);
for(memoryIncrement=0;memoryIncrement<EEPROM.length();memoryIncrement++){
EEPROM.write(memoryIncrement,0);
incrementChecker++;}
digitalWrite(13,HIGH);
 /*if(Serial.available()){
  while(j<i){
    Serial.print("EEPROM slot cleared: ");    Serial.println(j);
    j++;}*/
if(incrementChecker==EEPROM.length()){
return incrementChecker;}}