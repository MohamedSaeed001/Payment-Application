/*
 ============================================================================
 Name        : main.c
 Author      : Mohamed Saeed
 Created on  : Aug 18, 2022
 Description : main function
 ============================================================================
 */

#include <stdio.h>
#include "../src/Application/app.h"
#include "../src/Std_types/std_types.h"

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);

	uint8_t choice;
	uint8_t nothing;

	printf("\n\n____________________________________________________");
	printf("\n\t\tHELLO");
	printf("\n____________________________________________________");

	printf("\n Start The System (Y,N) : ");
	scanf("%c",&choice);

	if((choice == 'Y') || (choice == 'y'))
	{
		appStart();
	}
	else
	{
		printf("\n Thanks ...!!! ");
		printf("\n---------------------------------------------------------------");

		scanf("%c",&nothing);
		main();
	}
	return 0;
}
