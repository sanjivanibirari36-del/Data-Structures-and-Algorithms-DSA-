#include <stdio.h>

char * mystrnset(char *, char, int);

int main(void)
{
	char string[20];
	char ch;
	int iNo;
	
	printf("Enter string: ");
	gets(string);
	printf("Enter the character to set: ");
	scanf("%c", &ch);
	printf("Enter value of n: ");
	scanf("%d", &iNo);
	
	mystrnset(string, ch, iNo);
	
	printf("Now string is: ");
	puts(string);
	
	return 0;
}

char * mystrnset(char *string, char ch, int iNo)
{
	int iCounter;
	
	for(iCounter = 0; iCounter < iNo; iCounter++)
		string[iCounter] = ch;
		
	while(string[iCounter] != '\0')
		iCounter++;
	
	string[iCounter] = '\0';
	
	return string;
}	
	
