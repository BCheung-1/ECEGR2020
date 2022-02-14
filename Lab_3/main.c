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

Student** studentInfoFile(void){
	FILE *gpaFile = fopen("gpaOrganizer.txt", "r");
	if(gpaFile == NULL){
		printf("File does not exist\n");
		return NULL;
	}
	int studentNum = 0;
	fscanf(gpaFile, "%d", &studentNum);
	char c;
	for(c = getc(gpaFile); c != EOF; c = getc(gpaFile)){
		if (c == '\n'){ // Increment count if this character is newline
			studentNum = studentNum + 1;
		}
	}
	studentNum /= 4;
	Student **newArray = (Student**)malloc(studentNum * sizeof(Student*));
	float averageGPA = 0.0;
	for(int i = 0; i < studentNum; ++i){
		newArray[i] = (Student*)malloc(sizeof(Student));
		fscanf(gpaFile, "%d", &(newArray[i] -> ID));
		fscanf(gpaFile, "%s", (newArray[i] -> firstName));
		fscanf(gpaFile, "%s", (newArray[i] -> lastName));
		fscanf(gpaFile, "%f", (newArray[i] -> GPA));
		
		printf("Student ID: %d\n", i+1, newArray[i]->ID);
		printf("Student firstname: %s\n", i+1, newArray[i]->firstName);
		printf("Student lastname: %s\n", i+1, newArray[i]->lastName);
		printf("Student GPA: %f\n", i+1, newArray[i]->GPA);
		
		averageGPA += newArray[i] -> GPA;
	}
	averageGPA /= studentNum;
	printf("There are %d students and the average GPA is: %f\n", studentNum, averageGPA);
	return newArray;
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
	for (int j = 0; j < number; j++){
		fprintf(fp,"Student ID: %d\n", newArray[j] -> ID);
		fprintf(fp,"Student firstname: %s\n", newArray[j] ->  firstName);
		fprintf(fp,"Student lastname: %s\n", newArray[j] ->  lastName);
		fprintf(fp,"Student GPA: %f\n", newArray[j] ->  GPA);
	} 
	fclose(fp);
	free(newArray);
	
	Student **Array = studentInfoFile();
	free(Array);
	return 0;
	
}
