#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include "balance.h"
#include "global.h"
//start of check balance function
void balance(){

    printf("\nYour balance in chequing account is: %f", balanceInChequing);
    printf("\nYour balance in savings account is: %f", balanceInSaving);
    int another_transaction;
    printf("\n Do you want to continue transaction? Press 1 to continue and 2 to exit");
    scanf("%d",&another_transaction);
    if((another_transaction==1)||(another_transaction==2))
    {
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
}//end of check balance function

