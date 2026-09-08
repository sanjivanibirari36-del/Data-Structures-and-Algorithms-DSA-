#include <stdio.h>

char * mystrncpy(char *, const char *, int);

int main(void)
{
	char source[20];
	char destination[20];
	int iNo;
	
	printf("\nEnter source string: ");
	gets(source);
	
	printf("\nEnter the value of No: ");
	scanf("%d", &iNo);
	
	printf("\nSource string is: ");
	puts(source);
	
	mystrncpy(destination, source, iNo);	
	printf("\nDestination string is: ");
	puts(destination);
	
	return 0;
}

char * mystrncpy(char *destination, const char *source, int iNo)
{
	int iCounter;
	
	for(iCounter = 0; source[iCounter] == '\0' || iCounter < iNo; iCounter++)
		destination[iCounter] = source[iCounter];
		
	destination[iCounter] = '\0';
	
	return destination;
}
