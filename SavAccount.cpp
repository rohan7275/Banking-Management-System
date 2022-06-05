#include "Account.h"
#include "SavAccount.h"

SavAccount::SavAccount(double bal) : Account('s', bal) {
    cout << "Creating Savings Account.\n";
}
