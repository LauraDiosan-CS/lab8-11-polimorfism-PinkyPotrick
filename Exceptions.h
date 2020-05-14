#pragma once
#include "Medicine.h"
#include "Employee.h"
#include <vector>
using namespace std;

class MedException {
protected:
	vector<Medicament> medicamente;
public:
	MedException();
	~MedException();
	void checkMedicament(Medicament& m);
	void checkMedForID(int ID);
};

class EmployeeException {
protected:
	vector<Employee> employees;
public:
	EmployeeException();
	~EmployeeException();
	void checkEmployee(Employee& e);
	void checkEmpForID(int ID);
};
