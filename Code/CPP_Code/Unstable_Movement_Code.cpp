#include<Servo.h>
Servo motor_1,motor_2,motor_3;
int angleIncrementer=90;
void S_MOVE(){
for(angleIncrementer=90;angleIncrementer<=150;angleIncrementer++){
	motor_1.write(angleIncrementer);
	delay(10);
}
for(angleIncrementer=150;angleIncrementer>=0;angleIncrementer--){
	motor_1.write(angleIncrementer);
	delay(10);
}
for(angleIncrementer=0;angleIncrementer<=90;angleIncrementer++){
	motor_1.write(angleIncrementer);
	delay(10);
}
}
void C_MOVE(){

}
void C_MOVE_RIGHT(){

}
void C_MOVE_LEFT(){

}