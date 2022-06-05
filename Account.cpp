#include "Account.h"
#include <iostream>
#include <sstream>
#include <iomanip>

int n = rand() % 100001;


Account::Account(char accType, double balance) {
    this->setAccNumber();
    this->setBalance(balance);
    this->setAccType(accType);
}

double Account::getBalance() {
    return this->balance;
}

string Account::getAccNumber() {
    return this->accountNumber;
}

void Account::setBalance(double balance) {
    this->balance = balance;
}

void Account::setAccType(char c) {
    this->accType = c;
}

char Account::getAccType() {
    return this->accType;
}

void Account::setAccNumber() {
    ++n;

    ostringstream stm ;
    stm << setw(8) << setfill('0') << n ;
    this->accountNumber = stm.str();
}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (balance - amount < 0) {
        cout << "Your balance is inadequate to withdraw this amount.";
    }
    balance -= amount;
}