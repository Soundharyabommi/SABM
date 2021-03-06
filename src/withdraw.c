#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "../include/withdraw.h"
#include "../include/global.h"
#include "../include/transaction.h"
#include "../include/switch_statement.h"

/**
 * @file withdraw.c
 * @brief performs withdrawal and stores the withdrawal operation done by the user to the file.
 * @param[in] there is no input parameter
 * @return zero
 */

float  balanceInChequing =1000;
float balanceInSaving =1000;
int withdraw(){
    int amountToWidthdraw;
    float dailyLimit =500;
    FILE *fPtr;
    //mkdir("c:\\cfile");
    fPtr=fopen("datafolder/data.txt","a");
    if(fPtr==NULL){
        printf("not exist");
        exit(EXIT_FAILURE);
    }
    int withdrawAccountChoice;
    printf("\nPlease enter account you want to withdraw from: \n 1. Chequing \t 2.Saving\n");
    scanf("%d",&withdrawAccountChoice);

    if((withdrawAccountChoice==1)||(withdrawAccountChoice==2)){
      printf("Please enter amount to withdraw: ");
      scanf("%d", &amountToWidthdraw);

    if(withdrawAccountChoice==1){
                if(amountToWidthdraw > balanceInChequing){
                        printf("There is no sufficient funds in your chequing account");
                        // ask them to enter amount again
                        withdraw();

                } else {
                // this means account has something so that u can withdraw
                // but check for daily limit and update the balance variable
                      if(amountToWidthdraw<=dailyLimit) {
                                           fprintf(fPtr,"Amount to withdraw = %d",amountToWidthdraw);
                                           balanceInChequing = balanceInChequing - amountToWidthdraw;

                                           printf("You have withdrawn %d and your new balance in chequing account is %f ", amountToWidthdraw, balanceInChequing);
                                           fprintf(fPtr,"Balance in chequing = %f\n",balanceInChequing);


                      } else {
                     printf("\nYour daily limit has been exceeded");
                        }
                  }
    }  else if(amountToWidthdraw > balanceInSaving){
          printf("There is no sufficient funds in your savings account");
          // ask them to enter amount again
          withdraw();
       } else {
                // this means account has something so that u can withdraw
                // but check for daily limit and update the balance variable
                      if(amountToWidthdraw<=dailyLimit) {
                                           balanceInSaving = balanceInSaving - amountToWidthdraw;

                                           printf("You have withdrawn %d and your new balance in savings account is %f ", amountToWidthdraw, balanceInSaving);
                                           fprintf(fPtr,"Balance in savings = %f\n",balanceInSaving);




                      } else {
                     printf("\nYour daily limit has been exceeded");
                        }
                  }
    } //end of if for withdraw choice and else starts
    else {
        printf("\n Invalid account choice");
        withdraw();
    }// end of else for choice
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
}//end of withdraw






