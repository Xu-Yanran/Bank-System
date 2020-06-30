//
// Created by 82734 on 2020/6/23.
//

#ifndef BANKSYSTEM_ACCOUNT_H
#define BANKSYSTEM_ACCOUNT_H

# include <fstream>
# include <string>
# include <unordered_map>
# include <list>
# include "Account.h"
# include "Record.h"



using namespace std;

class Account {
private:
public:
    long int ID;
    char* name;
    char* password;
    char* address;
    long int amount;

    int recordCount = 0;

//    list<Record> recordList;        // TODO : here is the bug. But do not know why
    Account() {;}
    Account(long int id, char* n, char* p, char* ad, long int am) {
        ID = id;
        name = n;
        password = p;
        address = ad;
        amount = am;
    }

    char* getPassword();
    long int getAmount();
    void changeAmount(long int am);
    int getRecordAccount();
    void addRecordAccount();
};


#endif //BANKSYSTEM_ACCOUNT_H
