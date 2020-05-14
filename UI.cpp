#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include "Exceptions.h"
#include "UI.h"
#include "LoginRegisterProcesses.h"

UI::UI() {

}

UI::UI(MedicineService& serviceMed, EmployeeService& serviceEmp) {
	this->serviceMed = serviceMed;
	this->serviceEmp = serviceEmp;
}

UI::~UI() {

}

void UI::showLoginMenu() {
	cout << "\nPlease authenticate to proceed.\nPress 1 to login, press 2 to register, press 3 to exit.\n\n";
	cout << "1. Login.\n";
	cout << "2. Register.\n";
	cout << "3. Exit.\n";
}

void UI::showMenu() {
	cout << "Menu:\n\n";
	cout << "1. Search for meds.\n";
	cout << "2. CRUD medicine.\n";
	cout << "3. Update the entry rank for a specified employee.\n";
	cout << "4. Show all the users that are registered to this platform.\n";
	cout << "5. Logout.\n";
}

void UI::handleCRUD() {

	while (true) {
		cout << "\nMedicine CRUD\n\n";
		cout << "1. Create medicine.\n";
		cout << "2. Read medicine by ID.\n";
		cout << "3. Update medicine.\n";
		cout << "4. Delete medicine.\n";
		cout << "5. Go back.\n";

		try {
			int optionCRUD;
			cout << "Program: Write an option from the ones above.\nUser: ";
			cin >> optionCRUD;

			//throw exception("Program: Error! The option has to be an integer type.\n");

			if (optionCRUD == 1) {
				handleAddMedicine();
			}
			else if (optionCRUD == 2) {
				handleReadMedicine();
			}
			else if (optionCRUD == 3) {
				handleUpdateMedicine();
			}
			else if (optionCRUD == 4) {
				handleDeleteByID();
			}
			else if (optionCRUD == 5) {
				break;
			}
			else
				cout << "Program: Error! Option unavailable.\n";
		}
		catch (exception &exc){
			cout << exc.what() << endl;
			system("pause");
		}
	}
}

void UI::handleAddMedicine() {
	cout << "The medicine has been added.\n";
}

void UI::handleReadMedicine() {

}

void UI::handleDeleteByID() {
	cout << "The medicine has been deleted.\n";
}

void UI::handleUpdateMedicine() {
	cout << "The medicine has been updated.\n";
}

void UI::handleSearchMedicine() {

}

void UI::handleShowAllMedicines() {

}

void UI::handleShowAllEmployees() {

}

void UI::handleUpdateEntryRank() {

}

void UI::handleShowUsers() {

}

void UI::handleLogin(string &usernameLogin, ifstream &inFile, bool &loggedIn, bool &validAuth) {

	string password;
	cout << "Username: ";
	cin >> usernameLogin;
	cout << "Password: ";
	cin >> password;

	loginProcess(password, usernameLogin, inFile, validAuth, loggedIn, "usersList.txt");

	if (validAuth) {
		cout << "\nProgram: You have succesfully logged in.\n";
	}
}

void UI::handleRegister(ofstream &outFile) {

	string username, password, confirmedPassword;
	bool registerApproved = false;

	while (registerApproved == false) {
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		cout << "Confirm password: ";
		cin >> confirmedPassword;

		if (password == confirmedPassword)
			registerApproved = true;
		else
			cout << "\n\nProgram: Error! The password does not match the confirmed password.\n";
	}

	registerProcess(username, password, outFile, "usersList.txt");

	cout << "\n\nProgram: You have succesfully registered\n";
}

void UI::runUI() {

	string extension;
	//RepositoryFileTXT<Medicament>* repoMedicamenteTXT;
	//RepositoryFileTXT<Employee>* repoEmployeesTXT;
	//RepoFileCSV<Medicament>* repoMedicamenteCSV;
	//RepoFileCSV<Employee>* repoEmployeesCSV;
	bool validAuth;
	bool loggedIn;
	bool txtExtension = false;
	bool csvExtension = false;

	ofstream outFile;
	ifstream inFile;

	cout << "Welcome!\n";
	while (true) {

		showLoginMenu();
		int option1;
		string usernameLogin;
		validAuth = false;
		loggedIn = false;

		cout << "\nProgram: Choose an option from the ones above.\nUser: ";
		cin >> option1;
		if (option1 == 1) {
			handleLogin(usernameLogin, inFile, loggedIn, validAuth);
		}
		else if (option1 == 2) {
			handleRegister(outFile);
		}
		else if (option1 == 3) {
			break;
		}
		else {
			cout << "\nProgram: Error! Invalid option.\n";
		}

		if (validAuth == true && loggedIn == true) {
			cout << "Program: Welcome " << usernameLogin << "!\n";
			bool correctExtension = false;

			while (correctExtension == false) {
				cout << "         Which file extension would you like to use? Write 'txt' or 'csv'.\nUser: ";
				cin >> extension;
				if (extension == "txt")
				{
					txtExtension = true;
					csvExtension = false;
					correctExtension = true;
					//repoMedicamenteTXT = new RepositoryFileTXT<Medicament>("Medicamente.txt");
					//repoEmployeesTXT = new RepositoryFileTXT<Employee>("Employees.txt");
				}
				else if (extension == "csv")
				{
					csvExtension = true;
					txtExtension = false;
					correctExtension = true;
					//repoMedicamenteCSV = new RepoFileCSV<Medicament>("Medicamente.csv");
					//repoEmployeesCSV = new RepoFileCSV<Employee>("Employees.csv");
				}
				else {
					cout << "Program: Error! The written extension is unavailable.\n";
					correctExtension = false;
				}
			}
			
			while (true) {
				cout << "The list of medicines is:\n\n";
				handleShowAllMedicines();
				cout << "\n\n";
				cout << "The list of employees is:\n\n";
				handleShowAllEmployees();
				cout << "\n\n";
				showMenu();

				int option2;

				cout << "\nProgram: Choose an option from the ones above.\nUser: ";
				cin >> option2;
				if (option2 == 1) {
					handleSearchMedicine();
				}
				else if (option2 == 2) {
					handleCRUD();
				}
				else if (option2 == 3) {
					handleUpdateEntryRank();
				}
				else if (option2 == 4) {
					handleShowUsers();
				}
				else if (option2 == 5) {
					loggedIn = false;
					break;
				}
				else {
					cout << "\nProgram: Error! Invalid option.\n";
				}
			}
		}
		else {
			cout << "\nProgram: Error! Invalid credentials. Please try again.";
		}
	}

	system("pause");
	return;
}
