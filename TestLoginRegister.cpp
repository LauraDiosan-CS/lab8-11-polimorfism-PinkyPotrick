#include "LoginRegisterProcesses.h"
#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

void testRegister() {
	string username1, password1, username2, password2;
	ofstream outFile;
	ifstream inFile;
	outFile.open("usersListTest.txt", std::ofstream::out | std::ofstream::trunc);
	outFile.close();

	username1 = "Username1";
	password1 = "Password123";
	username2 = "Username2";
	password2 = "Password456";

	registerProcess(username1, password1, outFile, "usersListTest.txt");
	registerProcess(username2, password2, outFile, "usersListTest.txt");

	inFile.open("usersListTest.txt");

	string line;
	getline(inFile, line);
	assert(line == "Username1|Password123");
	getline(inFile, line);
	assert(line == "Username2|Password456");

	inFile.close();
}

void testLogin() {
	string password, username;
	ifstream inFile;
	bool validAuth = false;
	bool loggedIn = false;

	username = "Username1";
	password = "Password123";

	loginProcess(password, username, inFile, validAuth, loggedIn, "usersListTest.txt");

	assert(validAuth == true);
	assert(loggedIn == true);
}
