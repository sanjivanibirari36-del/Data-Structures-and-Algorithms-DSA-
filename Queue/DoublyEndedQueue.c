#include <stdio.h>

#define MAX 5

void EnqueueAtFront(int *, int);
int DequeueFromFront(int *);
void EnqueueAtRear(int *, int);
int DequeueFromRear(int *);
int IsQueueFull();
int IsQueueEmpty();
void Display(int *);


int g_iFront = 0;
int g_iRear = -1;

int main(void)
{
	int iNo;
	int iChoice = 0;
	int arr[MAX] = {0};
	int iDel;
	
	while(iChoice != 7)
	{
		printf("1.Enqueue at front\n2.Dequeue from front\n3.Enqueue at rear\n4.Dequeue from rear\n5.Is Queue Full\n6.Is Queue Empty\n7.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &iChoice);
		
		switch(iChoice)
		{
			case 1:
			{
				if(IsQueueFull())
				{
					printf("Queue is full!\n");
					break;
				}
				printf("Enter the data: ");
				scanf("%d", &iNo);
				EnqueueAtFront(arr, iNo);
				Display(arr);
			}
			break;
			
			case 2:
			{
				if(IsQueueEmpty())
				{
					printf("Queue is Empty");
					break;
				}
				iDel = DequeueFromFront(arr);
				printf("Deleted data is: %d\n", iDel);
				Display(arr);
			}
			break;
			
			case 3:
			{
				if(IsQueueFull())
				{
					printf("Queue is full!\n");
					break;
				}
				printf("Enter the data: ");
				scanf("%d", &iNo);
				EnqueueAtRear(arr, iNo);
				Display(arr);
			}
			break;
			
			case 4:
			{
				if(IsQueueEmpty())
				{
					printf("Queue is empty!\n");
					break;
				}
				iDel = DequeueFromRear(arr);
				printf("Deleted data is: %d\n", iDel);
				Display(arr);
			}
			break;
			
			case 5:
			{
				if(IsQueueFull())
					printf("Queue is full!\n");
				else
					printf("Queue is not full.\n");
			}
			break;
			
			case 6:
			{
				if(IsQueueEmpty())
					printf("Queue is empty!\n");
				else
					printf("Queue is not empty.\n");
			}
			break;
			
			case 7:
			{
				break;
			}
		}
	}
	return 0;
}		
								
void EnqueueAtFront(int *parr, int iNo)
{
	if(IsQueueFull())
	{
		printf("Queue is full!\n");
		return;
	}
	
	if(g_iFront == 0 && g_iRear == -1)
	{
		g_iFront = MAX-1;
		g_iRear = MAX-1;
		parr[g_iFront] = iNo;
		return;
	}
	
	parr[--g_iFront] = iNo; 
}

int DequeueFromRear(int *parr)
{
	int iDel;
	if(IsQueueEmpty())
	{
		printf("Queue is empty!\n");
		return 0;
	}
	iDel = parr[g_iRear];
	
	if(g_iRear == 0 && g_iFront == MAX-1)
	{
		g_iRear = MAX-1;
		return iDel;
	}
	
	if(g_iRear == g_iFront)
	{
		g_iRear = -1;
		g_iFront = 0;
		return iDel;
	}
	
	g_iRear--;
	
	return iDel;
}


void EnqueueAtRear(int *parr, int iNo)
{
	if(IsQueueFull())
	{
		printf("Queue is full!\n");
		return;
	}
	
	if(g_iRear == (MAX-1))
	{
		g_iRear = 0;
		parr[g_iRear] = iNo;
		return;
	}
	
	parr[++g_iRear] = iNo;
}

int DequeueFromFront(int *parr)
{
	int iDel;
	if(IsQueueEmpty())
	{
		printf("Queue is empty!\n");
		return 0;
	}
	iDel = parr[g_iFront];
	
	if(g_iRear == g_iFront)
	{
		g_iRear = -1;
		g_iFront = 0;
		
		return iDel;
	}
	g_iFront++;
	
	return iDel;
}

int IsQueueFull()
{
	if(g_iFront == 0 && g_iRear == MAX-1)
		return 1;
	
	else if((g_iRear == (g_iFront - 1)) && (g_iRear != -1))	
		return 1;
	
	else
		return 0;
}

int IsQueueEmpty()
{
	if(g_iRear == -1 && g_iFront == 0)
		return 1;

	return 0;
}

void Display(int *parr)
{
	int iCounter;

	if(IsQueueEmpty())
	{
		printf("Queue is empty!\n");
		return;
	}
	
	for(iCounter = g_iFront; iCounter <= (MAX-1); iCounter++)
	{
		printf("%d\t", parr[iCounter]);
		
		if(iCounter == g_iRear)
			break;
		
		if((g_iFront != (0)) && (g_iRear != (MAX-1)) && iCounter == (MAX-1))
			iCounter = -1;
			
		if(g_iFront == g_iRear)
			break;
	}
	printf("\n");
}		
