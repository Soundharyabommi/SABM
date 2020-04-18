#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include "switch_statement.h"
#include "global.h"

int switch_statement(int c)
{
    switch(c)
    {
       case 1:
              withdraw();
              break;

       case 2:
              deposit();
              break;
       case 3:
              balance();
              break;
       case 4:
              currency_transfer();
              break;
       case 5:
              transaction_history();
              break;

       case 6:;
           int attempt = 3;
           pin_change(attempt);
           break;


       case 7:;
           char curr[4];
           int amt;
           printf("\nInput the type of currency which you want to convert in (INR/CAD/USD): ");
           scanf("%s",&curr);
           printf("\nPlease enter the amount to be exchanged: ");
           scanf("%d",&amt);
           if(strlen(curr)>3)
           {
             printf("\nCurrency type length too long!!");
             return 0;
           }
           currency_exchange(amt,curr);
           break;

       case 8:
           pay_bill();
           break;


       case 9:
            cheque_book_request();
            break;

       case 10:
            personal_loan();
            break;

       case 11:
            help();
            break;

       case 12:
            printf("Thanks for using our SABM service");
            exit(0);
            break;

       default:
            printf("Invalid choice");
            break;
    }
    return 0;

} // end of switch statement
