#include<stdio.h>
#include<stdlib.h>
#include "../include/pay_bill.h"
#include "../include/global.h"
#include "../include/transaction.h"
#include "../include/switch_statement.h"

//assuming that the credit card number, electricity bill number and mobile number already exist in the bank record but not part of the problem
/**
 * @file pay_bill.c
 * @brief The function performs the bill payment operation for Credit card, electricity bill and mobile bill and stores the details of the amount withdrawn from chequing or saving to the file.
 * @param[in] there is no input parameter
 * @return zero
 */


int pay_bill()
{

    int choice;
    printf("\nPlease choose your option for bill payment  \n 1.Credit Card Bill  \t 2.Electricity Bill  \t   3.Mobile Bill\n");
    scanf("%d",&choice);
    FILE *fPtr;
    //mkdir("c:\\cfile");
    fPtr=fopen("../datafolder/data.txt","a");
    if(fPtr==NULL){
        printf("not exist");
        exit(EXIT_FAILURE);
    }
    if((choice==1)||(choice==2)||(choice==3)){
            int payment_account_choice;
            printf("\nPlease enter account from which you want to pay: \n 1. Chequing \t 2.Savings\n");
            scanf("%d",&payment_account_choice);
            if((payment_account_choice==1)||(payment_account_choice==2)){
               int amount_to_pay;
               printf("\nPlease enter the amount you want to pay:");
               scanf("%d",&amount_to_pay);
               if(payment_account_choice==1){
                   if(amount_to_pay > balanceInChequing){
                        printf("There is no sufficient funds in your chequing account to pay the bill");
                   } else if(amount_to_pay==0){
                       printf("\nYou have not chosen a valid amount to pay");
                     } else {
                            fprintf(fPtr,"\nAmount paid for bill = %d and ",amount_to_pay);
                            balanceInChequing = balanceInChequing - amount_to_pay;
                            printf("You have made a payment of %d successfully and your new balance in chequing account is %f ", amount_to_pay, balanceInChequing);
                            fprintf(fPtr,"Balance in chequing = %f\n",balanceInChequing);
                       }
                } else if(amount_to_pay > balanceInSaving){
                    printf("There is no sufficient funds in your savings account to pay the bill");
                  } else if(amount_to_pay==0){
                       printf("\nYou have not chosen a valid amount to pay");
                     } else {
                          fprintf(fPtr,"\nAmount paid for bill = %d and",amount_to_pay);
                          balanceInSaving = balanceInSaving - amount_to_pay;
                          printf("You have made a payment of %d successfully and your new balance in savings account is %f ", amount_to_pay, balanceInSaving);
                          fprintf(fPtr,"Balance in savings = %f\n",balanceInSaving);
                       }

            } else {
                   printf("\nInvalid Payment Account Choice");
              }//end of else for oayment account choice




     } else {
     printf("\nInvalid Choice");
       }
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
}

