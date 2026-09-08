#include <stdio.h>
#include <malloc.h>

struct node
{
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
int SearchAllOccurrences(struct node *, int);
void Display(struct node *);
int CountNodes(struct node *);
void ConcatList(struct node **, struct node **);
void ConcatAtPosition(struct node **, struct node **, int);
void ReverseDisplay(struct node *);
void PhysicalReverse(struct node **);
void DeleteAll(struct node **);

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
 
 pNewNode=(struct node *)malloc(sizeof(struct node));
 
 if(NULL == pNewNode)
  return;
 
 pNewNode->iData= iNo;

 pNewNode->pNext= (*ppHead);
 *ppHead= pNewNode;
}

void InsertLast(struct node **ppHead, int iNo)
{
 struct node *pNewNode= NULL;
 struct node *pTemp=NULL;
 
 pNewNode= (struct node*)malloc(sizeof(struct node));

 if(NULL== pNewNode)
 {
  printf("Memory allocation FAILED");
  return;
 }

 pNewNode->iData= iNo;
 pNewNode->pNext= NULL;

 if(NULL == *ppHead)
 {
  *ppHead= pNewNode;
  return;
 }

 pTemp= *ppHead;

 while(pTemp->pNext != NULL)
  pTemp= pTemp->pNext;

 pTemp->pNext= pNewNode;

 pTemp= NULL;
}

void InsertAtPosition(struct node **ppHead, int iPos, int iNo)
{
 struct node *pNewNode= NULL;
 struct node *pTemp= NULL;
 int iCount;
 iCount = CountNodes(*ppHead);
 if(iPos == 1)
 {
  InsertFirst(ppHead, iNo);
  return;
 }

 if(iPos == iCount+1)
 {
  InsertLast(ppHead, iNo);
  return;
 }

 pNewNode= (struct node *)malloc(sizeof(struct node));

 if(NULL== pNewNode)
  return;

 pNewNode->iData= iNo;

 pTemp= *ppHead;
 iCount= 1;

 while(iCount < iPos-1)
 {
  pTemp= pTemp->pNext;
  iCount++;
 }

 pNewNode->pNext= pTemp->pNext;
 pTemp->pNext= pNewNode;
}

int DeleteFirst(struct node **ppHead)
{
 int iDelData;
 struct node *pTemp= NULL;

 pTemp= *ppHead;

 *ppHead= pTemp->pNext;

 iDelData= pTemp->iData;
 pTemp->pNext= NULL;
 free(pTemp);
 pTemp= NULL;
 
 return iDelData;
}

int DeleteLast(struct node **ppHead)
{
 int iDelData;
 struct node *pTemp= NULL;

 pTemp= *ppHead;

 if(NULL == pTemp->pNext)
 {
  iDelData= pTemp->iData;
  free(pTemp);
  *ppHead= NULL;
  pTemp= NULL;

  return iDelData;
 }
 while(NULL != pTemp->pNext->pNext)
  pTemp= pTemp->pNext;

 iDelData= pTemp->pNext->iData;
 
 free(pTemp->pNext);
 pTemp->pNext= NULL;

 pTemp= NULL;
 return iDelData;
}

int DeleteAtPosition(struct node **ppHead, int iPos)
{
 struct node *pTemp1= NULL;
 struct node *pTemp2= NULL;
 int iCount;
 
 iCount= CountNodes(*ppHead);
 
 if(iPos == 1)
  return DeleteFirst(ppHead);
 
 if(iPos == iCount)
  return DeleteLast(ppHead);
 
 pTemp1= *ppHead;
 iCount= 1;

 while(iCount < iPos-1)
 {
  pTemp1= pTemp1->pNext;
  iCount++;
 }
 
 pTemp2 = pTemp1->pNext;
 iCount= pTemp2->iData;
 
 pTemp1->pNext= pTemp2->pNext;
 pTemp2->pNext= NULL;
 free(pTemp2);

 pTemp1= NULL;
 pTemp2= NULL;
 
 return iCount;
}

int SearchFirstOccurrence(struct node *pHead, int iKey)
{
 int iPos;

 iPos = 0;

 while(pHead != NULL)
 {
  iPos++;

  if(pHead->iData== iKey)
  break;

  pHead= pHead->pNext;
 }

 if(NULL== pHead)
  iPos= 0;

 return iPos;
}

int SearchLastOccurrence(struct node *pHead, int iKey)
{
 int iPos= 0;
 int iLast= 0;

 while(pHead != NULL)
 {
  iPos++;
  if(pHead->iData == iKey)
   iLast= iPos;

  pHead= pHead->pNext;
 }

 return iLast;
}

int SearchAllOccurrences(struct node *pHead, int iKey)
{
 int iCount= 0;

 while(pHead != NULL)
 {
  if(pHead->iData== iKey)
   iCount++;

  pHead= pHead->pNext;
 }

 return iCount;
}

void Display(struct node *pHead)
{
 if(NULL==pHead)
 {
  printf("List is empty\n");
  return;
 }

 while(pHead != NULL)
 {
  printf("|%d|->",pHead->iData);
  pHead= pHead->pNext;
 }
 printf("\n");
}

int CountNodes(struct node *pHead)
{
 int iCount= 0;

 while(pHead != NULL)
 {
  iCount++;
  pHead= pHead->pNext;
 }

 return iCount;
}

void ConcatList(struct node **ppHead1, struct node **ppHead2)
{
 struct node *pTemp= NULL;
 
 if(NULL == *ppHead2)
  return;

 if(NULL == *ppHead1)
  *ppHead1 = *ppHead2;

 else
 {
  pTemp= *ppHead1;
 
  while(pTemp->pNext != NULL)
   pTemp= pTemp->pNext;

  pTemp->pNext= *ppHead2;
 }

  *ppHead2 = NULL;
  pTemp= NULL;

}

void ConcatAtPosition(
                 struct node **ppHead1,
  		 struct node **ppHead2,
		 int iPos
                     )
{
 int iCount;
 struct node *pTemp1= NULL;
 struct node *pTemp2= NULL;
 
 iCount= CountNodes(*ppHead1);

 if(NULL == *ppHead2)
  return;

 if(iPos == 1)
 {
  ConcatList(ppHead2, ppHead1);
  
  *ppHead1= *ppHead2;
  *ppHead2= NULL;
  return;
 }

 if(iPos == iCount+1)
 {
  ConcatList(ppHead1, ppHead2);
  return; 
 }

 pTemp1= *ppHead1;
 iCount = 1;
 while(iCount != iPos- 1)
 {
  pTemp1= pTemp1->pNext;
  iCount++;
 }

 pTemp2= *ppHead2;
 while(NULL != pTemp2-> pNext)
  pTemp2= pTemp2->pNext;

 pTemp2->pNext= pTemp1->pNext;
 pTemp1->pNext= *ppHead2;

 pTemp1= NULL;
 pTemp2= NULL;
 *ppHead2= NULL;
}

void ReverseDisplay(struct node *pHead)
{
 PhysicalReverse(&pHead);
 Display(pHead);
 PhysicalReverse(&pHead);
}

void PhysicalReverse(struct node **ppHead)
{
 struct node *pNext= NULL;
 struct node *pCurrent= *ppHead;
 struct node *pPrev= NULL;

 while(pCurrent != NULL)
 {
  pNext= pCurrent->pNext;
  pCurrent->pNext= pPrev;
  pPrev= pCurrent;
  pCurrent= pNext;
 }

 *ppHead= pPrev;
 pPrev= NULL;
}

void DeleteAll(struct node **ppHead)
{
 struct node *pTemp= *ppHead;

 while(NULL != pTemp)
 {
  *ppHead=pTemp->pNext;
  pTemp->pNext= NULL;
  free(pTemp);
  pTemp= *ppHead;
 }
}
