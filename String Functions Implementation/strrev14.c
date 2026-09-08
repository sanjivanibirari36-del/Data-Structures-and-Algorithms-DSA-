#include <stdio.h>

char * mystrrev(char *);

int main(void)
{
	char string[20];
	
	printf("\nEnter string: ");
	gets(string);
	
	mystrrev(string);
	
	printf("\nReverse string is: ");
	puts(string);
	
	return 0;
}

char * mystrrev(char *string)
{
	int iFront;
	int iRear = 0;
	
	while(string[iRear+1] != '\0')
		iRear++;
		
	for(iFront = 0; iFront < iRear; iFront++)
	{
		string[iRear] = string[iFront] + string[iRear];
		string[iFront] = string[iRear] - string[iFront];
		string[iRear] = string[iRear] - string[iFront];
		iRear--;
	}
	
	return string;
}
