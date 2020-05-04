#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "../include/deposit.h"
#include "../include/global.h"
#include "../include/transaction.h"
#include "../include/switch_statement.h"

/**
 * @file deposit.c
 * @brief performs deposit operation and stores the deposit operation done by the user to the file
 * @param[in] there is no input parameter
 * @return zero
 */

int deposit(){

    int amountToDeposit;
    FILE *fPtr;
    //mkdir("c:\\cfile");
    fPtr=fopen("../datafolder/data.txt","a");
    if(fPtr==NULL){
        printf("not exist");
        exit(EXIT_FAILURE);
    }
    int paymentChoice;
    int depositAccountChoice;
    printf("\nPlease enter whether you are depositing \n 1.cash \t 2.cheque\n");
    scanf("%d",&paymentChoice);
    if ((paymentChoice==1)||(paymentChoice==2)){
            printf("\nPlease enter account you want to deposit to: \n 1. Chequing \t 2.Saving\n");
            scanf("%d",&depositAccountChoice);
            if ((depositAccountChoice==1)||(depositAccountChoice==2)){
                 printf("\nPlease enter amount to deposit: ");
                 scanf("%d", &amountToDeposit);
                 fprintf(fPtr,"Amount deposited=%d",amountToDeposit);
                 if(depositAccountChoice==1){
                            balanceInChequing = balanceInChequing+amountToDeposit;
                            printf("\nPlease insert cash/currency in the deposit slot");
                            printf("\nThank you for depositing, new balance in your chequing account is: %f", balanceInChequing);
                 } else {
                      balanceInSaving = balanceInSaving+amountToDeposit;
                      printf("\nPlease insert cash/currency in the deposit slot");
                      printf("\nThank you for depositing, new balance in your savings account is: %f", balanceInSaving);
                   }//end of else for deposit in saving


            } else{
                printf("\nInvalid Account choice");
                deposit();
              }// end of else for account choice

    } else {
        printf("\nInvalid payment choice");
        deposit();
      }//end of else for payment choice
    fflush(stdin);
    fclose(fPtr);
    int another_transaction;
    printf("\n Do you want to continue transaction? Press 1 to continue and 2 to exit");
    scanf("%d",&another_transaction);
    if((another_transaction==1)||(another_transaction==2)){
        if(another_transaction==1){
           int t1=transaction();
           switch_statement(t1);
        } else {
        exit(0);
         }
    } else {
        printf("Invalid choice");
        exit(0);
      }
    return 0;
}//end of deposit

