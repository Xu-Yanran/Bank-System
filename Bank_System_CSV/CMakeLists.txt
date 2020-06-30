cmake_minimum_required(VERSION 3.15)
project(Bank_System_CSV)

set(CMAKE_CXX_STANDARD 14)

add_executable(BankSystem main.cpp System.cpp System.h Account.cpp Account.h Record.cpp Record.h)