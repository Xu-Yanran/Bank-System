//
// Created by 82734 on 2020/6/23.
//

#include "Account.h"

char* Account::getPassword() {
    return password;
}

long int Account::getAmount() {
    return amount;
}

void Account::changeAmount(long int am) {
    amount += am;
}

int Account::getRecordAccount() {
    return recordCount;
}

void Account::addRecordAccount() {
    recordCount++;
}