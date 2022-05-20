#pragma once
#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include <pqxx/pqxx> 

using namespace std;
using namespace pqxx;

//guestlogin.h
class guestlogin
{
public:
	void guestsignup();
	void guestsignin();
	void guest_login();

};

