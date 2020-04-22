# Smart Automated Banking Machine (SABM)

Smart Automated Banking Machine (SABM) is a banking software prototype that tests the functionalities of the banking machine based on the requirement of the client.

# Authors

- Soundharya Bommi Raja Bommannan - soundharyabommirajab@cmail.carleton.ca (101158576) - GitHub User ID: Soundharyabommi  - Carleton University
- Aniruudh Kannan                 - aniruudhkannan@cmail.carleton.ca       (101152294) - GitHub User ID: AniruudhKannan   - Carleton University
- Adhithyan Haridas               - adhithyanharidas@cmail.carleton.ca     (101145056) - GitHub User ID: AdhithyanHaridas - Carleton University

# Installation

Installation steps are mentioned in [INSTALL.md](https://github.com/Soundharyabommi/SABM/tree/master/INSTALL.md)

# Usage

To run, you must first install it. Then you can follow instructions mentioned in
[User_Manual.md](https://github.com/Soundharyabommi/SABM/tree/master/doc/User_Manual.md).

# File Structure

The correct file structure

```

├── INSTALL.md 	-> Installation Guide
├── LICENSE 	-> License file
├── Makefile 	-> Makefile
├── README.md 	-> Readme file
├── bin 	-> Binary directory
├── doc         -> Doxygen documents
│   |── html 	
|   ├── latex
│   ├── man
│   ├── rtf
|   |__ xml
|   |__ User_Manual.md
|   |__ Developer_Manual.md
|
├── include 	-> Header files
│   ├── functions.h
│   ├── global.h
│   ├── switch_statement.h
│   ├── transaction.h
│   ├── pin_init.h
│   ├── withdraw.h
│   ├── deposit.h
│   ├── help.h
│   ├── balance.h
│   ├── currency_exchange.h
│   ├── currency_transfer.h
│   ├── personal_loan.h
│   ├── cheque_book_request.h
│   ├── pay_bill.h
│   ├── pin_change.h
│   ├── transaction_history.h
│   
├── install.sh 	-> Installation script
├── obj 	-> Object files
├── Doxyfile	-> Doxygen Configuration files
├── src 	-> Source files for Smart Automated Banking Machine (SABM)
│   ├── main.c
│   ├── switch_statement.c
│   ├── transaction.c
│   ├── pin_init.c
│   ├── withdraw.c
│   ├── deposit.c
│   ├── help.c
│   ├── balance.c
│   ├── currency_exchange.c
│   ├── currency_transfer.c
│   ├── personal_loan.c
│   ├── cheque_book_request.c
│   ├── pay_bill.c
│   ├── pin_change.c
│   ├── transaction_history.c
└── test
    ├── include	-> testing_function.h
    ├── results -> results.csv -> contains log files of test cases executed
    ├── testing_function.c
 
  
```

# For Developers

The developer manual is available [here](https://github.com/Soundharyabommi/SABM/tree/master/doc/Developer_Manual.md).

# License

This project is licensed under the GPL 2.0 License - see the LICENSE.md file for details

# Acknowledgements

Our sincere thanks to Dr. Cristina Ruiz Martin for providing valuable feedback and guidance on how to develop the software.
