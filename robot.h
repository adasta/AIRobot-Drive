/*
 * robot.h
 *
 *  Created on: Dec 9, 2009
 *      Author: asher
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#ifndef roboRocks
#define roboRocks

#include "Encoder.h"


#define feedBackLoopFrequency 30.5
#define EncoderPulsesPerRevolution 564
#define wheelDiameter 6.0325 //cm  (2.375 inches)
#define EncoderPulsePerCm EncoderPulsesPerRevolution/(wheelDiameter*2*3.14)


void RobotInit();

  struct robotState  //standard robot has ultrasound and speed controlled wheels
{
		struct wheel
		{
			int kpGain;  // proportional gain constant
			int kiGain; //  integral gain constant
			int kDGain; // derivative gain constant
			Encoder encoder;
			int previousCount;
			int vel;
			int velD;
			int countD; // desired distance in encoder counts
			int velCM;   // current velocity counts
			int error;
			int errorp;
			char blacklashFlag;// Use for backlash control
			int pwmPeriod;

		}  rightWheel,  leftWheel;
		char feedbackState;
} ;
extern robotState Robot;


 void initEncoders();
 void initSpeedControl();

 void setLeftMotorSpeed(float cmPerSec);
 void setRightMotorSpeed(float cmPerSec);
 void move(float cmPerSec, float distanceCM);
 void turn(float cmPerSec, int AngleDegrees);



void RobotInit();

void stop();

#endif
#endif /* ROBOT_H_ */
