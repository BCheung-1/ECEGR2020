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
	for (int i = 0; i < num-1; i++){
		for (int j = 0; j < num-1; j++){
			if (newArray[i] -> GPA > newArray[j] -> GPA){
				float a = newArray[i] -> GPA;
				newArray[i] -> GPA = newArray[j] -> GPA;
				newArray[j] -> GPA = a; 
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
	strcpy(first, ptr -> firstName);
	printf("Input lastname \n");
	scanf("%s", &last);
	strcpy(last, ptr -> lastName);
	printf("Input grade");
	scanf("%f",&grade);
	ptr -> GPA = grade;
	return ptr;
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
	return 0;
	FILE *fp; // uses file io commands to open a new txt that saves the orginal number and reversed number
	fp = fopen("gpaOrganizer.txt","wt");
	for (int j = 0; j < number-1; j++){
		fprintf(fp,"Student ID: %d", newArray -> ID);
		fprintf(fp,"Student firstname: %s", newArray -> ID);
		fprintf(fp,"Student lastname: %s", newArray -> ID);
		fprintf(fp,"Student GPA: %", newArray -> ID);
		
	} 
	
}
