#pragma once

#include<iostream>
#include<conio.h>
#include<string.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include <pqxx/pqxx> 
//search1.h
//hotel_rentel_management_system

using namespace std;
using namespace pqxx;

class search1
{
public:
    int  room_search();
    void room_type();
    void floor_num();
    void room_rent();
    void vacancy();
    void type_floor();
    void guest_history();

};