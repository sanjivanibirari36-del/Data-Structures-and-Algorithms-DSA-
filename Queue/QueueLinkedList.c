#include <stdio.h>
#include <malloc.h>
#define MAX 5

struct node 
{
	int iData;
	struct node *pNext;
};

void EnQueue(struct node **, int);
int DeQueue(struct node **);
int IsQueueFull(struct node *);
int IsQueueEmpty(struct node *);
void Display(struct node *);
int CountNodes(struct node *);
void DeleteAll(struct node **);

int main(void)
{
	int iDel;
	int iNo;
	int iChoice = 0;
	struct node *pQueue = NULL;
	
	while(iChoice != 6)
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.IsQueueFull\n4.IsQueueEmpty\n5.Count\n6.Exit\n");
		printf("Enter your choice:");
		scanf("%d", &iChoice);
		
		switch(iChoice)
		{
			case 1:
			{
				if(IsQueueFull(pQueue))
				{
					printf("Queue is full!\n");
					break;
				}
				printf("Enter the data: ");
				scanf("%d", &iNo);
				EnQueue(&pQueue, iNo);
				Display(pQueue);
			}
			break;
			
			case 2:
			{
				if(IsQueueEmpty(pQueue))
				{
					printf("Queue is empty!\n");
					break;
				}
				iDel = DeQueue(&pQueue);
				printf("Deleted data is %d\n", iDel);
				Display(pQueue);
			}
			break;
			
			case 3:
			{
				if(IsQueueFull(pQueue))
					printf("Queue is full!\n");
				else
					printf("Queue is not full\n");
			}
			break;
			
			case 4:
			{
				if(IsQueueEmpty(pQueue))
					printf("Queue is empty!\n");
				else
					printf("Queue is not empty\n");
			}
			break;
			
			case 5:
			{
				iDel = CountNodes(pQueue);
				printf("Total number of nodes in queue are: %d\n", iDel);
			}
			break;
			
			case 6:
			{
				DeleteAll(&pQueue);
				Display(pQueue);
			}
		}
	}
	return 0;
}					
				
void EnQueue(struct node **ppHead, int iNo)
{
	struct node *pNewNode = NULL;
	struct node *pTemp = NULL;
	
	if(IsQueueFull(*ppHead))
	{
		printf("Queue is full!\n");
		return;
	}
	
	pNewNode = (struct node *)malloc(sizeof(struct node));
	if(pNewNode == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}
	
	pNewNode->iData = iNo;
	pNewNode->pNext = NULL;
	if(*ppHead == NULL)
	{
		*ppHead = pNewNode;
		return;
	}
	
	pTemp = *ppHead; 
	while(pTemp->pNext != NULL)
		pTemp = pTemp->pNext;
		
	pTemp->pNext = pNewNode;
	pTemp = NULL;
}			

int DeQueue(struct node **ppHead)
{
	int iDel;
	struct node *pTemp = NULL;
	
	if(IsQueueEmpty(*ppHead))
	{
		printf("Queue is empty!\n");
		return;
	}
	
	pTemp = *ppHead;
	*ppHead = pTemp->pNext;
	
	iDel = pTemp->iData;
	pTemp->pNext = NULL;
	free(pTemp);
	
	return iDel;
}

int IsQueueFull(struct node *pHead)
{
	if(MAX == CountNodes(pHead))
		return 1;
	return 0;
}

int IsQueueEmpty(struct node *pHead)
{
	if(NULL == pHead)
		return 1;
	return 0;
}

void Display(struct node *pHead)
{
	if(NULL == pHead)
	{
		printf("Queue is empty!\n");
		return;
	}
	
	while(pHead != NULL)
	{
		printf("|%d|->", pHead->iData);
		pHead = pHead->pNext;
	}
	printf("\n");
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


