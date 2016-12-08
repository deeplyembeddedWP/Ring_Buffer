/*
 * Queue.c
 *
 *  Created on: Dec 8, 2016
 *      Author: VinayDivakar
 */

#include "Queue.h"

static Q_BufferT My_buffer;

/* Initialize the Queue */
void InitializeQueue()
{
	/*  Set up the queue for operation.  */
	My_buffer.front = 0;
	My_buffer.rear  = 0;
	My_buffer.empty = TRUE;
	My_buffer.full  = FALSE;
}

/* Function to feed samples into the buffer */
signed char Put_Sample(unsigned char rf_sample)
{
	/*  Puts an entry at the end of the queue, if not full. Returns 0 if successful, -1 if failed */
	if (!My_buffer.full)
	{
		My_buffer.empty = FALSE;
		My_buffer.buffer[My_buffer.rear] = rf_sample;
		My_buffer.rear = (My_buffer.rear + 1) % BUFFER_SIZE;
		if (My_buffer.rear == My_buffer.front)
			My_buffer.full = TRUE;
		return FALSE;
	}
	else
		return -1;
}

/* Function to read samples from the buffer */
signed char Fetch_Sample(unsigned char *rf_sample)
{
	signed char ret;

	/* Fetches the sample from the front of the queue, if not empty. Returns 0 if successful, -1 if failed */
	if (!My_buffer.empty)
	{
		ret = 0;
		My_buffer.full = FALSE;
		*rf_sample = My_buffer.buffer[My_buffer.front];
		My_buffer.front = (My_buffer.front + 1) % BUFFER_SIZE;

		if (My_buffer.front == My_buffer.rear)
			My_buffer.empty = TRUE;
	}
	else
		ret = -1;
	return ret;
}
