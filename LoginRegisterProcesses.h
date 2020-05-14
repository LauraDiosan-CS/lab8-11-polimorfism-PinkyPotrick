#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

/*
Description: The login process
Input: password - string, the password of the user
	   usernameLogin - string, the username
	   inFile - ifstream, the file where the users are being stored
	   validAuth - bool, True if the authentication has been approved, False otherwise
	   loggedIn - bool, True if the user has logged in succesfully, False otherwise
	   fileName - string, the name of the file where the users and passwords are stored
Output: -
*/
void loginProcess(string password, string &usernameLogin, ifstream &inFile, bool &validAuth, bool &loggedIn, string fileName);
/*
Description: The register process
Input: username - string, the username
       password - string, the password of the user
	   outFile - ofstream, the file where the users are being stored
	   fileName - string, the name of the file where the users and passwords are stored
Output: -
*/
void registerProcess(string username, string password, ofstream &outFile, string fileName);
