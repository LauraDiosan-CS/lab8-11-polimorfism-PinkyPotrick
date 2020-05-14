#include "Employee.h"
#include <cstddef>
#include <string.h>
#include <iostream>

using namespace std;

Employee::Employee() : Entity() {
	this->ID = 0;
	this->entryRank = 0;
}

Employee::Employee(int ID, string name, string email, int entryRank)
{
	this->ID = ID;
	this->name = name;
	this->email = email;
	this->entryRank = entryRank;
}

Employee::Employee(const Employee &e) {

	this->ID = e.ID;
	this->name = e.name;
	this->email = e.email;
	this->entryRank = e.entryRank;
}

Employee::~Employee() {
	this->name.clear();
	this->email.clear();
}

int Employee::getID() {
	return this->ID;
}

string Employee::getName() {
	return this->name;
}

string Employee::getEmail() {
	return this->email;
}

int Employee::getEntryRank() {
	return this->entryRank;
}

void Employee::setID(int newID) {
	this->ID = newID;
}

void Employee::setName(string newName) {
	this->name = newName;
}

void Employee::setEmail(string newEmail) {
	this->email = newEmail;
}

void Employee::setEntryRank(int newEntryRank) {
	this->entryRank = newEntryRank;
}

Employee& Employee::operator=(const Employee& e) {
	this->setID(e.ID);
	this->setName(e.name);
	this->setEmail(e.email);
	this->setEntryRank(e.entryRank);
	return *this;
}

bool Employee:: operator==(const Employee& e) {
	return (this->ID == e.ID) && (this->name == e.name) && (this->email == e.email) && (this->entryRank == e.entryRank);
}

string Employee::toString()
{
	return to_string(this->ID) + "," + this->name + "," + this->email + "," + to_string(this->entryRank);
}

ostream& operator<<(ostream& os, const Employee& e)
{
	os << e.ID << "|" << e.name << "|" << e.email << "|" << e.entryRank << "\n";
	return os;
}

istream& operator>>(istream& is, Employee& e)
{
	is >> e.ID;
	is.get();
	getline(is, e.name, '|');
	getline(is, e.email, '|');
	is >> e.entryRank;
	is.get();
	return is;
}
