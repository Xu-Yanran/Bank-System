//
// Created by 82734 on 2020/6/23.
//

#include "Record.h"
#include <iostream>

Record::Record(long int id, string d, string t, long int a, string m) {
    ID = id;
    date = d;
    type = t;
    amount = a;
    manager = m;
//    client = c;
}

void Record::display() {
    cout<<"###############################"<<endl;
    cout<<"ID:          "<<ID<<endl;
    cout<<"date:        "<<date<<endl;
    cout<<"type:        "<<type<<endl;
    cout<<"amount:      "<<amount<<endl;
    cout<<"manager:     "<<manager<<endl;
}