#include "User.h"
#include <fstream>

User::User() {
    string id;
    cout << "Enter UserID: ";
    cin >> id;
    string pwd;
    cout << "Enter password: ";
    cin >> pwd;
    setUserId(id);
    setpassword(pwd);
    double balance;
    string accNumber;
    char accType;
    cout << "Enter account type(s for saving and c for cuurent): ";
    cin >> accType;
    cout << "Enter balance: ";
    cin >> balance;
    if (accType == 's') {
        this->account = new SavAccount(balance);
    } else if (accType == 'c') {
        this->account = new CurrAccount(balance);
    }
    if (this->account != nullptr) {
        cout << "Account created successsfully.\n";
    }
    updateFile();
}

User::~User() {
    delete account;
}

void User::setUserId(string id) {
    this->userId = id;
}

void User::setpassword(string pwd) {
    this->passwordhash = hash(pwd);
}


string User::getUserId() {
    return userId;
}

long long User::gethash() {
    return passwordhash;
}

void User::updateFile() {
    ofstream output;
    output.open("record.txt", std::ios_base::app);
    output << this->userId;
    output << " ";
    output << this->account->getBalance();
    output << " ";
    output << this->account->getAccNumber();
    output << " ";
    output << this->gethash();
    output << '\n';
    output.close();
}

long long User::hash(string str)
{
    // P and M
    int p = 31;
    int m = 1e9 + 9;
    long long power_of_p = 1;
    long long hash_val = 0;
 
    // Loop to calculate the hash value
    // by iterating over the elements of string
    for (int i = 0; i < str.length(); i++) {
        hash_val = (hash_val + (str[i] - 'a' + 1) * power_of_p) % m;
        power_of_p = (power_of_p * p) % m;
    }
    return hash_val;
}



