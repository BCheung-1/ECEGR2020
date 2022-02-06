#include <stdio.h>
#include <string.h>
int theArray[10] = {1,2,3,4,5,6,7,8,9,10};
struct student{
		int ID;
		char firstName[30];
		char lastName[30];
		float GPA;
	} Student; 

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

void gpaOrganizer(){
	
	
	
}

int main(int argc, char **argv)
{
	ReverseArray();
	
	return 0;
}
