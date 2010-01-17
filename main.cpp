#include "WProgram.h"
extern "C"{
	#include <avr/interrupt.h>
	#include <avr/io.h>
#include "motorcontrol.h"
#include "pwm.h"
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

	Serial.begin(19200);

setLeftMotorSpeed(0);
setRightMotorSpeed(0);


UCSR0B &= ~_BV(TXEN0);

while(1==1){
	if(messageAvailable()){
		char * message = getMessage();
		char command[20];
		int L, R;
		sscanf(message,"%s %d %d", command, &L, &R);
		if (command[0] == 'A'){
			UCSR0B |= _BV(TXEN0);
			fprintf(uart, "A\n");
			UCSR0B &= ~_BV(TXEN0);
		}


		if (command[0] == 'W'){
			UCSR0B |= _BV(TXEN0);
			fprintf(uart, "%s %d %d\n", command, L, R);

			while (!messageAvailable());

			char ack[10];
			sscanf(getMessage(), " %s", ack);
			if (ack[0] == 'A'){
				fprintf(uart, "A\n");
				setLeftMotorSpeed(L);
				setRightMotorSpeed(R);
				//fprintf(uart, "VelD %d Vel %d PWM %d  CE %d PE %d \n", Robot.leftWheel.velD, Robot.leftWheel.vel, Robot.leftWheel.pwmPeriod, Robot.leftWheel.encoder.count(), Robot.leftWheel.previousCount);
			}
			UCSR0B &= ~_BV(TXEN0);

		}

		if (command[0] == 'E'){
			UCSR0B |= _BV(TXEN0);
			int Le = Robot.leftWheel.encoder.count();
			int Re = Robot.rightWheel.encoder.count();
			fprintf(uart, "E %d %d\n", Le, Re);
			UCSR0B &= ~_BV(TXEN0);
		}
		if ((command[0] == 'C') && (command[1] == 'E')){
			Robot.leftWheel.encoder.clearCount();
			Robot.rightWheel.encoder.clearCount();
			Robot.leftWheel.previousCount =0;
			Robot.rightWheel.previousCount=0;
			Robot.rightWheel.errorp=0;
			Robot.leftWheel.errorp=0;
			UCSR0B |= _BV(TXEN0);
			fprintf(uart, "CE\n", L, R);
			UCSR0B &= ~_BV(TXEN0);
		}

	}
}

}

