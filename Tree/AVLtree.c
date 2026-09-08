#include <stdio.h>
#include <malloc.h>

struct node
{
	struct node *pLeft;
	int iData;
	struct node *pRight;
	struct node *pParent;
};

struct node * InsertInTree(struct node **, int);
struct node * Pivot(struct node *, int *, int *, int *);
void Right(struct node **, struct node *, int *);
void Left(struct node **, struct node *, int *);
void RightLeft(struct node **, struct node *, int *, int *);
void LeftRight(struct node **, struct node *, int *, int *);
void DisplayPreOrder(struct node *);
void DeleteAll(struct node **);

int main(void)
{
	struct node *pRoot = NULL;
	struct node *pTemp1 = NULL;
	struct node *pTemp2 = NULL;
	int iBalFactor;
	int iDel;
	int iChoice;
	int iNo;
	int iFlagL;
	int iFlagR;
	
	while(iChoice != 3)
	{
		printf("\n\n1.Insert in tree\n2.Display(PreOrder)\n3.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &iChoice);
		
		switch(iChoice)
		{
			case 1:
			{
				printf("Enter the data: ");
				scanf("%d", &iNo);
				
				pTemp1 = InsertInTree(&pRoot, iNo);
				pTemp2 = Pivot(pTemp1, &iBalFactor, &iFlagL, &iFlagR);

				if(pTemp2 == NULL)
					printf("Tree is balanced!");
				
				else
				{
					if(iBalFactor > 1) //R
					{
						if(iFlagL == 1)
							LeftRight(&pRoot, pTemp2, &iFlagL, &iFlagR);							
						else
							Right(&pRoot, pTemp2, &iFlagR);
					}
					
					else							//L
					{
						if(iFlagR == 1)
							RightLeft(&pRoot, pTemp2, &iFlagL, &iFlagR);
						
						else
							Left(&pRoot, pTemp2, &iFlagL);
					}
				}
			}
			break;
			
			case 2:
			{
				DisplayPreOrder(pRoot);
			}
			break;
			
			case 3:
			{
				DeleteAll(&pRoot);
				
				if(pRoot == NULL)
					printf("Tree is empty!\n");
				else
					printf("Tree is not empty!\n");
			}
		}
	}
	
	return 0;
}

struct node * InsertInTree(struct node **ppRoot, int iNo)
{
	struct node *pPtr = NULL;
	struct node *pParent = NULL;
	
	pPtr= *ppRoot;
	
	while(pPtr != NULL)
	{
		pParent = pPtr;
		
		if(iNo < pPtr->iData)
			pPtr = pPtr->pLeft;
		else if(iNo > pPtr->iData)
			pPtr = pPtr->pRight;
		else
		{
			printf("Duplicate data");
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
	pPtr->pParent = pParent;
	
	if(pParent == NULL)
	{
		*ppRoot = pPtr;
		return pPtr;
	}
	else if(iNo < pParent->iData)
		pParent->pLeft = pPtr;
	else
		pParent->pRight = pPtr;
		
	return pPtr;
}

struct node * Pivot(struct node *pNewNode, int *iBalFactor, int *pFlagL, int *pFlagR)
{
	int iLeftHeight;
	int iRightHeight;
	int iNo = pNewNode->iData;
	
	while(pNewNode != NULL)
	{
		iLeftHeight = Height(pNewNode->pLeft);
		iRightHeight = Height(pNewNode->pRight);
		
		*iBalFactor = iLeftHeight - iRightHeight;

		if(*iBalFactor < -1 || *iBalFactor > 1)
		{
			if(*iBalFactor > 1)
			{
				if(iNo < pNewNode->pLeft->iData)
					*pFlagL = 0;	
				else
					*pFlagL = 1;
					
				*pFlagR = 0;
			}
			else
			{
				if(iNo < pNewNode->pRight->iData)
					*pFlagR = 1;
				else
					*pFlagR = 0;
					
				*pFlagL = 0;
			}
			break;
		}
		pNewNode = pNewNode->pParent;
	}
	return pNewNode;
}

void Left(struct node **ppRoot, struct node *pTemp, int *pFlagL)
{
	if(*pFlagL == 1)														//don rotation
	{  
		pTemp->pParent->pLeft = pTemp->pRight;
		*pFlagL = 0;
	}
	else if(pTemp != (*ppRoot))								//normal left rotation
		pTemp->pParent->pRight = pTemp->pRight;
	
	else//((*ppRoot) == pTemp)
		(*ppRoot) = pTemp->pRight;							// root ahe
	
	pTemp->pRight->pParent = pTemp->pParent;
	pTemp->pParent = pTemp->pRight;
	
	if(pTemp->pRight->pLeft != NULL)
	{
		pTemp->pRight = pTemp->pParent->pLeft;
		pTemp->pRight->pParent = pTemp;
	}
	else
		pTemp->pRight = NULL;
		
	pTemp->pParent->pLeft = pTemp;
}		
					
void Right(struct node **ppRoot, struct node *pTemp, int *pFlagR)
{
	if(*pFlagR == 1)
	{
		pTemp->pParent->pRight = pTemp->pLeft;
		*pFlagR = 0;
	}
	else if(pTemp != (*ppRoot))
		pTemp->pParent->pLeft = pTemp->pLeft;
	
	else//((*ppRoot) == pTemp) 
		(*ppRoot) = pTemp->pLeft;
		
	pTemp->pLeft->pParent = pTemp->pParent;
	pTemp->pParent = pTemp->pLeft;
	
	if(pTemp->pLeft->pRight != NULL)
	{
		pTemp->pLeft = pTemp->pParent->pRight;
		pTemp->pLeft->pParent = pTemp;
	}
	
	else
		pTemp->pLeft = NULL;
		
	pTemp->pParent->pRight = pTemp;
}	

void RightLeft(struct node **ppRoot, struct node *pTemp, int *pFlagL, int *pFlagR)
{
	Right(ppRoot, pTemp->pRight, pFlagR);
	Left(ppRoot, pTemp, pFlagL);
}

void LeftRight(struct node **ppRoot, struct node *pTemp, int *pFlagL, int *pFlagR)
{
	Left(ppRoot, pTemp->pLeft, pFlagL);
	Right(ppRoot, pTemp, pFlagR);
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
