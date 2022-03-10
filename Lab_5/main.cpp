#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

enum Department{Physics, Math, Engineering, Chemistry, English, General};

class Student{
	private:
		int ID =NULL;
		char* firstName = NULL;
		char* lastName = NULL;
		float GPA =NULL;
	
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
};

Student :: Student(){
	this->ID = 0000;
	this->firstName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this -> firstName, (char*)"<unknown>");
	this->lastName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this-> lastName, (char*) "<unknown>");
	this->GPA = 0.0;
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
	cout << "Student Deconstructor " << firstName << lastName << endl;
	if(firstName)
	{
		free(firstName);
	}
	if(lastName)
	{
		free(lastName);
	}
}

class Professor{
	private:
		int ID;
		char* firstName;
		char* lastName;
		float salary;
		bool tenured;
		Department department;
	
	public:
		Professor();
		Professor(int identity, char *fName, char *lName, float money, bool ten, Department major);
		Professor(Professor &init);
		~Professor();
		
		Professor& operator=(Professor const &pro)
	{
		this->ID = pro.ID;
		setfirstName(pro.firstName);
		setlastName(pro.lastName);
		this->salary = pro.salary;
		this->tenured = pro.tenured;
		this->department = pro.department;
		cout << "Professor Assignment Operator \n";
		return *this;
	}
	
	int getID(){
		return ID;
	} 
	float getsalary(){
		return salary;
	}
	char* getfirstName(){
		return firstName;
	}
	char* getlastName(){
		return lastName;
	}
	bool getTenured(){
		return tenured;
	}
	Department getDepartment(){
		return department;
	}
	
	void setID(int identity){
		ID = identity;
	}
	void setGPA(float money){
		salary = money;
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
	void setTenured(bool ten){
		tenured = ten;
	}
	void setDepartment(Department major){
		department = major;
	}
	
};

Professor :: Professor(){
	this->ID = 0000;
	this->firstName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this -> firstName, (char*)"<unknown>");
	this->lastName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this-> lastName, (char*) "<unknown>");
	this->salary = 0.0;
	tenured = false;
	department = General;
	cout << "Professor Default constructor \n";
}

Professor :: Professor(int identity, char* fname, char* lname, float money, bool ten, Department major )
{
	this->ID = identity;
	this->firstName = (char*) malloc(sizeof(strlen(fname)+1));
	strcpy(this->firstName, fname);
	this->lastName = (char*) malloc(sizeof(strlen(lname)+1));
	strcpy(this->lastName, lname);
	this->salary = money;
	this->tenured = ten;
	this->department = major;
	cout << "Professor constructor for " << firstName << lastName <<"\n";
}

Professor :: Professor(Professor &init)
{
	ID = init.ID;
	salary = init.salary;
	if(init.firstName)
	{
		setfirstName(init.firstName);
	}
	if(init.lastName)
	{
		setlastName(init.lastName);
	}
	tenured = init.tenured;
	department = init.department;
	cout << "Professor Copy Constructor \n";
}

Professor :: ~Professor()
{
	cout << "Professor Deconstructor " << firstName << lastName << endl;
	if(firstName)
	{
		free(firstName);
	}
	if(lastName)
	{
		free(lastName);
	}
}

class Employee{
	private:
		int ID;
		char* firstName;
		char* lastName;
		float salary;
	
	public:
		Employee();
		Employee(int identity, char *fName, char *lName, float money);
		Employee(Employee &init);
		~Employee();
		
		Employee& operator=(Employee const &emp)
	{
		this->ID = emp.ID;
		setfirstName(emp.firstName);
		setlastName(emp.lastName);
		this->salary = emp.salary;
		cout << "Employee Assignment Operator \n";
		return *this;
	}
	
	int getID(){
		return ID;
	} 
	float getsalary(){
		return salary;
	}
	char* getfirstName(){
		return firstName;
	}
	char* getlastName(){
		return lastName;
	}
	
	void setID(int identity){
		ID = identity;
	}
	void setGPA(float money){
		salary = money;
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
	
};

Employee :: Employee(){
	this->ID = 0000;
	this->firstName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this -> firstName, (char*)"<unknown>");
	this->lastName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this-> lastName, (char*) "<unknown>");
	this->salary = 0.0;
	cout << "Employee Default constructor \n";
}

Employee :: Employee(int identity, char* fname, char* lname, float money)
{
	this->ID = identity;
	this->firstName = (char*) malloc(sizeof(strlen(fname)+1));
	strcpy(this->firstName, fname);
	this->lastName = (char*) malloc(sizeof(strlen(lname)+1));
	strcpy(this->lastName, lname);
	this->salary = money;
	cout << "Employee constructor for " << firstName << lastName <<"\n";
}

Employee :: Employee(Employee &init)
{
	ID = init.ID;
	salary = init.salary;
	if(init.firstName)
	{
		setfirstName(init.firstName);
	}
	if(init.lastName)
	{
		setlastName(init.lastName);
	}
	cout << "Employee Copy Constructor \n";
}

Employee :: ~Employee()
{
	cout << "Employee Deconstructor " << firstName << lastName << endl;
	if(firstName)
	{
		free(firstName);
	}
	if(lastName)
	{
		free(lastName);
	}
}

int main()
{
	Student student1(2342, (char*) "Bobby", (char*) "Wasabi", 3.0);
	//if deconstructor is printed out therefore it doesn't leak the memory
	cout << endl << student1.getID()<< endl <<student1.getfirstName() << endl << student1.getlastName() << endl <<student1.getGPA() << endl;
	Student student2 = student1;
	cout << endl << student2.getID()<< endl <<student2.getfirstName() << endl << student2.getlastName() << endl <<student2.getGPA() << endl;
	if(student2.getID() == student1.getID()){
		cout << "It is the same" << endl;
	}
	student2.setID(8587);
	student2.setfirstName((char*) "John");
	student2.setlastName((char*) "Smith");
	student2.setGPA(3.6);
	cout << endl << student2.getID()<< endl <<student2.getfirstName() << endl << student2.getlastName() << endl <<student2.getGPA() << endl;
}
