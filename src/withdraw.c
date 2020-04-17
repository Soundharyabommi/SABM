#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include"withdraw.h"
#include "globals.h"

//float balanceInChequing = 1000;
//float balanceInSaving = 1000;
//float dailyLimit=500
    int withdraw()
    {
    int amountToWidthdraw;
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
    }






