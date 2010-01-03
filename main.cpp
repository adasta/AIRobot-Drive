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

	Serial.begin(57600);

setLeftMotorSpeed(0);
setRightMotorSpeed(0);
DDRD &= ~_BV(PIN1);


while(1==1){
	if(messageAvailable()){
		char * message = getMessage();
		char command[20];
		int L, R;
		sscanf(message,"%s %d %d", command, &L, &R);

		if (command[0] == 'W'){
			DDRD |= _BV(PIN1);
			fprintf(uart, "%s %d %d\n", command, L, R);
			DDRD &= ~_BV(PIN1);

			while (!messageAvailable());

			char ack[10];
			sscanf(getMessage(), " %s", ack);
			if (ack[0] == 'A'){
				setLeftMotorSpeed(L);
				setRightMotorSpeed(R);
			}
		}

		if (command[0] == 'E'){
			DDRD |= _BV(PIN1);
			int Le = Robot.leftWheel.encoder.count();
			int Re = Robot.rightWheel.encoder.count();
			fprintf(uart, "E %d %d\n", Le, Re);
			DDRD &= ~_BV(PIN1);
		}
		if ((command[0] == 'C') && (command[1] == 'E')){
			Robot.leftWheel.encoder.clearCount();
			Robot.rightWheel.encoder.clearCount();
			DDRD |= _BV(PIN1);
			fprintf(uart, "CE\n", L, R);
			DDRD &= ~_BV(PIN1);
		}

	}
}

}

