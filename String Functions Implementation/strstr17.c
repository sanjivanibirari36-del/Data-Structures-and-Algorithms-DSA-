#include <stdio.h>

char * mystrstr(const char *, const char *);

int main(void)
{
	char string[20];
	char substring[20];
	char *ptr = NULL;
	
	printf("\nEnter string: ");
	gets(string);
	printf("\nEnter the sub string to be found: ");
	gets(substring);
	
	ptr = mystrstr(string, substring);
	if(ptr == NULL)
		printf("\nString not found!\n\n");
	else
	{
		printf("\nString found at %d position.\n", (ptr-string)+1);
		printf("String found in: '%s'\n\n", ptr);
	}
	
	return 0;
}

char * mystrstr(const char *string, const char *substring) 
{
	char *ptr1 = string;
	char *ptr2 = NULL;
	int iCounter1 = 0;
	int iCounter2 = 0;
	

	while((*ptr1) != '\0')
	{
		if(substring[iCounter2] == '\0')
			return ptr2;
		
		if((*ptr1) == substring[iCounter2])
		{	
			if(iCounter2 == 0)
				ptr2 = ptr1;
				
			ptr1++;
			iCounter2++;
			continue;
		}
		if(iCounter2 > 0)
		{
			iCounter2 = 0;
			continue;
		}
		
		ptr1++;
	}
	ptr2 = NULL;
	return ptr2;
}
