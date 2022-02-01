#include <lpc214x.h>   

#define LED_1	0
#define SW_1	1

#define LED_2	30
#define SW_2	31

int main() 
{
	unsigned int  SW_1_Status;
	unsigned int  SW_2_Status;

	PINSEL0 = 0x00000000;
	IODIR0 = ((1<<LED_1) | (0<<SW_1));				// LED pin as output and Switch Pin as input 
	
	PINSEL1 = 0x00000000;
	IODIR0 = ((1<<LED_2) | (0<<SW_2));				// LED pin as output and Switch Pin as input 

	IOPIN0 = 0X00000000;
		
	while(1)
	{
		SW_1_Status = (IOPIN0>>SW_1) & 0x01 ;	// Read the switch status
					 
		if(SW_1_Status == 1)										//Turn ON/OFF LEDs depending on switch status
		{  
			IOPIN0 = (1<<LED_1);
		}
		else
		{
			IOPIN0 = (0<<LED_1);
		}

/*		SW_2_Status = (IOPIN0>>SW_2) & 0x01 ;	// Read the switch status
					 
		if(SW_2_Status == 1)										//Turn ON/OFF LEDs depending on switch status
		{  
			IOPIN0 = (1<<LED_2);
		}
		else
		{
			IOPIN0 = (0<<LED_2);
		}	*/	
	}
}