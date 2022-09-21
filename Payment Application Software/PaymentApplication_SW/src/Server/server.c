/*
 ============================================================================
 Name        : server.c
 Author      : Mohamed Saeed
 Created on  : Aug 18, 2022
 Description : Source file to implement server functions
 ============================================================================
 */

#include "server.h"


uint8_t Account_Number = 0;
uint8_t transactionSaveNumber = 0;

ST_accountsDB_t ArrValidAccountsDB[MAX_SIZE_OF_DB] = {
		{6700.0,"1236954687456321"},
		{5800.5,"9564752385461258"},
		{2000.0,"8462156912534582"},
		{4400.6,"9632154862455684"}
};


ST_transaction_t Arr_transaction[MAX_SIZE_OF_DB] = {0};


EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{
	if(isValidAccount(&cardData) == OK_SERVER)
	{
		printf("\n The Account Exist at the Server");

		if(isAmountAvailable(&terminalData) == OK_SERVER)
		{
			printf("\n You Have Enough Compared to The Balance");

			if(saveTransaction(Arr_transaction) == OK_SERVER)
			{
				 return APPROVED;
			}
			else
			{
				return INTERNAL_SERVER_ERROR;
			}

		}
		else
		{
			return DECLINED_INSUFFECIENT_FUND;
		}
	}
	else
	{
		return DECLINED_STOLEN_CARD;
	}
}


EN_serverError_t isValidAccount(ST_cardData_t *cardData)
{
	uint8_t acc_index;

	for(acc_index =0 ;acc_index < MAX_SIZE_OF_DB ;acc_index++)
	{
		if(strcmp((const char*)cardData->primaryAccountNumber, (const char*)ArrValidAccountsDB[acc_index].primaryAccountNumber) == 0)
		{
			Account_Number = acc_index;
			return OK_SERVER;

		}
		else{}

	}

	return DECLINED_STOLEN_CARD;
}


EN_serverError_t isAmountAvailable(ST_terminalData_t *termData)
{

	if(ArrValidAccountsDB[Account_Number].balance != 0.0)
	{
		if(termData->transAmount > ArrValidAccountsDB[Account_Number].balance)
		{
			return LOW_BALANCE;
		}
		else
		{
			ArrValidAccountsDB[Account_Number].balance = (ArrValidAccountsDB[Account_Number].balance) - (termData->transAmount);
			return OK_SERVER;
		}
	}
	else
	{
		return LOW_BALANCE;
	}
}


EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
	transactionSaveNumber++;
	if(transactionSaveNumber >= MAX_SIZE_OF_DB)
	{
		return SAVING_FAILED;
	}
	else
	{
		Arr_transaction[transactionSaveNumber].transactionSequenceNumber = transactionSaveNumber;
		strcpy((char*)Arr_transaction[transactionSaveNumber].cardHolderData.cardExpirationDate, (const char*)transData->cardHolderData.cardExpirationDate);
		strcpy((char*)Arr_transaction[transactionSaveNumber].cardHolderData.cardHolderName, (const char*)transData->cardHolderData.cardHolderName);
		strcpy((char*)Arr_transaction[transactionSaveNumber].cardHolderData.primaryAccountNumber, (const char*)transData->cardHolderData.primaryAccountNumber);

		strcpy((char*)Arr_transaction[transactionSaveNumber].terminalData.transactionDate, (const char*)transData->terminalData.transactionDate);
		Arr_transaction[transactionSaveNumber].terminalData.maxTransAmount = transData->terminalData.maxTransAmount;
		Arr_transaction[transactionSaveNumber].terminalData.transAmount = transData->terminalData.transAmount;

		Arr_transaction[transactionSaveNumber].transState = APPROVED;

		return OK_SERVER;
	}

}
