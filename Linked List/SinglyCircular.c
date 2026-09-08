#include <stdio.h>
#include <malloc.h>

struct node
{
 int iData;
 struct node *pNext;
};

void InsertFirst(struct node **, struct node **, int);
void InsertLast(struct node **, struct node **, int);
void InsertAtPosition(struct node **, struct node **, int, int);
int DeleteFirst(struct node **, struct node **);
int DeleteLast(struct node **, struct node **);
int DeleteAtPosition(struct node **, struct node **, int);
int SearchFirstOccurrence(struct node *, struct node *, int);
int SearchLastOccurrence(struct node *, struct node *, int);
int SearchAllOccurrences(struct node *, struct node *, int);
void Display(struct node *, struct node *);
int CountNodes(struct node *, struct node *);
void ConcatList(struct node **, struct node **, struct node **, struct node **);
void ConcatAtPosition(struct node **, struct node **, struct node **, struct node **, int);
void ReverseDisplay(struct node *, struct node *);
void PhysicalReverse(struct node **, struct node **);
void DeleteAll(struct node **, struct node **);

int main(void)
{
 struct node *pFirst1 = NULL;
 struct node *pLast1 = NULL;
 struct node *pFirst2 = NULL;
 struct node *pLast2 = NULL;
 int iChoice = 0; 
 int iNo;
 int iPos;
 int iCount;
 int iDelData;

 while(iChoice != 7)
 {
 printf("\n1.Insert\n2.Delete\n3.Search\n4.Count\n5.Concat\n6.Reverse\n7.Exit\n");
 printf("Enter your choice:\t");
 scanf("%d", &iChoice);

 switch(iChoice)
 {
 case 1:
 {
 while(iChoice != 4)
 {
  printf("1.Insert First\n2.Insert Last\n3.Insert At Position\n4.Back\n");
  printf("Enter your choice:\t");
  scanf("%d", &iChoice);

  switch(iChoice)
  {
case 1:
  {
   printf("Enter the data:\t");
   scanf("%d", &iNo);
   
   InsertFirst(&pFirst1, &pLast1, iNo);
	 Display(pFirst1, pLast1);		
  }
  break;
 
  case 2:
  {
   printf("Enter the data:\t");
   scanf("%d", &iNo);

   InsertLast(&pFirst1, &pLast1, iNo);
   Display(pFirst1, pLast1);
  }
  break;

  case 3:
  {
   printf("Enter the position:\t");
   scanf("%d", &iPos);

   iCount = CountNodes(pFirst1, pLast1);
   if(iPos <= 0 || iPos > iCount+1)
   {
    printf("Position invalid\n");
    break;
   }
   printf("Enter the data:\t");
   scanf("%d", &iNo);

   InsertAtPosition(&pFirst1, &pLast1, iPos, iNo);
   Display(pFirst1, pLast1);
  }
  break;

  case 4:
  {
		Display(pFirst1, pLast1);
  }
  }
 }
 }
 break;

 case 2:
 {
 if(pFirst1 == NULL)
 {
  printf("List is empty\n");
  break;
 }
 while(iChoice != 4)
 {
  printf("1.Delete First\n2.Delete Last\n3.Delete At Position\n4.Back\n");
  printf("Enter your choice:\t");
  scanf("%d", &iChoice);
 
  switch(iChoice)
  {
  case 1:
  {
   iDelData = DeleteFirst(&pFirst1, &pLast1);
   printf("Deleted data is %d\n", iDelData);
   Display(pFirst1, pLast1);
  }
  break;

  case 2:
  {
   iDelData = DeleteLast(&pFirst1, &pLast1);
   printf("Deleted data is %d\n", iDelData);
   Display(pFirst1, pLast1);
  }
  break;

  case 3:
  {
   printf("Enter the position:\t");
   scanf("%d", &iPos);
   
   iCount = CountNodes(pFirst1, pLast1);
   if(iPos <= 0 || iPos > iCount)
   {
    printf("Position invalid\n");
    break;
   }
 
   iDelData = DeleteAtPosition(&pFirst1, &pLast1, iPos); 
   printf("Deleted data is %d\n", iDelData);
   Display(pFirst1, pLast1);
  }
  break;

  case 4:
  {
		Display(pFirst1, pLast1);
  }
  }
 }
 }
 break;

 case 3:
 {
  if(pFirst1 == NULL)
  {
   printf("List is empty\n");
   break;
  }
 while(iChoice != 4)
 {
  printf("1.Search First Occurrence\n2.Search Last Occurrence\n3.Search All Occurrences\n4.Back\n");
  printf("Enter your choice:\t");
  scanf("%d", &iChoice);

  switch(iChoice)
  {
  case 1:
  {
   printf("Enter the number to be searched:\t");
   scanf("%d", &iNo);
  
   iPos = SearchFirstOccurrence(pFirst1, pLast1, iNo);
   if(iPos != 0)
    printf("%d first occurred at %d position\n", iNo, iPos);
   else
    printf("Data not found\n");
    
   Display(pFirst1, pLast1);
  }
  break;

  case 2:
  {
   printf("Enter the number to be searched:\t");
   scanf("%d", &iNo);
  
   iPos = SearchLastOccurrence(pFirst1, pLast1, iNo);
   if(iPos != 0)
    printf("%d last occurred at %d position\n", iNo, iPos);
   else
    printf("Data not found\n");
    
   Display(pFirst1, pLast1);
  }
  break;

  case 3:
  {
   printf("Enter the number to be searched:\t");
   scanf("%d", &iNo);

   iPos = SearchAllOccurrences(pFirst1, pLast1, iNo);
   printf("%d found %d times\n", iNo, iPos);
   
   Display(pFirst1, pLast1);
  }
  break;
   
  case 4:
  {
   	Display(pFirst1, pLast1);
  }
  }
 }
 }
 break;

 case 4:
 {
  iCount = CountNodes(pFirst1, pLast1);
  printf("Total nodes are %d\n", iCount);
  Display(pFirst1, pLast1);
 }
 break;

 case 5:
 {
  while(iChoice != 3)
  {
  printf("1.Concat List\n2.Concat At Position\n3.Back\n");
  printf("Enter your choice:\t");
  scanf("%d", &iChoice);

  switch(iChoice)
  {
   case 1:
   {
   while(iChoice != 4)
   {
    printf("1.Insert First\n2.Insert Last\n3.Insert At Position\n4.Back\n");
    printf("Enter your choice:\t");
    scanf("%d", &iChoice);

    switch(iChoice)
    {
     case 1:
     {
      printf("Enter the data:\t");
      scanf("%d", &iNo);
      InsertFirst(&pFirst2, &pLast2, iNo);
      Display(pFirst2, pLast2);
     }
     break;

     case 2:
     {
      printf("Enter the data:\t");
      scanf("%d", &iNo);
      InsertLast(&pFirst2, &pLast2, iNo);
      Display(pFirst2, pLast2);
     }
     break;

     case 3:
     {
      iCount = CountNodes(pFirst2, pLast2);
      printf("Enter the position:\t");
      scanf("%d", &iPos);
    
      if(iPos <= 0 || iPos > iCount+1)
      {
       printf("Position Invalid\n");
       break;
      }

      printf("Enter the data:\t");
      scanf("%d", &iNo);
      InsertAtPosition(&pFirst2, &pLast2, iPos, iNo);
      Display(pFirst2, pLast2);
     }
     break;

     case 4:
     {
      ConcatList(&pFirst1, &pLast1, &pFirst2, &pLast2);
      Display(pFirst1, pLast1);
     }
    }
   }
   }
   break;

   case 2:
   {
    while(iChoice != 4)
   {
    printf("1.Insert First\n2.Insert Last\n3.Insert At Position\n4.Back\n");
    printf("Enter your choice:\t");
    scanf("%d", &iChoice);

    switch(iChoice)
    {
     case 1:
     {
      printf("Enter the data:\t");
      scanf("%d", &iNo);
      InsertFirst(&pFirst2, &pLast2, iNo);
      Display(pFirst2, pLast2);
     }
     break;
    
     case 2:
     {
      printf("Enter the data:\t");
      scanf("%d", &iNo);
      InsertLast(&pFirst2, &pLast2, iNo);
      Display(pFirst2, pLast2);
     }
     break;

     case 3:
     {
      iCount = CountNodes(pFirst2, pLast2);
      printf("Enter the position:\t");
      scanf("%d", &iPos);

      if(iPos <= 0 || iPos > iCount+1)
      {
       printf("Position Invalid\n");
       break;
      }

      printf("Enter the data:\t");
      scanf("%d", &iNo);
      InsertAtPosition(&pFirst2, &pLast2, iPos, iNo);
      Display(pFirst2, pLast2);
     }
     break;

     case 4:
     { 
      iCount = CountNodes(pFirst1, pLast1);
    
      printf("Enter the position:\t");
      scanf("%d", &iPos);
      if(iPos <= 0 || iPos > iCount+1)
      {
       printf("Position Invaild\n");
       break;
      }
      
      ConcatAtPosition(&pFirst1, &pLast1, &pFirst2, &pLast2, iPos);
      Display(pFirst1, pLast1);
     }
     }
    }
    }
    break;
    
    case 3:
    {
     Display(pFirst1, pLast1);
    }
   }
   }
   }
   break;

   case 6:
   {
    if(pFirst1 == NULL)
    {
     printf("List is empty\n");
     break;
    }
    while(iChoice != 3)
    {
    printf("1.Reverse Display\n2.Physical Reverse\n3.Back\n");
    printf("Enter your choice:\t");
    scanf("%d", &iChoice);
 
    switch(iChoice)
    {
    case 1:
    {
     ReverseDisplay(pFirst1, pLast1);
    }
    break;
  
    case 2:
    {
     PhysicalReverse(&pFirst1, &pLast1);
     Display(pFirst1, pLast1);
    }
    break;
  
    case 3:
    {
     Display(pFirst1, pLast1);
    }
   }
  }
  }
  break;
  
  case 7:
  {
   if(pFirst1 != NULL)
   {
    DeleteAll(&pFirst1, &pLast1);
    printf("First list is empty\n");
   }
   
   if(pFirst2 != NULL)
   {
    DeleteAll(&pFirst2, &pLast2);
    printf("Second  list is empty\n");
   }
  }
  }
 }
 return 0;
}

void InsertLast(struct node **ppHead, struct node **ppTail, int iNo)
{
	struct node *pNewNode = NULL;
	
	pNewNode = (struct node *)malloc(sizeof(struct node));
	if(NULL == pNewNode)
	{
		printf("Memory allocation failed\n");
		return;
	}
	
	pNewNode->iData = iNo;
	
	if(*ppHead == NULL)
	{
		*ppHead = *ppTail = pNewNode;
		(*ppTail)->pNext = *ppHead;
		return;
	}
	
	(*ppTail)->pNext = pNewNode;
	*ppTail = pNewNode;
	(*ppTail)->pNext = *ppHead;
}
	

void Display(struct node *pHead, struct node *pTail)
{
	if(NULL == pHead)
	{
		printf("List is empty\n");
		return;
	}
	
	do
	{
		printf("|%d|->", pHead->iData);
		pHead = pHead->pNext;
	}while(pHead != pTail->pNext);
	printf("\n");
}

void DeleteAll(struct node **ppHead, struct node **ppTail)
{
	struct node *pTemp = *ppHead;
	if(*ppHead == NULL)
		return;

	if(*ppHead	!= *ppTail)
	{
		do
		{
			if(pTemp->pNext == *ppHead)
				break;
				
			*ppHead = pTemp->pNext;
			pTemp->pNext = NULL;
			free(pTemp);
			pTemp = *ppHead;
		}while(pTemp != *ppTail);
	}

	(*ppHead)->pNext = NULL;
	free(*ppHead);
	
	*ppHead = *ppTail = NULL;
	pTemp = NULL;
}

void InsertFirst(struct node **ppHead, struct node **ppTail, int iNo)
{
	struct node *pNewNode = NULL;
	
	pNewNode = (struct node *)malloc(sizeof(struct node));
	if(NULL == pNewNode)
	{
		printf("Memory allocation failed/n");
		return;
	}
	
	pNewNode->iData = iNo;
	
	if(*ppHead == NULL)
	{
		*ppHead = pNewNode;
		*ppTail = pNewNode;
		(*ppTail)->pNext = *ppHead;
		return;
	}
	
	pNewNode->pNext = *ppHead;
	*ppHead = pNewNode;
	(*ppTail)->pNext = *ppHead;
}

int CountNodes(struct node *pHead, struct node *pTail)
{
	int iCount = 1;
	
	if(pHead == NULL)
		return 0;
		
	while(pHead != pTail)
	{
		pHead = pHead->pNext;
		iCount++;
	}
	
	return iCount;
}			
		
void InsertAtPosition(struct node **ppHead, struct node **ppTail, int iPos, int iNo)
{
	struct node *pNewNode = NULL;
	struct node *pTemp = NULL;
	int iCount;
	
	iCount = CountNodes(*ppHead, *ppTail);

	if(iPos == 1)
	{	
		InsertFirst(ppHead, ppTail, iNo);
		return;
	}
		
	if(iPos == iCount+1)
	{	
		InsertLast(ppHead, ppTail, iNo);
		return;
	}
		
	pNewNode = (struct node *)malloc(sizeof(struct node));
	if(NULL == pNewNode)
	{
		printf("Memory allocation failed./n");
		return;
	}
	
	pNewNode->iData = iNo;
	
	pTemp = *ppHead;
	iCount = 1;
	
	while(iCount != iPos-1)
	{
		pTemp = pTemp->pNext;
		iCount++;
	}
	
	pNewNode->pNext = pTemp->pNext;
	pTemp->pNext = pNewNode;
}

int DeleteLast(struct node **ppHead, struct node **ppTail)
{
	struct node *pTemp = NULL;
	int iDel;
	
	if(*ppHead == NULL)
		return -1;
	
	iDel = (*ppTail)->iData;	
	if(*ppHead == *ppTail)
	{
		(*ppHead)->pNext = NULL;
		free(*ppHead);
		*ppHead = *ppTail = NULL;
		return iDel;
	}
	
	pTemp = *ppHead;
	while(pTemp->pNext != *ppTail)
		pTemp = pTemp->pNext; 
	
	
	(*ppTail)->pNext = NULL;
	free(*ppTail);
	*ppTail = pTemp;
	(*ppTail)->pNext = *ppHead;
	
	pTemp = NULL;
	
	return iDel;
}

int DeleteFirst(struct node **ppHead, struct node **ppTail)
{
	int iDel;
	
	if(*ppHead == NULL)
		return -1;
		
	iDel = (*ppHead)->iData;
	
	if(*ppHead == *ppTail)
	{
		(*ppHead)->pNext = NULL;
		free(*ppHead);
		*ppHead = *ppTail = NULL;
		return iDel;
	}
	
	*ppHead = (*ppHead)->pNext;
	(*ppTail)->pNext->pNext = NULL;
	free((*ppTail)->pNext);
	(*ppTail)->pNext = *ppHead;
	
	return iDel;
}

int DeleteAtPosition(struct node **ppHead, struct node **ppTail, int iPos)
{
	struct node *pTemp1 = NULL;
	struct node *pTemp2 = NULL;
	int iCount;
	
	iCount = CountNodes(*ppHead, *ppTail);
	
	if(iPos == 1)
		return DeleteFirst(ppHead, ppTail);
		
	if(iPos == iCount)
		return DeleteLast(ppHead, ppTail);
		
	pTemp1 = *ppHead;
	iCount = 1;
	
	while(iCount < iPos-1)
	{
		pTemp1 = pTemp1->pNext;
		iCount++;
	}
	
	pTemp2 = pTemp1->pNext;
	iCount = pTemp2->iData;
	
	pTemp1->pNext = pTemp2->pNext;
	pTemp2->pNext = NULL;
	free(pTemp2);
	pTemp2 = NULL;	
	
	return iCount;
}

int SearchFirstOccurrence(struct node *pHead, struct node *pTail, int iKey)
{
	int iPos = 0;
	
	do
	{
		iPos++;
		
		if(pHead->iData == iKey)
			break;
			
		pHead = pHead->pNext;
	}while(pHead != pTail->pNext);
	
	if(pHead == pTail->pNext)
		iPos = 0;
	
	
	return iPos;
}

int SearchLastOccurrence(struct node *pHead, struct node *pTail, int iKey)
{
	int iPos = 0;
	int iLastPos = 0;
	
	do
	{
		iPos++;
		
		if(pHead->iData == iKey)
			iLastPos = iPos;
			
		pHead = pHead->pNext;
	}while(pHead != pTail->pNext);
	
	
	
	return iLastPos;
}

int SearchAllOccurrences(struct node *pHead, struct node *pTail, int iKey)
{
	int iPos = 0;
	
	do
	{
		if(pHead->iData == iKey)
			iPos++;
		pHead = pHead->pNext;
	}while(pHead != pTail->pNext);
	
	return iPos;
}

void ConcatList(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node **ppTail2)
{
	
	if(NULL == *ppHead2)
		return;
		
	if(NULL == *ppHead1)
	{
		*ppHead1 = *ppHead2;
		*ppTail1 = *ppTail2;
		*ppHead2 = *ppTail2 = NULL;
		
		return;
	}
	
	(*ppTail1)->pNext = *ppHead2;
	*ppTail1 = *ppTail2;
	(*ppTail1)->pNext = *ppHead1;
	
	*ppHead2 = *ppTail2 = NULL;			
}

void ConcatAtPosition(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node **ppTail2, int iPos)
{
	struct node *pTemp = NULL;
	int iCount;
	
	iCount = CountNodes(*ppHead1, *ppTail1);

	if(NULL == *ppHead2)
		return;
		
	if(iPos == 1)
	{
		ConcatList(ppHead2, ppTail2, ppHead1, ppTail1);
		*ppHead1 = *ppHead2;
		*ppTail1 = *ppTail2;
		*ppHead2 = *ppTail2 = NULL;
		
		return;
	}
	
	if(iPos == iCount+1)
	{
		ConcatList(ppHead1, ppTail1, ppHead2, ppTail2);
		return;
	}
	
	pTemp = *ppHead1;
	iCount = 1;
	while(iCount != iPos-1)
	{
		pTemp = pTemp->pNext;
		iCount++;
	}
	
	(*ppTail2)->pNext = pTemp->pNext;
	pTemp->pNext = *ppHead2;
	
	*ppHead2 = *ppTail2 = NULL;
	pTemp = NULL;
}

void PhysicalReverse(struct node **ppHead, struct node **ppTail)
{
	struct node *pPrev = *ppTail;
	struct node *pCurrent = *ppHead;
	struct node *pNext = NULL;
	
	if(NULL == *ppHead)
		return;
		
	do
	{
		pNext = pCurrent->pNext;
		pCurrent->pNext = pPrev;
		pPrev = pCurrent;
		pCurrent = pNext;
	}while(pCurrent != *ppHead);
	
	*ppHead = *ppTail;
	*ppTail = pCurrent;
}

void ReverseDisplay(struct node *pHead, struct node *pTail)
{
	if(NULL == pHead)
	{
		printf("List is empty.\n");
		return;
	}
	
	PhysicalReverse(&pHead, &pTail);
	Display(pHead, pTail);
	PhysicalReverse(&pHead, &pTail);
}
