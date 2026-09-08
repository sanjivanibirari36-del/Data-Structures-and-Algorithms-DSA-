#include <stdio.h>

char * mystrupr(char *);

int main(void)
{
	char string[20];
	
	printf("\nEnter string: ");
	gets(string);
	
	mystrupr(string);
	
	printf("\nString in upper case is: ");
	puts(string);
	
	return 0;
}

char * mystrupr(char *string)
{
	int iCounter;
	
	for(iCounter = 0; string[iCounter] != '\0'; iCounter++)
	{
		if(string[iCounter] <= 97 || string[iCounter] >= 123)
			continue;
	
		string[iCounter] = string[iCounter] - 32;
	}
		
	string[iCounter] = '\0';
	return string;
}
