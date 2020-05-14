#pragma once
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include <tuple>

class EmployeeService {
private:
	//RepoFileCSV<Employee>* repoEmployeeCSV;
	//RepositoryFileTXT<Employee>* repoEmployeeTXT;
	Repository<Employee>* repoEmployee;
public:
	/*
	Description: This is a default constructor
	Input: -
	Output: -
	*/
	EmployeeService();
	/*
	Description: This is a constructor with parameters
	Input: re - RepositoryFileTXT<Employee>, creates a RepoFileTXT class type object
	Output: -
	*/
	EmployeeService(Repository<Employee>*& rm);
	/*
	Description: This is a destructor
	Input: -
	Output: -
	*/
	~EmployeeService();
	/*
	Description: Sets the repo
	Input: newElementsMed - vector<Medicament>, the new list of medicamente
		   newElementsEmp - vector<Employee>, the new list of employees
	Output: -
	*/
	void setRepo(vector<Employee> newElementsEmp);//, vector<Employee> newElementsEmp);
	/*
	Description: Adds an employee to the repository
	Input: ID - int, the ID of the employee
		   name - string, the name of the employee
		   email - string, the email of the employee
		   entryRank - int, the entryRank of the employee
	Output: -
	*/
	void addEmp(int ID, string name, string email, int entryRank);
	/*
	Description: Returns all the emps from the repository
	Input: -
	Output: -
	*/
	vector<Employee> getAllEmps();
	/*
	Description: Returns the employee at a certain position
	Input: pos - int, the specified position in the list of employees
	Output: -
	*/
	Employee getEmpAtPosition(int pos);
	/*
	Description: Updated the employee by its ID
	Input: ID - int, the ID of the employee that needs to be updated
		   newName - string, the new name for the employee
		   newEmail - string, the new email for the employee
		   newEntryRank - int, the new entry rank for the employee
	Output: -
	*/
	void updateEmpByID(int ID, string newName, string newEmail, int newEntryRank);
	/*
	Description: Deletes the employee by its ID
	Input: ID - int, the ID of the employee that needs to be deleted
	Output: -
	*/
	void deleteEmpByID(int ID);
};
