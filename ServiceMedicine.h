#pragma once
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include <tuple>

class MedicineService {
private:
	//RepoFileCSV<Medicament>* repoMedicamentCSV;
	//RepoFileCSV<Employee>* repoEmployeeCSV;
	//RepositoryFileTXT<Medicament>* repoMedicamentTXT;
	//RepositoryFileTXT<Employee>* repoEmployeeTXT;
	Repository<Medicament>* repoMedicament;
public:
	/*
	Description: This is a default constructor
	Input: -
	Output: -
	*/
	MedicineService();
	/*
	Description: This is a constructor with parameters
	Input: rm - RepositoryFileTXT<Medicament>, creates a RepoFileTXT class type object
		   re - RepositoryFileTXT<Employee>, creates a RepoFileTXT class type object
	Output: -
	*/
	MedicineService(Repository<Medicament>*& rm);
	/*
	Description: This is a destructor
	Input: -
	Output: -
	*/
	~MedicineService();
	/*
	Description: Sets the repo
	Input: newElementsMed - vector<Medicament>, the new list of medicamente
		   newElementsEmp - vector<Employee>, the new list of employees
	Output: -
	*/
	void setRepo(vector<Medicament> newElementsMed);//, vector<Employee> newElementsEmp);
	/*
	Description: Adds a medicament to the repository
	Input: ID - int, the ID of the med
		   name - string, the name of the med
		   prescription - bool, the prescription of the med
		   stockNr - int, the stockNr of the med
		   producer - string, the producer of the med
	Output: -
	*/
	//void addMed(int ID, string name, bool prescription, int stockNr, string producer);
	void add(const Medicament med);
	/*
	Description: Returns all the meds from the repository
	Input: -
	Output: -
	*/
	vector<Medicament> getAll();
	/*
	Description: Returns the med at a certain position
	Input: pos - int, the specified position in the list of meds
	Output: -
	*/
	Medicament getMedAtPosition(int pos);
	/*
	Description: Updated the med by its ID
	Input: ID - int, the ID of the med that needs to be updated
		   newName - string, the new name for the med
		   newPrescription - bool, the new ingredients for the med
		   newStockNr - int, the new stock number for the med
		   newProducer - string, the new producer for the med
	Output: -
	*/
	//void updateMedByID(int ID, string newName, bool newPrescription, int newStockNr, string newProducer);
	void update(Medicament& oldMed, Medicament& newMed);
	/*
	Description: Deletes the med by its ID
	Input: ID - int, the ID of the med that needs to be deleted
	Output: -
	*/
	void remove(int ID);
	//Description: Searches for a medicine in the repository
	vector<Medicament> search(string medSubStr);
};
