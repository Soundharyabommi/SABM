#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include <ctype.h>
#include "../include/pin_init.h"
#include "../include/global.h"

/**
 * @file pin_init.c
 * @brief checks whether the pin entered by the user matches with the PIN stored in the file but
 * the user is only allowed three attempts to enter the correct password to get access to the program
 * @param [in] counter and the function returns zero on successful execution
 * @detailed description counter = 3 when the function is called for the first time. The function checks whether the input entered by the user
 * matches with the one stored in the file. The user is only allowed three attempts to get the PIN correct. On successful execution, the function returns 0
 * and allows the user to access the features of the SABM
 */

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
        fPtr=fopen("datafolder/password.txt","r");
        if(fPtr==NULL){
        printf("not exist");
        exit(EXIT_FAILURE);
        }
        while(fgets(string,1024,fPtr))
        {
          
           b=atoi(string);
        }
        //char asci[]="1234";
        
        //printf("%d\n", b);
        //printf("%d\n", a);
        //int pincmp; //=strcmp(PIN,"1234");
        //if(strcmp(PIN,b)) 
           //printf("%d\n", a);
           //printf("%d\n", b);
        if(a==b)
           {  
           printf("\nCorrect password");
           counter=4;
           }
        else if(a!=b)
            {
            printf("\nInCorrect password");
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
