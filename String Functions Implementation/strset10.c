#include <stdio.h>

char * mystrset(char *, char);

int main(void)
{
	char string[20];
	char ch;
	
	printf("Enter the string: ");
	gets(string);
	printf("Enter the character to set: ");
	scanf("%c", &ch);
	
	mystrset(string, ch);
	
	printf("Now string is: ");
	puts(string);
	
	return 0;
}

char * mystrset(char *string, char ch)
{
	int iCounter;
	
	for(iCounter = 0; string[iCounter] != '\0'; iCounter++)
		string[iCounter] = ch;
	string[iCounter] = '\0';
		
	return string;
}
