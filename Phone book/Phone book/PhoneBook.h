#pragma once
#include<string>
using namespace std;

struct Contact
{
	string FullName;
	string phoneNumber;
};
struct user
{
	string login;
	string email;
	string password;
};

void initUser();
void init();
void authorization();
void addNewUser(); 
void addNewContact();
void showAllContacts();