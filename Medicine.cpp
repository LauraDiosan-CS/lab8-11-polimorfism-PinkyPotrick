#include "Medicine.h"
#include <cstddef>
#include <string.h>
#include <iostream>

using namespace std;

Medicament::Medicament() : Entity() {
	this->ID = 0;
	this->stockNr = 0;
	this->prescription = false;
}

Medicament::Medicament(int ID, string name, bool prescription, int stockNr, string producer)
{
	this->ID = ID;
	this->name = name;
	this->prescription = prescription;
	this->stockNr = stockNr;
	this->producer = producer;
}

Medicament::Medicament(const Medicament &m) {

	this->ID = m.ID;
	this->name = m.name;
	this->prescription = m.prescription;
	this->stockNr = m.stockNr;
	this->producer = m.producer;
}

Medicament::~Medicament() {
	this->name.clear();
	this->producer.clear();
}

int Medicament::getID() {
	return this->ID;
}

string Medicament::getName() {
	return this->name;
}

bool Medicament::getPrescription() {
	return this->prescription;
}

int Medicament::getStockNr() {
	return this->stockNr;
}

string Medicament::getProducer() {
	return this->producer;
}

void Medicament::setID(int newID) {
	this->ID = newID;
}

void Medicament::setName(string newName) {
	this->name = newName;
}

void Medicament::setPrescription(bool newPrescription) {
	this->prescription = newPrescription;
}

void Medicament::setStockNr(int newStockNr) {
	this->stockNr = newStockNr;
}

void Medicament::setProducer(string newProducer) {
	this->producer = newProducer;
}

Medicament& Medicament::operator=(const Medicament& m) {
	this->setID(m.ID);
	this->setName(m.name);
	this->setPrescription(m.prescription);
	this->setStockNr(m.stockNr);
	this->setProducer(m.producer);
	return *this;
}

bool Medicament:: operator==(const Medicament& m) {
	return (this->ID == m.ID) && (this->name == m.name) && (this->prescription == m.prescription)
		&& (this->stockNr == m.stockNr) && (this->producer == m.producer);
}

bool Medicament:: operator!=(const Medicament& m) {
	return !((this->ID == m.ID) && (this->name == m.name) && (this->prescription == m.prescription)
		&& (this->stockNr == m.stockNr) && (this->producer == m.producer));
}

string Medicament::toString()
{
	string prescriptionString;
	if (this->prescription == 1)
		prescriptionString = "true";
	else
		prescriptionString = "false";
	return to_string(this->ID) + "," + this->name + "," + prescriptionString + "," + to_string(this->stockNr) + "," + producer;
}

ostream& operator<<(ostream& os, const Medicament& m)
{
	string prescriptionString;
	if (m.prescription == 1)
		prescriptionString = "true";
	else
		prescriptionString = "false";
	os << m.ID << "|" << m.name << "|" << prescriptionString << "|" << m.stockNr << "|" << m.producer << "\n";
	return os;
}

istream& operator>>(istream& is, Medicament& m)
{
	string prescriptionString;
	if (m.prescription == true)
		prescriptionString = "true";
	else if (m.prescription == false)
		prescriptionString = "false";
	is >> m.ID;
	is.get();
	getline(is, m.name, '|');
	getline(is, prescriptionString, '|');
	is >> m.stockNr;
	is.get();
	getline(is, m.producer, '|');
	return is;
}
