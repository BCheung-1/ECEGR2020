#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char str[100];
char option;
int a = 1;
char junk;

void request(char *str){
	do{
		printf("Choose your option:\n");
		option = getchar();
		junk = getchar();
		switch(option){
			case 'A':
				vowelCount(str);
				break;
			case 'B': 
				consCount(str);
				break;
			case 'C':
				Upper(str);
				break;
			case 'D':
				Lower(str);
				break;
			case 'E':
				printf("%s",str);
				break;
			case 'F':
				//printAgain(str);
				printf("Enter the string: \n");
				fgets(str, 100, stdin);
				break;
			case 'R':
				printf("Reverse string is: %s\n", strrev(str));
				break;
			case 'M':
				menu();
				break;
			case 'X':
				--a;
				break;
		}
		
	}while(a);
}

int vowelCount(char *str){
	int count = 0;
	int c = 0;
	for(c = 0; str[c] != '\0';c++){
		if(str[c] == 'a' || str[c] == 'A' || str[c] == 'e' || str[c] == 'E' || str[c] == 'i' || str[c] == 'I' || str[c] =='o' || str[c]=='O' || str[c] == 'u' || str[c] == 'U'){
			count++;
		}
	}
	printf("\nNumber of vowels in the string: %d\n" , count);
	return count;
}

int consCount(char *str){
	int count = 0;
	int c = 0;
	for(c = 0; str[c] != '\0';c++){
		if(str[c] != 'a' || str[c] != 'A' || str[c] != 'e' || str[c] != 'E' || str[c] != 'i' || str[c] != 'I' || str[c] !='o' || str[c]!='O' || str[c] != 'u' || str[c] != 'U'){
			count++;
		}
	}
	printf("\nNumber of vowels in the string: %d\n" , count);
	return count;
}

void Upper(char *str){
	puts(strupr(str));
}

void Lower(char *str){
	puts(strlwr(str));
}

void printAgain(char *str){
	printf("Enter the string: \n");
	fgets(str, 100, stdin);
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
	fgets(str, 100, stdin);

	menu();
	request(str);
	return 0;
}