#include <stdio.h>

int mystrcmpi(const char *, const char *);

int main(void)
{
	char string1[20];
	char string2[20];
	int iResult;
	
	printf("\nEnter string1: ");
	gets(string1);
	printf("\nEnter string2: ");
	gets(string2);
	
	iResult = mystrcmpi(string1, string2);
	
	if(iResult == 0)
		printf("Both strings are same\n");
	else
		printf("Both strings are different\n");
		
	return 0;
}

int mystrcmpi(const char *string1, const char *string2)
{
	int iCounter = 0;
	
	while(string1[iCounter] != '\0')
	{
		if((string1[iCounter] - string2[iCounter]) == 32 || (string2[iCounter]-string1[iCounter]) == 32 || string1[iCounter] == 32 || string2[iCounter] == 32 || string1[iCounter] == string2[iCounter])
		{
			iCounter++;
			continue;
		}
		return -1;
	}
	return 0;
}
