#include<stdio.h>
#include<malloc.h>
#define MAX 5

struct node
{
	int iData;
	struct node *pNext;
};

void Push(struct node **, int);
int Pop(struct node **);
int IsFull(struct node *);
int IsEmpty(struct node *);
void Display(struct node *);
int CountNodes(struct node *);
void DeleteAll(struct node **);

int main(void)
{
	int iDel;
	int iChoice = 0;
	int iNo;
	struct node *pStack = NULL;
	
	while(iChoice != 6)
	{
		printf("\n1.Push\n2.Pop\n3.IsFull\n4.IsEmpty\n5.Count\n6.Exit\n");
		printf("Enter your choice:\t");
		scanf("%d", &iChoice);
		
		switch(iChoice)
		{
			case 1:
			{
				if(IsFull(pStack))
				{
					printf("Stack is full!\n");
					break;
				}
				printf("Enter the data:\t");
				scanf("%d", &iNo);
				Push(&pStack, iNo);
				Display(pStack);
			}
			break;
			
			case 2:
			{
				if(IsEmpty(pStack))
				{
					printf("Stack is empty!\n");
					break;
				}
				iDel = Pop(&pStack);
				printf("Popped data is %d\n", iDel);
				Display(pStack);
			}
			break;
			
			case 3:
			{
				if(IsFull(pStack))
					printf("Stack is full!\n");
				else
					printf("Stack is not full\n");
			}
			break;
			
			case 4:
			{
				if(IsEmpty(pStack))
					printf("Stack is empty!\n");
				else
					printf("Stack is not empty\n");
			}
			break;
			
			case 5:
			{
				iDel = CountNodes(pStack);
				printf("Total nodes in stack are: %d\n", iDel);
			}
			break;
			
			case 6:
			{
				if(pStack != NULL)
					DeleteAll(&pStack);
				printf("Stack is empty.\n");
			}
		}
	}
	return 0;
}
				
				
void Push(struct node **ppHead, int iNo)
{
	struct node *pNewNode = NULL;
	
	pNewNode = (struct node *)malloc(sizeof(struct node));
	if(pNewNode == NULL)
	{
		printf("Memory allocation failed!");
		return;
	}
	
	pNewNode->iData = iNo;
	
	if(NULL == *ppHead)
	{
		pNewNode->pNext = NULL;
		*ppHead = pNewNode;
		return;
	}
	
	pNewNode->pNext = *ppHead;
	*ppHead = pNewNode;
}

int Pop(struct node **ppHead)
{
	int iDelData;
	struct node *pTemp = NULL;
	
	pTemp = *ppHead;
	*ppHead = pTemp->pNext;
	iDelData = pTemp->iData;
	pTemp->pNext = NULL;
	free(pTemp);
	pTemp = NULL; 
	
	return iDelData;
}

int IsFull(struct node *pHead)
{
	if(MAX == CountNodes(pHead))
		return 1;
	return 0;
}

int IsEmpty(struct node *pHead)
{
	if(NULL == pHead)
		return 1;
	return 0;
}

int CountNodes(struct node *pHead)
{
	int iCount = 0;
	while(pHead != NULL)
	{
		iCount++;
		pHead = pHead->pNext;
	}
	
	return iCount;
}

void Display(struct node *pHead)
{
	if(NULL == pHead)
	{
		printf("Stack is empty!\n");
		return;
	}
	
	while(pHead != NULL)
	{
		printf("|%d|->", pHead->iData);
		pHead = pHead->pNext;
	}
	printf("\n");
}

void DeleteAll(struct node **ppHead)
{
	struct node *pTemp = NULL;
	
	while(*ppHead != NULL)
	{
		pTemp = *ppHead;
		*ppHead = pTemp->pNext;
		pTemp->pNext = NULL;
		free(pTemp);
	}
	pTemp = NULL;
}
				
