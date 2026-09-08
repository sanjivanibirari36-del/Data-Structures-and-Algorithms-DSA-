#include <stdio.h>
#include <malloc.h>
#define MAX 10

struct node
{
	struct node *pLeft;
	int iData;
	struct node *pRight;
};

struct queue
{
	struct node *pNode;
	struct queue *pNext;
};

void InsertInTree(struct node **, int);
int DeleteFromTree(struct node**, int);
void DeleteAll(struct node**);
void Display(const int *);
void BFS(struct node *);
int CountNodes(struct node *);
void DisplayPreOrder(struct node *);
void Enqueue(struct queue **, struct node *);
struct node * Dequeue(struct queue **);
int IsFull(struct queue *);
int IsEmpty(struct queue *);
int iQCount(struct queue *);
void DeleteAllQueue(struct queue **);


int main(void)
{
	int iChoice;
	int iDel;
	int iNo;
	struct node *pRoot = NULL;
	
	while(iChoice != 7)
	{
		printf("\n\n1.Insert In Tree\n2.Delete From Tree\n3.BFS Traversal\n4.Count\n5.Height of Tree\n6.Display(pre-order)\n7.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &iChoice);
		
		switch(iChoice)
		{
			case 1:
			{
				printf("Enter the data: ");
				scanf("%d", &iNo);
				
				InsertInTree(&pRoot, iNo);
			}
			break;
			
			case 2:
			{
				printf("Enter the data you want to delete: ");
				scanf("%d", &iNo);
				
				iDel = DeleteFromTree(&pRoot, iNo);
				printf("Deleted data is %d\n", iDel);
			}
			break;
			
			case 3:
			{
				BFS(pRoot);
			}
			break;
			
			case 4:
			{
				iDel = CountNodes(pRoot);
				printf("Total nodes in tree are: %d\n", iDel);
			}
			break;
			
			case 5:
			{
				iDel = Height(pRoot);
				printf("Height of the tree is: %d\n", iDel);
			}
			break;
			
			case 6:
			{
				DisplayPreOrder(pRoot);
			}
			break;
			
			case 7:
			{
				DeleteAll(&pRoot);
				if(pRoot == NULL)
					printf("Tree is empty!\n");
			}
		}
	}
	return 0;
}

void InsertInTree(struct node **ppRoot, int iNo)
{
	struct node *pPtr = NULL;
	struct node *pParent = NULL;

	pPtr = *ppRoot;
	
	while(pPtr != NULL)
	{
		pParent = pPtr;
		
		if(iNo < pPtr->iData)
			pPtr = pPtr->pLeft;
			
		else if(iNo > pPtr->iData)
			pPtr = pPtr->pRight;
			
		else
		{
			printf("Duplicate data\n");
			return;
		}
	}
	
	pPtr = (struct node *)malloc(sizeof(struct node));
	if(pPtr == NULL)
	{
		printf("Memory allocation failed!\n");
		return;
	}
	
	pPtr->iData = iNo;
	pPtr->pLeft = pPtr->pRight = NULL;
	
	if(pParent == NULL)
		*ppRoot = pPtr;
	
	else if(iNo < pParent->iData)
		pParent->pLeft = pPtr;
		
	else
		pParent->pRight = pPtr;
}

int CountNodes(struct node *pRoot)
{
	static int iCount = 0;
	
	if(pRoot != NULL)
	{
		iCount++;
		CountNodes(pRoot->pLeft);
		CountNodes(pRoot->pRight);
	}
		return iCount;
}

int Height(struct node *pRoot)
{
	int iLeftHeight;
	int iRightHeight;
	
	if(pRoot == NULL)
		return 0;
		
	iLeftHeight = Height(pRoot->pLeft);
	iRightHeight = Height(pRoot->pRight);
	
	if(iLeftHeight > iRightHeight)
		return 1 + iLeftHeight;
		
	else
		return 1 + iRightHeight;
}

void DisplayPreOrder(struct node *pRoot)
{
	if(pRoot == NULL)
		return;
		
	printf("%d\t", pRoot->iData);
	DisplayPreOrder(pRoot->pLeft);
	DisplayPreOrder(pRoot->pRight);
}	

void BFS(struct node *pRoot)
{
	int iNo;
	struct node *pTemp = pRoot;
	struct node *pTemp2 = NULL;
	struct queue *pQueue = NULL;
	
	if(pRoot == NULL)
		return;
		
	Enqueue(&pQueue, pRoot);
	
	while(!IsEmpty(pQueue))
	{
		pTemp2 = Dequeue(&pQueue);
		printf("%d\t", pTemp2->iData);
		
		pRoot = pTemp;
		while(pRoot->iData != pTemp2->iData)
		{
			if(pTemp2->iData < pRoot->iData)
				pRoot = pRoot->pLeft;
			else
				pRoot = pRoot->pRight;
		}
		
		if(pRoot->pLeft	!= NULL)
			Enqueue(&pQueue, pRoot->pLeft);
			
		if(pRoot->pRight != NULL)
			Enqueue(&pQueue, pRoot->pRight);		
  }
  DeleteAllQueue(&pQueue);
}
	

int DeleteFromTree(struct node **ppRoot, int iNo)
{
	struct node *pPtr = NULL;
	struct node *pParent = NULL;
	struct node *pSuccessor = NULL;
	struct node *pParentSuccessor = NULL;
	struct node *pChild = NULL;
	int iDel;
	
	pPtr = *ppRoot;
	
	while(pPtr != NULL)
	{
		if(iNo == pPtr->iData)
			break;
		
		pParent = pPtr;
		if(iNo > pPtr->iData)
			pPtr = pPtr->pRight;
			
		else
			pPtr = pPtr->pLeft;
	}
	
	if(NULL == pPtr)
		return;
		
	iDel = pPtr->iData;
		
	if((pPtr->pLeft != NULL) && (pPtr->pRight != NULL))
	{
		pParentSuccessor = pPtr;
		pSuccessor = pPtr->pRight;
		
		while(pSuccessor->pLeft != NULL)
		{
			pParentSuccessor = pSuccessor;
			pSuccessor = pSuccessor->pLeft;
		}
		
		pPtr->iData = pSuccessor->iData;
		
		pPtr = pSuccessor;
		pParent = pParentSuccessor;
	}
	
	if(pPtr->pLeft != NULL)
		pChild = pPtr->pLeft;
	else
		pChild = pPtr->pRight;
		
	if(NULL == pParent)
		*ppRoot = pChild;
	else if(pPtr == pParent->pLeft)
		pParent->pLeft = pChild;
	else
		pParent->pRight = pChild;
		
	free(pPtr);
	pPtr = NULL;
	
	return iDel;
}

void DeleteAll(struct node **ppRoot)
{
	if(NULL == *ppRoot)
		return;
		
	DeleteAll(&((*ppRoot)->pLeft));
	DeleteAll(&((*ppRoot)->pRight));
	(*ppRoot)->pLeft = (*ppRoot)->pRight = NULL;
	free(*ppRoot);
	*ppRoot = NULL;
}

void Enqueue(struct queue **ppHead, struct node *pTemp)
{
	struct queue *pPtr = NULL;
	struct queue *pNewNode = NULL;
	
	if(IsFull(*ppHead))
	{
		printf("Queue is full!\n");
		return;
	}
	
	pNewNode = (struct queue *)malloc(sizeof(struct queue));
	if(pNewNode == NULL)
	{
		printf("Memory allocation failed!\n");
		return;
	}
	
	pNewNode->pNode = pTemp;
	pNewNode->pNext = NULL;
	
	if(*ppHead == NULL)
	{
		*ppHead = pNewNode;
		return;
	}
	
	pPtr = *ppHead;
	while(pPtr->pNext != NULL)
		pPtr = pPtr->pNext;
		
	pPtr->pNext = pNewNode;
	pNewNode = NULL;
}

struct node * Dequeue(struct queue **ppHead)
{
	struct queue *pTemp1 = NULL;
	struct node *pTemp2 = NULL;

	if(IsEmpty(*ppHead))
	{
		printf("Queue is empty!\n");
		return NULL;
	}
	pTemp2 = (*ppHead)->pNode;
	
	pTemp1 = *ppHead;
	*ppHead = pTemp1->pNext;
	
	pTemp1->pNext = NULL;
	free(pTemp1);
	pTemp1 = NULL;
	
	return pTemp2;
}
	
int IsFull(struct queue *pHead)
{
	if(MAX == QCount(pHead))
		return 1;
		
	return 0;
}

int IsEmpty(struct queue *pHead)
{
	if(pHead == NULL)
		return 1;
		
	return 0;
}

int QCount(struct queue *pHead)
{
	static int iCount = 0;
	
	while(pHead != NULL)
	{
		iCount++;
		pHead = pHead->pNext;
	}
	
	return iCount;
}

void DeleteAllQueue(struct queue **ppHead)
{
	struct queue *pTemp = NULL;
	
	while(*ppHead != NULL)
	{
		pTemp = *ppHead;
		*ppHead = (*ppHead)->pNext;
		pTemp->pNode = NULL;
		pTemp->pNext = NULL;
		free(pTemp);
	}
	
	pTemp = NULL;
}
