#include "ring.h"
#include <stdio.h>
#include "usart.h"



int main (void)
{
	USART_Init();
char k;
	
	 USART_WriteString("ALAMAKO");
	 USART_GetChar(&k);
	printf("%c\n\r", k);
	
		 USART_GetChar(&k);
	printf("%c\n\r", k);
	
		 USART_GetChar(&k);
	printf("%c\n\r", k);
//		USART_GetChar(&k);
	//printf("%c\n\r", k);
		//	USART_GetChar(&k);
//	printf("%c\n\r", k);
	
return 0;	
	
}
