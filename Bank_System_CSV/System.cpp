//
// Created by 82734 on 2020/6/23.
//

#include "System.h"
# include <iostream>
# include <fstream>
# include <io.h>
# include "Account.h"
# include "Record.h"
# include <ctime>
# include <sstream>

using namespace std;

long int System::numAcc = 0;
//string sysPath = "C:\\Users\\82734\\Desktop\\BankSystem\\DataOfBank";
string sysPath = "..\\DataOfBank";

void System::initAccount() {
    string in_test;
    char in_name[20];
    char in_password[20];
    char in_address[20];
    cout<<"#######################################"<<endl;
    cout<<"Sir. I will help to create an account. "<<endl;
    cout<<"Please input your name                 "<<endl; cin>>in_name;
    cout<<"Please input your passwword            "<<endl; cin>>in_password;
    cout<<"Please input your address              "<<endl; cin>>in_address;
    cout<<"#######################################"<<endl;
    Account acc(numAcc, in_name, in_password, in_address, 0);
    // insert new account to account map.
    accountMap.insert(make_pair(numAcc, acc));
    // Show the info of the client
    System::numAcc += 1;

    // storage
    // build a folder containing the info of cliend
    string cmd = "mkdir " + sysPath + "\\" + in_name;
    system(cmd.c_str());
    string rcmd = "mkdir " + sysPath + "\\" + in_name + "\\" + "records";
    system(rcmd.c_str());
    // store the info into it.
    ofstream osm(sysPath + "\\" + in_name + "\\info.csv", ios::out);
//    osm.write((char*)&acc,sizeof(Account));
    osm<<System::numAcc<<","<<in_name<<","<<in_password<<","<<in_address<<","<<0<<","<<acc.recordCount;
    osm.close();
}

bool System::searchAccount(string name) {
//    return (accountMap.find(name) == accountMap.end());
    return (0 != _access((sysPath + "\\" + name).c_str(),0));
}

bool System::checkPassword(string n, string p) {
    ifstream ism(sysPath + "\\" + n + "\\info.csv", ios::in);
    string accInfo[6];
    string tmpInfo;
    string wholeInfo;
    int count = 0;
    while(std::getline(ism, wholeInfo))
    {
        istringstream is(wholeInfo);
        while(std::getline(is, tmpInfo, ','))
        {
            accInfo[count] = tmpInfo;
            count++;
        }
    }
    ism.close();
    return (accInfo[2] == p);
}

void System::deposit(string n, long int am) {
    cout<<"May I have your name?"<<endl;
    string manager;
    cin>>manager;
    ifstream ism(sysPath + "\\" + n + "\\info.csv", ios::in);
    string accInfo[6];
    string tmpInfo;
    string wholeInfo;
    int count = 0;
    while(std::getline(ism, wholeInfo))
    {
        istringstream is(wholeInfo);
        while(std::getline(is, tmpInfo, ','))
        {
            accInfo[count] = tmpInfo;
            count++;
        }
    }
    ism.close();
    ofstream osm(sysPath + "\\" + n + "\\info.csv", ios::out);
    osm<<accInfo[0]<<","<<accInfo[1]<<","<<accInfo[2]<<","<<accInfo[3]<<","<<stol(accInfo[4])+am<<","<<stol(accInfo[5])+1;
    osm.close();

    // store records.
    time_t t = time(NULL);
    char ch[64] = {0};
    strftime(ch, sizeof(ch) - 1, "%Y-%m-%d %H:%M:%S", localtime(&t));
    Record rec(stol(accInfo[5])+1, ch, "deposit", am, manager);
    string tmp = to_string(stol(accInfo[5])+1);
    rec.display();
    ofstream rosm(sysPath + "\\" + n + "\\" + "records" + "\\" + tmp + ".csv", ios::out);
    rosm<<stol(accInfo[5])+1<<","<<ch<<","<<"deposit"<<","<<am<<","<<manager;
    rosm.close();
}

void System::withdraw(string n, int am) {
    ifstream ism(sysPath + "\\" + n + "\\info.csv", ios::in);
    string accInfo[6];
    string tmpInfo;
    string wholeInfo;
    int count = 0;
    while(std::getline(ism, wholeInfo))
    {
        istringstream is(wholeInfo);
        while(std::getline(is, tmpInfo, ','))
        {
            accInfo[count] = tmpInfo;
            count++;
        }
    }
    ism.close();
    if (am > stol(accInfo[4])) {
        cout<<"Sir, your balance is insufficient.\n";
        return;
    } else {
        cout<<"May I have your name?"<<endl;
        string manager;
        cin>>manager;

        ofstream osm(sysPath + "\\" + n + "\\info.csv", ios::out);
        osm<<accInfo[0]<<","<<accInfo[1]<<","<<accInfo[2]<<","<<accInfo[3]<<","<<stol(accInfo[4])-am<<","<<stol(accInfo[5])+1;
        osm.close();

        // store records.
        time_t t = time(NULL);
        char ch[64] = {0};
        strftime(ch, sizeof(ch) - 1, "%Y-%m-%d %H:%M:%S", localtime(&t));
        Record rec(stol(accInfo[5])+1, ch, "withdraw", am, manager);
        string tmp = to_string(stol(accInfo[5])+1);
        rec.display();
        ofstream rosm(sysPath + "\\" + n + "\\" + "records" + "\\" + tmp + ".csv", ios::out);
        rosm<<stol(accInfo[5])+1<<","<<ch<<","<<"withdraw"<<","<<am<<","<<manager;
        rosm.close();
    }
}

void System::inquire(string n) {
    for (int i = 1; !(0 != _access((sysPath + "\\" + n + "\\" + "records" + "\\" + (to_string(i)) + ".csv").c_str(),0)); i++){
        string accInfo[5];
        string tmpInfo;
        string wholeInfo;
        int count = 0;
        ifstream ism(sysPath + "\\" + n + "\\" + "records" + "\\" + to_string(i) + ".csv", ios::in);
        while(std::getline(ism, wholeInfo))
        {
            istringstream is(wholeInfo);
            while(std::getline(is, tmpInfo, ','))
            {
                accInfo[count] = tmpInfo;
                count++;
            }
        }
        ism.close();
        cout<<"###############################"<<endl;
        cout<<"ID:          "<<accInfo[0]<<endl;
        cout<<"date:        "<<accInfo[1]<<endl;
        cout<<"type:        "<<accInfo[2]<<endl;
        cout<<"amount:      "<<accInfo[3]<<endl;
        cout<<"manager:     "<<accInfo[4]<<endl;
    }
}
