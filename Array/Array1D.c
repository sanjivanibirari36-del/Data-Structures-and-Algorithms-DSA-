#include <stdio.h>
#include <malloc.h>

int main(void)
{
	int *pArray = NULL;
	int iCount;
	int iCounter;
	
	printf("Enter the number of elements:\t");
	scanf("%d", &iCount);
	
	iCount = iCount - 1;
	pArray = (int *)malloc(iCount * sizeof(int));
	if(pArray == NULL)
	{
		printf("Memory allocation failed!\n");
		return -1;
	}
	
	for(iCounter = 0; iCounter <= iCount; iCounter++)
	{
		printf("Enter the value[%d]: ", iCounter+1);
		scanf("%d", &pArray[iCounter]);
		printf("\n");
	}
	
	printf("Array values:\n");
	for(iCounter = 0; iCounter <= iCount; iCounter++)
		printf("%d\t", pArray[iCounter]);
	printf("\n");
		
	return 0;
}
