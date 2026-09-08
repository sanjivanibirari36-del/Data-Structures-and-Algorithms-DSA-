#include<stdio.h>

#define MAX 20

void Push(char *, int *, char);
char Pop(char *, int *);
int IsFull(int);
int IsEmpty(int);

int main(void)
{
	char brack[MAX];
	char str[MAX];
	int iTop = -1;
	int iCounter1;
	
	printf("Enter the string:\n");
	scanf("%s", str);
	
	for(iCounter1 = 0; iCounter1 <= MAX-1; iCounter1++)
	{
		if(str[iCounter1] == '(' || str[iCounter1] == '{' || str[iCounter1] == '[')
			Push(brack, &iTop, str[iCounter1]);
			
		if((str[iCounter1] == ')' && str[iTop]=='(') || (str[iCounter1]=='}' && str[iTop]=='{') || (str[iCounter1]==']' && str[iTop]=='['))
			Pop(brack, &iTop);
	}
	
	if(IsEmpty(iTop))
		printf("String is valid!\n");
	else
		printf("String is invalid.\n");

	return 0;
}

void Push(char *brack,int *pTop, char cBrack)
{
	if(IsFull(*pTop))
	{
		printf("Stack is full!\n");
		return;
	}
	
	brack[++(*pTop)] = cBrack;
}

char Pop(char *brack, int *pTop)
{
	char iDel;
	if(IsEmpty(*pTop))
	{
		printf("Stack is empty!\n");
		return -1;
	}
	
	iDel = brack[(*pTop)--];
	return iDel;
}

int IsFull(int iTop)
{
	if(iTop == MAX-1)
		return 1;
	return 0;
}

int IsEmpty(int iTop)
{
	if(iTop == -1)
		return 1;
	return 0;
}
