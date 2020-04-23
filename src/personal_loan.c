#include<stdio.h>
#include<stdlib.h>
#include "../include/personal_loan.h"
#include "../include/transaction.h"
#include "../include/switch_statement.h"

/**
 * @file personal_loan.c
 * @brief places request for personal loan
 * @param[in] there is no input parameter and the function does not return anything
 */

void personal_loan(){
  printf("\nThanks! Your request for personal loan has been placed.");
  printf("\nNote: You will be contacted from the bank shortly\n");
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

