#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream> 

using namespace std;

enum Department{Physics, Math, Engineering, Chemistry, English, General};

class Student{
	private:
		int ID = 0;
		string firstName = "";
		string lastName = "";
		float GPA = 0;
		Student* next;
	
	public:
		Student();
		Student(int identity, string fName, string lName, float grade);
		Student(Student &init);
		~Student();
		
		Student& operator=(Student const &stu)
	{
		this->ID = stu.ID;
		setfirstName(stu.firstName);
		setlastName(stu.lastName);
		this->GPA = stu.GPA;
		cout << "Student Assignment Operator \n";
		return *this;
	}
	
	int getID(){
		return ID;
	} 
	float getGPA(){
		return GPA;
	}
	string getfirstName(){
		return firstName;
	}
	string getlastName(){
		return lastName;
	}
	Student* getNext(){
		return next;
	}
	
	void setID(int identity){
		ID = identity;
	}
	void setGPA(float grade){
		GPA = grade;
	}
	void setfirstName(string fname){
		this->firstName = fname;
	}
	void setlastName(string lname){
		this->lastName = lname;
	}
	void setNext(Student* adj){
		next = adj;
	}
};

Student* headNode = NULL;

Student :: Student(){
	this->ID = 0000;
	this->firstName = "(null)";
	this->lastName = "(null)";
	this->GPA = 0.0;
	this->next = NULL; 
	cout << "Default constructor \n";
}

Student :: Student(int identity, string fname, string lname, float grade)
{
	this->ID = identity;
	this->firstName = fname;
	this->lastName = lname;
	this->GPA = grade;
	this->next = NULL; 
	cout << "Default constructor \n";
}

Student :: Student(Student &init)
{
	ID = init.ID;
	GPA = init.GPA;
	firstName = "";
	lastName = "";
	setfirstName(init.firstName);
	setlastName(init.lastName);
	cout << "Student Copy Constructor \n";
}

Student :: ~Student()
{
	cout << "Student Deconstructor " << firstName << " " <<lastName << endl;
}

void addNode(Student* newNode){
	Student* currentNode = headNode; 
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

void insertNode(Student* newNode){
	Student* list = headNode;
	while(list->getNext() != NULL){
		Student* nextNode = list->getNext();
		if((list -> getGPA() > newNode -> getGPA()) && (newNode -> getGPA() >= nextNode -> getGPA())){
			newNode->setNext(list->getNext());
			list->setNext(newNode);
			return;
		}
		else if(list -> getGPA() <= newNode -> getGPA()){
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

void deleteNode(Student* newNode){
	Student* currentNode = headNode;
	Student* prevNode = NULL;
	
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

void readFile(){
	ifstream FILE;
	int giveMeYourID = 0;
	string fiName = "";
	string laName = "";
	float leGrades = 0;
	int studentNum = 0;

	FILE.open("gpaOrganizer.txt"); //reads the text file
	
	if(!FILE.is_open()){
		cout << "File does not exist\n"; //checking if the file exists
	}
	else{
		string fill = "";
		FILE >> fill;
		FILE >> fill;
		FILE >> fill;
		//FILE >> fill;
		FILE >> studentNum;
		cout << "Number of Student: " << studentNum;
		for(int i = 0; i < studentNum; i++){
			FILE >> fill;
			FILE >> fill;
			FILE >> giveMeYourID;
			FILE >> fill;
			FILE >> fill;
			FILE >> fiName;
			FILE >> fill;
			FILE >> fill;
			FILE >> laName;
			FILE >> fill;
			FILE >> fill;
			FILE >> leGrades;
			Student* fileNode = new Student(giveMeYourID, fiName, laName, leGrades);
			addNode(fileNode);
		}
	}
	FILE.close();
}


void removeStudent(int id){
	Student* list = headNode;
	while(list != NULL){
		if(id == list->getID()){
			string fname = list->getfirstName();
			string lname = list->getlastName();
			deleteNode(list);
			printf("Student deleted");
			return;
		}
		list = list-> getNext();
	}
	return; 
}

void listStudent(){
	Student* list = headNode;
	while(list != NULL){
		printf("\nStudent ID: %d", list -> getID());
		cout << "\nStudent firstname: " << list -> getfirstName();
		cout << "\nStudent lastname: " << list -> getlastName();
		printf("\nStudent GPA: %f", list -> getGPA());
		list = list ->getNext();
	}
}

void menu(){
	printf("\n1) List all Students\n");
	printf("2) Add Student\n");
	printf("3) Remove Student\n");
	printf("4) Update Student\n");
	printf("5) Quit\n");

}

void updateMenu(string fi, string la)
{
	cout << "What would you like to update?" << fi << " " << la << endl;
	printf("1) ID \n");
	printf("2) First Name \n");
	printf("3) Last Name \n");
	printf("4) GPA \n");
	printf("5) Quit \n");
}

void updateStudent(int id){
	Student* list = headNode;
	Student* prevList = list;
	//int c = 0;
	int options = 0;
	while(list != NULL){
		if(id == list->getID()){
			do{
				updateMenu(list->getfirstName(), list-> getlastName());
				cout << "Choose your option:";
				cin >> options;
				
				int nextID, prevID = 0;
				string nextFirstName,nextLastName ="";
				float nextGPA, prevGPA = 0;
				string fill = "";
				Student* updateList = headNode;
				
				switch(options){
					case 1: 
						cout << "Enter new ID:";
						cin >> nextID;
						while(updateList != NULL){
							if(nextID == updateList -> getID()){
								cout << "Enter a different id\n";
								updateList = headNode;
								cout << "Enter updated ID of student: ";
								cin >> nextID;;
							}
							updateList = updateList ->getNext();
						}
						prevID = list->getID();
						list->setID(nextID);
					case 2:
						cout << "\nEnter updated first name: ";
						cin >> nextFirstName;
						list->setfirstName(nextFirstName);
						break;
					case 3:
						cout << "\nEnter updated name name: ";
						cin >> nextLastName;
						list->setfirstName(nextLastName);
						break;
					case 4: 
						cout << "\nEnter updated GPA: ";
						cin >> nextGPA;
						prevGPA = list -> getGPA();
						list -> setGPA(nextGPA);
						if(prevList == list){
							list -> setNext(NULL);
							insertNode(list);
						}
						else{
							prevList-> setNext(list->getNext());
							insertNode(list);
						}
					case 5:
						break;
				}
			}
			while(options != 5);
			return;
		}
		prevList = list;
		list = list-> getNext();
	}
}

void saving(){
	ofstream FILE;
	Student* list = headNode;
	int studentNum = 0;

	FILE.open("gpaOrganizer.txt"); //reads the text file
	
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
			FILE << "\nStudent ID: " << list->getID();
			FILE << "\nStudent firstname: " << list->getfirstName();
			FILE << "\nStudent lastname: " << list->getlastName();
			FILE << "\nStudent GPA: " << list->getGPA();
			list = list->getNext();
		}
	}
	FILE.close();
}

int main()
{
	int options = 0;
	readFile();
	do{
		int yourID = 0;
		string firName;
		string lasName;
		float megrades = 0;
		Student* id = headNode;
		menu();
		cout << "Choose your option:\n";
		cin >> options;
		switch(options){
			case 1:
				listStudent();
				break;
			case 2: {
				cout << "Student ID: \n"; 
				cin >> yourID;
				while(id != NULL){
					if(yourID == id->getID()){
						cout << "ID is in use, use another one. \n";
						id = headNode;
						cout << "Enter a new id \n";
						cin >> yourID;
					}
					id = id->getNext();
				}
				
				cout << "Student firstname: \n";
				cin >> firName;
				
				cout << "Student lastname: \n";
				cin >> lasName;
				
				cout << "Student GPA: \n";
				cin >> megrades;
				
				Student* ptr = new Student(yourID, firName, lasName, megrades);
				insertNode(ptr);
				break;
			}
			case 3: 
				cout << "Enter ID of student to remove: ";
				cin >> yourID;
				removeStudent(yourID);
				break;
			case 4:
				cout << "Enter id of student to update:";
				cin >> yourID;
				updateStudent(yourID);
				break;
			case 5:
				break;
		}
	}
	while(options != 5);
	saving();
}