# simple-ATM
A simple ATM simulation program that allows users to insert a card, enter a PIN, select an account, and perform actions like checking balance, depositing, or withdrawing money.

# Project Testing Guide

This document explains how to test the **simpleAtm** project step by step. Follow the instructions below to ensure that the program behaves as expected.

## Building the Project
To build the project and create the `simpleAtm` executable:

```bash
make
```

This command generates the `simpleAtm` executable file.

## Running the Application
To start the application:

```bash
./simpleAtm
```

## Program Workflow
The following steps describe the workflow of the `simpleAtm` application:

1. **Card Insertion**
   - The program begins by simulating card insertion automatically.
   - Once the card is recognized, the program prompts you to enter your PIN.
```bash
Please insert card.
Card inserted.
Recognizing your card, please wait...
Card recognition was successful.
```

2. **PIN Entry**
   - Enter the PIN to authenticate. For testing purposes, the PIN is set to be the same as the username.
   - The application has only one preconfigured user, `suhwan`.
```
Please enter the pin: suhwan

Checking PIN, please wait...

 * PIN verified. *
```

3. **Account Selection**
   - After successful authentication, a list of available accounts associated with the user is displayed.
   - Select an account by typing its corresponding name.
   - Please select the account you want to use.
```
--------ACCOUNTS LIST---------
 - test1
 - test2
 - lucky
 - bear
 - robotics
------------------------------
test1
you selected: test1
```

4. **Command List**
   - After selecting an account, a list of commands is displayed.
   - Choose a command by entering its corresponding number.
```
-----Menu-----
1. see balance
2. deposit
3. withdraw
4. select other account
5. exit
```

5. **Now use the command you want!**
   - input: 1
     ```
     1
     Current Balance: $1000000
     ```
   - input: 2
     ```
     2
     Please enter the amount to deposit: 1234
     *****************************
     Account balance
     before deposit: $1000000
     after deposit: $1001234
     *****************************
     ```
   - input: 3
     ```
     3
     Please enter the amount to withdraw: 1234
     *****************************
     Account balance
     before deposit: $1001234
     after deposit: $1000000
     *****************************
     ```
   - input: 4
     ```
     4
     Please select the account you want to use.
     --------ACCOUNTS LIST---------
      - test1
      - test2
      - lucky
      - bear
      - robotics
     ------------------------------
     ```
## Notes
- The username and PIN must match during the login step.
- The only preconfigured user for testing is `suhwan`.
- If you want to add new users and accounts In the ./src/SimpleATM.cpp file, you can add a test case in the run() function.

By following this guide, you can verify the correct functionality of the `simpleAtm` application.
