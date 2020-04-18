#include<stdio.h>
#include<conio.h>
#include "transaction.h"
#include "global.h"

int transaction(){
    int choice;
    printf("\nPlease enter any option to be served!\n");
    printf("\n1.  Withdraw cash");
    printf("\n2.  Deposit cash/cheque");
    printf("\n3.  Balance Enquiry");
    printf("\n4.  Transfer Funds between accounts");
    printf("\n5.  View Transaction History");
    printf("\n6.  Pin Change");
    printf("\n7.  Make Foreign Currency Exchange");
    printf("\n8.  Manage Payments");
    printf("\n9.  Request Cheque Book");
    printf("\n10. Apply Personal Loan");
    printf("\n11. Request Help");
    printf("\n12. Exit");
    printf("\nInput your choice: ");
    scanf("%d",&choice);
    return(choice);
}
