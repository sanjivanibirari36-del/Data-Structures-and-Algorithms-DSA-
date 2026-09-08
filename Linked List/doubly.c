#include <stdio.h>
#include <malloc.h>

struct node
{
	struct node *pPrev;
	int iData;
	struct node *pNext;
};

void InsertFirst(struct node **, int);
void InsertLast(struct node **, int);
void InsertAtPosition(struct node **, int, int);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
int DeleteAtPosition(struct node **, int);
int SearchFirstOccurrence(struct node *, int);
int SearchLastOccurrence(struct node *, int);
int SearchAllOccurrence(struct node *, int);
void ConcatList(struct node **, struct node **);
void ConcatAtPosition(struct node **, struct node **, int);
void ReverseDisplay(struct node *);
void PhysicalReverse(struct node **);
void Display(struct node *);
void DeleteAll(struct node **);
int CountNodes(struct node *);

int main(void)
{
 struct node *pFirst = NULL;
 struct node *pSecond = NULL;
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
   
   InsertFirst(&pFirst, iNo);
	 Display(pFirst);		
  }
  break;
 
  case 2:
  {
   printf("Enter the data:\t");
   scanf("%d", &iNo);

   InsertLast(&pFirst, iNo);
   Display(pFirst);
  }
  break;

  case 3:
  {
   printf("Enter the position:\t");
   scanf("%d", &iPos);

   iCount = CountNodes(pFirst);
   if(iPos <= 0 || iPos > iCount+1)
   {
    printf("Position invalid\n");
    break;
   }
   printf("Enter the data:\t");
   scanf("%d", &iNo);

   InsertAtPosition(&pFirst, iPos, iNo);
   Display(pFirst);
  }
  break;

  case 4:
  {
		Display(pFirst);
  }
  }
 }
 }
 break;

 case 2:
 {
 if(pFirst ==NULL)
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
   iDelData = DeleteFirst(&pFirst);
   printf("Deleted data is %d\n", iDelData);
   Display(pFirst);
  }
  break;

  case 2:
  {
   iDelData = DeleteLast(&pFirst);
   printf("Deleted data is %d\n", iDelData);
   Display(pFirst);
  }
  break;

  case 3:
  {
   printf("Enter the position:\t");
   scanf("%d", &iPos);
   
   iCount = CountNodes(pFirst);
   if(iPos <= 0 || iPos > iCount)
   {
    printf("Position invalid\n");
    break;
   }
 
   iDelData = DeleteAtPosition(&pFirst, iPos); 
   printf("Deleted data is %d\n", iDelData);
   Display(pFirst);
  }
  break;

  case 4:
  {
	Display(pFirst);
  }
  }
 }
 }
 break;

 case 3:
 {
  if(pFirst == NULL)
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
  
   iPos = SearchFirstOccurrence(pFirst, iNo);
   if(iPos != 0)
    printf("%d first occurred at %d position\n", iNo, iPos);
   else
    printf("Data not found\n");
    
   Display(pFirst);
  }
  break;

  case 2:
  {
   printf("Enter the number to be searched:\t");
   scanf("%d", &iNo);
  
   iPos = SearchLastOccurrence(pFirst, iNo);
   if(iPos != 0)
    printf("%d last occurred at %d position\n", iNo, iPos);
   else
    printf("Data not found\n");
    
   Display(pFirst);
  }
  break;

  case 3:
  {
   printf("Enter the number to be searched:\t");
   scanf("%d", &iNo);

   iPos = SearchAllOccurrences(pFirst, iNo);
   printf("%d found %d times\n", iNo, iPos);
   
   Display(pFirst);
  }
  break;
   
  case 4:
  {
   	Display(pFirst);
  }
  }
 }
 }
 break;

 case 4:
 {
  iCount = CountNodes(pFirst);
  printf("Total nodes are %d\n", iCount);
  Display(pFirst);
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
      InsertFirst(&pSecond, iNo);
      Display(pSecond);
     }
     break;

     case 2:
     {
      printf("Enter the data:\t");
      scanf("%d", &iNo);
      InsertLast(&pSecond, iNo);
      Display(pSecond);
     }
     break;

     case 3:
     {
      iCount = CountNodes(pSecond);
      printf("Enter the position:\t");
      scanf("%d", &iPos);
    
      if(iPos <= 0 || iPos > iCount+1)
      {
       printf("Position Invalid\n");
       break;
      }

      printf("Enter the data:\t");
      scanf("%d", &iNo);
      InsertAtPosition(&pSecond, iPos, iNo);
      Display(pSecond);
     }
     break;

     case 4:
     {
      ConcatList(&pFirst, &pSecond);
      Display(pFirst);
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
      InsertFirst(&pSecond, iNo);
      Display(pSecond);
     }
     break;
    
     case 2:
     {
      printf("Enter the data:\t");
      scanf("%d", &iNo);
      InsertLast(&pSecond, iNo);
      Display(pSecond);
     }
     break;

     case 3:
     {
      iCount = CountNodes(pSecond);
      printf("Enter the position:\t");
      scanf("%d", &iPos);

      if(iPos <= 0 || iPos > iCount+1)
      {
       printf("Position Invalid\n");
       break;
      }

      printf("Enter the data:\t");
      scanf("%d", &iNo);
      InsertAtPosition(&pSecond, iPos, iNo);
      Display(pSecond);
     }
     break;

     case 4:
     { 
      iCount = CountNodes(pFirst);
    
      printf("Enter the position:\t");
      scanf("%d", &iPos);
      if(iPos <= 0 || iPos > iCount+1)
      {
       printf("Position Invaild\n");
       break;
      }
      
      ConcatAtPosition(&pFirst, &pSecond, iPos);
      Display(pFirst);
     }
     }
    }
    }
    break;
    
    case 3:
    {
     Display(pFirst);
    }
   }
   }
   }
   break;

   case 6:
   {
    if(pFirst == NULL)
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
     ReverseDisplay(pFirst);
    }
    break;
  
    case 2:
    {
     PhysicalReverse(&pFirst);
     Display(pFirst);
    }
    break;
  
    case 3:
    {
     Display(pFirst);
    }
   }
  }
  }
  break;
  
  case 7:
  {
   if(pFirst != NULL)
   {
    DeleteAll(&pFirst);
    printf("First list is empty\n");
   }
   
   if(pSecond != NULL)
   {
    DeleteAll(&pSecond);
    printf("Second  list is empty\n");
   }
  }
  }
 }
 return 0;
}

void InsertFirst(struct node **ppHead, int iNo)
{
 struct node *pNewNode= NULL;

 pNewNode= (struct node *)malloc(sizeof(struct node));
 
 if(NULL == pNewNode)
 {
  printf("Memory allocation Failed");
  return;
 }

 pNewNode->iData= iNo;
 pNewNode->pPrev= NULL;
 
 if(NULL == *ppHead)
  pNewNode->pNext= NULL;
 
 else
 {
  pNewNode->pNext= *ppHead;
  (*ppHead)->pPrev= pNewNode;
 } 
 *ppHead= pNewNode;
}

void InsertLast(struct node **ppHead, int iNo)
{
 struct node *pNewNode = NULL;
 struct node *pTemp = NULL;
 
 pNewNode = (struct node *)malloc(sizeof(struct node));
 if(pNewNode == NULL)
 {
  printf("Memory allocation FAILED");
  return;
 }

 pNewNode->iData = iNo;
 pNewNode->pNext = NULL;

 if(NULL == *ppHead)
 { 
  pNewNode->pPrev = NULL;
  *ppHead = pNewNode;
  return;
 }

  pTemp = *ppHead;

  while(pTemp->pNext != NULL)
   pTemp = pTemp->pNext;

  pTemp->pNext = pNewNode;
  pNewNode->pPrev = pTemp;

  pTemp = NULL;
}   

void InsertAtPosition(
		struct node **ppHead, 
		int iPos, 
                int iNo
		)
{
 struct node *pNewNode = NULL;
 struct node *pTemp = NULL;
 int iCount;

 if(iPos == 1)
 {
  InsertFirst(ppHead, iNo);
  return;
 }

 pNewNode = (struct node *)malloc(sizeof(struct node));
 if(NULL == pNewNode)
 {
  printf("Memory allocation failed");
  return;
 }
 pNewNode->iData = iNo;

 iCount = 1;
 pTemp = *ppHead;
 while(iCount <  iPos-1)
 {
  pTemp = pTemp->pNext;
  iCount++;
 }

 pNewNode->pNext = pTemp->pNext;
 if(pTemp->pNext != NULL)
  pTemp->pNext->pPrev = pNewNode;
 pNewNode->pPrev = pTemp;
 pTemp->pNext = pNewNode;
} 
  
int CountNodes(struct node *pHead)
{
 int iCount = 0;

 while(pHead != NULL)
 {
  pHead = pHead->pNext;
  iCount++;
 }

 return iCount;
}

int DeleteAtPosition(struct node **ppHead, int iPos)
{
	struct node *pTemp = NULL;	
	int iCount = CountNodes(*ppHead);
	
	if(iPos == 1)
	{
		return DeleteFirst(ppHead);
		
	}
	
	if(iPos == iCount)
	{
		return DeleteLast(ppHead);
	}
	
	pTemp = *ppHead;
	iCount = 1;
	
	while(iCount != iPos)
	{
		iCount++;
		pTemp = pTemp->pNext;
	}
	
	iCount = pTemp->iData;
	pTemp->pPrev->pNext = pTemp->pNext;
	pTemp->pNext->pPrev = pTemp->pPrev;
	
	pTemp->pPrev = NULL;
	pTemp->pNext = NULL;
	free(pTemp);
	pTemp = NULL;
	
	return iCount;
}

int DeleteFirst(struct node **ppHead)
{
	int iDel;
	
	if(NULL == *ppHead)
	{
		printf("List is empty\n");
		return -1;
	}
	
	if(NULL == (*ppHead)->pNext)
	{
		iDel = (*ppHead)->iData;
		free(*ppHead);
		*ppHead = NULL;
		return iDel;
	}
	
	*ppHead = (*ppHead)->pNext;
	iDel = (*ppHead)->pPrev->iData;
	(*ppHead)->pPrev->pNext = NULL;
	free((*ppHead)->pPrev);
	
	return iDel;
}

int DeleteLast(struct node **ppHead)
{
	struct node *pTemp = NULL;
	int iDel;
	
	if(NULL == *ppHead)
	{
		printf("List is empty\n");
		return -1;
	}
	
	if((*ppHead)->pNext == NULL)
	{
	    iDel = (*ppHead)->iData; 
		free(*ppHead);
		*ppHead = NULL;
		return iDel;
	}
	
	pTemp = *ppHead;
	
	while(pTemp->pNext != NULL)
		pTemp = pTemp->pNext;
	
	iDel = pTemp->iData;	
	pTemp = pTemp->pPrev;
	pTemp->pNext->pPrev = NULL;
	free(pTemp->pNext);
	pTemp->pNext = NULL;
	
	return iDel;
}

int SearchFirstOccurrence(struct node *pHead, int iKey)
{
	int iPos = 0;
	
	while(pHead != NULL)
	{
		iPos++;
		if(pHead->iData == iKey)
			break;
			
		pHead = pHead->pNext;
	}
	
	if(NULL == pHead)
		iPos = 0;
		
	return iPos;
}

int SearchLastOccurrence(struct node *pHead, int iKey)
{
	int iPos = 0;
	int iLastPos = 0;
	
	while(pHead != NULL)
	{
		iPos++;
		
		if(pHead->iData == iKey)
			iLastPos = iPos;
			
		pHead = pHead->pNext;
		
	}
	
	return iLastPos;
}

int SearchAllOccurrences(struct node *pHead, int iKey)
{
	int iCount = 0;
	
	
	while(pHead != NULL)
	{
		if(pHead->iData == iKey)
			iCount++;
		
		pHead = pHead->pNext;
	}
	return iCount;
}

void PhysicalReverse(struct node **ppHead)
{
	struct node *pCurrent = *ppHead;
	struct node *pNext = NULL;
	
	while(pCurrent != NULL)
	{
		pNext = pCurrent->pPrev;
		pCurrent->pPrev = pCurrent->pNext;
		if(pCurrent->pNext == NULL)
			*ppHead = pCurrent;
		pCurrent->pNext = pNext;
		pCurrent = pCurrent->pPrev;
	}
	pNext = NULL;
}

void ConcatAtPosition(struct node **ppHead1, struct node **ppHead2, int iPos)
{
	struct node *pTemp1 = NULL;
	struct node *pTemp2 = NULL;
	int iCount;
	
	if(*ppHead2 == NULL)
		return;	
		
	if(iPos == 1)
	{
		ConcatList(ppHead2, ppHead1);
		*ppHead1 = *ppHead2;
		*ppHead2 = NULL;
		return;
	}
	
	if(iPos == iCount+1)
	{
		ConcatList(ppHead1, ppHead2);
		return;
	}
	
	pTemp1 = *ppHead1;
	iCount = 1;
	while(iCount < iPos)
	{
		iCount++;
		pTemp1 = pTemp1->pNext;
	}
	
	pTemp2 = *ppHead2;
	while(pTemp2->pNext != NULL)
		pTemp2 = pTemp2->pNext;
		
	pTemp1->pPrev->pNext = *ppHead2;
	(*ppHead2)->pPrev = pTemp1->pPrev;
	pTemp1->pPrev = pTemp2;
	pTemp2->pNext = pTemp1;
	
	*ppHead2 = NULL;
	pTemp1 = pTemp2 = NULL;
}

void ConcatList(struct node **ppHead1, struct node **ppHead2)
{
	struct node *pTemp = NULL;
	
	if(*ppHead2 == NULL)
		return;

	if(*ppHead1 == NULL)
	{
		*ppHead1 = *ppHead2;
		*ppHead2 = NULL;
		return;
	}
		
	pTemp = *ppHead1;
	
	while(pTemp->pNext != NULL)
		pTemp = pTemp->pNext;
		
	pTemp->pNext = *ppHead2;
	(*ppHead2)->pPrev = pTemp;
	*ppHead2 = NULL;
}

void Display(struct node *pHead)
{
 if(NULL == pHead)
 {
  printf("List is empty\n");
  return;
 }

 while(pHead != NULL)
 {
  printf("|%d|->", pHead->iData);
  pHead= pHead->pNext;
 }

 printf("\n");
}

void DeleteAll(struct node **ppHead)
{
 struct node *pTemp= NULL;
 
 if(NULL == *ppHead)
  return;

 pTemp= *ppHead;

 while(pTemp != NULL)
 {
  *ppHead= pTemp->pNext;
  pTemp->pPrev= NULL;
  pTemp->pNext= NULL;
  free(pTemp);
  pTemp= *ppHead;
 }
}

void ReverseDisplay(struct node *pHead)
{
	PhysicalReverse(&pHead);
	Display(pHead);
	PhysicalReverse(&pHead);
}


