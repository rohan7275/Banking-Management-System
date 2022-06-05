#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "Admin.h"

void Admin::addNewAccount() {
    User user = User();
}

void Admin::removeAccount() {
    string id;
    cout << "Enter the userID you wish to delete: ";
    cin >> id;
    cout << '\n';
    ifstream ifs("record.txt");
    string line;
    int num = 0;
    while(getline(ifs, line)) {
        num++;
        size_t pos = line.find(id);
        if (pos != string::npos)
            break;
    }
    ifs.close();
    ifstream is("record.txt");
    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);
    char c;
    int line_no = 1;
    while (is.get(c)) {
        if (c == '\n')
        line_no++;
  
        if (line_no != num)
            ofs << c;
    }
  
    ofs.close();
    is.close();
    remove("record.txt");
    rename("temp.txt", "record.txt");
}

bool Admin::authenticateUser() {
    string userID, pwd;
    cout << "Enter UserID: ";
    cin >> userID;
    cout << "\nEnter pwd: ";
    cin >> pwd;
    vector<vector<string>> users = loadfromfile("record.txt");
    string hash_val = to_string(User::hash(pwd));
    for (vector<string> user : users) {
        if (user[0] == userID) {
            if (user[3] == hash_val) return true;
        }
    }
    return false;
}

void Admin::listAllAccounts() {
    vector<vector<string>> users = loadfromfile("record.txt");
    if (users.size() == 0) {
        cout << "No accounts created yet.\n";
        return;
    }
    cout << "UserId | Balance | AccNumber\n";
    for (vector<string> user : users) {
            int count = 0;
            for (string s : user) {
                count++;
                if (count == 4) {
                    break;
                }
                cout << s << " ";
            }
            cout << '\n';
    }
}
