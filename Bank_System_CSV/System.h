//
// Created by 82734 on 2020/6/23.
//

#ifndef BANKSYSTEM_SYSTEM_H
#define BANKSYSTEM_SYSTEM_H

# include <string>
# include <unordered_map>
# include <list>
# include "Account.h"
# include "Record.h"

using namespace std;

class System {
    unordered_map<long int, Account> accountMap;
//    list<Record> recordList;
public:
    static long int numAcc;    // TODO: temp account ID
    System() {};
    void initAccount();
    void deposit(string n, long int am);
    void withdraw(string n, int am);
    void inquire(string n);
    bool searchAccount(string name);
    bool checkPassword(string n, string p);
};


#endif //BANKSYSTEM_SYSTEM_H
