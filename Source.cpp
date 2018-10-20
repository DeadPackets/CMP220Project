#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Employee {
private:
	string ID, name;
	//…add more attributes as needed
public:
	Employee();
	Employee(string myname, string myid);
	string getID();
	string getName();
	//…add other functions as needed
};


class Project {
private:
	string ID, title;
	//…add more attributes as needed
public:
	Project();
	Project(string mytitle, string myid);
	string getID();
	string getTitle();
	//…add other functions as needed
};


class ProjectEmployeeAssignment {
private:
	string pID, eID;
	bool completed;
	//…add more attributes as needed
public:
	ProjectEmployeeAssignment();
	ProjectEmployeeAssignment
	(string mypID, string myeID, bool complete = false);
	string getpID();
	string geteID();
	bool isCompleted();
	void setCompleted(bool flag) { completed = flag; };
	//…add other functions as needed
};

class EmployeeList {
private:
	vector<Employee> listofEmployees;
	string empFileName;
	//…add more attributes as needed 
public:
	EmployeeList(); //reads from the file
	void addEmployee(Employee e);
	bool deleteEmployee(string ID);
	Employee getEmployee(string ID);
	int findEmployeeIndexInVector(string ID);
	void listEmployees();
	~EmployeeList(); //writes back to the same input file
		//…add other functions as needed
};

class ProjectList {
private:
	vector<Project> listofProjects;
	string prjFileName;
	//…add more attributes as needed
public:
	ProjectList(); //reads from the file
	void addProject(Project p);
	bool deleteProject(string x);
	Project getProject(string x);
	string getProjectTitle(string ID);
	string getProjectID(string title);
	int findProjectIndexInVector(string ID);
	void listProjects();
	~ProjectList(); //writes back to the same input file
		//…add other functions as needed
};

class listofPrjEmpAssignment {
private:
	vector <ProjectEmployeeAssignment> list;
	string prj_empFileName;
	//…add more attributes as needed
public:
	listofPrjEmpAssignment();//reads from the file
	void addEmpPrjAssignment(Project b, Employee e);
	bool markProjectAsCompleted(Project b, Employee e);
	bool isEmpInList(string ID);
	bool isPrjInList(string ID);
	bool isEmpPrjInList(string eID, string pID);
	void listAllIncompleteProjects();
	void listAllCompleteProjects();
	void listAllProjectsAssignments();
	~listofPrjEmpAssignment();//writes back to the file
		//…add other functions as needed
};

