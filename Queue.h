/*
 * Queue.h
 *
 *  Created on: Dec 8, 2016
 *      Author: VinayDivakar
 */

#ifndef QUEUE_H_
#define QUEUE_H_
/* Circular buffer size, Change it as per you needs */
#define BUFFER_SIZE			1024
#define FALSE	0
#define TRUE	1

/* Function to feed samples into the buffer */
typedef struct{
	char buffer[BUFFER_SIZE];
	int front;
	int rear;
	unsigned char empty;
	unsigned char full;
}Q_BufferT, *Q_BufferP;

/* Extern Functions */
extern signed char Put_Sample(unsigned char rf_sample);
extern signed char Fetch_Sample(unsigned char *rf_sample);
extern void InitializeQueue();


#endif /* QUEUE_H_ */
