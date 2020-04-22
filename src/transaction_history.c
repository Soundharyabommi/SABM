#include<stdio.h>
#include<stdlib.h>
#include "../include/transaction_history.h"
#include "../include/transaction.h"
#include "../include/switch_statement.h"
void transaction_history(){
    FILE *fpr;
    printf("\nYour recent transactions:\n");
    char str[100];
    //mkdir("c:\\cfile");
    fpr=fopen("../datafolder/data.txt","r");
     //open the file to display the contents
    //the file will contain the history of withdrawal and deposit made
    if(fpr==NULL){
        printf("not exist");
        exit(EXIT_FAILURE);
    }
    while(fgets(str,100,fpr)!=NULL)
    {
            printf("%s",str);
    }
    printf("\n**************No more transactions to show****************************************\n");
    fflush(stdin);
	fclose(fpr);
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

