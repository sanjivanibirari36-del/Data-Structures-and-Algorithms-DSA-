#include <stdio.h>
#define MAX 10

int main(void)
{
	int iVertices;
	int vertex[MAX];
	int arr[MAX][MAX] = {0};
	int iEdge;
	int iData;
	int iCounter1;
	int iCounter2;
	int iCounter3;
	
	printf("How many vertices you want(<10)?\n");
	scanf("%d", &iVertices);
	
	for(iCounter1 = 0; iCounter1 < iVertices; iCounter1++)
	{
		printf("Enter %d data: ", iCounter1+1);
		scanf("%d", &vertex[iCounter1]);
	}
	printf("\n");
	
	for(iCounter1 = 0; iCounter1 < iVertices; iCounter1++)
	{
		printf("How many adjacent vertices for %d?\n", vertex[iCounter1]);
		scanf("%d", &iEdge);
		
		for(iCounter2 = 0; iCounter2 < iEdge; iCounter2++)
		{
			printf("Enter %d vertex: ", iCounter2+1);
			scanf("%d", &iData);
			
			for(iCounter3 = 0; iCounter3 < iVertices; iCounter3++)
			{
				if(iData == vertex[iCounter3])
				{
					arr[iCounter1][iCounter3] = 1;
					arr[iCounter3][iCounter1] = 1;
				}
			}
		}
		printf("\n");
	}
	
	for(iCounter1 = 0; iCounter1 < iVertices; iCounter1++)
	{
		printf("\n%d-> ", vertex[iCounter1]);
		
		for(iCounter2 = 0; iCounter2 < iVertices; iCounter2++)
		{
			if(arr[iCounter1][iCounter2] == 1)
				printf("%d ", vertex[iCounter2]);
		}
	}
	printf("\n");
	return 0;
}
				
					
			 
