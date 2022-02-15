#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int theArray[10] = {1,2,3,4,5,6,7,8,9,10};

typedef struct student{
		int ID;
		char firstName[30];
		char lastName[30];
		float GPA;
	} Student; 

Student* adding(void);
void gpaOrganizer(Student** newArray, int num);
Student** studentInfoFile(void);

void ReverseArray(void){
	int n = sizeof(theArray)/sizeof(theArray[0]);
	int size = n;
	int start = 0;
	int end = n - 1;
	int temp;
	while(start < end){
		temp = theArray[start];
		theArray[start] = theArray[end];
		theArray[end] = temp;
		start++;
		end--;
	}
	for (int i = 0; i < size; i++){
		printf("%d,", theArray[i]);
	}
}

void gpaOrganizer(Student** newArray , int num){
	for (int i = 0; i < num; i++){
		for (int j = 0; j < num; j++){
			if (newArray[i] -> GPA > newArray[j] -> GPA){
				Student* temp = newArray[i];
				newArray[i] = newArray[j];
				newArray[j] = temp;
			}
		}
	}
}

Student* adding(void){
	Student* ptr = (Student*)malloc(sizeof(Student));
	int identity = 0;
	char first[30] = "";
	char last[30] = "";
	float grade; 
	printf("Input ID number \n");
	scanf("%d", &identity);
	ptr -> ID = identity;
	printf("Input firstname \n");
	scanf("%s", &first);
	strcpy(ptr -> firstName,first );
	printf("Input lastname \n");
	scanf("%s", &last);
	strcpy(ptr -> lastName, last);
	printf("Input grade \n");
	scanf("%f",&grade);
	ptr -> GPA = grade;
	return ptr;
}

void readFile(Student** array){
	int giveMeYourID = 0;
	char fiName[30] = "";
	char laName[30] = "";
	float leGrades;
	int studentNum = 0;
	float averageGPA = 0.0;
	char c;
	Student* pointer = (Student*)malloc(sizeof(Student));
	//Student **newArray = (Student**)malloc(studentNum * sizeof(Student*));
	//newArray[i] = (Student*)malloc(sizeof(Student));
	FILE *gpaFile;
	gpaFile = fopen("gpaOrganizer.txt", "r");
	
	if(gpaFile == NULL){
		printf("File does not exist\n");
		return NULL;
	}
	
	fscanf(gpaFile, "Number of Student: %d", &studentNum);
	printf("Number of Student: %d\n", studentNum);
	
	for(int i = 0; i < studentNum; i++){
		fscanf(gpaFile, "\nStudent ID: %d", &giveMeYourID );
		fscanf(gpaFile, "\nStudent firstname: %s", fiName);
		fscanf(gpaFile, "\nStudent lastname: %s", laName);
		fscanf(gpaFile, "\nStudent GPA: %f", &leGrades);
		
		pointer -> ID = giveMeYourID;
		strcpy(pointer -> firstName,fiName);
		strcpy(pointer -> firstName,laName);
		pointer -> GPA = leGrades;
		
		printf("Student ID: %d\n", giveMeYourID);
		printf("Student firstname: %s\n", fiName);
		printf("Student lastname: %s\n", laName);
		printf("Student GPA: %f\n", leGrades);
		
		array[i] = pointer;
		averageGPA += leGrades;
	}
	averageGPA /= studentNum;
	printf("There are %d students and the average GPA is: %f\n", studentNum, averageGPA);
}

int main(int argc, char **argv)
{
	ReverseArray();
	int number;
	printf("\nNumber of students\n");
	scanf("%d",&number);
	Student **newArray =(Student*)malloc(number*sizeof(Student));
	
	for (int i =0; i < number; i++){
		newArray[i] = adding(); 
	}
	
	gpaOrganizer(newArray,number);
	
	FILE *fp; // uses file io commands to open a new txt that saves the orginal number and reversed number
	fp = fopen("gpaOrganizer.txt","wt");
	fprintf(fp, "Number of Student: %d\n", number);
	for (int j = 0; j < number; j++){
		fprintf(fp,"Student ID: %d\n", newArray[j] -> ID);
		fprintf(fp,"Student firstname: %s\n", newArray[j] ->  firstName);
		fprintf(fp,"Student lastname: %s\n", newArray[j] ->  lastName);
		fprintf(fp,"Student GPA: %f\n", newArray[j] ->  GPA);
	} 
	fclose(fp);
	free(newArray);
	
	Student** stuInfo = (Student**)malloc(number*sizeof(Student*));
	readFile(stuInfo);
	free(stuInfo);
	return 0;
}
