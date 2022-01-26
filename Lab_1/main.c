#include <stdio.h>
#include <ctype.h>

void SizeOfVariables(void){
	char c;  
	short s;  
	int i;  
	unsigned int ui;  
	unsigned long int ul; 
	float f;
	double d;  
	long double ld;
	void *ptr;
	//prints the bytes of the variables
	printf("Size of char: %zu bytes\n", sizeof(c));
	printf("Size of short: %zu bytes\n", sizeof(s));
	printf("Size of int: %zu bytes\n", sizeof(i));
	printf("Size of unsigned int: %zu bytes\n", sizeof(ui));
	printf("Size of unsigned long int: %zu bytes\n", sizeof(ul));
	printf("Size of unsigned float: %zu bytes\n", sizeof(f));
	printf("Size of double: %zu bytes\n", sizeof(d));
	printf("Size of long double: %zu bytes\n", sizeof(ld));
	printf("Size of pointer: %zu bytes\n", sizeof(ptr));
}

int IsLeapYear(int aYear){
	int year = aYear;
	/*printf("Enter a year: ");
	scanf("%d", &year);*/

	// leap year if perfectly divisible by 400
	if (year % 400 == 0){
		printf("%d is a leap year.\n", year);
		return 1;
	}
	// not a leap year if divisible by 100
	// but not divisible by 400
	else if (year % 100 == 0){
		printf("%d is not a leap year.\n", year);
		return 0;
	}
	// leap year if not divisible by 100
	// but divisible by 4
	else if (year % 4 == 0){
		printf("%d is a leap year.\n", year);
		return 1;
	}
	// all other years are not leap years
	else{
		printf("%d is not a leap year.\n", year);
		return 0;
		}
	
}

int IsVowel(char aLetter){
	char c = aLetter;
	int lowercase_vowel, uppercase_vowel;
	//printf("Enter an alphabet: ");
	//scanf("%c", &c);

	// evaluates to 1 if variable c is a lowercase vowel
	lowercase_vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

	// evaluates to 1 if variable c is a uppercase vowel
	uppercase_vowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

   // Show error message if c is not an alphabet
	if (!isalpha(c)){
		printf("Error! Non-alphabetic character. \n");
	}
	else if (lowercase_vowel || uppercase_vowel){
		printf("%c is a vowel. \n", c);
		return 1;
   }
   else{
		printf("%c is a consonant. \n", c);
		return 0;
   }
}

void ReverseNumber(long aNumber){
	int n = aNumber, rev = 0, remainder;
    //printf("Enter an integer: ");
    //scanf("%d", &n);
	
	//runs the while loop until n becomes zero and will flip the number
    while (n != 0) {
		remainder = n % 10;
		rev = rev * 10 + remainder;
		n /= 10;
    }
    printf("Reversed number = %d \n", rev);
    return 0;
 }

int main()
{
    int num1, num2;  
    float fraction;     
    char character;
    char str[50];   // char array of size 50
	SizeOfVariables();
	IsLeapYear(1243);
	IsLeapYear(2000);
	IsLeapYear(3456);
	IsLeapYear(2012);
	IsLeapYear(2342);
	IsVowel('b');
	IsVowel('a');
	ReverseNumber(12345);
    printf("Enter two numbers\n");
    
    // Taking integer as input from user
    scanf(" %d%i", &num1, &num2);
    printf("\n\nThe two numbers You have entered are %d and %i\n\n", num1, num2);

    // Taking float or fraction as input from the user
    printf("\n\nEnter a Decimal number\n");
    scanf(" %f", &fraction); 
    printf("\n\nThe float or fraction that you have entered is %f", fraction);

    // Taking Character as input from the user
    printf("\n\nEnter a Character\n");
    scanf(" %c",&character);
    printf("\n\nThe character that you have entered is %c and the ASCII number is %d", character, character);
    getchar();

    printf("\n\nEnter your complete name:\n\n\n");

    gets(str);
    printf("\n\nWelcome to ECEGR 2020  %s\n\n\n", str);

    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    
    printf("Press Enter to quit");
    scanf("%c",&character);
    return 0;
}


 
 