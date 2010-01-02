#include "WProgram.h"
extern "C"{
	#include <avr/interrupt.h>
	#include <avr/io.h>
}

#include "robot.h"
#include "global.h"


int main(void)
{
	init();
	RobotInit();
	initEncoders();

	Serial.begin(9600);

Serial.println("hello start");

setLeftMotorSpeed(0);
setRightMotorSpeed(0);

while(1==1){
	delay(1000);
	Serial.print("EL : ");
	Serial.print(Robot.leftWheel.encoder.count());
	Serial.println(" ");
	Serial.print("RL : " );
	Serial.print(Robot.rightWheel.encoder.count());
	Serial.println(  " ");
}

}

