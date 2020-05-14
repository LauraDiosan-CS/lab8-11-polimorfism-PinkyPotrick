#pragma once
#include <string>
#include "Entity.h"

using namespace std;

class Employee : public Entity {
protected:
	int ID;
	string name;
	string email;
	int entryRank;
public:
	/*
	Description: This is a default constructor
	Input: -
	Output: -
	*/
	Employee();
	/*
	Description: This is a destructor
	Input: -
	Output: -
	*/
	~Employee();
	/*
	Description: This is a constructor with parameters
	Input: ID - int, the ID of the employee
		   name - string, the name of the employee
		   email - string, the email of the employee
		   entryRank - int, the entry rank of the employee
	Output: -
	*/
	Employee(int ID, string name, string email, int entryRank);
	/*
	Description: This is a copy constructor
	Input: m - const class, the Employee class object
	Output: -
	*/
	Employee(const Employee& m);
	/*
	Description: Returns the ID of the employee
	Input: -
	Output: ID - int, the ID of the employee
	*/
	int getID();
	/*
	Description: Returns the name for the employee
	Input: -
	Output: name - string, the name of the employee
	*/
	string getName();
	/*
	Description: Returns the email for the employee
	Input: -
	Output: email - string, the email of the employee
	*/
	string getEmail();
	/*
	Description: Returns the stock number for the employee
	Input: -
	Output: entryRank - int, the stock number of the employee
	*/
	int getEntryRank();
	/*
	Description: Sets the ID for the employee
	Input: newID - int, the new ID
	Output: -
	*/
	void setID(int newID);
	/*
	Description: Sets the name for an employee
	Input: newName - string, the new name
	Output: -
	*/
	void setName(string newName);
	/*
	Description: Sets the email for an employee
	Input: newEmail - string, the new email
	Output: -
	*/
	void setEmail(string newEmail);
	/*
	Description: Sets the entry rank for an employee
	Input: newEntryRank - int, the new entry rank
	Output: -
	*/
	void setEntryRank(int newEntryRank);
	/*
	Description: Creates a new Employee (equal to a given Employee m)
	Input: m - class, the Employee class object
	Output: a new employee (equal to m)
	*/
	Employee& operator=(const Employee& m);
	/*
	Description: Compares the two objects
	Input: m - class, the Employee class object
	Output: true/false
	*/
	bool operator==(const Employee& m);
	/*
	Description: Converts the Medicine object to a string
	Input: -
	Output: -
	*/
	string toString();
	/*
	Description: Shows the employee using an output stream
	Input: os - ostream&, the output stream
		   m - class, the Employee class object
	Output: os - ostream&, the employee that has been read
	*/
	friend ostream& operator<<(ostream& os, const Employee& m);
	/*
	Description: Reads the employee using an input stream
	Input: is - istream&, the input stream
		   m - class, the Employee class object
	Output: is - istream&, a new Employee class object
	*/
	friend istream& operator>>(istream& is, Employee& m);
};
