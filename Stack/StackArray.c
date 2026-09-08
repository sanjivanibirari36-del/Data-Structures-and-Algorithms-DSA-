#include <stdio.h>

#define MAX 5

void Push(int *, int *, int);
int Pop(int *, int *);
int IsFull(int);
int IsEmpty(int);
void Display(const int *, int);

int main(void)
{
	int iNo;
	int iRet;
	int iTop = -1;
	int iChoice = 0;
	int arrStack[MAX] = {0};
	
	while(iChoice != 5)
	{
		printf("\n1.Push\n2.Pop\n3.IsFull\n4.IsEmpty\n5.Exit\n");
		printf("Enter your choice:\t");
		scanf("%d", &iChoice);
		
		switch(iChoice)
		{
			case 1:
			{
				if(IsFull(iTop))
				{
					printf("Stack is full!\n");
					break;
				}
				
				printf("Enter the data:\t");
				scanf("%d", &iNo);
				Push(arrStack, &iTop, iNo);
				Display(arrStack, iTop);
			}
			break;
			
			case 2:
			{ 
				if(IsEmpty(iTop))
				{
					printf("Stack is empty!\n");
					break;
				}
				iRet = Pop(arrStack, &iTop);
				printf("Popped data is: %d\n", iRet);
				Display(arrStack, iTop);
			}
			break;
			
			case 3:
			{
				if(IsFull(iTop))
					printf("Stack is full!\n");
				else
					printf("Stack is not full\n");
			}
			break;
			
			case 4:
			{
				if(IsEmpty(iTop))
					printf("Stack is empty!\n");
				else
					printf("Stack is not empty\n");
			}
			break;
			
			case 5:
			{
				break;
			}
		}
	}
	return 0;
}				
			
void Push(int *pStack, int *pTop, int iNo)
{	
	if(IsFull(*pTop))
	{
		printf("Stack is full!\n");
		return;
	}
	
	pStack[++(*pTop)] = iNo;
	
	return;
}

int Pop(int *pStack, int *pTop)
{	
	int iDel;
	if(IsEmpty(*pTop))
	{
		printf("Stack is empty!\n");
		return;
	}
	
	iDel = pStack[(*pTop)--];
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

void Display(const int *pStack, int iTop)
{
	int iCounter;
	if(iTop == -1)
	{
		printf("Stack is empty!\n");
		return;
	}
	
	for(iCounter = 0; iCounter <= iTop; iCounter++)
	{
		printf("%d\t", pStack[iCounter]);
	}
}		
