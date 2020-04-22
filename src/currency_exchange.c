#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../include/currency_exchange.h"
#include "../include/transaction.h"
#include "../include/switch_statement.h"

int currency_exchange( int cash,char *type)
 {
    int ch;
    printf("\nchoose the conversion type\n 1. INR \n 2. USD \n 3. CAD\n");
    scanf("%d",&ch);
    printf("\nPlease deposit the currency to be exchanged\n");
    FILE *fpr;
    char str[100];
    //mkdir("c:\\cfile");
    fpr=fopen("../datafolder/conversion.txt","r");
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
    fclose(fpr);
    printf("\nThanks for depositing.Please collect your converted currency\n");
    switch(ch)
    {
    case 1:
            if(strcmp(type,"INR")==0) {
                printf("\nThe from and to conversion type are same\n");
            }
            if(strcmp(type,"USD")==0) {
                printf("\nUSD to INR : %lf\n",cash*76.62);
            }
            if(strcmp(type,"CAD")==0){
                printf("\nCAD to INR : %lf\n",cash*54.64);
            }
            break;

    case 2:
            if(strcmp(type,"USD")==0) {
                printf("\nThe from and to conversion type are same\n");
            }
            if(strcmp(type,"INR")==0) {
                printf("\nINR to USD : %lf\n",cash*.013);
            }
            if(strcmp(type,"CAD")==0) {
                printf("\nCAD to USD : %lf\n",cash*0.71);
            }
            break;

    case 3:
            if(strcmp(type,"CAD")==0) {
                printf("\nThe from and to conversion type are same\n");
            }
            if(strcmp(type,"INR")==0) {
                printf("\nINR to CAD : %lf\n",cash*.018);
            }
            if(strcmp(type,"USD")==0) {
                printf("\nUSD to CAD : %lf\n",cash*1.40);
            }
            break;
    }
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
    return 0;
 }
