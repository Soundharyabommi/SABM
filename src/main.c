#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include <unistd.h>
#include "../include/functions.h"
#include "../include/global.h"
#include "../test/include/testing_function.h"

/* This is the main function. This function has entire control over the execution of application and testing*/

int main(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, "hat")) != -1)
    {
        switch(opt)
        {
            case 'h':
                printf("-t Runs automated unit testing and exits\n");
                printf("-a Runs main program and exits\n");
                return 0;
                break;

            case 't':
                /* Run automated unit testing */
                printf("Running automated unit testing\n");
                test_all_cases();
                printf("Automated testing has completed\n");
                return 0;
                break;

            case 'a':
                /* Run main SABM Management program */
                printf("Running SABM Program\n");
                int counter=3;
                printf("\nWELCOME TO OUR SABM SERVICE\n\n");
                printf("Please insert the SABM Card\n");
                pin_init(counter); //call the pin initialization function
                int c=transaction();
                switch_statement(c);
                break;
          }
    }
    return 0;
}
