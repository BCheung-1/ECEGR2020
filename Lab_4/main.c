#include <stdlib.h>
#include <stdio.h>
typedef struct student{
	int ID;
	char firstName[30];
	char lastName[30];
	float GPA;
	struct student *next;
} Student;

Student* headNode = NULL;

Student* createStudent(int identity, char first[30],char last[30],float grade){
	Student* newNode = NULL;
	newNode = (Student *)malloc(sizeof(Student));
	if( newNode != NULL){

		newNode -> ID = identity;//points to the memory allocation of Student struct and sets ID as number
		strcpy(newNode -> firstName,first ); //points to the memory allocation of Student struct and sets firstName as a string
		strcpy(newNode -> lastName, last); //points to the memory allocation of Student struct and sets lastName as a string
		newNode -> GPA = grade; //points to the memory allocation of Student struct and sets GPA as a float
		newNode->next = NULL;
	}
	return newNode;
}

void addNode(Student* newNode){
	Student* currentNode = headNode; 
	if (headNode == NULL){
		headNode== newNode;
		return;
	}
	while(currentNode-> next != NULL){
		currentNode = currentNode->next;
	}
	currentNode->next = newNode;
	newNode->next = NULL;
}

void insertNode(Student* afterNode, Student* newNode){
	newNode-> next = afterNode-> next;
	afterNode->next = newNode;
}

int main()
{
    Student *newNode;
	newNode = createStudent(123, Bobby, Wasabi, 3.4);
	if(newNode){
		addNode(newNode);
	}
	newNode = createStudent(321, John, Smith, 3.2);
	if(newNode){
		addNode(newNode);
	}
	newNode = createStudent(234, Nerd, Joe, 2.0);
	if(newNode){
		addNode(newNode);
	}
 
    return 0;
}