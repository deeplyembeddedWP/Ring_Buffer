# Ring_Buffer
A simple circular buffer that can be used for inter-process communication in embedded applications, or for anything else as well. 
A simple use case example would be something like below:

/* Interrupt Service Routine called every 100 us */
void ISR()
{
  unsigned char sample;
  sample = ReadGPIO;
  
  /* Puts the sample into the queue */
  Put_Sample(sample);
  
}

Main()
{
 unsigned char read_sample;
 signed char fetch_ret;
 while(1)
  {
    /* Read sample from the queue and prints it */
    while ((fetch_ret = Fetch_Sample(&read_sample)) == -1);
    UART_PRINT("%d", read_sample);
  }
}
