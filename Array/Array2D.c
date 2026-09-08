#include <stdio.h>
#include <malloc.h>

int main(void)
{
	int **pArray = NULL;
	int iRows;
	int iColumns;
	int iCounter1;
	int iCounter2;
	
	printf("Enter number of rows: \t");
	scanf("%d", &iRows);
	printf("Enter number of columns: \t");
	scanf("%d", &iColumns);
	
	pArray = (int *)malloc(iRows * sizeof(int));
	if(pArray == NULL)
	{
		printf("Memory allocation failed!\n");
		return -1;
	}
	
	for(iCounter1 = 0; iCounter1 < iColumns; iCounter1++)
	{
		pArray[iCounter1] = (int *)malloc(iColumns * sizeof(int));
		if(pArray[iCounter1] == NULL)
		{
			printf("Memory allocation failed!\n");
			return -1;
		}
	}
	
	for(iCounter1 = 0; iCounter1 < iRows; iCounter1++)
	{
		for(iCounter2 = 0; iCounter2 < iColumns; iCounter2++)
		{
			printf("Enter the values[%d][%d]: ", iCounter1, iCounter2);
			scanf("%d", &pArray[iCounter1][iCounter2]);
		}
	}
	
	printf("Array values are:\n");	
	for(iCounter1 = 0; iCounter1 < iRows; iCounter1++)
	{
		for(iCounter2 = 0; iCounter2 < iColumns; iCounter2++)
		{
			printf("%d\t", pArray[iCounter1][iCounter2]);
		}
		printf("\n");
	}
	
	for(iCounter1 = 0; iCounter1 < iRows; iCounter1++)
	{
		free(pArray[iCounter1]);
		pArray[iCounter1] = NULL;
	}
	free(pArray);
	pArray = NULL;
	
	return 0;
}
