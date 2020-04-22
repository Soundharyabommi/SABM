/**
 * @file pin_change.h
 * @brief First checks whether the existing pin matches with the pin stored in the file and on changing the pin, the new pin is updated to that file.
 * @param[in] attempt and the function returns 0 when the pin has been updated successfully
 */
#ifndef __PIN_CHANGE_H__
#define __PIN_CHANGE_H__

int pin_change(int attempt);

/**
 * @detailed description attempt = 3 when the function is called for the first time. The function changes the PIN of the user only after confirming if the
 * input 'existingPin' matches with the PIN stored in the file and  the entered 'newPin' is a non-palindrome series. The user is only allowed three attempts 
 * to get the existingPin correct. When the function is executed successfully, the PIN will be changed and it will be updated to the file
 */

#endif
