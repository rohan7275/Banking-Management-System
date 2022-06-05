#pragma once

#include <iostream>

using namespace std;

class Account {
public:
    Account(char accType, double balance);
    double getBalance();
    std::string getAccNumber();
    void setBalance(double);
    void setAccType(char accType);
    char getAccType();
    void setAccNumber();
    void deposit(double amount);
    void withdraw(double amount);

private:
    double balance;
    char accType;
    std::string accountNumber;
};