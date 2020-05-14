#include "TestEntities.h"

void testMedicine() {
	Medicament m1;
	assert(m1.getID() == 0);
	assert(m1.getStockNr() == 0);

	string name = "Medicine1";
	bool prescription = true;
	string producer = "Producer1";
	Medicament m2(1, name, prescription, 10, producer);
	assert(m2.getID() == 1);
	assert(m2.getName() == "Medicine1");
	assert(m2.getPrescription() == true);
	assert(m2.getStockNr() == 10);
	assert(m2.getProducer() == "Producer1");

	Medicament m3(m2);
	assert(m3.getID() == 1);
	assert(m3.getName() == "Medicine1");
	assert(m3.getPrescription() == true);
	assert(m3.getStockNr() == 10);
	assert(m3.getProducer() == "Producer1");

	string name2 = "Medicine2";
	bool prescription2 = false;
	string producer2 = "Producer2";
	m3.setID(2);
	assert(m3.getID() == 2);
	m3.setName(name2);
	assert(m3.getName() == name2);
	m3.setPrescription(prescription2);
	assert(m3.getPrescription() == prescription2);
	m3.setStockNr(30);
	assert(m3.getStockNr() == 30);
	m3.setProducer(producer2);
	assert(m3.getProducer() == producer2);

	Medicament m4;
	m4 = m2;
	assert(m4.getID() == 1);
	assert(m4.getName() == name);
	assert(m4.getPrescription() == prescription);
	assert(m4.getStockNr() == 10);
	assert(m4.getProducer() == producer);
}

void testEmployee() {
	Employee e1;
	assert(e1.getID() == 0);
	assert(e1.getEntryRank() == 0);

	string name = "Employee427";
	string email = "stanley@gmail.com";
	Employee e2(1, name, email, 5);
	assert(e2.getID() == 1);
	assert(e2.getName() == "Employee427");
	assert(e2.getEmail() == "stanley@gmail.com");
	assert(e2.getEntryRank() == 5);

	Employee e3(e2);
	assert(e3.getID() == 1);
	assert(e3.getName() == "Employee427");
	assert(e3.getEmail() == "stanley@gmail.com");
	assert(e3.getEntryRank() == 5);

	string name2 = "Employee1";
	string email2 = "employee1@gmail.com";
	e3.setID(2);
	assert(e3.getID() == 2);
	e3.setName(name2);
	assert(e3.getName() == name2);
	e3.setEmail(email2);
	assert(e3.getEmail() == email2);
	e3.setEntryRank(3);
	assert(e3.getEntryRank() == 3);

	Employee e4;
	e4 = e2;
	assert(e4.getID() == 1);
	assert(e4.getName() == name);
	assert(e4.getEmail() == email);
	assert(e4.getEntryRank() == 5);
}
