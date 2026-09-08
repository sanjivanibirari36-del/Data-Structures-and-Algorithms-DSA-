#include <stdio.h>

char * strcpy(char *, const char *);

int main(void)
{
	char source[20];
	char destination[20];
	
	printf("\nEnter the source string: ");
	gets(source);
	
	printf("\nSource string is: ");
	puts(source);
	
	strcpy(destination, source);
	
	printf("\nDestination string is: ");
	puts(destination);
	
	return 0;
}

char * strcpy(char *destination, const char *source)
{
	int iCounter;
	
	for(iCounter = 0; source[iCounter] != '\0'; iCounter++)
		destination[iCounter] = source[iCounter];
		
	destination[iCounter] = '\0';
	
	return destination;
}
