#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include"deposit.h"
#include "globals.h"

//float balanceInChequing = 1000;
//float balanceInSaving = 1000;
int deposit(){
    int amountToDeposit;
    FILE *fPtr;
    //mkdir("c:\\cfile");
    fPtr=fopen("datafolder/data.txt","a");
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
}
