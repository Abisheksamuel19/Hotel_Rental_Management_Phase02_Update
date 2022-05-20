#pragma once
#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include <pqxx/pqxx> 

using namespace std;
using namespace pqxx;
//guest_console.h
class guest_console
{
private:
	char c1;

public:

	void updateguestinfo();
	void bookroom();
	void cancelbooking();
	int reserve();
	void check_out();

	void guest_menu();
};