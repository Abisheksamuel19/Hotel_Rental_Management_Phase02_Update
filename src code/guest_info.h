#pragma once
#include<iostream>
#include<conio.h>
#include<string.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include <pqxx/pqxx> 

using namespace std;
using namespace pqxx;
//guest_info.h

class guest_info
{
private:
    char c1;
public:
    const char* sql;

    int showguestInfoMenu();
    void addguest();
    void updateguest_info();
    void deleteguest();
    void bookroom();
    void cancelbooking();
    void reserve_info();
    void check_out();
    void search_info();

    void report();
    int vacancy();
    int occupied();
    int history();
};
