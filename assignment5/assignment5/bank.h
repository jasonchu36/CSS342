// Created by Jason Chu on 3/9/2022

#ifndef ASS5_BANK_H
#define ASS5_BANK_H

#include "BSTree.h"
#include "transaction.h"
#include <vector>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

class Bank {
  public:
    //Constructor
    Bank();

    //Destructor
    ~Bank();

    //Runs and processes all the transactions
    void readTransactions(const string& fileName);

    //Displays all the processed transactions
    void displayAllBankBalances() const;

    // Runs and processes all the transactions
    void processTransactions();

  private:
    BSTree accounts;
    queue <Transactions> Transaction;
}; 
#endif //ASS5_BANK_H