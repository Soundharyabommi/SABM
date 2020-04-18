#include<stdio.h>
#include "cheque_book_request.h"

void cheque_book_request(){
  printf("\nThanks! Cheque book request has been placed.");
  printf("\nNote: The bank will be notified shortly. The cheque book will be couriered to your registered address.");
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
  }

