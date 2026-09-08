#include <stdio.h>

int mystrncmp(const char *, const char *, int);

int main(void)
{
	char string1[20];
	char string2[20];
	int iNo;
	int iResult;
	
	printf("Enter string1: ");
	gets(string1);
	
	printf("Enter string2: ");
	gets(string2);
	
	printf("Enter n: ");
	scanf("%d", &iNo);
	
	iResult = mystrncmp(string1, string2, iNo);
	
	if(iResult == 0)
		printf("Given strings are same\n");
	else
		printf("Given strings are different\n");
		
	return 0;
}

int mystrncmp(const char *string1, const char *string2, int iNo)
{
	int iCounter = 0;
	
	for(iCounter = 0; string1[iCounter] == string2[iCounter]; iCounter++)
	{
		if(string1[iCounter] == '\0' || iCounter == iNo-1)
			return 0;
	}
	return -1;
}
			


