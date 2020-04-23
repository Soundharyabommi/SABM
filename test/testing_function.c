#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include "testing_function.h"

//start of pin initialization function



int test_pin_init(int counter){
    int a,b;
    char string[1024];
    if(counter<=3){
        char PIN[4];
        printf("\nEnter your 4-DIGIT PIN: ");
        scanf("%s",&PIN);
        //gets(PIN);
        //fgetc(stdin);
        a=atoi(PIN);
        FILE *fPtr;
        fPtr=fopen("../datafolder/password.txt","r");
        if(fPtr==NULL){
        printf("not exist");
        exit(EXIT_FAILURE);
        }
        while(fgets(string,1024,fPtr)){
            b=atoi(string);
        }
        //char asci[]="1234";
        int pincmp; //=strcmp(PIN,"1234");
        if(a==b)
            pincmp=0;
        if(pincmp==0){
            printf("\nCorrect password");
            counter = 4;
            return -1;
        } else {
            printf("\nInCorrect password\n");
            counter--;
            if(counter==0){
                printf("\nSorry, You have exceeded the number of times that you need to input the correct password");
                printf("\nThe system is temporarily confiscated\n");
                counter=4;
                return -2;
                //exit(0);
            }
            test_pin_init(counter);
        }
    }
    return -2;
}//end of pin init

//start of pin change function

int test_pin_change(int attempt)
{
    FILE *fPtr;
    char string[1024];
    int a,b;
    fPtr=fopen("../datafolder/password.txt","r"); //opening file to check if the existing pin entered by the user matches the old pin stored in a file
    if(attempt<=3){
        char existingPin[5];
        printf("Please enter your existing PIN:");
        //gets(existingPin);
        scanf("%s",&existingPin);

        a=atoi(existingPin);
        while(fgets(string,1024,fPtr)){
                b=atoi(string);
        }
        fclose(fPtr);
        fPtr=fopen("../datafolder/password.txt","r+");
        int existingPinCmp;
        if(a==b){
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
                                                 //test_pin_change(3);
                                                 return -4;
                                    } else{
                                            printf("\nnew pin has been set");
                                            printf("\nThanks!Please re-login again to get access to the features of SABM");

                                            //printf("%d",originalN);
                                            fprintf(fPtr,"%d",originalN);
                                            return 0;
                                            exit(0);
                                      }

                            } else {
                                printf("\nInvalid entry\n");
                                return -3;
                                //test_pin_change(3);
                              }
                }  } else {
                        printf("\nInCorrect password\n");
                        attempt--;
                        if(attempt==0){
                                    printf("\nSorry, You have exceeded the number of times that you need to input the correct password");
                                    attempt=4;
                                    return -2;
                                    //exit(0);
                        }
                        test_pin_change(attempt);
                    }
     }

       return -2;
}

 float balanceInChequing;
 float balanceInSaving;

 int test_currency_transfer(){

     unsigned int amountToTransfer;
     int fromAccountChoice;
     int toAccountChoice;
     FILE *fPtr;
    //mkdir("c:\\cfile");
     fPtr=fopen("../datafolder/data.txt","a");
     if(fPtr==NULL){
        printf("not exist");
        exit(EXIT_FAILURE);
     }
     printf("\nEnter the account from which you want to transfer the fund  \n 1.chequing \t 2.saving\n");
     scanf("%d",&fromAccountChoice);
     printf("\nEnter the account to which you want the fund to be transferred  \n 1.chequing \t 2.saving\n");
     scanf("%d",&toAccountChoice);
     if(fromAccountChoice==1 && toAccountChoice==2){
        printf("\nPlease enter the amount to be transferred\n");
        scanf("%d",&amountToTransfer);
       if((amountToTransfer<=balanceInChequing)&& (amountToTransfer!=0)){
       balanceInChequing=balanceInChequing - amountToTransfer;
       balanceInSaving=balanceInSaving + amountToTransfer;
       fprintf(fPtr,"\nAmount transferred=%d and ",amountToTransfer);
       printf("\nThe amount has been transferred");
       printf("\nThe current balance of chequing account is %f and saving account is %f",balanceInChequing,balanceInSaving);
       fprintf(fPtr,"The current balance of chequing account is %f and saving account is %f",balanceInChequing,balanceInSaving);
       return -5;
     } else {
        if(amountToTransfer>balanceInChequing){
        printf("\n There are no sufficient funds to make a transfer");
        return -3;
        } else {
            printf("\nPlease enter valid amount to be transferred");
            return -4;
           }
       }
     } else if(fromAccountChoice==2 && toAccountChoice==1){
         printf("\nPlease enter the amount to be transferred\n");
         scanf("%d",&amountToTransfer);
         if((amountToTransfer<=balanceInSaving)&&(amountToTransfer!=0)){
       balanceInChequing=balanceInChequing + amountToTransfer;
       balanceInSaving=balanceInSaving - amountToTransfer;
       fprintf(fPtr,"\nAmount transferred=%d and ",amountToTransfer);
       printf("\nThe amount has been transferred");
       printf("\nThe current balance of chequing account is %f and saving account is %f",balanceInChequing,balanceInSaving);
       fprintf(fPtr,"The current balance of chequing account is %f and saving account is %f",balanceInChequing,balanceInSaving);
       return -5;
     }
     else{
        if(amountToTransfer>balanceInSaving){
        printf("\n There are no sufficient funds to make a transfer");
        return -3;
        } else {
            printf("\nPlease enter valid amount to be transferred");
            return -4;
          }
     }
      }else if((fromAccountChoice==1 && toAccountChoice==1)||(fromAccountChoice==2 && toAccountChoice==2)){
      printf("\nInvalid choice");
      return -1;
      }
      else{
        printf("\nPlease enter a valid choice");
        return -2;
      }
      fflush(stdin);
      fclose(fPtr);


    } // end of currency transfer

// withdraw
int test_withdraw()
    {
    int amountToWidthdraw;
    float dailyLimit =500;
    FILE *fPtr;
    //mkdir("c:\\cfile");
    fPtr=fopen("../datafolder/data.txt","a");
    if(fPtr==NULL){
        printf("not exist");
        exit(EXIT_FAILURE);
    }
    int withdrawAccountChoice;
    printf("\nPlease enter account you want to withdraw from: \n 1. Chequing \t 2.Saving\n");
    scanf("%d",&withdrawAccountChoice);

    if((withdrawAccountChoice==1)||(withdrawAccountChoice==2)){
      printf("Please enter amount to withdraw: ");
      scanf("%d", &amountToWidthdraw);

    if(withdrawAccountChoice==1){
                if(amountToWidthdraw > balanceInChequing){
                        printf("There is no sufficient funds in your chequing account");
                        return -1;
                        // ask them to enter amount again
                        //withdraw();

                } else {
                // this means account has something so that u can withdraw
                // but check for daily limit and update the balance variable
                      if(amountToWidthdraw<=dailyLimit) {
                                           fprintf(fPtr,"Amount to withdraw = %d",amountToWidthdraw);
                                           balanceInChequing = balanceInChequing - amountToWidthdraw;

                                           printf("You have withdrawn %d and your new balance in chequing account is %f ", amountToWidthdraw, balanceInChequing);
                                           fprintf(fPtr,"Balance in chequing = %f\n",balanceInChequing);
                                           return -3;


                      } else {
                     printf("\nYour daily limit has been exceeded");
                     return -2;
                        }
                  }
    }  else if(amountToWidthdraw > balanceInSaving){
          printf("There is no sufficient funds in your savings account");
          return -1;
          // ask them to enter amount again
          //withdraw();
       } else {
                // this means account has something so that u can withdraw
                // but check for daily limit and update the balance variable
                      if(amountToWidthdraw<=dailyLimit) {
                                           balanceInSaving = balanceInSaving - amountToWidthdraw;

                                           printf("You have withdrawn %d and your new balance in savings account is %f ", amountToWidthdraw, balanceInSaving);
                                           fprintf(fPtr,"Balance in savings = %f\n",balanceInSaving);
                                           return -3;




                      } else {
                     printf("\nYour daily limit has been exceeded");
                     return -2;
                        }
                  }
    } //end of if for withdraw choice and else starts
    else {
        printf("\n Invalid account choice");
        test_withdraw();
    }// end of else for choice
    fflush(stdin);
    fclose(fPtr);
	return 0;
    }//end of withdraw

int test_balance(){

    printf("\nYour balance in chequing account is: %f", balanceInChequing);
    printf("\nYour balance in savings account is: %f", balanceInSaving);
    return 0;

}//end of check b

//start of deposit
int test_deposit(){

    int amountToDeposit;
    FILE *fPtr;
    //mkdir("c:\\cfile");
    fPtr=fopen("../datafolder/data.txt","a");
    if(fPtr==NULL){
        printf("not exist");
        exit(EXIT_FAILURE);
    }
    int paymentChoice;
    int depositAccountChoice;
    printf("\nPlease enter whether you are depositing \n 1.cash \t 2.cheque\n");
    scanf("%d",&paymentChoice);
    if ((paymentChoice==1)||(paymentChoice==2)){
            printf("\nPlease enter account you want to deposit to: \n 1. Chequing \t 2.Saving\n");
            scanf("%d",&depositAccountChoice);
            if ((depositAccountChoice==1)||(depositAccountChoice==2)){
                 printf("\nPlease enter amount to deposit: ");
                 scanf("%d", &amountToDeposit);
                 fprintf(fPtr,"Amount deposited=%d",amountToDeposit);
                 if(depositAccountChoice==1){
                            balanceInChequing = balanceInChequing+amountToDeposit;
                            printf("\nPlease insert cash/currency in the deposit slot");
                            printf("\nThank you for depositing, new balance in your chequing account is: %f", balanceInChequing);
                            return 1;
                 } else {
                      balanceInSaving = balanceInSaving+amountToDeposit;
                      printf("\nPlease insert cash/currency in the deposit slot");
                      printf("\nThank you for depositing, new balance in your savings account is: %f", balanceInSaving);
                      return -1;
                   }//end of else for deposit in saving


            } else{
                printf("\nInvalid Account choice");
                //deposit();
                return -3;
              }// end of else for account choice

    } else {
        printf("\nInvalid payment choice");
        //deposit();
        return -2;
      }//end of else for payment choice
        fflush(stdin);
        fclose(fPtr);
    return 0;
}//end of deposit

//transaction history
int test_transaction_history(){
    //FILE *fhr;
    printf("\n Recent transactions will be displayed here\n");
    /*char str[100];
    //mkdir("c:\\cfile");
    fhr=fopen("..datafolder/data.txt","r");
    if(fhr = NULL){
        printf("not exist");
        exit(EXIT_FAILURE);
    }
   while(1)
    {
        if(fgets(str,100,fhr)==NULL)
            break;
        else
            printf("%s",str);
    }
    printf("\n**************No more transactions to show****************************************\n");
    fflush(fhr);
    fclose(fhr);*/
   return -1;
}
//pay bill
int test_pay_bill()
{

    int choice;
    printf("\nPlease choose your option for bill payment  \n 1.Credit Card Bill  \t 2.Electricity Bill  \t   3.Mobile Bill\n");
    scanf("%d",&choice);
    FILE *fPtr;
    //mkdir("c:\\cfile");
    fPtr=fopen("../datafolder/data.txt","a");
    if(fPtr==NULL){
        printf("not exist");
        exit(EXIT_FAILURE);
    }
    if((choice==1)||(choice==2)||(choice==3)){
            int payment_account_choice;
            printf("\nPlease enter account from which you want to pay: \n 1. Chequing \t 2.Savings\n");
            scanf("%d",&payment_account_choice);
            if((payment_account_choice==1)||(payment_account_choice==2)){
               int amount_to_pay;
               printf("\nPlease enter the amount you want to pay:");
               scanf("%d",&amount_to_pay);
               if(payment_account_choice==1){
                   if(amount_to_pay > balanceInChequing){
                        printf("There is no sufficient funds in your chequing account to pay the bill");
                   } else if(amount_to_pay==0){
                       printf("\nYou have not chosen a valid amount to pay");
                       return -2;
                     } else {
                            fprintf(fPtr,"\nAmount paid for bill = %d and ",amount_to_pay);
                            balanceInChequing = balanceInChequing - amount_to_pay;
                            printf("You have made a payment of %d successfully and your new balance in chequing account is %f ", amount_to_pay, balanceInChequing);
                            fprintf(fPtr,"Balance in chequing = %f\n",balanceInChequing);
                            return -3;
                       }
                } else if(amount_to_pay > balanceInSaving){
                    printf("There is no sufficient funds in your savings account to pay the bill");
                  } else if(amount_to_pay==0){
                       printf("\nYou have not chosen a valid amount to pay");
                       return -2;
                     } else {
                          fprintf(fPtr,"\nAmount paid for bill = %d and",amount_to_pay);
                          balanceInSaving = balanceInSaving - amount_to_pay;
                          printf("You have made a payment of %d successfully and your new balance in savings account is %f ", amount_to_pay, balanceInSaving);
                          fprintf(fPtr,"Balance in savings = %f\n",balanceInSaving);
                          return -3;
                       }

            } else {
                   printf("\nInvalid Payment Account Choice");
              }//end of else for oayment account choice




     } else {
     printf("\nInvalid Choice");
     return -1;
       }
       fflush(stdin);
       fclose(fPtr);

       return 0;
}
//cheque book
int test_cheque_book_request(){
  printf("\nThanks! Cheque book request has been placed.");
  printf("\nNote: The bank will be notified shortly. The cheque book will be couriered to your registered address.");
  return -1;
  }
//currency exchange
int test_currency_exchange( int cash,char *type)
 {
    int ch;
    printf("\nchoose the conversion type\n 1. INR \n 2. USD \n 3. CAD\n");
    scanf("%d",&ch);
    printf("\nPlease deposit the currency to be exchanged\n");
   /* FILE *fpr;
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
    fclose(fpr);*/
    printf("\nThanks for depositing\n");
    switch(ch)
    {
    case 1:
            if(strcmp(type,"INR")==0){
                printf("\nSorry!The from and to conversion type are same\n");
             }
            if(strcmp(type,"USD")==0){
                printf("\nUSD to INR : %lf\n",cash*76.62);
            }
            if(strcmp(type,"CAD")==0){
                printf("\nCAD to INR : %lf\n",cash*54.64);
            }
            break;

    case 2:
            if(strcmp(type,"USD")==0) {
                printf("\nSorry!The from and to conversion type are same\n");
            }
            if(strcmp(type,"INR")==0){
                printf("\nINR to USD : %lf\n",cash*.013);
            }
            if(strcmp(type,"CAD")==0){
                printf("\nCAD to USD : %lf\n",cash*0.71);
            }
            break;

    case 3:
            if(strcmp(type,"CAD")==0){
                printf("\nSorry!The from and to conversion type are same\n");
            }
            if(strcmp(type,"INR")==0) {
                printf("\nINR to CAD : %lf\n",cash*.018);
            }
            if(strcmp(type,"USD")==0){
                printf("\nUSD to CAD : %lf\n",cash*1.40);
            }
                break;
    }
        return -1;
 }

 int test_personal_loan(){
  printf("\nThanks! Your request for personal loan has been placed.");
  printf("\nNote: You will be contacted from the bank shortly\n");
  return 0;
  }

  int test_help(){
  printf("\nThanks! Your request for help has been placed.");
  printf("\nNote: You will be contacted from the bank shortly");
  return 0;
  }



int test_all_cases()
{
    int var,inp;
    FILE *test_result = fopen("../test/results/results.csv", "a");
    printf("\n1. Test pin init function");
    printf("\n2. Test pin change function");
    printf("\n3. Test currency transfer function");
    printf("\n4. Test withdraw function");
    printf("\n5. Test deposit function");
    printf("\n6. Test transaction history function");
    printf("\n7. Test Balance Enquiry function");
    printf("\n8. Test Balance bill payment function");
    printf("\n9. Test cheque book request function function");
    printf("\n10. Test currency exchange function");
    printf("\n11. Test help function");
    printf("\n12. Test personal loan function");
    printf("\nNOTE: Please follow the instructions correctly for proper running of test cases.\nIf the instructions are misled, the test cases are designed to fail\n");
    printf("\nInput your choice of test: ");

    scanf("%d",&inp);
    switch(inp)
    {
       case 1:
           printf("\nTesting Pin init function.\n");

           //int counter=3;
           var = test_pin_init(4);
           /* Test case 1: A function call with counter=4. The program should finish by returning -2 */
           if(var == -2)
                {
                    char t[100];
                    printf("\nINPUT: Test case 1: A function call with counter=4. The program should finish as the attempt will be exceeded\n");
                    sprintf(t,"\nOUTPUT: 1) TEST CASE PASS: Maximum attempts exceeded, Expected Output: %d, Output: %d .\n",-2,var);

                    printf(t);
                    fprintf(test_result,t);
                }
          /* Test case 2: A function call with counter=1. The program should display Incorrect password and attempt exceeded by returning -1 */
          printf("\nINPUT: Test case 2: A function call with counter=1 allowing the user for a last chance to enter the right password\n");
          printf("\n The program should get a wrong password from user and display as the attempt will be exceeded\n");
          int var1 = test_pin_init(1);
            if(var1 == -2)
            {
                char t[1000];
                    sprintf(t,"\nOUTPUT: 2) TEST CASE PASS: wrong password in third attempt,so display exceeded message, Expected Output: %d, Output: %d .\n",-2,var1);

                    printf(t);
                    fprintf(test_result,t);
            } else {
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 2) TEST CASE FAIL: You are supposed to enter a wrong password, Expected Output: %d, Output: %d .\n",-2,var1);

                    printf(t);
                    fprintf(test_result,t);
               }
        /* Test case 3: Check the o/p by giving character as input to the PIN */
          printf("\nINPUT: Test case 3: Check the output by giving character/special character/negative value as input to the PIN. The program should display Incorrect password\n");
          printf("\nHint: Please enter a character/special character/negative value as input to the PIN and check the output\n");
          int var2 = test_pin_init(3);
          if (var2 == -2){
          char t[1000];
          sprintf(t,"\nOUTPUT: 3) TEST CASE PASS: Incorrect password as it is either a character or special character or negative value, Expected Output: %d, Output: %d .\n",-2,var2);
          printf(t);
          fprintf(test_result,t);
          } else {
          char t[1000];
          sprintf(t,"\nOUTPUT: 3) TEST CASE FAIL: You failed to enter either a character or special character or negative value, Expected Output: %d, Output: %d .\n",-2,var2);
          printf(t);
          fprintf(test_result,t);

            }

      /* Test case 4: Check the output by entering the right password*/
          printf("\nINPUT: Test case 4: Check the output by entering the right password as input to the PIN. The program should display Correct password\n");
          printf("\nHint: Please check the file password.txt for the PIN and enter it right to check the output.");
          FILE *fPtr;
          fPtr=fopen("../datafolder/password.txt","r");
          char str[100];
          while(fgets(str,100,fPtr)!=NULL)
           {
            printf("\nThe PIN stored in file is %s",str);
           }
           fflush(fPtr);
           fclose(fPtr);
          int var3 = test_pin_init(3);
          if (var3 == -1) {
          char t1[1000];
          sprintf(t1,"\nOUTPUT: 4) TEST CASE PASS: Correct password as it is same as the one stored in file, Expected Output: %d, Output: %d .\n",-1,var3);
          printf(t1);
          fprintf(test_result,t1);
          } else {
          char t1[1000];
          sprintf(t1,"\nOUTPUT: 4) TEST CASE FAIL: You were supposed to enter the one stored in file, Expected Output: %d, Output: %d .\n",-1,var3);
          printf(t1);
          fprintf(test_result,t1);

            }

     /* Test case 5: Check the output of the code by entering a PIN less than 4 digits, greater than 4 digits and equal to four digits
     but not same as the pin stored in the file*/
          printf("\nINPUT: Test case 5: Check the output by entering a PIN less than 4-digits, greater than 4-digits and equal to 4-digits but not same as the PIN stored in the file. The program should display Incorrect password\n");
          printf("\nHint: Enter a PIN that is less than, greater than and equal to 4-digits but not the right password and check the output");
          int var4 = test_pin_init(3);
          if (var4 == -2){
          char t2[1000];
          sprintf(t2,"\nOUTPUT: 5) TEST CASE PASS: Incorrect password as it is either less or greater than 4-digits or not same as the one stored in file, Expected Output: %d, Output: %d .\n",-2,var4);
          printf(t2);
          fprintf(test_result,t2);
          } else {
          char t2[1000];
          sprintf(t2,"\nOUTPUT: 5) TEST CASE FAIL: You were supposed to enter incorrect password, Expected Output: %d, Output: %d .\n",-2,var4);
          printf(t2);
          fprintf(test_result,t2);
            }

        break;

        case 2:
            printf("\nTesting Pin Change function.\n");

            //int attempt=3;
            var = test_pin_change(4);
           /* Test case 1: A function call with attempt=4. The program should finish by returning -2 */
            if(var == -2)
                {
                    char t[1000];
                    printf("\nINPUT: Test case 1: A function call with attempt=4. The program should finish as the attempt will be exceeded\n");
                    sprintf(t,"\nOUTPUT: 1) TEST CASE PASS: Maximum attempts exceeded, Expected Output: %d, Output: %d .\n",-2,var);
                    printf(t);
                    fprintf(test_result,t);
                }
         /* Test case 2: A function call with attempt=1. The program should display Incorrect password and attempt exceeded by returning -1 */
          printf("\nINPUT: Test case 2: A function call with attempt=1 allowing the user for a last chance to enter the existing password right\n");
          printf("\n The program should get a wrong password from user and display as the attempt will be exceeded\n");
           var = test_pin_change(1);
            if(var == -2)
            {
                char t[1000];
                sprintf(t,"\nOUTPUT: 2) TEST CASE PASS: wrong password in third attempt,so display exceeded message, Expected Output: %d, Output: %d .\n",-2,var);

                printf(t);
                fprintf(test_result,t);
            } else {
                 char t[1000];
                    sprintf(t,"\nOUTPUT: 2) TEST CASE FAIL: You are supposed to enter wrong password, Expected Output: %d, Output: %d .\n",-2,var);

                    printf(t);
                    fprintf(test_result,t);
              }
            /* Test case 3: Check the output by giving invalid inputs to the existing pin more than 3 times and verify it shows that the limit has been exceeded*/
           printf("\nINPUT: Test case 3: Check the output by giving invalid inputs to the existing pin for 3 times and verify it shows that the limit has exceeded after the third attempt\n");
           FILE *fPr;
           fPr=fopen("../datafolder/password.txt","r");
           char str1[100];
           while(fgets(str1,100,fPr)!=NULL)
           {
            printf("\nThe existing PIN stored in file is %s",str1);
           }
           fflush(fPr);
           fclose(fPr);
           printf("\nNote: Please enter any PIN other than %s and check the output\n",str1);
           var = test_pin_change(3);
           if (var == -2){
           char t3[1000];
           sprintf(t3,"\nOUTPUT: 3) TEST CASE PASS: Incorrect password as long as the attempt was not four, Expected Output: %d, Output: %d .\n",-2,var);
           printf(t3);
           fprintf(test_result,t3);
           } else {
               char t3[1000];
               sprintf(t3,"\nOUTPUT: 3) TEST CASE FAIL: You failed to give invalid values to the existing pin, Expected Output: %d, Output: %d .\n",-2,var);
               printf(t3);
               fprintf(test_result,t3);
           }

           /*Test case 4: Check the output by entering a New PIN less than/greater than 4 digits. Any number of Zeros in the beginning will not be counted as a digit*/
           printf("\nINPUT:Test case 4: Check the output by entering a new PIN having a password length lesser than/greater than 4-digits");
           printf("\nPlease note that any number of zeros in the beginning of password will not be counted as a digit\n");
           FILE *fp;
           fp=fopen("../datafolder/password.txt","r");
           char str2[100];
           while(fgets(str2,100,fp)!=NULL)
           {
            printf("\nThe existing PIN stored in file is %s\n",str2);
           }
           fflush(fp);
           fclose(fp);
           printf("\nNOTE: Please enter existing PIN right in order to get a chance to set your new password\n");
           var = test_pin_change(3);
           if(var==-3){
               char t4[1000];
               sprintf(t4,"\nOUTPUT: 4) TEST CASE PASS: Invalid entry as password length is not equal to 4, Expected Output: %d, Output: %d .\n",var,var);
               printf(t4);
               fprintf(test_result,t4);
           } else {
                    char t4[1000];
                    sprintf(t4,"\nOUTPUT: 4)TEST CASE FAIL: Because you were supposed to check for password length,Expected Output: %d, Output: %d .\n",-3,var);
                    printf(t4);
                    fprintf(test_result,t4);
             }
           /* Test case 5: Check the output by entering palindrome 4-digit number as input to the new PIN*/
           printf("\nINPUT: Test Case 5: Check the output by entering any palindrome 4-digit number (like for example 1001) as input to the new PIN");
           printf("\nPlease note that any number of zeros in the beginning of password will not be counted as a digit\n");
           FILE *fr;
           fr=fopen("../datafolder/password.txt","r");
           char str3[100];
           while(fgets(str3,100,fr)!=NULL)
           {
            printf("\nThe existing PIN stored in file is %s\n",str3);
           }
           fflush(fr);
           fclose(fr);
           printf("\nNOTE: Please enter existing PIN right in order to get a chance to set your new password.\n");
           var = test_pin_change(3);
           if(var==-4){
               char t5[1000];
               sprintf(t5,"\nOUTPUT: 5) TEST CASE PASS: Invalid as it is a palindrome, Expected Output: %d, Output: %d .\n",-4,var);
               printf(t5);
               fprintf(test_result,t5);
           } else {
               char t5[1000];
               sprintf(t5,"\nOUTPUT: 5) TEST CASE FAIL: You are supposed to enter palindrome, Expected Output: %d, Output: %d .\n",-4,var);
               printf(t5);
               fprintf(test_result,t5);


             }


           /* Test case 6: Check the output by giving invalid inputs to the existing pin more than 3 times and verify it shows that the limit has been exceeded*/
           printf("\nINPUT: Test case 6: Check the output by giving invalid inputs like characters/specials character to the existing pin for 3 times and verify it shows that the limit has exceeded after the third attempt\n");
           FILE *fptr;
           fptr=fopen("../datafolder/password.txt","r");
           char s1[100];
           while(fgets(s1,100,fptr)!=NULL)
           {
            printf("\nThe existing PIN stored in file is %s",s1);
           }
           fflush(fptr);
           fclose(fptr);
           printf("\nNote: Please enter any PIN other than %s and check the output\n",s1);
           var = test_pin_change(3);
           if (var == -2){
           char s[1000];
           sprintf(s,"\nOUTPUT: 6) TEST CASE PASS: Incorrect password as it has characters/special characters/any invalid entries, Expected Output: %d, Output: %d \n",-2,var);
           printf(s);
           fprintf(test_result,s);
           } else {
             char s[1000];
             sprintf(s,"\nOUTPUT: 6) TEST CASE FAIL: You failed to enter characters/special characters as inputs to existingPin, Expected Output: %d, Output: %d .\n",-2,var);
             printf(s);
             fprintf(test_result,s);

             }


           /* Test Case 7: Check the output of the code by entering a non-palindrome 4-digit PIN as input to the new PIN*/
           printf("\nINPUT: Test Case 7: Check the output by entering a non-palindrome 4-digit PIN (like for example 1000) as input to the new PIN\n");
           printf("\nPlease note that any number of zeros in the beginning of password will not be counted as a digit\n");
           FILE *ft;
           ft = fopen("../datafolder/password.txt","r");
           char str4[100];
           while(fgets(str4,100,ft)!=NULL)
           {
            printf("\nThe existing PIN stored in file is %s\n",str4);
           }
           //fflush(ft);

           printf("\nNOTE: Please enter existing PIN right in order to get a chance to set your new password.\n");
           var = test_pin_change(3);
           if(var==0){
               char t6[1000];
               sprintf(t6,"\nOUTPUT: 7) TEST CASE PASS: Valid PIN as it is not a palindrome, Expected Output: %d, Output: %d .\n",0,var);
               printf(t6);
               fprintf(test_result,t6);
           } else {
               char t6[1000];
               sprintf(t6,"\nOUTPUT: 7) TEST CASE FAIL: You were supposed to input a non-palindrome number , Expected Output: %d, Output: %d .\n",0,var);
               printf(t6);
               fprintf(test_result,t6);

             }
           fclose(ft);
           exit(0);


           break;

        case 3:
             printf("\nTesting currency transfer function.\n");
             /* Test case 1: Same account choice for from and to accounts*/
             printf("\n Test case 1: Check the output by giving same account choice for 'From' and 'To' accounts\n");
             var = test_currency_transfer();
             if (var == -1){
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 1) TEST CASE PASS: Invalid choice, Expected Output: %d, Output: %d .\n",-1,var);
                    printf(t);
                    fprintf(test_result,t);
             } else {
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 1) TEST CASE FAIL: You are supposed to give same account choice, Expected Output: %d, Output: %d .\n",-1,var);
                    printf(t);
                    fprintf(test_result,t);
               }
             printf("\n Test case 2: Check the output by giving invalid account choice that is not shown in the list (for example 'from': 3 and to:'2')  for 'From' and 'To' accounts\n");
             var = test_currency_transfer();
             if (var == -2){
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 2) TEST CASE PASS: The option entered does not exist, Expected Output: %d, Output: %d .\n",-2,var);
                    printf(t);
                    fprintf(test_result,t);
             } else {
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 2) TEST CASE FAIL: You did not enter invalid account choice, Expected Output: %d, Output: %d .\n",-2,var);
                    printf(t);
                    fprintf(test_result,t);
               }
              printf("\n Test case 3: Check the output by giving negative value/amount greater than current balance of chequing and savings account as input to amount to transfer\n");
              printf("\n Note: 'From' and 'To' account should be different. Assume current balance of chequing and saving is 1000");
              var = test_currency_transfer();
             if (var == -3){
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 3) TEST CASE PASS: No sufficient amount to make transfer, Expected Output: %d, Output: %d .\n",-3,var);
                    printf(t);
                    fprintf(test_result,t);
             } else {
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 3) TEST CASE FAIL: You are supposed to enter insufficient amounts, Expected Output: %d, Output: %d .\n",-3,var);
                    printf(t);
                    fprintf(test_result,t);
               }
             printf("\n Test case 4: Check the output by giving 0 as input to amount to transfer when two account choices are different valid choices\n");
             var = test_currency_transfer();
             if (var == -4) {
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 4) TEST CASE PASS: 0 is not a valid amount , Expected Output: %d, Output: %d .\n",-4,var);
                    printf(t);
                    fprintf(test_result,t);
             } else {

                    char t[1000];
                    sprintf(t,"\nOUTPUT: 4) TEST CASE FAIL: You failed to enter invalid amount , Expected Output: %d, Output: %d .\n",-4,var);
                    printf(t);
                    fprintf(test_result,t);

                }
             printf("\n Test case 5: Check the output by entering a value for 'amount to transfer' lesser than or equal to balance in chequing/savings when two account choices are different valid choices\n");
             var = test_currency_transfer();
             if (var == -5){
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 5) TEST CASE PASS: Value is subtracted from the 'from' acc and added to the 'to' acc , Expected Output: %d, Output: %d .\n",-5,var);
                    printf(t);
                    fprintf(test_result,t);
             } else {
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 5) TEST CASE FAIL: You did not enter a valid value as requested , Expected Output: %d, Output: %d .\n",-5,var);
                    printf(t);
                    fprintf(test_result,t);
              }
             break;

        case 4:
               printf("\n Testing withdraw function");
               /* Test case 1: Check the output by giving amount to withdraw greater than balance in chequing/saving*/
            printf("\n Test case 1: Check the output by giving amount to withdraw greater than balance in chequing/savings two account chosen is a valid choices\n");
            printf("Note: Assume balance in chequing and saving as 1000 each\n");
             var = test_withdraw();
             if (var == -1)
             {
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 1) TEST CASE PASS: Insufficient funds , Expected Output: %d, Output: %d .\n",-1,var);
                    printf(t);
                    fprintf(test_result,t);
             }

               /* Test case 2: Check the output by giving the amount to withdraw greater than the daily limit*/
             printf("\n Test case 2: Check the output by entering a value for 'amount to withdraw' greater than the daily limit of 500 when account chosen is a valid choice\n");
             var = test_withdraw();
             if (var == -2)
             {
                    char t[100];
                    sprintf(t,"\nOUTPUT: 2) TEST CASE PASS: Daily limit exceeded , Expected Output: %d, Output: %d .\n",-2,var);
                    printf(t);
                    fprintf(test_result,t);
             }
               /* Test case 3: Check the output by giving amount to withdraw lesser than daily limit*/
               printf("\n Test case 3: Check the output by entering a value for 'amount to withdraw' lesser than or equal to daily Limit of 500 when account chosen is a valid choice\n");
               var = test_withdraw();
             if (var == -3)
             {
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 3) TEST CASE PASS: Value will be  subtracted from the respective account, Expected Output: %d, Output: %d .\n",-3,var);
                    printf(t);
                    fprintf(test_result,t);
             }
             break;

        case 5:
            printf("\n Testing deposit function");
            /* Test case 1: Check the output by giving invalid account choice*/
            printf("\n Test case 1: Check the output by giving invalid account choice");
            printf("Note: Assume initial balance in chequing and saving as 1000 each\n");
             var = test_deposit();
             if (var == -3)
             {
                    char t[100];
                    sprintf(t,"\nOUTPUT: 1) TEST CASE PASS: Invalid account choice , Expected Output: %d, Output: %d .\n",-3,var);
                    printf(t);
                    fprintf(test_result,t);
             }

            /* Test case 2: Check the output by giving invalid payment choice*/
            printf("\n Test case 2: Check the output by giving invalid payment choice");
            printf("Note: Assume initial balance in chequing and saving as 1000 each\n");
             var = test_deposit();
             if (var == -2)
             {
                    char t[100];
                    sprintf(t,"\nOUTPUT: 2) TEST CASE PASS: Invalid payment choice , Expected Output: %d, Output: %d .\n",-2,var);
                    printf(t);
                    fprintf(test_result,t);
             }

            /* Test case 3: Check the output by depositing any amount to the chequing account*/
             printf("\n Test case 3: Check the output by depositing any amount to the chequing account");
             printf("Note: Assume initial balance in chequing and saving as 1000 each\n");
             var = test_deposit();
             if (var == 1)
             {
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 3) TEST CASE PASS: Amount will be added to that respective account , Expected Output: %d, Output: %d .\n",1,var);
                    printf(t);
                    fprintf(test_result,t);
             }

            /* Test case 4: Check the output by depositing any amount to the savings account*/
            printf("\n Test case 4: Check the output by depositing any amount to the savings account");
            printf("Note: Assume initial balance in chequing and saving as 1000 each\n");
             var = test_deposit();
             if (var == -1)
             {
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 4) TEST CASE PASS: Amount will be added to that respective account , Expected Output: %d, Output: %d .\n",-1,var);
                    printf(t);
                    fprintf(test_result,t);
             }
             break;

        case 6:
             printf("\n Testing transaction history function");
             /* Test case 1: Check whether the file has contents*/
             int var = test_transaction_history();
             if (var == -1){
                    char t[100];
                    sprintf(t,"\nOUTPUT: 1) TEST CASE PASS: Function executed successfully, Expected Output: %d, Output: %d .\n",-1,var);
                    printf(t);
                    fprintf(test_result,t);
             } else {
                    char r[100];
                    sprintf(r,"\nOUTPUT: 1) TEST CASE Fail, Expected Output: %d, Output: %d .\n",-1,var);
                    printf(r);
                    fprintf(test_result,r);
             }
             break;


        case 7:
            printf("\n Testing Balance Enquiry function");
            int a = test_balance();
            if (a == 0){
                    char t[100];
                    sprintf(t,"\nOUTPUT: 1) TEST CASE PASS: Function executed successfully , Expected Output: %d, Output: %d .\n",0,a);
                    printf(t);
                    fprintf(test_result,t);
             }
            break;

        case 8:
             printf("\n Testing bill payment function");
             /* Test case 1: Check whether the bill payment choices are valid*/

             printf("\n Check the output by entering invalid bill payments option\n");
             var = test_pay_bill();
             if (var == -1){
                    char t[100];
                    sprintf(t,"\nOUTPUT: 1) TEST CASE PASS: Invalid bill payment option, Expected Output: %d, Output: %d .\n",-1,var);
                    printf(t);
                    fprintf(test_result,t);
             }
             /* Test case 2: Check the output by entering 0 as the value for amount to pay*/
             printf("\n Check the output by giving 0 as the value for amount to pay");
             var = test_pay_bill();
             if (var == -2){
                    char t[100];
                    sprintf(t,"\nOUTPUT: 2) TEST CASE PASS: Not a valid amount to make payment, Expected Output: %d, Output: %d .\n",-2,var);
                    printf(t);
                    fprintf(test_result,t);
             }

            /* Test case 3: Check the output by entering value for amount lesser than balance in chequing and savings*/
             printf("\n Check the output by entering value for amount to pay lesser than balance in chequing and savings");
             var = test_pay_bill();
             if (var == -3){
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 3) TEST CASE PASS: Payment made, Expected Output: %d, Output: %d .\n",-3,var);
                    printf(t);
                    fprintf(test_result,t);
             }
             break;

        case 9:

        printf("\nTesting cheque book request function function");
        var = test_cheque_book_request();
             if (var == -1){
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 1) TEST CASE PASS: Function executed successfully, Expected Output: %d, Output: %d .\n",-1,var);
                    printf(t);
                    fprintf(test_result,t);
             }
        break;

        case 10:
            printf("\n Testing Currency exchange function");
            /*Test case 1: Check whether 5000 cad has been converted to INR and output is as expected*/
           printf("\n Check whether 5000 cad has been converted to desired currency and output is the expected one");
           printf("\nNote please enter as a string and use CAPS LOCK and not a number. For example if cad enter CAD");
           char curr[4];
           int amt;
           printf("\nInput the type of currency which you want to convert in (INR/CAD/USD): ");
           scanf("%s",&curr);
           //gets(curr);
           //fgetc(stdin);
           printf("\nPlease enter the amount to be exchanged: ");
           scanf("%d",&amt);
           if(strlen(curr)>3)
           {
             printf("\nCurrency type length too long!!");
             return 0;
           }
           var = test_currency_exchange(amt,curr);

                    if (var == -1) {
                    char b[1000];
                    sprintf(b,"\nOUTPUT: 1) TEST CASE PASS: Function executed successfully, Expected Output: %d, Output: %d .\n",-1,var);
                    printf(b);
                    fprintf(test_result,b);
            }
            break;

        case 11:
             printf("\n Testing help function");
             var = test_help();
             if (var == 0){
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 1) TEST CASE PASS: Function executed successfully, Expected Output: %d, Output: %d .\n",0,var);
                    printf(t);
                    fprintf(test_result,t);
             }
            break;


        case 12:
             printf("\n Testing personal loan function");
             var = test_personal_loan();
             if (var == 0){
                    char t[1000];
                    sprintf(t,"\nOUTPUT: 1) TEST CASE PASS: Function executed successfully, Expected Output: %d, Output: %d .\n",0,var);
                    printf(t);
                    fprintf(test_result,t);
             }
             break;

        default :
             printf("\nInvalid choice");
             break;


    }
    int another_transaction;
    printf("\n Do you want to continue testing? Press 1 to continue and 2 to exit");
    scanf("%d",&another_transaction);
    if((another_transaction==1)||(another_transaction==2))
    {
        if(another_transaction==1){
           test_all_cases();
        } else {
        exit(0);
        }
    } else {
    printf("Invalid choice");
    exit(0);
      }
    return 0;
}

