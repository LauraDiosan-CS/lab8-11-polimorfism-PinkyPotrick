#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include "Medicine.h"
#include "Employee.h"

using namespace std;

template <class T> class Repository {
private:
	vector<T> elements;
	//vector<Medicament> medicamente;
	//vector<Employee> employees;
public:
	/*
	Description: This is a default constructor
	Input: -
	Output: -
	*/
	Repository();
	/*
	Description: This is a destructor
	Input: -
	Output: -
	*/
	~Repository();
	/*
	Description: This following function adds an element to the repository
	Input: elem - const T, the elements that is added
	Output: -
	*/
	virtual void add(const T elem);
	/*
	Description: Returns all the elements from the repository
	Input: -
	Output: elements - vector, the list of elements
	*/
	virtual vector<T> getAll();
	/*
	Description: Retuns the size of the repository
	Input: -
	Output: the size of the list
	*/
	virtual int getSize();
	/*
	Description: Returns the element at a specified position
	Input: pos - int, the position from the list
	Output: element - vector, the element from the specified position
	*/
	virtual T getElementAtPosition(int pos);
	/*
	Description: Updates an old element from the repository with a new one
	Input: oldElem - T&, the old element
		   newElem - T&, the new element
	Output: -
	*/
	virtual void update(T& oldElem, T& newElem);
	/*
	Description: Deletes an element from the repository
	Input: elem - T&, the element that will be deleted
	Output: -
	*/
	virtual void remove(T& elem);
	/*
	Description: Sets the new list of elements for the repository
	Input: newElements - vector<T>, the new list of elements
	Output: -
	*/
	virtual void setRepo(vector<T> newElements);
	/*
	Description: Creates a repo object
	Input: r - const Repository<T>&, a Repository class object
	Output: a new Repository type object equal with r
	*/
	virtual Repository<T>& operator=(const Repository<T>& r);
	/*
	Description: Clears the repo
	Input: -
	Output: -
	*/
	virtual void clearRepo();
};

template <class T> Repository<T>::Repository() {
}

template <class T> Repository<T>::~Repository() {

}

template <class T> void Repository<T>::add(const T elem) {
	/*
	T temp;
	Medicament med;
	Employee emp;
	if (typeid(temp) == typeid(med))
		medicamente.push_back(elem);
	if (typeid(temp) == typeid(emp))
		employees.push_back(elem);
	*/
	this->elements.push_back(elem);
}
/*
	vector<Medicament> medicines = this->elements();
	for (int i = 0; i < this->elements.size(); i++)
	{
		if (medicines[i].getID() == ID)
		{
			Medicament deletedMed(ID, medicines[i].getName(), medicines[i].getPrescription(), medicines[i].getStockNr(), medicines[i].getProducer());
			this->elements.erase(deletedMed);
			return;
		}
	}
*/
template <class T> void Repository<T>::remove(T& elem) {
	
	typename vector<T>::iterator it;

	/*
	T temp;
	Medicament med;
	Employee emp;
	if (typeid(temp) == typeid(med)) {
		it = find(this->medicamente.begin(), this->medicamente.end(), elem);
		if (!(it == this->medicamente.end())) {
			this->medicamente.erase(it);
		}
	}
	if (typeid(temp) == typeid(emp)) {
		it = find(this->employees.begin(), this->employees.end(), elem);
		if (!(it == this->employees.end())) {
			this->employees.erase(it);
		}
	}
	*/
	
	it = find(this->elements.begin(), this->elements.end(), elem);
	if (!(it == this->elements.end())) {
		this->elements.erase(it);
	}
}

template <class T> void Repository<T>::update(T& oldElem, T& newElem) {
	typename vector<T>::iterator it;
	/*
	T temp;
	Medicament med;
	Employee emp;
	if (typeid(temp) == typeid(med)) {
		it = find(this->medicamente.begin(), this->medicamente.end(), oldElem);
		if (!(it == this->medicamente.end())) {
			*it = newElem;
		}
	}
	if (typeid(temp) == typeid(emp)) {
		it = find(this->employees.begin(), this->employees.end(), oldElem);
		if (!(it == this->employees.end())) {
			*it = newElem;
		}
	}
	*/
	it = find(this->elements.begin(), this->elements.end(), oldElem);
	if (!(it == this->elements.end())) {
		*it = newElem;
	}
}

template <class T> T Repository<T>::getElementAtPosition(int pos) {
	/*
	T temp;
	Medicament med;
	Employee emp;
	if (typeid(temp) == typeid(med)) {
		return this->medicamente[pos];
	}
	if (typeid(temp) == typeid(emp)) {
		return this->elements[pos];
	}
	*/
	return this->elements[pos];
}

template <class T> void Repository<T>::setRepo(vector<T> newElements) {
	/*
	T temp;
	Medicament med;
	Employee emp;
	if (typeid(temp) == typeid(med)) {
		this->medicamente = newElements;
	}
	if (typeid(temp) == typeid(emp)) {
		this->employees = newElements;
	}
	*/
	this->elements = newElements;
}

template <class T> vector<T> Repository<T>::getAll() {
	/*
	T temp;
	Medicament med;
	Employee emp;
	if (typeid(temp) == typeid(med)) {
		return this->medicamente;
	}
	if (typeid(temp) == typeid(emp)) {
		return this->employees;
	}
	*/
	return this->elements;
}

template <class T> int Repository<T>::getSize() {
	/*
	T temp;
	Medicament med;
	Employee emp;
	if (typeid(temp) == typeid(med)) {
		return this->medicamente.size();
	}
	if (typeid(temp) == typeid(emp)) {
		return this->employees.size();
	}
	*/
	return this->elements.size();
}

template <class T> void Repository<T>::clearRepo() {
	/*
	T temp;
	Medicament med;
	Employee emp;
	if (typeid(temp) == typeid(med)) {
		this->medicamente.clear();
	}
	if (typeid(temp) == typeid(emp)) {
		this->employees.clear();
	}
	*/
	this->elements.clear();
}

template <class T> Repository<T>& Repository<T>::operator=(const Repository<T>& r) {
	/*
	T temp;
	Medicament med;
	Employee emp;
	if (typeid(temp) == typeid(med)) {
		this->medicamente = r.medicamente;
	}
	if (typeid(temp) == typeid(emp)) {
		this->employees = r.employees;
	}
	*/
	this->elements = r.elements;
	return *this;
}
