#pragma once

#include "Account.h"
#include "SavAccount.h"
#include "CurrAccount.h"

#include <iostream>
using namespace std;

class User {
public:
    User();
    ~User();

    void setUserId(string id);
    void setpassword(string pwd);
    static long long hash(string pwd);
    string getUserId();
    long long gethash();
    void updateFile();
    
private:
    string userId;
    long long passwordhash;
    Account* account;
    
};