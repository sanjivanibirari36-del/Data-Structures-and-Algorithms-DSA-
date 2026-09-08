#include <stdio.h>
#include <malloc.h>
#define MAX 20

int main(void)
{
	int ***pArray1 = NULL;
	int pArray2[MAX][MAX][MAX];
	int iPlane;
	int iRows;
	int iColumns;
	int iCounter1;
	int iCounter2;
	int iCounter3;
	
	printf("Enter number of plane:\t");
	scanf("%d", &iPlane);
	printf("Enter number of rows:\t");
	scanf("%d", &iRows);
	printf("Enter number of columns:\t");
	scanf("%d", &iColumns);
	
	printf("\nStatic memory allocation\n");
	for(iCounter1 = 0; iCounter1 < iPlane; iCounter1++)
	{
		for(iCounter2 = 0; iCounter2 < iRows; iCounter2++)
		{
			for(iCounter3 = 0; iCounter3 < iColumns; iCounter3++)
			{
				printf("Enter the value[%d][%d][%d]: \t", iCounter1, iCounter2, iCounter3);
				scanf("%d", &pArray2[iCounter1][iCounter2][iCounter3]);
			}
		}
	}	
	
	printf("\n3D array values are:\n");
	for(iCounter1 = 0; iCounter1 < iPlane; iCounter1++)
	{
		for(iCounter2 = 0; iCounter2 < iRows; iCounter2++)
		{
			for(iCounter3 = 0; iCounter3 < iColumns; iCounter3++)
			{
				printf("%d\t", pArray2[iCounter1][iCounter2][iCounter3]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
	
	printf("Dynamic memory allocation\n");
	
	pArray1 = (int ***)malloc(iPlane * sizeof(int **));
	if(pArray1 == NULL)
	{
		printf("Memory allocation failed!\n");
		return -1;
	}
			
	for(iCounter1 = 0; iCounter1 < iPlane; iCounter1++)
	{
		pArray1[iCounter1] = (int **)malloc(iRows * sizeof(int *));
		if(pArray1[iCounter1] == NULL)
		{
			printf("Memory allocation failed!\n");
			return -1;
		}
		
		for(iCounter2 = 0; iCounter2 < iRows; iCounter2++)
		{
			pArray1[iCounter1][iCounter2] = (int *)malloc(iColumns * sizeof(int));
			if(pArray1[iCounter1][iCounter2] == NULL)
			{
				printf("Memory allocation failed!\n");
				return -1;
			}
			
			for(iCounter3 = 0; iCounter3 < iColumns; iCounter3++)
			{
				printf("Enter the value[%d][%d][%d]: \t", iCounter1, iCounter2, iCounter3);
				scanf("%d", &pArray1[iCounter1][iCounter2][iCounter3]);
			}
		}
	}
	
	printf("\n3D array values are:\n");
	
	for(iCounter1 = 0; iCounter1 < iPlane; iCounter1++)
	{
		for(iCounter2 = 0; iCounter2 < iRows; iCounter2++)
		{
			for(iCounter3 = 0; iCounter3 < iColumns; iCounter3++)
			{
				printf("%d\t", pArray1[iCounter1][iCounter2][iCounter3]);
			}
			printf("\n");
		}
		printf("\n\n");
	} 	
	
	if(pArray1 != NULL)
	{
		for(iCounter1 = 0; iCounter1 < iPlane; iCounter1++)
		{
			if(pArray1[iCounter1] != NULL)
			{
				for(iCounter2 = 0; iCounter2 < iRows; iCounter2++)
				{	
					if(pArray1[iCounter1][iCounter2] != NULL)
					{
						free(pArray1[iCounter1][iCounter2]);
						pArray1[iCounter1][iCounter2] = NULL;
					}
				}
				free(pArray1[iCounter1]);
				pArray1[iCounter1] = NULL;
			}
		}
		free(pArray1);
		pArray1 = NULL;		
	}	
	return 0;
}			
