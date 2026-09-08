#include <stdio.h>

char * mystrlwr(char *);

int main(void)
{
	char string[20];
	
	printf("\nEnter the string: ");
	gets(string);
	
	mystrlwr(string);
	
	printf("\nString in lower case is: ");
	puts(string);
	
	return 0;
}

char * mystrlwr(char *string)
{
	int iCounter;
	
	for(iCounter = 0; string[iCounter] != '\0'; iCounter++)
	{
		if(string[iCounter] <= 64 || string[iCounter] >= 91)
				continue;
		
		string[iCounter] = string[iCounter] + 32;
	}

	string[iCounter] = '\0';
	
	return string;
}
