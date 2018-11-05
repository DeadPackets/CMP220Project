#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
//Prints the menu. No input/output
void printMenu();

//Employee Class
class Employee {
private:
	string ID, name;

public:
//Default constructor
	Employee() { ID = "0", name = "none"; }
//Non-default constructor
//Initializes an employee to the passed name and ID
	Employee(string myname, string myid) { ID = myid, name = myname; }
//A getter function for the Employee ID
//Takes no input. Returns the calling object's (Employee) ID
	string get_ID() { return ID; }
//A getter function for the Employee name
//Takes no input. Returns the calling object's (Employee) name
	string get_name() { return name; }
//A setter function for the Employee ID
//Takes an input string and sets it equal to the employee ID
	void set_ID(string myid) { ID = myid; }
//A setter function for the Employee name
//Takes an input string and sets it equal to the employee name
	void set_name(string myname) { name = myname; }
};

//Project Class
class Project {
private:
	string ID, title;
public:
//Default Constructor
	Project() { ID = "0", title = "none"; }
//Non-default constructor
//Initializes a project to the passed title and ID
	Project(string mytitle, string myid) { ID = myid, title = mytitle; }
//A getter function for the Project ID
//Takes no input. Returns the calling object's (Project) ID
	string get_ID() { return ID; }
//A getter function for the Project title
//Takes no input. Returns the calling object's (Project) title
	string get_name() { return title; }

};

//Employee List Class
class EmployeeList
{
private:
	vector <Employee> listofEmployees;
	string empFileName;
public:
	//Default constructor that reads from a file
	//and fills the vector of employees
	EmployeeList();
	//Adds an employee to the list of employees
	//Takes input of type Employee and returns nothing
	void addEmployee(Employee e);
	//Takes an employee's ID and deletes it from the list of employees.
	//Returns true if employee is deleted and false if employee not found 
	bool deleteEmployee(string ID);
	//Finds an employee with the passed ID
	//returns an Employee
	//NOTE: should use the findEmployeeIndexInVector first.
	Employee getEmployee(string ID);
	//Searches for employee by ID in list of employees
	//takes a string (ID) and returns an int(index of employee in list)
	int findEmployeeIndexInVector(string ID);
	//Prints out the list of employees
	//no input/output
	void listEmployees();
	//Detsructor: saves Employee list to the original input file
	~EmployeeList();

};

//Project List Class
class ProjectList
{
private:
	vector <Project> listofProjects;
	string prjFileName;

public:
//Default constructor that reads from a file
//and fills the vector of projects.
	ProjectList();
//takes input Project and adds it to  listofPRojects vector
	void addProject(Project p);
//Takes a project's ID and deletes it from the list of projects.
//Returns true if the project is deleted and false if project not found.
	bool deleteProject(string x);
//Takes project ID. Return is of type project
////NOTE: should use the findProjectIndexInVector first.
	Project getProject(string ID);
//Checks if the project exists.
//takes a string (could be ID or title). Returns true if project
//exists and false if not.
	bool doesProjectExist(string z);
//I still HAVE NO IDEA WHEN TO USE THOSE 
//Takes project ID and returns project Title
//USE doesProjectExist function before using it.
	string getProjectTitle(string ID);
//Takes project Title and returns project ID
//USE doesProjectExist function before using it.
	string getProjectID(string Title);
//Searches for employee by ID in list of employees
//takes a string (ID) and returns an int(index of employee in list)
	int findProjectIndexInVector(string ID);
//Prints all the projects in the list of projects
//No input/output
	void listProjects();
//Destructor:saves Project list to the original input file
	~ProjectList();

};

//ProjectEmployeeAssignment
class ProjectEmployeeAssignment
{
private:
	string pID, eID;//eID:employee ID, pID: project ID
	bool completed;
public:
	//Default Constructor
	ProjectEmployeeAssignment() { pID = -1, eID = -1, completed = false; };
	//Non-default constructor: initializes the object to the passed project ID
	//employee ID and sets the project status to false
	ProjectEmployeeAssignment(string mypID, string myeID, bool complete = false);
	//A getter function for the project ID
	//Takes no input. Returns the calling object's project ID
	string get_pID() { return pID; }
	//A getter function for the employee ID
	//Takes no input. Returns the calling object's employee ID
	string get_eID() { return eID; }
	//Checks if project is completed
	//takes no input and return true or false
	bool isCompleted();
	//A setter function for completed. Takes a boolean. No output
	void setCompleted(bool flag) { completed = flag; }

};

//List of Project Assignment
class listofProjectEmpAssignment
{
private:
	vector <ProjectEmployeeAssignment> list;
	string prj_empFileName;
public:
//Default Constructor: Reads from file
//and fills in vector of Project Employee Assignment
	listofProjectEmpAssignment();
//Takes two parameters of type Project and Employee
//and adds them to the vector
	void addEmpPrjAssignment(string pID, string eID);
//Takes two strings (project ID and employee ID)
//Returns true if if project is completed and false if not.
//NOTE: use isEmpPrjInList function before using this.
	bool markProjectAsCompleted(string p, string e);
//checks if an employee is in the vector
//takes employee ID and returns true/false
	bool isEmpInList(string ID);
//checks if a project is in the vector
//takes project ID and returns true/false
	bool isPrjInList(string ID);
//checks if an EmpPrjAssignment is in the vector
//returns true if yes and false if not
	bool isEmpPrjInList(string eID, string pID);
//Lists all incomplete projects
//Takes no inout and returns nothing.
	void listAllIncompleteProjects();
//Lists are completed projects
//Takes no inout and returns nothing.
	void listAllCompleteProjects();
//Lists all employees assigned to a certain project
//takes no input and gives no output
	void listAllProjectsAssignments();
//Class Destructor
//Saves the vector to the original input file
	~listofProjectEmpAssignment();
};

void main()
{
	system("pause");
}
void printMenu()
{
	cout << "\t\t\t\tMenu" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "1) Add a new employee to the “list of employees\"." << endl;
	cout << "2) Add a new project to the “list of projects”." << endl;
	cout << "3) List all employees and the projects they are assigned to (if any)." << endl;
	cout << "4) List all projects (project name & ID)." << endl;
	cout << "5) List all completed projects (Employee’s name & ID, project’s name & ID)." << endl;
	cout << "6) List all incomplete projects (Employee’s name & ID, project’s name & ID)." << endl;
	cout << "7) Search for a given employee or project by ID or name." << endl;
	cout << "8) Assign an employee to a project (if not assigned already)." << endl;
	cout << "9) Set a project as complete or incomplete for a given employee." << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "Enter choice:";
}
//---------------------------------------------------------------------------
//Class Functions
//--------------------------------------------------------------------------
//Employee List Class
EmployeeList::EmployeeList()
{
	ifstream in(empFileName);
	if (in.fail())
	{
		cout << "Employee input file failed to open." << endl;
		exit(1);
	}
	//create a temporary employee to push it
	//into the list of employees
	Employee temp;
	string myname, myid;

	while (!in.eof())
	{
	in >> myid;
	getline(in, myname);
	temp.set_ID(myid);
	temp.set_name(myname);
	listofEmployees.push_back(temp);
	}
	in.close();
}
void EmployeeList::addEmployee(Employee e)
{
	//first check if the employee already exists
	//or if another employee has the same name/ID
	for (int i = 0; i < listofEmployees.size(); i++)
	{
		if (listofEmployees[i].get_ID() == e.get_ID() &&
			listofEmployees[i].get_name() == e.get_name())
			cout << "Employee already exists." << endl;
		else if (listofEmployees[i].get_ID() != e.get_ID() &&
			listofEmployees[i].get_name() == e.get_name())
			cout << "Employee with the same name already exists." << endl;
		else if (listofEmployees[i].get_ID() == e.get_ID() &&
			listofEmployees[i].get_name() != e.get_name())
			cout << "Employee with the same ID already exits." << endl;
		else
		{
			listofEmployees.push_back(e);
			cout << "New employee added to the list of employees." << endl;
		}
	}
	listofEmployees.push_back(e);
}
bool EmployeeList::deleteEmployee(string ID)
{
	for (int i = 0; i < listofEmployees.size(); i++)
	{
		if (listofEmployees[i].get_ID() == ID)
		{
			listofEmployees.erase(listofEmployees.begin() + i);
			return true;
		}
	}
	return false;

}
//MUST use findEmployeeIndexInVector function first
Employee EmployeeList::getEmployee(string ID)
{
	for (int i = 0; i < listofEmployees.size(); i++)
	{
		if (listofEmployees[i].get_ID() == ID)
			return listofEmployees[i];
	}
}
int EmployeeList::findEmployeeIndexInVector(string ID)
{
	for (int i = 0; i < listofEmployees.size(); i++)
	{
		if (listofEmployees[i].get_ID() == ID)
			return i;
	}
	//returns -1 if the employee doesn't exist 
	return -1;
}
void EmployeeList::listEmployees()
{
	for (int i = 0; i < listofEmployees.size(); i++)
		cout << "ID:" << listofEmployees[i].get_ID() << "\t Name:" 
		<< listofEmployees[i].get_name() << endl;
}
EmployeeList::~EmployeeList()
{
	ofstream out(empFileName);
	if (out.fail())
	{
		cout << "Employee output file failed to open." << endl;
		exit(1);
	}
	for (int i = 0; i < listofEmployees.size(); i++)
		out<<  listofEmployees[i].get_ID() << "\t"
		<< listofEmployees[i].get_name()<<endl;
	out.flush();
	out.close();
}
//Project List Class
//-------------------------------------------------------------------
ProjectList::ProjectList()
{
	ifstream in(prjFileName);
	if (in.fail())
	{
		cout << "The project input file failed to open." << endl;
		exit(1);
	}
	string myid,mytitle;
	while (!in.eof())
	{
		in >> myid;
		getline(in, mytitle);
		Project x(mytitle, myid);
		listofProjects.push_back(x);
	}
	in.close();
}
void ProjectList::addProject(Project p)
{
	//first check if the project already exists
	//or if another project has the same title/ID
	for (int i = 0; i < listofProjects.size(); i++)
	{
		if (listofProjects[i].get_ID() == p.get_ID() &&
			listofProjects[i].get_name() == p.get_name())
			cout << "Project already exists." << endl;
		else if (listofProjects[i].get_ID() != p.get_ID() &&
			listofProjects[i].get_name() == p.get_name())
			cout << "Project with the same title already exists." << endl;
		else if (listofProjects[i].get_ID() == p.get_ID() &&
			listofProjects[i].get_name() != p.get_name())
			cout << "Project with the same ID already exits." << endl;
		else
		{ 
			listofProjects.push_back(p);
			cout << "New project added to list of projects." << endl;
		}
	}
}
//deletes project by ID
bool ProjectList::deleteProject(string x)
{
	//Assuming string x is the project ID
	for (int i = 0; i < listofProjects.size(); i++)
	{
		if (listofProjects[i].get_ID() == x)
		{
			listofProjects.erase(listofProjects.begin() + i);
			return true;
		}
		return false;
	}
}
int ProjectList::findProjectIndexInVector(string ID)
{
	for (int i = 0; i < listofProjects.size(); i++)
	{
		if (listofProjects[i].get_ID() == ID)
			return i;
	}
	//returns -1 if the employee doesn't exist 
	return -1;
}
//MUST use findProjectIndexInVector function first
Project ProjectList::getProject(string ID)
{
	for (int i = 0; i < listofProjects.size(); i++)
	{
		if (listofProjects[i].get_ID() == ID)
			return listofProjects[i];
	}
}
bool ProjectList::doesProjectExist(string z)
{
	for (int i = 0; i < listofProjects.size(); i++)
	{
		if(listofProjects[i].get_ID()==z || listofProjects[i].get_name()==z)
			return true;
	}
	return false;
}
string ProjectList::getProjectTitle(string ID)
{
	for (int i = 0; i < listofProjects.size(); i++)
	{
		if (listofProjects[i].get_ID() == ID)
			return listofProjects[i].get_name();
	}
}
string ProjectList::getProjectID(string Title)
{
	for (int i = 0; i < listofProjects.size(); i++)
	{
		if (listofProjects[i].get_ID() == Title)
			return listofProjects[i].get_ID();
	}
}
void ProjectList::listProjects()
{
	for (int i = 0; i < listofProjects.size(); i++)
		cout << "ID:" << listofProjects[i].get_ID() << "\t Title:"
		<< listofProjects[i].get_name() << endl;
}
ProjectList::~ProjectList()
{
	ofstream out(prjFileName);
	if (out.fail())
	{
		cout << "Project output file failed to open." << endl;
		exit(1);
	}
	for (int i = 0; i < listofProjects.size(); i++)
		out << listofProjects[i].get_ID() << "\t"
		<< listofProjects[i].get_name()<<endl;
	out.flush();
	out.close();
}
//Project Employee Assignment Class
//-------------------------------------------------------------------
ProjectEmployeeAssignment::ProjectEmployeeAssignment(string mypID, string myeID, bool complete = false)
{
	pID = mypID;
	eID = myeID;
	completed = complete;
}
bool ProjectEmployeeAssignment::isCompleted()
{
	return completed;
}
//List of Project Employee Assignment Class
//-------------------------------------------------------------------
listofProjectEmpAssignment::listofProjectEmpAssignment()
{
	ifstream in(prj_empFileName);
	if (in.fail())
	{
		cout << "Project Employee Assignment input file failed to open." << endl;
		exit(1);
	}
	string mypID, myeID;
	bool mycompleted;
	while (!in.eof())
	{
		in >> myeID >> mypID >> mycompleted;
		ProjectEmployeeAssignment x(mypID, myeID, mycompleted);
		list.push_back(x);
	}
	in.close();
}
//Do we set project status to incomplete?
void listofProjectEmpAssignment::addEmpPrjAssignment(string pID, string eID)
{
	ProjectEmployeeAssignment x (pID,eID);
	list.push_back(x);
}
bool listofProjectEmpAssignment::markProjectAsCompleted(string p, string e)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].get_eID() == e && list[i].get_pID() == p)
			return list[i].isCompleted();
	}
}
bool listofProjectEmpAssignment::isEmpInList(string ID)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].get_eID() == ID)
			return true;
	}
	return false;
}
bool listofProjectEmpAssignment::isPrjInList(string ID)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].get_pID() == ID)
			return true;
	}
	return false;
}
bool listofProjectEmpAssignment::isEmpPrjInList(string eID, string pID)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].get_pID() == pID && list[i].get_eID()==eID)
			return true;
	}
	return false;
}
void listofProjectEmpAssignment::listAllIncompleteProjects()
{
	for (int i = 0; i < list.size(); i++)
	{
		if (!list[i].isCompleted())
			cout << "Employee ID:" << list[i].get_eID() << "\tProject ID:" << list[i].get_pID() << endl;
	}
}
void listofProjectEmpAssignment::listAllCompleteProjects()
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].isCompleted())
			cout << "Employee ID:" << list[i].get_eID() << "\tProject ID:" << list[i].get_pID() << endl;
	}
}
void listofProjectEmpAssignment::listAllProjectsAssignments()
{
	int projectID;
	for (int i = 0; i < list.size(); i++)
	{
		cout << "Project " << list[i].get_pID() << "has the following employee(s) working on it:" << endl;
		for (int j = 0; j < list.size(); j++)
			if (list[j].get_pID == list[i].get_pID)
				cout << "Employee ID: " << list[j].get_eID() << endl;
	}
}
listofProjectEmpAssignment::~listofProjectEmpAssignment()
{
	ofstream out(prj_empFileName);
	if (out.fail())
	{
		cout << "Project-Employee output file failed to open." << endl;
		exit(1);
	}
	for (int i = 0; i < list.size(); i++)
		out << list[i].get_eID() << " "
		<< list[i].get_pID() << " " << list[i].isCompleted() << endl; ;
	out.flush();
	out.close();
}
int main(){
    int choice;
    EmployeeList el;
    ProjectList pl;
    ProjectEmployeeAssignment epa;
    listofProjectEmpAssignment lpa;
    while (true){
        printMenu();
        cin >> choice;
        if (choice ==1){
            string name, id;
            cout << "Please enter your ID and Name:\n";
            cin >> name>> id;
            Employee e(name, id);
            el.addEmployee(e);
        }
        else if(choice ==2){
            string name, id;
            cout << "Please enter the ID and Name of the project:\n";
            cin >> name>> id;
            Project p(name, id);
            pl.addProject(p);
        }
        else if(choice ==3){
            lpa.listAllProjectsAssignments();
        }
        else if(choice==4){
            pl.listProjects();
        }
        else if(choice==5){
            lpa.listAllCompleteProjects();
        }
        else if(choice==6){
            lpa.listAllIncompleteProjects();
        }
        else if(choice==7){
            string id, name;
            cout << "Enter ID or the Name of the Employee you are searching for:\n";
            cin >> id >> name;
            
            
        }
        else if(choice==8){
            
        }
        else if(choice==9){
            
        }


    }
    
    return 0;
}
