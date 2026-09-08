#include <stdio.h>

int mystrcmp(const char *, const char *);

int main(void)
{
	char string1[20];
	char string2[20];
	int iResult;
	
	printf("Enter string1: ");
	gets(string1);
	
	printf("Enter string2: ");
	gets(string2);
	
	iResult = mystrcmp(string1, string2);
	
	if(iResult == 0)
		printf("Given strings are same.\n");
	else
		printf("Given strings are different.\n");	
	
	return 0;
}

int mystrcmp(const char *string1, const char *string2)
{
	int iCounter;
	
	for(iCounter = 0; string1[iCounter] == string2[iCounter]; iCounter++)
	{
		if(string1[iCounter] == '\0')
		return 0;
	} 
	
	return -1;
}
