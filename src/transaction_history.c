#include<stdio.h>
#include<stdlib.h>
#include "transaction_history.h"
void transaction_history(){
    FILE *fpr;
    printf("\nYour recent transactions:\n");
    char str[100];
    //mkdir("c:\\cfile");
    fpr=fopen("c:\\cfile\\data.txt","r");
     //open the file to display the contents
    //the file will contain the history of withdrawal and deposit made
    if(fpr==NULL){
        printf("not exist");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        if(fgets(str,100,fpr)==NULL)
            break;
        else
            printf("%s",str);
    }
    printf("\n**************No more transactions to show****************************************\n");

}

