#include <assert.h>
#include "TestRepoFile.h"
#include "Employee.h"
#include "Medicine.h"

void testRepo() {
	Repository<Medicament> repo;
	assert(repo.getSize() == 0);
	Repository<Medicament>* dynamicRepo;
	dynamicRepo = new Repository<Medicament>;
	assert(dynamicRepo->getSize() == 0);
	delete dynamicRepo;

	vector<Medicament> medicines = repo.getAll();
	assert((medicines.empty()) && (repo.getSize() == 0));
	dynamicRepo = new Repository<Medicament>;
	medicines = dynamicRepo->getAll();
	assert((medicines.empty()) && (dynamicRepo->getSize() == 0));
	delete dynamicRepo;

	Medicament m1(1, "Medicine1", true, 10, "Producer1");
	Medicament m2(2, "Medicine2", false, 8, "Producer2");

	repo.add(m1);
	repo.add(m2);
	medicines = repo.getAll();
	assert((medicines.size() == 2) && (medicines[0] == m1) && (medicines[1] == m2));

	repo.remove(m1);
	medicines = repo.getAll();
	assert((medicines.size() == 1) && (medicines[0] == m2));
	repo.remove(m2);
	assert(repo.getSize() == 0);

	repo.add(m1);
	repo.update(m1, m2);
	medicines = repo.getAll();
	assert(medicines[0] == m2);
}

void testRepoFileTXT() {
	RepositoryFileTXT<Medicament> RepoTXTFile("TestMedicines.txt");
	RepoTXTFile.clearRepo();
	assert((RepoTXTFile.getSize() == 0) && (strcmp(RepoTXTFile.getFileName(), "TestMedicines.txt") == 0));
	RepositoryFileTXT<Medicament>* dynamicRepoFile;
	dynamicRepoFile = new RepositoryFileTXT<Medicament>("TestMedicines.txt");
	dynamicRepoFile->clearRepo();
	assert((dynamicRepoFile->getSize() == 0) && (strcmp(dynamicRepoFile->getFileName(), "TestMedicines.txt") == 0));
	delete dynamicRepoFile;

	Medicament m1(1, "Medicine1", true, 10, "Producer1");
	Medicament m2(2, "Medicine2", false, 8, "Producer2");

	RepoTXTFile.add(m1);
	RepoTXTFile.add(m2);
	vector<Medicament> medicines = RepoTXTFile.getAll();
	assert((medicines.size() == 2) && (medicines[0] == m1) && (medicines[1] == m2));

	RepoTXTFile.remove(m1);
	medicines = RepoTXTFile.getAll();
	assert((medicines.size() == 1) && (medicines[0] == m2));
	RepoTXTFile.remove(m2);
	assert(RepoTXTFile.getSize() == 0);

	RepoTXTFile.add(m1);
	RepoTXTFile.update(m1, m2);
	medicines = RepoTXTFile.getAll();
	assert(medicines[0] == m2);

	RepositoryFileTXT<Medicament> RepoTXTFile1;
	RepositoryFileTXT<Medicament> RepoTXTFile2;

	RepoTXTFile1.add(m1);
	RepoTXTFile1.add(m2);

	assert(RepoTXTFile2.getSize() == 0);
	RepoTXTFile2 = RepoTXTFile1;
	assert(RepoTXTFile2.getSize() == 2);

	RepoTXTFile.loadFromFile();
	medicines = RepoTXTFile.getAll();
	assert(medicines[0] == m2);

	RepositoryFileTXT<Employee> RepoTXTFileEmployees("TestEmployees.txt");
	RepoTXTFileEmployees.clearRepo();
	Employee e1(1, "Employee427", "employee427@gmail.com", 5);
	Employee e2(2, "Stanley", "stanley@gmail.com", 3);
	RepoTXTFileEmployees.add(e1);
	RepoTXTFileEmployees.add(e2);
	vector<Employee> employees = RepoTXTFileEmployees.getAll();
	assert(RepoTXTFileEmployees.getSize() == employees.size());
	Employee e3 = e1;
	RepoTXTFileEmployees.remove(e1);
	assert(RepoTXTFileEmployees.getSize() == 1);
	RepoTXTFileEmployees.add(e3);
}

void testRepoFileCSV() {
	RepoFileCSV<Medicament> RepoCSVFile("TestMedicines.csv");
	RepoCSVFile.clearRepo();
	assert((RepoCSVFile.getSize() == 0) && (strcmp(RepoCSVFile.getFileName(), "TestMedicines.csv") == 0));
	RepoFileCSV<Medicament>* dynamicRepoFile;
	dynamicRepoFile = new RepoFileCSV<Medicament>("TestMedicines.csv");
	assert((dynamicRepoFile->getSize() == 0) && (strcmp(dynamicRepoFile->getFileName(), "TestMedicines.csv") == 0));
	delete dynamicRepoFile;

	Medicament m1(1, "Medicine1", true, 10, "Producer1");
	Medicament m2(2, "Medicine2", false, 8, "Producer2");

	RepoCSVFile.add(m1);
	RepoCSVFile.add(m2);
	vector<Medicament> medicines = RepoCSVFile.getAll();
	assert((medicines.size() == 2) && (medicines[0] == m1) && (medicines[1] == m2));

	RepoCSVFile.remove(m1);
	medicines = RepoCSVFile.getAll();
	assert((medicines.size() == 1) && (medicines[0] == m2));
	RepoCSVFile.remove(m2);
	assert(RepoCSVFile.getSize() == 0);

	RepoCSVFile.add(m1);
	RepoCSVFile.update(m1, m2);
	medicines = RepoCSVFile.getAll();
	assert(medicines[0] == m2);

	RepoFileCSV<Medicament> RepoCSVFile1;
	RepoFileCSV<Medicament> RepoCSVFile2;

	RepoCSVFile1.add(m1);
	RepoCSVFile1.add(m2);

	assert(RepoCSVFile2.getSize() == 0);
	RepoCSVFile2 = RepoCSVFile1;
	assert(RepoCSVFile2.getSize() == 2);

	Medicament m4(50, "Medicine4", true, 10, "Producer3");
	RepoCSVFile.add(m4);

	RepoCSVFile.loadFromFile();
	medicines = RepoCSVFile.getAll();
	assert(medicines[0] == m2);
	assert(medicines[1] == m4);

	RepoFileCSV<Employee> RepoCSVFileEmployees("TestEmployees.csv");
	RepoCSVFileEmployees.clearRepo();
	Employee e1(1, "Employee427", "employee427@gmail.com", 5);
	Employee e2(2, "Stanley", "stanley@gmail.com", 3);
	RepoCSVFileEmployees.add(e1);
	RepoCSVFileEmployees.add(e2);
	vector<Employee> employees = RepoCSVFileEmployees.getAll();
	assert(RepoCSVFileEmployees.getSize() == employees.size());
	Employee e3 = e1;
	RepoCSVFileEmployees.remove(e1);
	assert(RepoCSVFileEmployees.getSize() == 1);
	RepoCSVFileEmployees.add(e3);
}
