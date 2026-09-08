#include <stdio.h>

int mystrncmpi(const char *, const char *, int );

int main(void)
{
	char string1[20];
	char string2[20];
	int iNo;
	int iResult;
	
	printf("\nEnter string1: ");
	gets(string1);
	printf("\nEnter string2: ");
	gets(string2);
	printf("\nEnter iNo: ");
	scanf("%d", &iNo);
	
	iResult = mystrncmpi(string1, string2, iNo);
	
	if(iResult == 0)
		printf("Both string are same.\n");
	else
		printf("Both strings are different.\n");
		
	return 0;
}

int mystrncmpi(const char *string1, const char *string2, int iNo)
{
	int iCounter = 0;
	
	while(string1[iCounter] != '\0')
	{
		if(string1[iCounter]-string2[iCounter] == 32 || string2[iCounter]-string1[iCounter] == 32 || (string1[iCounter] == 32 && string2[iCounter] == 32) || string1[iCounter] == string2[iCounter])
		{
			if(iCounter == iNo-1)
				break;
				
			iCounter++;
			continue;
		}
		return -1;
	}
	return 0;
}
