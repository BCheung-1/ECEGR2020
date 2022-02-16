#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char str[100];
char option;
int a = 1;


void request(char str[100]){
	do{
		printf("Choose your option:\n");
		scanf("%c", &option);
		switch(option){
			case 'A':
				printf("\nNumber of vowels in the string: %d" , vowelCount(str));
				break;
			case 'B': 
				printf("\nNumber of consonants in the string: %d" , consCount(str));
				break;
			case 'C':
				Upper(str);
				break;
			case 'D':
				Lower(str);
				break;
			case 'E':
				printf("\n%c", str);
				break;
			case 'F':
				printf("Enter the string\n");
				scanf("%s", str);
				break;
			case 'R':
				
				break;
			case 'M':
				printf("A) Count the number of vowels in the string\n");
				printf("B) Count the number of consonants in the string\n");
				printf("C) Convert the string to uppercase\n");
				printf("D) Convert the string to lowercase\n");
				printf("E) Display the current string\n");
				printf("F) Enter another string\n");
				printf("R) Reverse the string\n\n");
				printf("M) Display this menu\n");
				printf("X) Exit the program\n");
				break;
			case 'X':
				break;
		}
		
	}while(a);
}

int vowelCount(char str[]){
	int count = 0;
	int c = 0;
	while(str[c] != '\0'){
		if(str[c] == 'a' || str[c] == 'A' || str[c] == 'e' || str[c] == 'E' || str[c] == 'i' || str[c] == 'I' || str[c] =='o' || str[c]=='O' || str[c] == 'u' || str[c] == 'U'){
			count++;
			c++;
		}
	}
	return count;
}

int consCount(char str[]){
	int count = 0;
	int c = 0;
	while(str[c] != '\0'){
		if(str[c] != 'a' || str[c] != 'A' || str[c] != 'e' || str[c] != 'E' || str[c] != 'i' || str[c] != 'I' || str[c] !='o' || str[c]!='O' || str[c] != 'u' || str[c] != 'U'){
			count++;
			c++;
		}
	}
	return count;
}

void Upper(char str[]){
	for(int i = 0; str[i] != "\0"; i++){
		str[i] = toupper(str[i]);
		printf("\nThe uppercase sentence is: %c", str[i]);
	}
	
}

void Lower(char str[]){
	for(int i = 0; str[i] != "\0"; i++){
		str[i] = tolower(str[i]);
		printf("\nThe uppercase sentence is: %c", str[i]);
	}
}



void menu(){
	printf("A) Count the number of vowels in the string\n");
	printf("B) Count the number of consonants in the string\n");
	printf("C) Convert the string to uppercase\n");
	printf("D) Convert the string to lowercase\n");
	printf("E) Display the current string\n");
	printf("F) Enter another string\n");
	printf("R) Reverse the string\n\n");
	printf("M) Display this menu\n");
	printf("X) Exit the program\n");
	
}

int main(){
	printf("Enter the string\n");
	scanf("%s", str);
	menu();
	request(str);
	return 0;
}