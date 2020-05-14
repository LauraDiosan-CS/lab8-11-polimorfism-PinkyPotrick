#include "ServiceMedicine.h"
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

MedicineService::MedicineService() {
	this->repoMedicament = new Repository<Medicament>;
}

MedicineService::MedicineService(Repository<Medicament>*& rm) {
	this->repoMedicament = rm;
}

MedicineService::~MedicineService() {

}

void MedicineService::setRepo(vector<Medicament> newElementsMed) {
	this->repoMedicament->setRepo(newElementsMed);
}

void MedicineService::add(const Medicament med) {//int ID, string name, bool prescription, int stockNr, string producer) {
	//Medicament medicament(ID, name, prescription, stockNr, producer);
	this->repoMedicament->add(med);//medicament);
	//this->repoMedicamentCSV->add(medicament);
}

vector<Medicament> MedicineService::getAll() {
	return this->repoMedicament->getAll();
}

Medicament MedicineService::getMedAtPosition(int pos) {
	if (pos >= 0 && pos < this->repoMedicament->getSize())
	{
		return this->repoMedicament->getElementAtPosition(pos);
	}
	return Medicament();
}

void MedicineService::update(Medicament& oldMed, Medicament& newMed) {
	this->repoMedicament->update(oldMed, newMed);
}

/*
void MedicineService::updateMedByID(int ID, string newName, bool newPrescription, int newStockNr, string newProducer) {
	vector<Medicament> meds = this->repoMedicament->getAll();
	Medicament newMedicament(ID, newName, newPrescription, newStockNr, newProducer);
	for (int i = 0; i < this->repoMedicament->getSize(); i++)
	{
		if (meds[i].getID() == ID)
		{
			Medicament oldMedicament(ID, meds[i].getName(), meds[i].getPrescription(), meds[i].getStockNr(), meds[i].getProducer());
			this->repoMedicament->update(oldMedicament, newMedicament);
			this->repoMedicamentCSV->update(oldMedicament, newMedicament);
			return;
		}
	}
}
*/

void MedicineService::remove(int ID) {
	vector<Medicament> meds = this->repoMedicament->getAll();
	for (int i = 0; i < this->repoMedicament->getSize(); i++)
	{
		if (meds[i].getID() == ID)
		{
			Medicament medToBeDeleted(ID, meds[i].getName(), meds[i].getPrescription(), meds[i].getStockNr(), meds[i].getProducer());
			this->repoMedicament->remove(medToBeDeleted);
			//this->repoMedicamentCSV->remove(medToBeDeleted);
			return;
		}
	}
}

vector<Medicament> MedicineService::search(string medSubStr) {
	vector<Medicament> elemente;
	for (int index = 0; index < this->repoMedicament->getSize(); index++) {
		string aux = this->repoMedicament->getAll()[index].toString();
		string name = this->repoMedicament->getAll()[index].getName();
		if (name.find(medSubStr) != string::npos) {
			elemente.push_back(this->repoMedicament->getAll()[index]);
		}
	}
	return elemente;
}

