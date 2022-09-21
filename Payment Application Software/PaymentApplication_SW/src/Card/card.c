/*
 ============================================================================
 Name        : card.c
 Author      : Mohamed Saeed
 Created on  : Aug 18, 2022
 Description : Source file to implement card functions
 ============================================================================
 */

#include "../Card/card.h"


ST_cardData_t cardData = {0};

EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
	uint8_t cardName[25] = {0};
	uint8_t nothing;

	scanf("%c",&nothing);
	printf("\n Please Enter The Card Holder Name : ");
	gets((char*)cardName);

	strcpy((char*)cardData->cardHolderName, (const char*)cardName);

	if(cardData->cardHolderName[0] == NULL_CH )
	{
		return WRONG_NAME;
	}
	else
	{
		if((strlen((const char*)cardData->cardHolderName) < 20) || (strlen((const char*)cardData->cardHolderName) > 24))
		{
			return WRONG_NAME;
		}
		else
		{
			return OK_CARD;
		}
	}

}



EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
	uint8_t cardExpDate[25] = {0};

	printf("\n Please Enter The Card Expiry Date (MM/YY) : ");
	gets((char*)cardExpDate);

	strcpy((char*)cardData->cardExpirationDate, (const char*)cardExpDate);


	if(cardData->cardExpirationDate[0] == NULL_CH)
	{
		return WRONG_EXP_DATE;
	}
	else
	{
		if((strlen((const char*)cardData->cardExpirationDate) < 5) || (strlen((const char*)cardData->cardExpirationDate) > 5))
		{
			return WRONG_EXP_DATE;
		}
		else
		{
			return OK_CARD;
		}
	}
}



EN_cardError_t getCardPAN(ST_cardData_t *cardData)
	{

	printf("\n Please Enter The Card PAN : ");
	gets((char*)&cardData->primaryAccountNumber);

	if(cardData->primaryAccountNumber[0] == NULL_CH)
	{
		return WRONG_PAN;
	}
	else
	{
		if((strlen((const char*)cardData->primaryAccountNumber) < 16) || (strlen((const char*)cardData->primaryAccountNumber) > 19))
		{
			return WRONG_PAN;
		}
		else
		{
			return OK_CARD;
		}
	}

}
