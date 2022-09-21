/*
 ============================================================================
 Name        : terminal.c
 Author      : Mohamed Saeed
 Created on  : Aug 18, 2022
 Description : Source file to implement terminal functions
 ============================================================================
 */

#include "../Terminal/terminal.h"


ST_terminalData_t terminalData = {0};


EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
	uint8_t index,temp;
	uint8_t buff[11];

	strcpy( (char *)termData->transactionDate , _strdate((char*)buff));

	/* 08/22/22 */

	for(index=0 ;index<2 ;index++)
	{
		temp = termData->transactionDate[index];
		termData->transactionDate[index] = termData->transactionDate[index+3];
		termData->transactionDate[index+3] = temp;
	}		/* 22/08/22 */

	termData->transactionDate[8] = NULL_CH;

	if(termData->transactionDate == NULL_CH)
	{
		return WRONG_DATE;
	}
	else
	{
		if(strlen((const char*)termData->transactionDate) < 8)
		{
			return WRONG_DATE;
		}
		else
		{
			return OK_TERMINAL;
		}
	}
}

/* 22/08/22 */
/* 08/22 */
EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData)
{
	uint8_t flag = FALSE;
	/*check if the years is equal */
	if((termData->transactionDate[7] == cardData->cardExpirationDate[4]) && (termData->transactionDate[6] == cardData->cardExpirationDate[3]))
	{
		/* check if the first element of month is equal and second element of user date is greater than second element of OS date */
		if((termData->transactionDate[3] == cardData->cardExpirationDate[0]) && (termData->transactionDate[4] < cardData->cardExpirationDate[1]))
		{
			flag = TRUE;
		}
		/* check if the first element of month for OS is smaller than first element of user date and first element of user month equal 1 */
		else if((termData->transactionDate[3] < cardData->cardExpirationDate[0]) && (cardData->cardExpirationDate[0] == '1'))
		{
			flag = TRUE;
		}
		else
		{
			flag = FALSE;
		}
	}
	/* check if the first element of year for user date is greater than first element of year for OS */
	else if((termData->transactionDate[6] < cardData->cardExpirationDate[3]))
	{
		flag = TRUE;
	}
	/* check if the first or second element of year for OS is greater than user date */
	else if((termData->transactionDate[7] > cardData->cardExpirationDate[4]) || (termData->transactionDate[6] > cardData->cardExpirationDate[3]))
	{
		flag = FALSE;
	}
	/* check if the second element of year for user date is greater than second element of year for OS date */
	else if((termData->transactionDate[7] < cardData->cardExpirationDate[4]))
	{
		/* check if the first element of year for user date is greater than or equal to first element of year for OS date */
		if((termData->transactionDate[6] < cardData->cardExpirationDate[3]) || (termData->transactionDate[6] == cardData->cardExpirationDate[3]))
		{
			flag = TRUE;
		}
		else{}
	}
	else{}

	if(flag == TRUE)
	{
		return OK_TERMINAL;
	}
	else
	{
		return WRONG_EXP_DATE;
	}
}


EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
	printf("\n\n Please Enter The Transaction Amount : ");
	scanf("%f",&termData->transAmount);

	if(termData->transAmount <= 0)
	{
		return INVALID_AMOUNT;
	}
	else
	{
		return OK_TERMINAL;
	}
}


EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
	if(termData->maxTransAmount < termData->transAmount)
	{
		return EXCEED_MAX_AMOUNT;
	}
	else
	{
		return OK_TERMINAL;
	}
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
{
	termData->maxTransAmount = TRANSACTION_MAX_AMOUNT;
	if(termData->transAmount <= 0)
	{
		return INVALID_MAX_AMOUNT;
	}
	else
	{
		return OK_TERMINAL;
	}
}
