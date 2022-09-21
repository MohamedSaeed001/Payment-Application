/*
 ============================================================================
 Name        : app.c
 Author      : Mohamed Saeed
 Created on  : Aug 18, 2022
 Description : Source file to implement application functions
 ============================================================================
 */
#include "app.h"

void appStart(void)
{
	if(getCardHolderName(&cardData) == OK_CARD)
	{
		if(getCardPAN(&cardData) == OK_CARD)
		{
			if(getCardExpiryDate(&cardData) == OK_CARD)
			{
				if(getTransactionDate(&terminalData) == OK_TERMINAL)
				{
					if(isCardExpired(&cardData, &terminalData) == OK_TERMINAL)
					{
						printf("\n\n The Data Of Card is Correct");
						if(getTransactionAmount(&terminalData) == OK_TERMINAL)
						{
							if(setMaxAmount(&terminalData) == OK_TERMINAL)
							{
								if(isBelowMaxAmount(&terminalData) == OK_TERMINAL)
								{
									printf("\n The Transaction is Accepted");

									if(recieveTransactionData(Arr_transaction) == APPROVED)
									{
										printf("\n\n\t\t(--------------------Done--------------------)");
									}
									else if(recieveTransactionData(Arr_transaction) == INTERNAL_SERVER_ERROR)
									{
										printf("\n Internal Server Error");
										printf("\n Please Try Again ...");
										appStart();
									}
									else if(recieveTransactionData(Arr_transaction) == DECLINED_INSUFFECIENT_FUND)
									{
										printf("\n Declined Insufficient Fund");
										printf("\n Please Try Again ...");
										appStart();
									}
									else
									{
										printf("\n Declined Stolen Card");
										printf("\n Please Try Again ...");
										appStart();
									}
								}
								else
								{
									printf("\n Invalid Max Amount (The Max Amount 5000)");
									printf("\n Please Try Again ...");
									appStart();
								}
							}
							else
							{
								printf("\n Exceed Max Amount");
								printf("\n Please Try Again ...");
								appStart();
							}
						}
						else
						{
							printf("\n Invalid Amount");
							printf("\n Please Try Again ...");
							appStart();
						}
					}
					else
					{
						printf("\n The Card is Expired");
						printf("\n Please Try Again ...");
						appStart();
					}
				}
				else
				{
					printf("\n The Transaction Date Incorrect");
					printf("\n Please Try Again ...");
					appStart();
				}
			}
			else
			{
				printf("\n The Card Expiry Date Error");
				printf("\n The Format Of Date MM/YY");
				printf("\n Please Try Again ...");
				appStart();
			}
		}
		else
		{
			printf("\n The Card PAN Error");
			printf("\n Please Try Again ...");
			appStart();
		}
	}
	else
	{
		printf("\n The Card Holder Name Error");
		printf("\n Please Try Again ...");
		appStart();
	}

	printf("\n\n\n\n The Primary Account Number : %s",ArrValidAccountsDB[Account_Number].primaryAccountNumber);
	printf("\n Your Money: %.2f",ArrValidAccountsDB[Account_Number].balance);

	EndTransaction();
}

void EndTransaction(void)
{
	uint8_t choice;
	uint8_t nothing;

	scanf("%c",&nothing);
	printf("\n\n\n\n You Want to Start The System Again (Y,N) : ");
	scanf("%c",&choice);
	if((choice == 'Y') || (choice == 'y'))
	{
		appStart();
	}
	else
	{
		printf("\n Thanks ...!!! ");
	}
}
