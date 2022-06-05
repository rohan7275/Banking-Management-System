#pragma once

using namespace std;

vector<vector<string>> loadfromfile(string filename);

class Admin {
public:
    static void listAllAccounts();
    static void addNewAccount();
    static void removeAccount();
    static bool authenticateUser();
private:
};