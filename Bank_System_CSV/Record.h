//
// Created by 82734 on 2020/6/23.
//

#ifndef BANKSYSTEM_RECORD_H
#define BANKSYSTEM_RECORD_H

# include <string>
# include <list>
# include "Account.h"


using namespace std;


class Record {
private:
    long int ID;
    string date;
    string type;
    long int amount;
    string manager;
//    Account *client;      //TODO: add a client
public:
    Record() {;}
    Record(long int id, string d, string t, long int a, string m);
    void display();

};


#endif //BANKSYSTEM_RECORD_H
