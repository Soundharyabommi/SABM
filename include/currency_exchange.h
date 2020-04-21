/**
 * @file currency_exchange.h
 * @brief the function performs the currency conversion between INR/CAD/USD and displays the amount that was converted
 * @param[in] cash - The amount that has to be converted
 * @param[in] *type  Pointer to type. input currency type which is to be converted. There is no output parameter.
 * @return the function returns 0 when the conversion has been made.
 */

#ifndef __CURRENCY_EXCHANGE_H__
#define __CURRENCY_EXCHANGE_H__

int currency_exchange( int cash,char *type);

/** 
 * The conversion rates are assumed and fixed for this transaction and are stored in the file
 */

#endif

