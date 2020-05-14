#include "TestService.h"
#include <assert.h>

void testServiceOld() {}
	/*
	RepositoryFileTXT<Medicament>* RepoTXTFileMedicines;
	RepoFileCSV<Medicament>* RepoCSVFileMedicines;
	RepositoryFileTXT<Employee>* RepoTXTFileEmployees;
	RepoFileCSV<Employee>* RepoCSVFileEmployees;

	RepoTXTFileMedicines = new RepositoryFileTXT<Medicament>("TestMedicines.txt");
	RepoTXTFileEmployees = new RepositoryFileTXT<Employee>("TestEmployees.txt");
	RepoCSVFileMedicines = new RepoFileCSV<Medicament>("TestMedicines.csv");
	RepoCSVFileEmployees = new RepoFileCSV<Employee>("TestEmployees.csv");

	RepoTXTFileMedicines->clearRepo();
	RepoTXTFileEmployees->clearRepo();
	RepoCSVFileMedicines->clearRepo();
	RepoCSVFileEmployees->clearRepo();

	Service service(RepoTXTFileMedicines, RepoTXTFileEmployees, RepoCSVFileMedicines, RepoCSVFileEmployees);

	Medicament m1(1, "Medicine1", true, 10, "Producer1");
	Medicament m2(2, "Medicine2", false, 8, "Producer2");
	Employee e1(1, "Employee427", "employee427@gmail.com", 5);
	Employee e2(2, "Stanley", "stanley@gmail.com", 3);

	service.addMed(1, "Medicine1", true, 10, "Producer1");
	service.addMed(2, "Medicine2", false, 8, "Producer2");
	service.addEmp(1, "Employee427", "employee427@gmail.com", 5);
	service.addEmp(2, "Stanley", "stanley@gmail.com", 3);

	assert(service.getAllMeds().size() == 2);
	assert(service.getAllEmps().size() == 2);

	assert(service.getEmpAtPosition(0) == e1);
	assert(service.getEmpAtPosition(1) == e2);
	assert(service.getMedAtPosition(0) == m1);
	assert(service.getMedAtPosition(1) == m2);

	service.updateEmpByID(1, "Employee1", "employee1@gmail.com", 1);
	service.updateMedByID(1, "Medicine111", false, 10, "Producer111");
	Medicament newM(1, "Medicine111", false, 10, "Producer111");
	Employee newE(1, "Employee1", "employee1@gmail.com", 1);

	assert(service.getEmpAtPosition(0) == newE);
	assert(service.getMedAtPosition(0) == newM);

	service.deleteEmpByID(1);
	service.deleteMedByID(1);

	assert(service.getAllMeds().size() == 1);
	assert(service.getAllEmps().size() == 1);
}
	*/

void testServiceMedicine() {
	Repository<Medicament>* repoMedicines;

	repoMedicines = new RepositoryFileTXT<Medicament>();
	repoMedicines->clearRepo();

	MedicineService service(repoMedicines);

	Medicament m1(1, "Medicine1", true, 10, "Producer1");
	Medicament m2(2, "Medicine2", false, 8, "Producer2");

	service.add(m1);
	service.add(m2);

	assert(service.getAll().size() == 2);

	assert(service.getMedAtPosition(0) == m1);
	assert(service.getMedAtPosition(1) == m2);

	Medicament newM(1, "Medicine111", false, 10, "Producer111");
	service.update(m1, newM);

	assert(service.getMedAtPosition(0) == newM);

	service.remove(1);

	assert(service.getAll().size() == 1);
}

void testServiceEmployee() {
	Repository<Employee>* repoEmployees;

	repoEmployees = new RepositoryFileTXT<Employee>();
	repoEmployees->clearRepo();

	EmployeeService service(repoEmployees);

	Employee e1(1, "Employee427", "employee427@gmail.com", 5);
	Employee e2(2, "Stanley", "stanley@gmail.com", 3);

	service.addEmp(1, "Employee427", "employee427@gmail.com", 5);
	service.addEmp(2, "Stanley", "stanley@gmail.com", 3);

	assert(service.getAllEmps().size() == 2);

	assert(service.getEmpAtPosition(0) == e1);
	assert(service.getEmpAtPosition(1) == e2);

	service.updateEmpByID(1, "Employee1", "employee1@gmail.com", 1);

	Employee newE(1, "Employee1", "employee1@gmail.com", 1);

	assert(service.getEmpAtPosition(0) == newE);

	service.deleteEmpByID(1);

	assert(service.getAllEmps().size() == 1);
}
