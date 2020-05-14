#include "LoginRegisterProcesses.h"
#include <iostream>
#include <string>

using namespace std;

void loginProcess(string password, string &usernameLogin, ifstream &inFile, bool &validAuth, bool &loggedIn, string fileName) {

	vector<tuple<string, string>> userAndPassList;

	inFile.open(fileName);

	string line;
	while (getline(inFile, line)) {
		string user, pass;
		string word = "";
		for (auto x : line)
		{
			if (x == '|') {
				user = word;
				word = "";
			}
			else
			{
				word = word + x;
			}
		}
		pass = word;

		tuple<string, string> userPass(user, pass);
		userAndPassList.push_back(userPass);
	}
	inFile.close();

	for (int index = 0; index < userAndPassList.size(); index++) {
		if (get<0>(userAndPassList[index]) == usernameLogin && get<1>(userAndPassList[index]) == password) {
			loggedIn = true;
			validAuth = true;
			break;
		}
	}
}

void registerProcess(string username, string password, ofstream &outFile, string fileName) {
	outFile.open(fileName, ios_base::app);
	outFile << username << "|" << password << endl;
	outFile.close();
}
