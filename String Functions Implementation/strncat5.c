#include <stdio.h>

char * mystrncat(char *, const char *, int);

int main(void)
{
	char source[20];
	char destination[40];
	int iNo;
	
	printf("\nEnter destination string: ");
	gets(destination);
	
	printf("\nEnter source string: ");
	gets(source);
	
	printf("\nEnter the n value: ");
	scanf("%d", &iNo);
	
	mystrncat(destination, source, iNo);
	
	printf("\nConcatenated string is: ");
	puts(destination);
	
	return 0;
}

char * mystrncat(char *destination, const char *source, int iNo)
{
	int iCounter1;
	int iCounter2;
	
	for(iCounter1 = 0; destination[iCounter1] != '\0';)
		iCounter1++;
	
	for(iCounter2 = 0; source[iCounter2] == '\0' || iCounter2 < iNo;	iCounter2++)
	{
		destination[iCounter1] = source[iCounter2];
		iCounter1++;
	}
	destination[iCounter1] = '\0';
	
	return destination;
} 	
