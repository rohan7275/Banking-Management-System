#include "Account.h"
#include "CurrAccount.h"

CurrAccount::CurrAccount(double bal) : Account('c', bal) {
    cout << "Creating Current Account.\n";
}