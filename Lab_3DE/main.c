#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	char str[100], option;
	int count = 0;
	int c = 0;
	int i;
	printf("Enter the string\n");
	scanf("%s", str);

	while(1){
		printf("A) Count the number of vowels in the string\n");
		printf("B) Count the number of consonants in the string\n");
		printf("C) Convert the string to uppercase\n");
		printf("D) Convert the string to lowercase\n");
		printf("E) Display the current string\n");
		printf("F) Enter another string\n\n");
		printf("M) Display this menu\n");
		printf("X) Exit the program\n");
		
		scanf("%s", option);
		
		switch(option){
			case 1:
				while(str[c] != '\0'){
					if(str[c] == 'a' || str[c] == 'A' || str[c] == 'e' || str[c] == 'E' || str[c] == 'i' || str[c] == 'I' || str[c] =='o' || str[c]=='O' || str[c] == 'u' || str[c] == 'U'){
						count++;
						c++;
					}
				}
				printf("Number of vowels in the string: %d" , count);
				int count = 0;
				int c = 0;
			case 2: 
				while(str[c] != '\0'){
					if(str[c] != 'a' || str[c] != 'A' || str[c] != 'e' || str[c] != 'E' || str[c] != 'i' || str[c] != 'I' || str[c] !='o' || str[c]!='O' || str[c] != 'u' || str[c] != 'U'){
						count++;
						c++;
					}
				}
				printf("Number of consonants in the string: %d" , count);
			case 3:
				for (i = 0; str[i]!='\0'; i++) {
					if(str[i] >= 'a' && str[i] <= 'z') {
					str[i] = str[i] -32;
					}
				}
				printf("\nString in Upper Case = %s", str);
			case 4:
				break;
		}
	}
	return 0;
}