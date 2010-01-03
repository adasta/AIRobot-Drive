/*
 * communication.c
 *
 *  Created on: Jan 2, 2010
 *      Author: asher
 */
#include "communication.h"
#include "HardwareSerial.h"
#include <stdio.h>
#include <avr/io.h>


FILE * uart;
char message[100];
int messageIndex;
int messageDone;

int writeChar(char c , FILE * stream){


	Serial.write(c);


	return 0;
}
int readChar(FILE *stream){
	  int c =-1;
	  while(c==-1){
	  c = Serial.read();
	  }
	  return c;
}

int messageAvailable(){
	while( Serial.available() ){
		char c  = Serial.read();
		if ( (c == '\n') || (c == '\r') ){
			if (!messageDone){
				message[messageIndex] = 0;
				messageIndex++;
				messageDone =1;
			}
			 messageIndex = 0;
		}
		else{
			message[messageIndex] = c ;
			messageIndex++;
		}
	}
	return messageDone;
}

char  * getMessage(){
	messageDone =0;
	return message;
}

void initCom(){
	uart = fdevopen(writeChar, readChar);
	messageDone = 0;
	messageIndex= 0;
}


