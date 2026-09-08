#include <stdio.h>

char * mystrcat(char *, const char *);

int main(void)
{
	char source[20];
	char destination[40];
	
	printf("\nEnter destination string: ");
	gets(destination);
	
	printf("\nEnter source string: ");
	gets(source);
	
	mystrcat(destination, source);
	
	printf("\nConcatenated string is: ");
	puts(destination);
	
	return 0;
}

char * mystrcat(char *destination, const char *source)
{
	int iCounter1;
	int iCounter2;
	
	for(iCounter1 = 0; destination[iCounter1] != '\0';)
		iCounter1++;
		
	for(iCounter2 = 0; source[iCounter2] != '\0'; iCounter2++)
	{
		destination[iCounter1] = source[iCounter2];
		iCounter1++;
	}
	
	destination[iCounter1] = '\0';
	
	return destination;
}
