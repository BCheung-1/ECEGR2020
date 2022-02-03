#include <stdio.h>
#define MAX 20
long Factorial(long num){
	int i;
	int n = num; //setting up variables
	if (n < 0){
		printf("Error"); //if a number is enters is anything equal to zero or less than then there is a error
		return 0;
	}
	else {
		for (i = 1; i < n; ++i){
			num *= i; //takes the value of 1 then multiple by 2 then 3 and so forth til it is the number inputted 
		}
		printf("Factorial of %d = %ld\n", n, num);
		return 1;
	}
}

int IsPalidrome(long value){
	long n = value, rev = 0, remainder, first;
	first = n; //setting up variables
	while (n != 0) {
		remainder = n % 10;
		rev = rev * 10 + remainder; //divides the number by ten to save the value that can used for the palindrome
		n /= 10;
    }
	
	
	if (rev == first){
		printf("%ld is a palindrome.\n", first); //if it is a palindrome then prints to confirm
		return 1;
	}
	else 
		printf("%ld is not a palindrome\n", first); // if it is not a palindrome print the following message
		return 0;
	
}

int HighestBitSet(int value){
	int a[32], n = value, i;
	printf("the binary is %d\n", n);
	for(i = 0; 0 < n; i++){
		a[i] = n%2; // converts the number to binary by dividing it by modlus 
		n = n/2;
		
	}
	
	printf("The binary number is ");
	
	for (int j = i - 1; j >= 0; j--){
        printf("%d",a[j]); //finds the highest bit set and prints it out
	}
	
	printf("\n The number of bits is %d\n", i);
	
}

void ReverseIt(void){
	FILE *fp; // uses file io commands to open a new txt that saves the orginal number and reversed number
	fp = fopen("Reverse.txt","w");
	char str[20];  
	printf("Enter number: "); 
	scanf( "%s" , str );
	printf("Reverse Number is: %s\n",strrev(str)); //reverses the number
	fprintf(fp, "The reverse number is %s\n", str);
	fprintf(fp, "The original number is %s\n", strrev(str));
	fclose(fp);
}

void ReverseItAgain(void){
	char singleLine[255];
	FILE *fp;
	fp = fopen("Reverse.txt", "r"); //reads the Reverse.txt file to get the values from it
	
	fgets(singleLine, 255, fp);
	printf("%s", singleLine);
	fgets(singleLine, 255, fp);
	printf("%s", singleLine);
	//}
	
	fclose(fp);
}

void Pyramid(int lines){
	FILE *fp;
	fp = fopen("Pyramid.txt", "w");
	int m, space, k = 0;
	for(m = 1; m <= lines; ++m, k = 0){
		for(space = 1; space <= lines - m; ++space){
			printf("  "); // prints the amount of spaces for the *
			fprintf(fp, "  ");
		}
		while (k !=2 * m -1){
			printf("* "); //prints the number of stars in one line
			fprintf(fp, "* ");
			++k;
		}
		printf("\n"); //brings it to the next line
		fprintf(fp, "\n");
	}
}

int main(int argc, char **argv)
{
	Factorial(6);
	IsPalidrome(1234321);
	IsPalidrome(12347345);
	HighestBitSet(69);
	ReverseIt();
	ReverseItAgain();
	Pyramid(7);
	//printf("hello world\n");
	return 0;
}

