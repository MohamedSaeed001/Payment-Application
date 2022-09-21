/*
 ============================================================================
 Name        : card.h
 Author      : Mohamed Saeed
 Created on  : Aug 18, 2022
 Description : header file for function prototypes and configuration of card
 ============================================================================
 */
#ifndef SRC_CARD_CARD_H_
#define SRC_CARD_CARD_H_


#include <stdio.h>
#include <string.h>
#include "../Std_types/std_types.h"



typedef struct ST_cardData_t
{
  uint8_t cardHolderName[25];
  uint8_t primaryAccountNumber[20];
  uint8_t cardExpirationDate[6];
}ST_cardData_t;

ST_cardData_t cardData;


typedef enum EN_cardError_t
{
OK_CARD, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;


EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);



#endif /* SCR_CARD_CARD_H_ */
