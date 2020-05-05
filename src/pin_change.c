#include<stdio.h>
#include<string.h>
//#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include "../include/pin_change.h"
#include "../include/global.h"
#include "../include/transaction.h"
#include "../include/switch_statement.h"

/**
 * @file pin_change.c
 * @brief First checks whether the existing pin matches with the pin stored in the file and on changing the pin, the new pin is updated to that file.
 * @param[in] attempt and the function returns 0 when the pin has been updated successfully
 * @detailed description attempt = 3 when the function is called for the first time. The function changes the PIN of the user only after confirming if the
 * input 'existingPin' matches with the PIN stored in the file and  the entered 'newPin' is a non-palindrome series. The user is only allowed three attempts
 * to get the existingPin correct. When the function is executed successfully, the PIN will be changed and it will be updated to the file
 */

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
         while(fgets(string,1024,fPtr)){
         b=atoi(string);
         }
     fclose(fPtr);
     fPtr=fopen("datafolder/password.txt","r+");
     int existingPinCmp;
     if(a==b) {
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
                            pin_change(3);
                     } else {
                            printf("\nnew pin has been set");
                            printf("\nThanks! Please re-login again to have access to the features of the SABM");
                           //printf("%d",originalN);
                            fprintf(fPtr,"%d",originalN);
                            exit(0);
                       }

         } else {
                   printf("\nInvalid entry\n");
                   pin_change(3);
           }
        }
    } else {
            printf("\nInCorrect password\n");
            attempt--;
            if(attempt==0){
                printf("\nSorry, You have exceeded the number of times that you need to input the correct password");
                attempt=4;
                exit(0);
            }
            pin_change(attempt);
      }
    }
    int another_transaction;
    printf("\n Do you want to continue transaction? Press 1 to continue and 2 to exit");
    scanf("%d",&another_transaction);
    if((another_transaction==1)||(another_transaction==2)){
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

