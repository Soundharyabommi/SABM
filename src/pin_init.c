#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#include "../include/pin_init.h"
#include "../include/global.h"
int pin_init(int counter)
{
    int a,b;
    char string[1024];
    if(counter<=3){
        char PIN[4];
        printf("\nEnter your 4-DIGIT PIN: ");
        //scanf("%s",&PIN);
        gets(PIN);
        a=atoi(PIN);
        FILE *fPtr;
        fPtr=fopen("../datafolder/password.txt","r");
        if(fPtr==NULL){
        printf("not exist");
        exit(EXIT_FAILURE);
        }
        while(fgets(string,1024,fPtr))
        {
            b=atoi(string);
        }
        //char asci[]="1234";
        int pincmp; //=strcmp(PIN,"1234");
        if(a==b)
            pincmp=0;
        if(pincmp==0){
            printf("\nCorrect password");
            counter = 4;}
        else{
            printf("\nInCorrect password\n");
            counter--;
            if(counter==0){
                printf("\nSorry, You have exceeded the number of times that you need to input the correct password");
                printf("\nThe system is temporarily confiscated\n");
                counter=4;
                exit(0);
            }
            pin_init(counter);
        }
    }
    return 0;
}
