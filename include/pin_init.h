/**
 * @file pin_init.h
 * @brief checks whether the pin entered by the user matches with the PIN stored in the file but
 * the user is only allowed three attempts to enter the correct password to get access to the program
 * @param [in] counter and the function returns zero on successful execution
 */
#ifndef __PIN_INIT_H__
#define __PIN_INIT_H__

int pin_init(int counter);

/**
 * @detailed description counter = 3 when the function is called for the first time. The function checks whether the input entered by the user 
 * matches with the one stored in the file. The user is only allowed three attempts to get the PIN correct. On successful execution, the function returns 0
 * and allows the user to access the features of the SABM
 */

#endif
