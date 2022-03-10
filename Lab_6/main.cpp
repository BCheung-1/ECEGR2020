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