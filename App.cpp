/*
Farmacie

Detinatorii unui lant de farmacii au nevoie de o aplicatie pentru gestionarea acestora. La fiecare locatie se foloseste un sistem soft pentru a vinde medicamente si pentru a gestiona stocul.
Precizare: la un moment dat, o singura persoana foloseste aplicatia (deci nu trebuie acces
concurent)

1. Login: Accesul la stoc se poate face doar in urma unei actiuni de logare. Dupa
autentificarea cu succes, sunt afisate toate medicamentele: id, nume, necesita reteta, numar stoc, producator) si toate datele despre angajati: id, nume, email, grad de acces (int)

2. Operare: După autentificarea cu succes, un utilizator poate:
- căutare medicament: utilizatorul introduce un string si programul afiseaza toate medicamentele al caror nume contine acel string.
- CRUD medicamente
- modificare grad acces: utilizatorul introduce un id de angajat si un nou grad de acces. Gradul de acces al utilizatorului cu id-ul dat se modifica doar daca gradul de acces al utilizatorului logat este strict mai mare decat al utilizatorului pe care incearca sa il modifice.
- view all utilizatori.

3. Logout: utilizatorul curent iese din aplicatie, dar alt utilizatorul se poate apoi loga.
*/

#include "TestEntities.h"
#include "TestRepoFile.h"
#include "TestService.h"
#include "TestLoginRegister.h"
#include "TestsForLab.h"
#include "ServiceMedicine.h"
#include "ServiceEmployee.h"
#include "UI.h"

int main()
{
	testMedicine();
	testEmployee();
	testRepo();
	testRepoFileTXT();
	testRepoFileCSV();
	testServiceMedicine();
	testServiceEmployee();
	testRegister();
	testLogin();
	testLab10();
	testLab11();

	Repository<Medicament>* repoMedicines;
	Repository<Employee>* repoEmployees;

	//RepositoryFileTXT<Medicament>* repoMedicinesTXT;
	//RepoFileCSV<Medicament>* repoMedicinesCSV;
	//RepositoryFileTXT<Employee>* repoEmployeeTXT;
	//RepoFileCSV<Employee>* repoEmployeeCSV;

	//repoMedicinesTXT = new RepositoryFileTXT<Medicament>("Medicamente.txt");
	//repoMedicinesCSV = new RepoFileCSV<Medicament>("Medicamente.csv");
	//repoEmployeeTXT = new RepositoryFileTXT<Employee>("Employees.txt");
	//repoEmployeeCSV = new RepoFileCSV<Employee>("Employees.csv");
	repoMedicines = new Repository<Medicament>();
	repoEmployees = new Repository<Employee>();

	//MedicineService serviceMed(repoMedicinesTXT);// , repoEmployeeTXT, repoMedicinesCSV, repoEmployeeCSV);
	//EmployeeService serviceEmp(repoEmployeeTXT);

	MedicineService serviceMed(repoMedicines);
	EmployeeService serviceEmp(repoEmployees);
	UI userInterface(serviceMed, serviceEmp);

	userInterface.runUI();

	//delete repo;
	return 0;
}
