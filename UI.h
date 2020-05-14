#pragma once
#include "ServiceMedicine.h"
#include "ServiceEmployee.h"

class UI {
private:
	MedicineService serviceMed;
	EmployeeService serviceEmp;
	//Description: Shows the login menu
	void showLoginMenu();
	//Description: Shows the menu
	void showMenu();
	//Description The CRUD Menu
	void handleCRUD();
	//Description: Adds a medicine
	void handleAddMedicine();
	//Description: Read a medicine
	void handleReadMedicine();
	//Description: Updates a medicine
	void handleUpdateMedicine();
	//Description: Shows all the medicines
	void handleShowAllMedicines();
	//Description: Shows all the employees
	void handleShowAllEmployees();
	//Description: Deletes a medicine by ID
	void handleDeleteByID();
	//Description: Shows medicines that have a specific string in them
	void handleSearchMedicine();
	//Description: Updates the entry rank of a specified employee
	void handleUpdateEntryRank();
	//Description: Shows all the users that are registered to this platform
	void handleShowUsers();
	//Description: The login process
	void handleLogin(string &usernameLogin, ifstream &inFile, bool &loggedIn, bool &validAuth);
	//Description: The registration process
	void handleRegister(ofstream &outFile);
public:
	//Description: This is a default constructor
	UI();
	//Description: This is a constructor with parameters
	UI(MedicineService& serviceMed, EmployeeService& serviceEmp);
	//Description: This is a destructor
	~UI();
	//Description: Runs the UI
	void runUI();
};
