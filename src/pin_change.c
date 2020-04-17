#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include"pin_change.h"
#include "globals.h"
int pin_change(int attempt)
{
    FILE *fPtr;
    char string[1024];
    int a,b;
    fPtr=fopen("datafolder/password.txt","r"); //opening file to check if the existing pin entered by the user matches the old pin stored in a file
    if(attempt<=3){
     char existingPin[5];
     printf("Please enter your existing PIN:");
     scanf("%s",&existingPin);
     a=atoi(existingPin);
         while(fgets(string,1024,fPtr))
     {
         b=atoi(string);
     }
     fclose(fPtr);
     fPtr=fopen("datafolder/password.txt","r+");
     int existingPinCmp;
     if(a==b)
        existingPinCmp=0;
     if(existingPinCmp==0){
        attempt = 4;
        int newPin;
        if(fPtr==NULL){
        printf("not exist");
        exit(EXIT_FAILURE);
        }
        int reversedN = 0, remainder, originalN;
        printf("\nPlease enter a new 4-digit PIN:");
        scanf("%d",&newPin);
        //calculates length of a given number
        int nDigits=1+(int)log10(newPin);
        //printf("\nnewPin has  %d digits.\n",nDigits); //can be used to output the length of digit
        if(nDigits==4){
        //now check whether the newPin is a palindrome or not
        originalN = newPin;

    // reversed integer is stored in reversedN
        while (newPin != 0) {
        remainder = newPin % 10;
        reversedN = reversedN * 10 + remainder;
        newPin /= 10;
    }


    // palindrome if orignalN and reversedN are equal
       if (originalN == reversedN){
        printf("\nThe entered PIN series is a palindrome.Please set a non-palindrome number\n");
        pin_change(3);}

       else{
        printf("\nnew pin has been set");
        //printf("%d",originalN);
        fprintf(fPtr,"%d",originalN);
        }

    }
    else{ printf("\nInvalid entry\n");
    pin_change(3);}
    }
     else{
            printf("\nInCorrect password\n");
            attempt--;
            if(attempt==0){
                printf("\nSorry, You have exceeded the number of times that you need to input the correct password");
                attempt=4;}
            pin_change(attempt);}
    }
            else
            {
                printf("\nThanks for using our SABM service");
                return 0;
            }
       return 0;
     }

