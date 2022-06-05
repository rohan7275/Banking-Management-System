#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Account.h"
#include "User.h"
#include "Admin.h"

using namespace std;

void menuForLoggedInUsers();
bool isValid(string accNumber);

vector<string> wordsFromString(string str) {
    string word = "";
    vector<string> words;
    for (char x : str) {
        if (x == ' ') {
            words.push_back(word);
            word = "";
        }
        else {
            word = word + x;
        }
    }
    words.push_back(word);
    return words;
}

vector<vector<string>> loadfromfile(string filename) {
    ifstream infile;
    infile.open(filename);
    string line;
    vector<vector<string>> users;
    while (getline(infile, line)) {
        users.push_back(wordsFromString(line));
    }
    infile.close();
    return users;
}

int main() {
    char ch;
    do {
        cout << "Press 1 to create new account.\n"
             << "Press 2 to list accounts\n"
             << "Press 3 to delete account\n"
             << "Press 4 to log in\n"
             << "Press X to exit\n";
        cin >> ch;
        switch (ch) {
            case '1': 
                Admin::addNewAccount();
                break;
            case '2':
                Admin::listAllAccounts();
                break;
            case '3':
                Admin::removeAccount();
                break;
            case '4':
                if (Admin::authenticateUser()) {
                    cout << "\nLogged In Successfully.\n";
                    menuForLoggedInUsers();
                } else {
                    cout << "Wrong password or no such user.\n";
                }
                break;
            default:
                cout << "\a";
        }
    } while (ch != 'X');
    
    
}

void menuForLoggedInUsers() {
    char ch;
    do {
        cout << "Welcome\n";
        cout << "1. Deposit Money\n"
             << "2. Withdraw Money\n"
             << "3. Transfer Money\n"
             << "4. Check Balance\n"
             << "q. Log out.\n";
        
        cin >> ch;
        double amount;
        string accountNumber;
        switch(ch) {
            case '1':
                cout << "Enter the amount you wish to deposit: ";
                cin >> amount;
                cout << "The amount has been deposited successfully.\n";
                break;
            case '2':
                cout << "Enter the amount you wish to withdraw: ";
                cin >> amount;
                cout << "The amount has been withdrawn successfully.\n";
                break;
            case '3':
                cout << "Enter the account number to which you wish to transfer money: ";
                cin >> accountNumber;
                if (isValid(accountNumber)) {
                    cout << "Enter the amount: ";
                    double amount;
                    cin >> amount;
                    cout << "Transfer Successfull.\n";
                } else {
                    cout << "Invalid Account Number.\n";
                }
                break;
            case '4':
                double balance;
                cout << "Your balance is: " << balance << endl;
                break;
        }
    } while (ch != 'q');
}

bool isValid(string accNum) {
    vector<vector<string>> users = loadfromfile("record.txt");
    vector<string> accNums;
    int index = 2;
    for (vector<string> user : users) {
        accNums.push_back(user[index]);
    }
    if (find(accNums.begin(), accNums.end(), accNum) != accNums.end()) {
        return true;
    }
    return false;
}