#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream> 

using namespace std;

enum Department{Physics, Math, Engineering, Chemistry, English, General};

class Student{
	private:
		int ID = NULL;
		char* firstName = NULL;
		char* lastName = NULL;
		float GPA = NULL;
		Student* next;
	
	public:
		Student();
		Student(int identity, char *fName, char *lName, float grade);
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
	char* getfirstName(){
		return firstName;
	}
	char* getlastName(){
		return lastName;
	}
	Student* getNext(){
		return next;;
	}
	
	void setID(int identity){
		ID = identity;
	}
	void setGPA(float grade){
		GPA = grade;
	}
	void setfirstName(char *fname){
		free(firstName);
		firstName = (char*)malloc(sizeof(strlen(fname)+1));
		strcpy(firstName,fname);
	}
	void setlastName(char *lname){
		free(lastName);
		lastName = (char*)malloc(sizeof(strlen(lname)+1));
		strcpy(lastName,lname);
	}
	void setNext(Student* adj){
		next = adj;
	}
};

Student* headNode = NULL;

Student :: Student(){
	this->ID = 0000;
	this->firstName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this -> firstName, (char*)"<unknown>");
	this->lastName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this-> lastName, (char*) "<unknown>");
	this->GPA = 0.0;
	this->next = NULL; 
	cout << "Default constructor \n";
}

Student :: Student(int identity, char* fname, char* lname, float grade)
{
	this->ID = identity;
	this->firstName = (char*) malloc(sizeof(strlen(fname)+1));
	strcpy(this->firstName, fname);
	this->lastName = (char*) malloc(sizeof(strlen(lname)+1));
	strcpy(this->lastName, lname);
	this->GPA = grade;
	this->next = NULL;
	cout << "Student constructor for " << firstName << lastName <<"\n";
}

Student :: Student(Student &init)
{
	ID = init.ID;
	GPA = init.GPA;
	if(init.firstName != NULL)
	{
		setfirstName(init.firstName);
	}
	if(init.lastName != NULL)
	{
		setlastName(init.lastName);
	}
	cout << "Student Copy Constructor \n";
}

Student :: ~Student()
{
	
	if(firstName)
	{
		free(firstName);
	}
	if(lastName)
	{
		free(lastName);
	}
	cout << "Student Deconstructor " << firstName << lastName << endl;
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
		free(newNode);
		return;
	}
	
	while(currentNode != NULL && currentNode != newNode){
		prevNode = currentNode;
		currentNode = currentNode->getNext();
	}
	
	if(currentNode != NULL){
		prevNode->setNext(currentNode->getNext());
	}
	
	free(newNode);
}

void readFile(){
	ifstream FILE;
	int giveMeYourID = 0;
	char fiName[30] = "";
	char laName[30] = "";
	float leGrades;
	int studentNum = 0;
	float averageGPA = 0.0;
	char c;
	//Student* pointer = (Student*)malloc(sizeof(Student)); //sets up a pointer to student memory allocation
	//Student **newArray = (Student**)malloc(studentNum * sizeof(Student*));
	//newArray[i] = (Student*)malloc(sizeof(Student));
	//FILE *gpaFile;
	FILE.open("gpaOrganizer.txt"); //reads the text file
	
	if(!FILE.is_open(){
		printf("File does not exist\n"); //checking if the file exists
	}
	
	fscanf(gpaFile, "Number of Student: %d", &studentNum); //looks at the first line to take the number of students
	printf("Number of Student: %d\n", studentNum);
	
	for(int i = 0; i < studentNum; i++){
		fscanf(gpaFile, "\nStudent ID: %d", &giveMeYourID ); //looks at the next line and sets variable as id
		fscanf(gpaFile, "\nStudent firstname: %s", fiName);//looks at the next line and sets variable as firstname
		fscanf(gpaFile, "\nStudent lastname: %s", laName);//looks at the next line and sets variable as lastname
		fscanf(gpaFile, "\nStudent GPA: %f", &leGrades);//looks at the next line and sets variable as gpa
		
		Student* fileNode = createStudent(giveMeYourID, fiName, laName, leGrades);
		addNode(fileNode);
	}
}

void updateStudent(int id){
	Student* list = headNode;
	Student* prevList = list;
	//int c = 0;
	int options = 0;
	while(list != NULL){
		if(id == list->ID){
			do{
				updateMenu(list->firstName, list-> lastName);
				printf("Choose your option:");
				scanf("%d", &options);
				
				int nextID, prevID;
				char nextFirstName[30], prevFirstName[30];
				char nextLastName[30], prevLastName[30];
				float nextGPA, prevGPA;
				Student* updateList = headNode;
				
				switch(options){
					case 1: 
						printf("Enter new ID:");
						scanf("%d",&nextID);
						while(updateList != NULL){
							if(nextID == updateList -> ID){
								printf("Enter a different id\n");
								updateList = headNode;
								printf("Enter updated ID of student: ");
								scanf("%d", &nextID);
								
							}
							updateList = updateList ->next;
						}
						prevID = list->ID;
						list->ID = nextID;
					case 2:
						printf("\nEnter updated first name:");
						scanf("%s", nextFirstName);
						strcpy(prevFirstName, list->firstName);
						strcpy(list -> firstName, nextFirstName);
						break;
					case 3:
						printf("\nEnter updated last name:");
						scanf("%s", nextLastName);
						strcpy(prevLastName, list->lastName);
						strcpy(list -> lastName, nextLastName);
						break;
					case 4: 
						printf("\nEnter updated GPA: ");
						scanf("%f", &nextGPA);
						prevGPA = list -> GPA;
						list -> GPA = nextGPA;
						if(prevList == list){
							list -> next = NULL;
							insertNode(list);
						}
						else{
							prevList-> next = list->next;
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
		list = list-> next;
	}
	
	
}

void removeStudent(int id){
	Student* list = headNode;
	while(list != NULL){
		if(id == list->ID){
			char fname[30];
			char lname[30];
			strcpy(fname, list->firstName);
			strcpy(lname, list->lastName);
			deleteNode(list);
			printf("Student deleted");
			return;
		}
		list = list-> next;
	}
	return; 
}

void listStudent(){
	Student* list = headNode;
	while(list != NULL){
		printf("\nStudent ID: %d", list -> ID);
		printf("\nStudent firstname: %s", list -> firstName);
		printf("\nStudent lastname: %s", list -> lastName);
		printf("\nStudent GPA: %f", list -> GPA);
		list = list ->next;
	}
}

void menu(){
	printf("\n1) List all Students\n");
	printf("2) Add Student\n");
	printf("3) Remove Student\n");
	printf("4) Update Student\n");
	printf("5) Quit\n");

}

void updateMenu(char fi[30], char la[30])
{
	printf("What would you like to update? %s %s?\n", fi, la);
	printf("1) ID \n");
	printf("2) First Name \n");
	printf("3) Last Name \n");
	printf("4) GPA \n");
	printf("5) Quit \n");
}