#pragma once
#include <string>
#include "Entity.h"

using namespace std;

class Medicament : public Entity {
protected:
	int ID;
	string name;
	bool prescription;
	int stockNr;
	string producer;
public:
	/*
	Description: This is a default constructor
	Input: -
	Output: -
	*/
	Medicament();
	/*
	Description: This is a destructor
	Input: -
	Output: -
	*/
	~Medicament();
	/*
	Description: This is a constructor with parameters
	Input: ID - int, the ID of the Medicament
		   name - string, the name of the Medicament
		   prescription - string, "Yes" if the Medicament needs prescription, "No" otherwise
		   stockNr - int, the stock number of the Medicament
		   producer - string, the producer of the Medicament
	Output: -
	*/
	Medicament(int ID, string name, bool prescription, int stockNr, string producer);
	/*
	Description: This is a copy constructor
	Input: m - const class, the Medicament class object
	Output: -
	*/
	Medicament(const Medicament& m);
	/*
	Description: Returns the ID of the Medicament
	Input: -
	Output: ID - int, the ID of the Medicament
	*/
	int getID();
	/*
	Description: Returns the name for the Medicament
	Input: -
	Output: name - string, the name of the Medicament
	*/
	string getName();
	/*
	Description: Returns the Prescription for the Medicament
	Input: -
	Output: prescription - bool, "Yes" if the Medicament requires a prescription, "No" otherwise
	*/
	bool getPrescription();
	/*
	Description: Returns the stock number for the Medicament
	Input: -
	Output: stockNr - int, the stock number of the Medicament
	*/
	int getStockNr();
	/*
	Description: Returns the producer of the Medicament
	Input: -
	Output: producer - string, the producer of the Medicament
	*/
	string getProducer();
	/*
	Description: Sets the ID for the Medicament
	Input: newID - int, the new ID
	Output: -
	*/
	void setID(int newID);
	/*
	Description: Sets the name for a Medicament
	Input: newName - string, the new name
	Output: -
	*/
	void setName(string newName);
	/*
	Description: Sets the prescription for a Medicament
	Input: newPrescription - bool, the new prescription
	Output: -
	*/
	void setPrescription(bool newPrescription);
	/*
	Description: Sets the stock number for a Medicament
	Input: newStockNr - int, the new stock number
	Output: -
	*/
	void setStockNr(int newStockNr);
	/*
	Description: Sets the producer for a Medicament
	Input: newProducer - string, the new producer
	Output: -
	*/
	void setProducer(string newProducer);
	/*
	Description: Creates a new Medicament (equal to a given Medicament m)
	Input: m - class, the Medicament class object
	Output: a new Medicament (equal to m)
	*/
	Medicament& operator=(const Medicament& m);
	/*
	Description: Compares the two objects
	Input: m - class, the Medicament class object
	Output: true/false
	*/
	bool operator==(const Medicament& m);
	/*
	Description: Compares the two objects
	Input: m - class, the Medicament class object
	Output: true/false
	*/
	bool operator!=(const Medicament& m);
	/*
	Description: Converts the Medicament object to a string
	Input: -
	Output: -
	*/
	string toString();
	/*
	Description: Shows the Medicament using an output stream
	Input: os - ostream&, the output stream
		   m - class, the Medicament class object
	Output: os - ostream&, the Medicament that has been read
	*/
	friend ostream& operator<<(ostream& os, const Medicament& m);
	/*
	Description: Reads the Medicament using an input stream
	Input: is - istream&, the input stream
		   m - class, the Medicament class object
	Output: is - istream&, a new Medicament class object
	*/
	friend istream& operator>>(istream& is, Medicament& m);
};
