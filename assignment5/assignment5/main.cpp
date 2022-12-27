#include "bank.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Bank Bank;
    Bank.readTransactions("BankTransIn.txt");
    Bank.processTransactions();
    Bank.displayAllBankBalances();
    return 0;
}