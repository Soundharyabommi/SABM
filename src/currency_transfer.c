#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "../include/currency_transfer.h"
#include "../include/global.h"
#include "../include/transaction.h"
#include "../include/switch_statement.h"

/**
 * @file currency_transfer.c
 * @brief The function transfers the amount between chequing and savings account and writes the transfer history to the file.
 * @param[in] there is no input parameter and the function does not return anything. On successful execution, the history of transfers made will be written to the file and balance of chequing and savings account will be updated
 */


//Transfer funds between chequing and savings
float balanceInChequing;
float balanceInSaving;
void currency_transfer(){

     unsigned int amountToTransfer;
     int fromAccountChoice;
     int toAccountChoice;
     FILE *fPtr;
    //mkdir("c:\\cfile");
     fPtr=fopen("datafolder/data.txt","a");
     if(fPtr==NULL){
        printf("not exist");
        exit(EXIT_FAILURE);
     }
     printf("\nEnter the account from which you want to transfer the fund  \n 1.chequing \t 2.saving\n");
     scanf("%d",&fromAccountChoice);
     printf("\nEnter the account to which you want the fund to be transferred  \n 1.chequing \t 2.saving\n");
     scanf("%d",&toAccountChoice);
     if(fromAccountChoice==1 && toAccountChoice==2){
           printf("\nPlease enter the amount to be transferred\n");
           scanf("%d",&amountToTransfer);
           if((amountToTransfer<=balanceInChequing)&& (amountToTransfer!=0)){
                       balanceInChequing=balanceInChequing - amountToTransfer;
                       balanceInSaving=balanceInSaving + amountToTransfer;
                       fprintf(fPtr,"\nAmount transferred=%d and ",amountToTransfer);
                       printf("\nThe amount has been transferred");
                       printf("\nThe current balance of chequing account is %f and saving account is %f",balanceInChequing,balanceInSaving);
                       fprintf(fPtr,"The current balance of chequing account is %f and saving account is %f",balanceInChequing,balanceInSaving);
            } else {
                        if(amountToTransfer>balanceInChequing){
                                printf("\n There are no sufficient funds to make a transfer");
                        } else {
                                 printf("\nPlease enter valid amount to be transferred");
                          }
              }
     } else if(fromAccountChoice==2 && toAccountChoice==1){
                printf("\nPlease enter the amount to be transferred\n");
                scanf("%d",&amountToTransfer);
                if((amountToTransfer<=balanceInSaving)&&(amountToTransfer!=0)){
                                  balanceInChequing=balanceInChequing + amountToTransfer;
                                  balanceInSaving=balanceInSaving - amountToTransfer;
                                  fprintf(fPtr,"\nAmount transferred=%d and ",amountToTransfer);
                                  printf("\nThe amount has been transferred");
                                  printf("\nThe current balance of chequing account is %f and saving account is %f",balanceInChequing,balanceInSaving);
                                  fprintf(fPtr,"The current balance of chequing account is %f and saving account is %f",balanceInChequing,balanceInSaving);
                } else {
                                 if(amountToTransfer>balanceInSaving) {
                                        printf("\n There are no sufficient funds to make a transfer");
                                 } else {
                                        printf("\nPlease enter valid amount to be transferred");
                                   }
                  }
      } else if((fromAccountChoice==1 && toAccountChoice==1)||(fromAccountChoice==2 && toAccountChoice==2)){
                    printf("\nInvalid choice");
        } else {
               printf("\nPlease enter a valid choice");
          }
    //fflush(stdin);
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

}
