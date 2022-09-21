/*
 ============================================================================
 Name        : terminal.h
 Author      : Mohamed Saeed
 Created on  : Aug 18, 2022
 Description : header file for function prototypes and configuration of card
 ============================================================================
 */

#ifndef SRC_TERMINAL_TERMINAL_H_
#define SRC_TERMINAL_TERMINAL_H_

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../Card/card.h"
#include "../Std_types/std_types.h"


#define TRANSACTION_MAX_AMOUNT			5000.0


typedef struct ST_terminalData_t
{
float32_t transAmount;
float32_t maxTransAmount;
uint8_t transactionDate[11];
}ST_terminalData_t;

ST_terminalData_t terminalData;


typedef enum EN_terminalError_t
{
  OK_TERMINAL, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;



EN_terminalError_t getTransactionDate(ST_terminalData_t *termData);
EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData);
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData);
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData);

#endif /* SCR_TERMINAL_TERMINAL_H_ */
