#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include <typeinfo>
#include <stdlib.h> 
using namespace std;

enum Department{Physics, Math, Engineering, Chemistry, English, General, Unknown};

class Person{
	private:
		int ID = 0;
		string firstName;
		string lastName = "";
		Person* next;

	public:
		Person();
		Person(int identity, string fName, string lName);
		Person(Person &init);
		virtual ~Person();
		Person& operator=(Person const &per)
		{
			this->ID = per.ID;
			setFirstName(per.firstName);
			setLastName(per.lastName);
			this->next = per.next;
			return *this;
		}
		
		// getters
		int getID()
		{
			return ID;
		}
		string getFirstName()
		{
			return firstName;
		}
		string getLastName()
		{
			return lastName;
		}
		Person* getNext()
		{
			return next;
		}
		void setID(int identity)
		{
			ID = identity;
		}
		void setFirstName(string fName)
		{
			this->firstName = fName;
		}
		void setLastName(string lName)
		{
			this->lastName = lName;
		}
		void setNext(Person* adj)
		{
			next = adj;
		}
};

Person* headNode = NULL;

Person :: Person()
{
	this->ID = 0000;
	this->firstName = "(null)";
	this->lastName = "(null)";
	this->next = NULL;
}

Person :: Person(int identity, string fName, string lName)
{
	this->ID = identity;
	this->firstName = fName;
	this->lastName = lName;
	this->next = NULL;
}

Person :: Person(Person &init)
{
	this->ID = init.ID;
	this->firstName = "";
	this->lastName = "";
	setFirstName(init.firstName);
	setLastName(init.lastName);
	this->next = init.next;
}

Person :: ~Person()
{

}

class Student: public Person
{
private:
	float GPA;
	
public:
	Student();
	Student(int identity, string fname, string lname, float grade);
	Student(Student &init);
	~Student();
	float getGPA()
	{
		return GPA;
	}
	
	void setGPA(float gpa_in)
	{
		GPA = gpa_in;
	}
};

Student :: Student()
{
	this->setID(0000);
	this->setFirstName("(null)");
	this->setLastName("(null)");
	this->GPA = 0.0;
	this->setNext(NULL);
}

Student :: Student(int identity, string fname, string lname, float grade)
{
	setID(identity);
	setFirstName(fname);
	setLastName(lname);
	this->GPA = grade;
	this->setNext(NULL);
}

Student :: Student(Student &init)
{
	this->setID(init.getID());
	this->setGPA(init.GPA);
	this->setFirstName(init.getFirstName());
	this->setLastName(init.getLastName());
	this->setNext(init.getNext());
}

Student :: ~Student()
{

}

class Employee: public Person
{
private:
	float salary;
	
public:
	Employee();
	Employee(int identity, string fname, string lname, float money);
	Employee(Employee &init);
	~Employee();
	float getSalary()
	{
		return salary;
	}
	
	void setSalary(float money)
	{
		salary = money;
	}
};

Employee :: Employee()
{
	this->setID(0000);
	this->setFirstName("(null)");
	this->setLastName("(null)");
	this->salary = 0.0;
	this->setNext(NULL);
}

Employee :: Employee(int identity, string fname, string lname, float money)
{
	setID(identity);
	setFirstName(fname);
	setLastName(lname);
	this->salary = money;
	this->setNext(NULL);
}

Employee :: Employee(Employee &init)
{
	this->setID(init.getID());
	this->setSalary(init.salary);
	this->setFirstName(init.getFirstName());
	this->setLastName(init.getLastName());
	this->setNext(init.getNext());
}

Employee :: ~Employee()
{

}

class Professor: public Employee
{
private:
	bool tenured;
	Department department;
	
public:
	Professor();
	Professor(int identity, string fname, string lname, float money, bool ten, Department major);
	Professor(Professor &init);
	~Professor();
	bool getTenured()
	{
		return tenured;
	}
	Department getDepartment()
	{
		return department;
	}
	
	void setTenured(bool ten)
	{
		tenured = ten;
	}
	void setDepartment(Department major)
	{
		department = major;
	}
};

Professor :: Professor()
{
	this->setID(0000);
	this->setFirstName("(null)");
	this->setLastName("(null)");
	this->setSalary(0.0);
	this->tenured = false;
	this->department = Unknown;
	this->setNext(NULL);
}

Professor :: Professor(int identity, string fname, string lname, float money, bool ten, Department major)
{
	setID(identity);
	setFirstName(fname);
	setLastName(lname);
	setSalary(money);
	this->tenured = ten;
	this->department = major;
	this->setNext(NULL);
}

Professor :: Professor(Professor &init)
{
	this->setID(init.getID());
	this->setSalary(init.getSalary());
	this->setFirstName(init.getFirstName());
	this->setLastName(init.getLastName());
	this->setTenured(init.tenured);
	this->setDepartment(init.department);
	this->setNext(init.getNext());
}

Professor :: ~Professor()
{

}

template <class DstType, class SrcType>
bool instanceof(const SrcType* src)
{
  return dynamic_cast<const DstType*>(src) != nullptr;
}

void addNode(Person* newNode){
	Person* currentNode = headNode; 
	if (headNode == NULL){
		headNode = newNode;
		return;
	}
	while(currentNode-> getNext() != NULL){
		currentNode = currentNode->getNext();
	}
	currentNode->setNext(newNode);
	newNode->setNext(NULL);
}

void insertNode(Person* newNode){
	Person* list = headNode;
	while(list->getNext() != NULL){
		Person* nextNode = list->getNext();
		if((list -> getID() > newNode -> getID()) && (newNode -> getID() >= nextNode -> getID())){
			newNode->setNext(list->getNext());
			list->setNext(newNode);
			return;
		}
		else if(list -> getID() <= newNode -> getID()){
			newNode->setNext(list);
			headNode = newNode;
			return;
		}
		list = list->getNext();
	}
	list->setNext(newNode);
	newNode->setNext(NULL);
	return;
}

void deleteNode(Person* newNode){
	Person* currentNode = headNode;
	Person* prevNode = NULL;
	
	if(headNode == newNode){
		headNode = headNode->getNext();
		delete newNode;
		return;
	}
	
	while(currentNode != NULL && currentNode != newNode){
		prevNode = currentNode;
		currentNode = currentNode->getNext();
	}
	
	if(currentNode != NULL){
		prevNode->setNext(currentNode->getNext());
	}
	
	delete newNode;
}

void menu(){
	printf("\n1) List everyone\n");
	printf("2) Add \n");
	printf("3) Remove \n");
	printf("4) Update \n");
	printf("5) Quit\n");
}

void studentMenu(string fi, string la){
	cout << "What would you like to update?" << fi << " " << la << endl;
	printf("1) ID \n");
	printf("2) First Name \n");
	printf("3) Last Name \n");
	printf("4) GPA \n");
	printf("5) Quit \n");
}

void professorMenu(string fi, string la){
	cout << "What would you like to update?" << fi << " " << la << endl;
	printf("1) ID \n");
	printf("2) First Name \n");
	printf("3) Last Name \n");
	printf("4) Salary \n");
	printf("5) Tenured \n");
	printf("6) Department \n");
	printf("7) Quit \n");
}

void employeeMenu(string fi, string la){
	cout << "What would you like to update?" << fi << " " << la << endl;
	printf("1) ID \n");
	printf("2) First Name \n");
	printf("3) Last Name \n");
	printf("4) Salary \n");
	printf("5) Quit \n");
}

void addMenu(){
	cout << "What would you like to add?" << endl;
	printf("1) Student \n");
	printf("2) Professor \n");
	printf("3) Employee \n");
	printf("4) Quit \n");
}

void readFile(){
	ifstream FILE;
	int giveMeYourID = 0;
	string fiName = "";
	string laName = "";
	float leGrades = 0;
	float leMoney = 0;
	bool leTenured = false;
	Department leMajor = Unknown;
	int studentNum = 0;

	FILE.open("school.txt"); //reads the text file
	
	if(!FILE.is_open()){
		cout << "File does not exist\n"; //checking if the file exists
	}
	else{
		string fill = "";
		FILE >> fill;
		FILE >> fill;
		FILE >> fill;
		FILE >> studentNum;
		cout << "Number of People: " << studentNum;
		for(int i = 0; i < studentNum; i++){
			FILE >> fill;
			if(fill == "Student"){
				FILE >> fill;
				FILE >> giveMeYourID;
				FILE >> fill;
				FILE >> fill;
				FILE >> fiName;
				FILE >> fill;
				FILE >> fill;
				FILE >> laName;
				FILE >> fill;
				FILE >> leGrades;
				
				Student* std = new Student(giveMeYourID, fiName, laName, leGrades);
				addNode(std);
			}
			else if (fill == "Professor"){
				FILE >> fill;
				FILE >> giveMeYourID;
				FILE >> fill;
				FILE >> fill;
				FILE >> fiName;
				FILE >> fill;
				FILE >> fill;
				FILE >> laName;
				FILE >> fill;
				FILE >> leMoney;
				FILE >> fill;
				FILE >> leTenured;
				FILE >> fill;
				FILE >> fill;
				if(fill == "Physics"){
					leMajor = Physics;
				}
				else if (fill == "Math"){
					leMajor = Math;
				}
				else if (fill == "Engineering"){
					leMajor = Engineering;
				}
				else if (fill == "Chemistry"){
					leMajor = Chemistry;
				}
				else if (fill == "English"){
					leMajor = English;
				}
				else if (fill == "General"){
					leMajor = General;
				}
				else{
					leMajor = Unknown;
				}
				
				Professor* prof = new Professor(giveMeYourID,  fiName,laName,  leMoney, leTenured, leMajor);
				addNode(prof);
			}
			else if(fill == "Employee"){
				FILE >> fill;
				FILE >> giveMeYourID;
				FILE >> fill;
				FILE >> fill;
				FILE >> fiName;
				FILE >> fill;
				FILE >> fill;
				FILE >> laName;
				FILE >> fill;
				FILE >> leMoney;
				
				Employee* employ = new Employee(giveMeYourID, fiName, laName, leMoney);
				addNode(employ);
			}
			else{
				cout << "This type of person is not supported.\n"; 
			}
		}
		}
	FILE.close();
}

void saving(){
	ofstream FILE;
	Person* list = headNode;
	int studentNum = 0;

	FILE.open("school.txt"); //reads the text file
	
	while(list != NULL){
		studentNum++;
		list = list->getNext();
	}
	if (!FILE.is_open()){
		cout << "File does not exist\n";
	}
	else{
		FILE << "Number of Student: "<< studentNum;
		while(list != NULL){
			if(instanceof<Student>(list)){
				Student* listStudent = (Student*) list;
				FILE << "\nStudent";
				FILE << "\nID: " << listStudent->getID();
				FILE << "\nFirst Name: " << listStudent->getFirstName();
				FILE << "\nLast Name: " << listStudent->getLastName();
				FILE << "\nGPA: " << listStudent->getGPA();
			}
			else if(instanceof<Professor>(list)){
				Professor* listProfessor = (Professor*) list;
				FILE << "\nProfessor";
				FILE << "\nID: " << listProfessor->getID();
				FILE << "\nFirst Name: " << listProfessor->getFirstName();
				FILE << "\nLast Name: " << listProfessor->getLastName();
				FILE << "\nSalary: " << listProfessor->getSalary();
				FILE << "\nTenured: " << listProfessor->getTenured();
				if(listProfessor->getDepartment() == English){
					FILE << "\nDepartment: English";
				}
				else if(listProfessor->getDepartment() == Math){
					FILE << "\nDepartment: Math";
				}
				else if(listProfessor->getDepartment() == General){
					FILE << "\nDepartment: General";
				}
				else if(listProfessor->getDepartment() == Physics){
					FILE << "\nDepartment: Physics";
				}
				else if(listProfessor->getDepartment() == Chemistry){
					FILE << "\nDepartment: Chemistry";
				}
				else if(listProfessor->getDepartment() == Engineering){
					FILE << "\nDepartment: Engineering";
				}
				else{
					FILE << "\nDepartment: Unknown";
				}
			}
			else if(instanceof<Employee>(list)){
				Employee* listEmployee = (Employee*) list;
				FILE << "\n\nEmployee";
				FILE << "\nID: " << listEmployee->getID();
				FILE << "\nFirst Name: " << listEmployee->getFirstName();
				FILE << "\nLast Name: " << listEmployee->getLastName();
				FILE << "\nSalary: " << listEmployee->getSalary();
			}
			
			list = list->getNext();
		}
	}
	FILE.close();
}
void listPeople(){
	Person* list = headNode;
	while(list != NULL)
	{
		if(instanceof<Student>(list))
		{
			Student* stulist = (Student*) list;
			cout << "\nStudent";
			cout << "\nID: " << stulist->getID();
			cout << "\nFirst Name: " << stulist->getFirstName();
			cout << "\nLast Name: " << stulist->getLastName();
			cout << "\nGPA: " << stulist->getGPA();
		}
		else if(instanceof<Professor>(list))
		{
			Professor* profList = (Professor*) list;
			cout << "\nProfessor";
			cout << "\nID: " << profList->getID();
			cout << "\nFirst Name: " << profList->getFirstName();
			cout << "\nLast Name: " << profList->getLastName();
			cout << "\nSalary: " << profList->getSalary();
			if(profList->getTenured())
			{
				cout << "\nTenured: True";
			}
			else
			{
				cout << "\nTenured: False";
			}
			profList->getTenured();
			if(profList->getDepartment() == English)
			{
				cout << "\nDepartment: English";
			}
			else if(profList->getDepartment() == Math)
			{
				cout << "\nDepartment: Math";
			}
			else if(profList->getDepartment() == General)
			{
				cout << "\nDepartment: General";
			}
			else if(profList->getDepartment() == Physics)
			{
				cout << "\nDepartment: Physics";
			}
			else if(profList->getDepartment() == Chemistry)
			{
				cout << "\nDepartment: Chemistry";
			}
			else if(profList->getDepartment() == Engineering)
			{
				cout << "\nDepartment: Engineering";
			}
			else
			{
				cout << "\nDepartment: Unknown";
			}
		}
		else if(instanceof<Employee>(list))
		{
			Employee* listEmployee = (Employee*) list;
			cout << "\nEmployee";
			cout << "\nID: " << listEmployee->getID();
			cout << "\nFirst Name: " << listEmployee->getFirstName();
			cout << "\nLast Name: " << listEmployee->getLastName();
			cout << "\nSalary: " << listEmployee->getSalary();
		}
		list = list->getNext(); // i++
	}
}

void addingPeople(){
	int options = 0;
	do{
		int giveMeYourID = 0;
		string fiName = "";
		string laName = "";
		float leGrades = 0;
		float leMoney = 0;
		bool leTenured = false;
		Department leMajor = Unknown;
		int studentNum = 0; 
		string fill = "";
		Person* list = headNode;
		
		addMenu();
		cin >> options;
		
		switch(options){
			case 1 :{
				cout << "Enter ID for Student: ";
				cin >> giveMeYourID;
				cout << "Enter the first name: ";
				cin >> fiName;
				cout << "Enter the last name: ";
				cin >> laName;
				cout << "Enter the GPA: ";
				cin >> leGrades;
				Person* adder = new Student(giveMeYourID, fiName, laName, leGrades);
				addNode(adder);
				break;
			}
			case 2:{
				cout << "Enter ID for Professor: ";
				cin >> giveMeYourID;
				cout << "Enter the first name: ";
				cin >> fiName;
				cout << "Enter the last name: ";
				cin >> laName;
				cout << "Enter the Salary: ";
				cin >> leMoney;
				cout << "Enter the tenured (1 or 0): ";
				cin >> leTenured;
				cout << "Enter major: ";
				cin >> fill;
				if(fill == "Physics"){
					leMajor = Physics;
				}
				else if (fill == "Math"){
					leMajor = Math;
				}
				else if (fill == "Engineering"){
					leMajor = Engineering;
				}
				else if (fill == "Chemistry"){
					leMajor = Chemistry;
				}
				else if (fill == "English"){
					leMajor = English;
				}
				else if (fill == "General"){
					leMajor = General;
				}
				else{
					leMajor = Unknown;
				}
				
				Person* adder = new Professor(giveMeYourID,  fiName,  laName,  leMoney,  leTenured,  leMajor);
				addNode(adder);
				break;
			}
			case 3:{
				cout << "Enter ID for Employee: ";
				cin >> giveMeYourID;
				cout << "Enter the first name: ";
				cin >> fiName;
				cout << "Enter the last name: ";
				cin >> laName;
				cout << "Enter the Salary: ";
				cin >> leMoney;
				
				Person* adder = new Employee( giveMeYourID,  fiName,  laName,  leMoney);
				addNode(adder);
				break;
			}
			case 4: {
				break;
			}
		}
	}while(options != 4);
}

void removePerson(int id){
	Person* list = headNode;
	while(list != NULL){
		if(id == list->getID()){
			string fname = list->getFirstName();
			string lname = list->getLastName();
			deleteNode(list);
			printf("Person deleted");
			return;
		}
		list = list-> getNext();
	}
	return; 
}

void updatePerson(int id){
	Person* list = headNode;
	int options = 0;
	while(list != NULL){
		if(id == list->getID()){
			if(instanceof<Student>(list)){
				do{
					studentMenu(list->getFirstName(), list-> getLastName());
					cout << "Choose your option:";
					cin >> options;
					
					int nextID, prevID = 0;
					string nextFirstName,nextLastName ="";
					float nextGPA, prevGPA = 0;
					string fill = "";
					Student* updateList = (Student*)list;
					
					switch(options){
						case 1: 
							cout << "Enter new Student ID:";
							cin >> nextID;
							updateList->setID(nextID);
							list = updateList;
							break;
						case 2:
							cout << "\nEnter updated first name: ";
							cin >> nextFirstName;
							updateList->setFirstName(nextFirstName);
							list = updateList;
							break;
						case 3:
							cout << "\nEnter updated last name: ";
							cin >> nextLastName;
							updateList->setLastName(nextLastName);
							list = updateList;
							break;
						case 4: 
							cout << "\nEnter updated GPA: ";
							cin >> nextGPA;
							updateList -> setGPA(nextGPA);
							list = updateList;
						case 5:
							break;
					}
				}
				while(options != 5);
			return;
			}
			else if (instanceof<Professor>(list)){
				do{
					professorMenu(list->getFirstName(), list-> getLastName());
					cout << "Choose your option:";
					cin >> options;
					
					int nextID, prevID = 0;
					string nextFirstName,nextLastName ="";
					float nextSalary = 0;
					float nextTenured = false;
					Department nextDepartment;
					string fill = "";
					Professor* updateProfList = (Professor*)list;
					
					switch(options){
						case 1: 
							cout << "Enter new Professor ID:";
							cin >> nextID;
							updateProfList->setID(nextID);
							list = updateProfList;
							break;
						case 2:
							cout << "\nEnter updated first name: ";
							cin >> nextFirstName;
							updateProfList->setFirstName(nextFirstName);
							list = updateProfList;
							break;
						case 3:
							cout << "\nEnter updated last name: ";
							cin >> nextLastName;
							updateProfList->setLastName(nextLastName);
							list = updateProfList;
							break;
						case 4: 
							cout << "\nEnter updated Salary: ";
							cin >> nextSalary;
							updateProfList -> setSalary(nextSalary);
							list = updateProfList;
						case 5:
							cout << "\nEnter updated Tenured (1/0): ";
							cin >> nextTenured;
							updateProfList -> setTenured(nextTenured);
							list = updateProfList;
							break;
						case 6:
							cout << "\nEnter updated Department: ";
							cin >> fill;
							if(fill == "Physics"){
								nextDepartment = Physics;
							}
							else if (fill == "Math"){
								nextDepartment = Math;
							}
							else if (fill == "Engineering"){
								nextDepartment = Engineering;
							}
							else if (fill == "Chemistry"){
								nextDepartment = Chemistry;
							}
							else if (fill == "English"){
								nextDepartment = English;
							}
							else if (fill == "General"){
								nextDepartment = General;
							}
							else{
								nextDepartment = Unknown;
							}
							
							updateProfList->setDepartment(nextDepartment);
							list = updateProfList;
							break;
						case 7:
							break;
					}
				}
				while(options != 7);
			return;
			}
			else if (instanceof<Employee>(list)){
				do{
					employeeMenu(list->getFirstName(), list-> getLastName());
					cout << "Choose your option:";
					cin >> options;
					
					int nextID, prevID = 0;
					string nextFirstName,nextLastName ="";
					float nextSalary = 0;
					string fill = "";
					Employee* updateEmployeeList = (Employee*)list;
					
					switch(options){
						case 1: 
							cout << "Enter new Employee ID:";
							cin >> nextID;
							updateEmployeeList->setID(nextID);
							list = updateEmployeeList;
							break;
						case 2:
							cout << "\nEnter updated first name: ";
							cin >> nextFirstName;
							updateEmployeeList->setFirstName(nextFirstName);
							list = updateEmployeeList;
							break;
						case 3:
							cout << "\nEnter updated last name: ";
							cin >> nextLastName;
							updateEmployeeList->setLastName(nextLastName);
							list = updateEmployeeList;
							break;
						case 4: 
							cout << "\nEnter updated Salary: ";
							cin >> nextSalary;
							updateEmployeeList -> setSalary(nextSalary);
							list = updateEmployeeList;
						case 5:
							break;
					}
				}
				while(options != 5);
			return;
			}
		}
		list = list-> getNext();
	}
}

int main(){
	int options = 0;
	int id = 0;
	readFile();
	do{
		menu();
		cout << "Choice your options: ";
		cin >> options;
		switch(options){
			case 1:
				listPeople();
				break;
			case 2:
				addingPeople();
				break;
			case 3:
				cout << "\nEnter id to delete person: ";
				cin >> id;
				removePerson(id);
				break;
			case 4: 
				cout << "\nEnter id to update person: ";
				cin >> id;
				updatePerson(id);
				break;
			case 5:
				break;
		}
	}while(options != 5);
	
}
