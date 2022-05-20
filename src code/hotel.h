#pragma once
#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include <pqxx/pqxx> 
//hotel.h
//hotel_rentel_management_system

using namespace std;
using namespace pqxx;


class hotel
{
private:
    char c1;
public:
    const char* sql;

    int showInfoMenu();
    void addrooms();
    void deleterooms();
    void updaterooms();
    void selectrooms();

};