#include "ServiceEmployee.h"
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

EmployeeService::EmployeeService() {
	this->repoEmployee = new Repository<Employee>;
}

EmployeeService::EmployeeService(Repository<Employee>*& re) {
	this->repoEmployee = re;
}

EmployeeService::~EmployeeService() {

}

void EmployeeService::setRepo(vector<Employee> newElementsEmp) {
	this->repoEmployee->setRepo(newElementsEmp);
}

void EmployeeService::addEmp(int ID, string name, string email, int entryRank) {
	Employee emplpoyee(ID, name, email, entryRank);
	this->repoEmployee->add(emplpoyee);
	//this->repoEmployeeCSV->add(emplpoyee);
}

vector<Employee> EmployeeService::getAllEmps() {
	return this->repoEmployee->getAll();
}

Employee EmployeeService::getEmpAtPosition(int pos) {
	if (pos >= 0 && pos < this->repoEmployee->getSize())
	{
		return this->repoEmployee->getElementAtPosition(pos);
	}
	return Employee();
}

void EmployeeService::updateEmpByID(int ID, string newName, string newEmail, int newEntryRank) {
	vector<Employee> employees = this->repoEmployee->getAll();
	Employee newEmployee(ID, newName, newEmail, newEntryRank);
	for (int i = 0; i < this->repoEmployee->getSize(); i++)
	{
		if (employees[i].getID() == ID)
		{
			Employee oldEmployee(ID, employees[i].getName(), employees[i].getEmail(), employees[i].getEntryRank());
			this->repoEmployee->update(oldEmployee, newEmployee);
			//this->repoEmployeeCSV->update(oldEmployee, newEmployee);
			return;
		}
	}
}

void EmployeeService::deleteEmpByID(int ID) {
	vector<Employee> employees = this->repoEmployee->getAll();
	for (int i = 0; i < this->repoEmployee->getSize(); i++)
	{
		if (employees[i].getID() == ID)
		{
			Employee employeeToBeDeleted(ID, employees[i].getName(), employees[i].getEmail(), employees[i].getEntryRank());
			this->repoEmployee->remove(employeeToBeDeleted);
			//this->repoEmployeeCSV->remove(employeeToBeDeleted);
			return;
		}
	}
}
