#include<iostream>
#include<string>
#include "PhoneBook.h"

using namespace std;

int main() {



	init();
	initUser();

	int hello = 0;
	do
	{
		start:
	cout << "1.Sign in:" << endl;
	cout << "2.Create new account:" << endl;
	cout << "3.Exit:" << endl;
	cin >> hello;
	switch (hello)
	{
	case 1:
	{
		authorization();
		int action = 0;
		do
		{
			cout << "\tMENU:" << endl;
			cout << "1. Add new contact" << endl;
			cout << "2. Show all contacts" << endl;
			cout << "3. Exit" << endl;
			cout << endl;
			cout << "Select action ->_";
			cin >> action;

			switch (action)
			{
			case 1: {
				cout << "ADD NEW CONTACT:" << endl;
				addNewContact();
			}break;

			case 2: {
				cout << "LIST ALL CONTACTS:" << endl;
				showAllContacts();
			}break;

			case 3: {
				cout << "Good Bye!" << endl;
			}break;
			default: {
				cout << "Please select action (1 - 3)" << endl;
			}
			}

		} while (action != 3);
	}break;
	case 2:
	{
		system("cls");
		addNewUser();
	}break;
	case 3:
	{
		system("cls");
		cout << "Good Bye!" << endl;
	}break;
	default:
		break;
	}
	} while (hello!=3);

	system("pause");
	return 0;
}