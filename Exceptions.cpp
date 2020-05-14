#include "Exceptions.h"
using namespace std;

MedException::MedException() {

}

MedException::~MedException() {

}

void MedException::checkMedicament(Medicament& med) {
	if (typeid(med.getName()) != typeid(string))
		throw("Program: Error! The name of the medicine has to be a string.");
	if (typeid(med.getPrescription()) != typeid(bool))
		throw("Program: Error! The prescription of the medicine has to be a bool.");
	if (typeid(med.getStockNr()) != typeid(int))
		throw("Program: Error! The stock nr of the medicine has to be an integer.");
	if (typeid(med.getProducer()) != typeid(string))
		throw("Program: Error! The producer of the medicine has to be a string.");
}

void MedException::checkMedForID(int ID) {
	vector<Medicament> medsList = medicamente;

	for (int index = 0; index < medsList.size(); index++)
		if (medsList[index].getID() == ID) {
			throw("Program: Error! The ID has been used before, please use another one instead.");
			return;
		}
}

EmployeeException::EmployeeException() {

}

EmployeeException::~EmployeeException() {

}

void EmployeeException::checkEmployee(Employee& emp) {
	if (typeid(emp.getName()) != typeid(string))
		throw("Program: Error! The name of the employee has to be a string.");
	if (typeid(emp.getEmail()) != typeid(string))
		throw("Program: Error! The email of the employee has to be a string.");
	if (typeid(emp.getEntryRank()) != typeid(int))
		throw("Program: Error! The entry rank of the employee has to be an integer.");
}

void EmployeeException::checkEmpForID(int ID) {
	vector<Employee> empsList = employees;

	for (int index = 0; index < empsList.size(); index++)
		if (empsList[index].getID() == ID) {
			throw("Program: Error! The ID has been used before, please use another one instead.");
			return;
		}
}
