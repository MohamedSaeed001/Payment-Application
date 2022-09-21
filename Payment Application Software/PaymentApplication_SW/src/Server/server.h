/*
 ============================================================================
 Name        : server.h
 Author      : Mohamed Saeed
 Created on  : Aug 18, 2022
 Description : header file for function prototypes and configuration of server
 ============================================================================
 */
#ifndef SRC_SERVER_SERVER_H_
#define SRC_SERVER_SERVER_H_

#include <stdio.h>
#include <string.h>
#include "../Terminal/terminal.h"
#include "../Card/card.h"
#include "../Std_types/std_types.h"


#define MAX_SIZE_OF_DB			255

typedef enum EN_transState_t
{
	APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t;


typedef struct ST_transaction_t
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t terminalData;
	EN_transState_t transState;
	uint32_t transactionSequenceNumber;
}ST_transaction_t;

ST_transaction_t transaction;
typedef struct ST_accountsDB_t
{
	float32_t balance;
	uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;



typedef enum EN_serverError_t
{
	OK_SERVER, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE,
}EN_serverError_t ;

extern uint8_t Account_Number;

ST_accountsDB_t ArrValidAccountsDB[MAX_SIZE_OF_DB];
ST_transaction_t Arr_transaction[MAX_SIZE_OF_DB];

EN_transState_t recieveTransactionData(ST_transaction_t *transData);
EN_serverError_t isValidAccount(ST_cardData_t *cardData);
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData);
EN_serverError_t saveTransaction(ST_transaction_t *transData);


#endif /* SCR_SERVER_SERVER_H_ */
