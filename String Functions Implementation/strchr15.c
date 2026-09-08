#include <stdio.h>

char * mystrchr(const char *, char);

int main(void)
{
	char string[20];
	char ch;
	char *ptr = NULL;
	
	printf("Enter string: ");
	gets(string);
	printf("Enter the character to be found: ");
	scanf("%c", &ch);
	
	ptr = mystrchr(string, ch);
	if(ptr == NULL)
		printf("Character not found!\n");
	else
		printf("Character found at %d position\n", (ptr-string)+1);
	
	return 0;
}

char * mystrchr(const char *string, char ch)
{
	char *ptr = string;
	
	while((*ptr) != '\0')
	{
		if((*ptr) == ch)
			return ptr;
			
		ptr++;
	}
	
	ptr = NULL;
	return ptr;
}	
