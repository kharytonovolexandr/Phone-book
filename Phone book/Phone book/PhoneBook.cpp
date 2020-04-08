#include "PhoneBook.h"
#include <iostream>
#include <list>
#include <fstream>

using namespace std;

#define CLEAR system("cls");
#define PAUSE system("pause");

list<Contact> contacts;
list<user> users;
const string fileName = "contacts.txt";
const string Users = "Users.txt";
void init()
{
	ifstream fin;
	fin.open(fileName);
	bool isOPen = fin.is_open();

	if (isOPen == false) 
	{
		cout << "Error" << endl;
	}
	else {
		Contact temp;
		while (!fin.eof()) 
		{
			getline(fin, temp.FullName);
			if (temp.FullName != "") {
				getline(fin, temp.phoneNumber);
				contacts.push_back(temp);
			}
		
		}

	}

	fin.close();


}

void initUser() {

	ifstream fin2;
	fin2.open(Users);
	bool isOpenUser = fin2.is_open();

	if (isOpenUser == false)
	{
		cout << "Error"<< endl;
	}
	else {
		user temp;
		while (!fin2.eof())
		{
			getline(fin2, temp.login);
			if (temp.login != "") {
				getline(fin2, temp.email);
				getline(fin2, temp.password);

				users.push_back(temp);
			}
		}

	}
	fin2.close();

}

void authorization()
{
	string login;
	string password;
	int tryAgain = 0;
	begin:
	cout << "Enter login or email:" << endl;
	cin >> login;
	cout << "Enter password: " << endl;
	cin >> password;
	
	for (user item : users)
	{
		if (item.login == login || item.password == password)
		{
			cout << "Hello " << login << "!" << endl;

		}
		else
			CLEAR

		cout << "Wrong login or password or such user doesn't exist!" << endl;
		cout << "Press 1 to try again: " << endl;
		cout << "2. Exit" << endl;
		cin >> tryAgain;
		if (tryAgain == 1)
		{
			goto begin;
		}
		else
			break;
		return; //Не знаю як тут зробити, щоб воно геть повернуло на початок функції мейн. Тому хай поки буде так.
	}
}

void addNewUser()
{
	user newUser;
	cout << "Enter name for new user (Login): ";
	cin.ignore();
	getline(cin, newUser.login);
	cout << "Enter email for new user: ";
	cin >> newUser.email;
	cout << "Enter password: ";
	cin >> newUser.password;

	users.push_back(newUser);

	ofstream fout;
	fout.open(Users, fstream::app);

	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connect to database file!" << endl;
	}
	else {
		fout << newUser.login << endl;
		fout << newUser.email << endl;
		fout << newUser.password << endl;

	}
	fout.close();
	cout << "New user added successful..." << endl;
	PAUSE
	CLEAR
}

void addNewContact()
{
	Contact newContact;
	cout << "Enter full name for new contact->_";
	cin.ignore();
	getline(cin,newContact.FullName);
	
	cout << "Enter phone number for new contact->_";
	cin >> newContact.phoneNumber;

	contacts.push_back(newContact);
	
	ofstream fout;
	fout.open(fileName, fstream::app);

	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connecting to database file!" << endl;
	}else {
		fout << newContact.FullName << endl;
		fout << newContact.phoneNumber << endl;
	}
	fout.close(); 
	cout << "New contact successful added..." << endl;
	PAUSE
	CLEAR
}

void showAllContacts()
{
	for (Contact item : contacts) 
	{
		cout << item.FullName << " - " << item.phoneNumber << endl;
	}
}
