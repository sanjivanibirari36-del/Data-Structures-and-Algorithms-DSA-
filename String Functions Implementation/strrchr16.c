#include <stdio.h>

char * mystrrchr(const char *, char);

int main(void)
{
	char string[20];
	char ch;
	char *ptr = NULL;
	
	printf("Enter string: ");
	gets(string);
	printf("Enter the character to be found: ");
	scanf("%c", &ch);
	
	ptr = mystrrchr(string, ch);
	
	if(ptr == NULL)
		printf("Character not found!\n");
	else
		printf("Character found at %d position.\n", (ptr-string)+1);	
		
	return 0;
}

char * mystrrchr(const char *string, char ch)
{
	char *ptr1 = string;
	char *ptr2 = NULL;
	int iCounter;
	
	while((*ptr1) != '\0')
	{	
		if((*ptr1) == ch)
			ptr2 = ptr1;
			
		ptr1++;
	}
	
	return ptr2;
}
