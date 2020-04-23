# Introduction

Smart Automated Banking Machine (SABM) is an advanced banking machine software which allows the user to perform quick self-serve transactions from everyday banking like deposits and withdrawals to more complex transactions like bill payments, currency transfers and various other features.

# Installation

Please refer to [INSTALL.md](https://github.com/Soundharyabommi/SABM/blob/master/INSTALL.md) file for installation instructions.

# Usage

- The user needs to input the software with a Personal Identification Number (PIN) that is stored in the "password.txt" text file to get access to the transactions (features of the sabm). The user is only allowed three attempts to input the right password otherwise the session will be terminated.

- When prompted to enter the choice of transaction, the user should enter a number between 1-12 to perform any transaction and selecting 12 will terminate the session.

    Press 1  to perform withdrawal operation 
    Press 2  to perform deposit cash/cheque
    Press 3  to view the balance
    Press 4  to perform fund transfer
    Press 5  to view the history of the transactions made
    Press 6  to change the existing PIN
    Press 7  to convert currency
    Press 8  to pay bills for credit card, electricity or mobile 
    Press 9  to request cheque book
    Press 10 to apply for personal loan
    Press 11 to request for help
    Press 12 to exit the session 

- Certain transactions require further action from the user. In such cases,the following actions specific to each transactions has to be done by the user while execution.

  Withdraw            : Enter 1 for Chequing and 2 for Savings 
  
  Deposit cash/cheque : For currency type  : Enter 1 for cash and 2 for cheque
                        For account choice : Enter 1 for chequing and 2 for savings

  Transfer funds      : For 'From' account choices - Enter 1 for chequing and 2 for savings
                        For 'To' account choices   - Enter 1 for chequing and 2 for savings
  
  Currency exchange   : For input currency type that is to be deposited to convert - Enter "INR" for depositing in indian rupees; "CAD" for depositing Canadian dollar bills and "USD" for depositing US dollar bills.
                        For conversion currency type that is to be collected after exchange - Enter 1 for INR, 2 for USD and 3 for CAD.

  Pay bill            : For bill payment option - Enter 1 for 'Credit Card Bill', 2 for 'Electricity Bill' and 3 for 'Mobile Bill'
                        For 'withdraw from' account choice : Enter 1 for Chequing and 2 for Savings.

  
    
- In general, at the end of each transaction when prompted to continue the transaction or exit : Enter 1 to continue and 2 to exit the session.       


Please note that the binary is located within `bin` folder

```
./bin/SABM
```

# Testing

Unit testing is done for each functions defined in the software. The test cases can be run using the command below:

```
./bin/sabm -t
```

# Help

User can run the below command to know the details about input parameters.

```
./bin/sabm -h
```

# Information of Data Files

Information about the password is stored in  "password.txt", the currency conversion rates are stored in "conversion.txt" and the details of withdrawal, deposit, transfers and bill payments made are stored in "data.txt"
the file 'results.csv' contains the log of test cases
To generate clean data and test files, you need to do the following:

```
make clean && make
```

Then run the `sabm` binary again
