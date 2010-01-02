#include "WProgram.h"
extern "C"{
	#include <avr/interrupt.h>
	#include <avr/io.h>
}

#include "robot.h"
#include "global.h"
#include <stdio.h>
#include "communication.h"



int main(void)
{
	init();
	RobotInit();
	initEncoders();
	initCom();

	Serial.begin(9600);

Serial.println("hello start");
fprintf(uart, "Hello From New transmision scheme\n");

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

	if(messageAvailable()){
		char * message = getMessage();
		char command[20];
		int L, R;
		sscanf(message,"%s %d %d", command, &L, &R);
		setLeftMotorSpeed(L);
		setRightMotorSpeed(R);
		fprintf(uart, "%s\n", message);
	}
}

}

