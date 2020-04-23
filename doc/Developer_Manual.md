# Introduction

  Smart Automated Banking Machine (SABM) is an advanced banking machine software which allows the user to perform quick self-serve transactions from everyday banking like deposits and withdrawals to more complex transactions like bill payments, currency transfers and various other features.

# Requirement

  To test the various functionalities of the Smart Automated Banking Machine based on the input from the user.

# Functionalities of the SABM

- Cash withdrawal
- Deposit cash/cheque
- Balance Enquiry
- Transfer funds between chequing and saving accounts
- Display Transaction History
- Pin Change
- Bill Payments (Credit card/ Electricity bill/ Mobile bill)
- Foreign Currency Exchange
- Request Cheque Book
- Apply Personal Loan
- Request for help


# Assumption

It is assumed that

- The functionality to open and close accounts;to create,update and delete customer and debit card records is not a part of this problem.
- Debit card is generally used for banking purposes and here, it is generalized as SABM card.
- SABM is always loaded with sufficient funds.
- the prototype works with one Personal Identification Number which is stored in the file and is maintained locally in the computer where the program is executed. In other words, it is only tested to work with one client.
- the client's credit/debit card records, mobile number, electricity bill number and address are all linked with his/her bank account and to verify this information is out of scope of this project.
- Chequing and Savings account already exists for that user.
- the default currency type in the banking machine is Canadian Dollar (CAD).
- the initial balance of Chequing and Savings account is 1000 CAD and the daily limit for withdrawal is assumed as 500 CAD.
- Currency conversion rates are fixed and are stored in the file.

#Note

- The current prototype does not include multiple users but it could be modified to work with multiple users.
- Conversion rates are subject to change and can be modified for future use.

# Program Flow

The program flow for the application is as follows:

![Diagram](https://github.com/Soundharyabommi/SABM/tree/master/asset/c.jpg)

- At the start of the main function, initially 'counter' variable is set to 3. The main.c file calls the function in pin_init.c, by passing the value stored in the counter,to allow the user to get access to the features of the sabm. 
- Transaction function is called to get the user's choice to run the program.
- The functions in switch_statement.c is called based on the return value of the transaction function which provides the user's choice.
- The switch_statement function calls:
  - The function in withdraw.c to perform the withdrawal operation from chequing or savings account  based on input from the user and on successful execution, writes the amount withdrawn to the file.
  - The function in deposit.c to perform cash/cheque deposit to chequing or savings account based on input from the user and on successful execution, writes the amount deposited to the file.
  - The function in balance.c to get the details of current balance in chequing and savings account.
  - The function in currency_transfer.c to make currency transfers between chequing and savings account based on input from the user and on successful execution, writes the amount transferred to the file.
  - The function in transaction_history.c to display the transactions made.
  - The function in pin_change.c to change the pin and update the new pin to the file based on the input from the user.
  - The function in currency_exchange.c to perform currency exchange by getting the input currency type, amount to be converted and converted currency type from the user.
  - The function in pay_bill.c to make payment for credit card/electricity bill/mobile bill by getting the amount to pay from the user and writes the transaction to the file.
  - The function in cheque_book_request.c to place request for cheque book.
  - The function in personal_loan.c to place request for personal loan.
  - The function in help.c to place request for help.
  

# Documentation

Complete documentation of the source code can be found [here](https://github.com/Soundharyabommi/SABM/blob/master/doc/html/index.html).
