#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include "../include/functions.h"
#include "../include/global.h"

int main()
{

    int counter=3;
    printf("\nWELCOME TO OUR SABM SERVICE\n\n");
    printf("Please insert the SABM Card\n");
    pin_init(counter); //call the pin initialization function
    int c=transaction();
    switch_statement(c);
    return 0;
}
