#include <stdio.h>

int mystrlen(const char *);

int main(void)
{
	char *pChar = "Hello";
	char str[] = "Good";
	
	printf("\nThe length of Hello is: %d\n", mystrlen(pChar));
	printf("\nThe length of Good is: %d\n", mystrlen(str));
	printf("\nThe length of Morning is: %d\n", mystrlen("Morning"));

	return 0;
}

int mystrlen(const char *pPtr)
{
	int iCount = 0;
	int iCounter;
	
	for(iCounter = 0; pPtr[iCounter] != '\0'; iCounter++)
		iCount++;
		
	return iCount;
}
	
