/*
 * communication.h
 *
 *  Created on: Jan 2, 2010
 *      Author: asher
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include <stdio.h>

extern FILE * uart;

int messageAvailable();
char * getMessage();
void initCom();



#endif /* COMMUNICATION_H_ */
