#pragma once
#include "RepoFileCSV.h"
#include "Medicine.h"

template <class T> class RepoFileCSV : public Repository<T> {
private:
	char* fileName;
public:
	/*
	Description: This is a default constructor
	Input: -
	Output: -
	*/
	RepoFileCSV() :Repository<T>() {
		this->fileName = NULL;
	}
	/*
	Description: This is a destructor
	Input: -
	Output: -
	*/
	~RepoFileCSV() {
		if (this->fileName) {
			delete[] this->fileName;
			this->fileName = NULL;
		}
	}
	/*
	Description: Creates a RepoFileCSV class object
	Input: fileName - const char*, the name of the file
	Output: -
	*/
	RepoFileCSV(const char* fileName) :Repository<T>() {
		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		this->loadFromFile();
	}
	/*
	Description: Loads the list of elements from a file
	Input: -
	Output: -
	*/
	void loadFromFile() {
		if (this->fileName != NULL) {
			ifstream in(this->fileName);
			T elem;
			//in >> elem;
			//cout << "\nelem = " << elem << "\n";

			while (in >> elem)
				Repository<T>::add(elem);

			in.close();
		}
		else
			Repository<T>::clearRepo();
	}
	/*
	Description: Saves the list of elements in a file
	Input: -
	Output: -
	*/
	void saveToFile() {
		if (this->fileName != NULL)
		{
			ofstream out(this->fileName);
			int size = Repository<T>::getSize();
			for (int index = 0; index < size; index++)
			{
				T elem = Repository<T>::getElementAtPosition(index);
				out << elem.toString() << endl;
			}
		}
	}
	/*
	Description: Sets the name of the file for a RepoFileCSV
	Input: - fileName - const char*, the new name for the file
	Output: -
	*/
	void setFileName(const char* fileName) {
		if (this->fileName)
			delete[] this->fileName;

		if (fileName != NULL) {
			this->fileName = new char[strlen(fileName) + 1];
			strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		}
		else
			this->fileName = NULL;
	}
	/*
	Description: Returns the name of the file
	Input: -
	Output: fileName - char, the name of the file
	*/
	char* getFileName() {
		return this->fileName;
	}
	/*
	Description: Adds an element to the repository file
	Input: elem - T, the element that will be added
	Output: -
	*/
	void add(const T elem) {
		Repository<T>::add(elem);
		this->saveToFile();
	}
	/*
	Description: Deletes an element from the repository file
	Input: elem - T&, the element that will be deleted
	Output: -
	*/
	void remove(T& elem) {
		Repository<T>::remove(elem);
		this->saveToFile();
	}
	/*
	Description: Updated an element from the repository file
	Input: oldElem - T&, the old element that needs to be updated
		   newElem - T&, the new element which replaces the old one
	Output: -
	*/
	void update(T& oldElem, T& newElem) {
		Repository<T>::update(oldElem, newElem);
		this->saveToFile();
	}
	/*
	Description: Returns all the elements from the repository file
	Input: -
	Output: -
	*/
	vector<T> getAll() {
		return Repository<T>::getAll();
	}
	/*
	Description: Creates a repoFile object
	Input: r - RepoFileCSV<T>&, a RepoFileCSV class object
	Output: a new RepoFileCSV type object equal with r
	*/
	RepoFileCSV<T>& operator=(RepoFileCSV<T>& r) {
		this->Repository<T>::setRepo(r.getAll());
		this->setFileName(r.fileName);
		return *this;
	}
};
