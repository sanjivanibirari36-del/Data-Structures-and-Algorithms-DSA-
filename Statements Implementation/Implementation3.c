//char (*(*arr[3])(int *))[2];

#include <stdio.h>
#include <malloc.h>

char (* fun1(int *))[2];
char (* fun2(int *))[2];
char (* fun3(int *))[2];

int main(void)
{
	char (*(*arr[3])(int *))[2];
	char (*ptr)[2] = NULL;
	int iCounter;	

	int iNo = 10;
	
	arr[0] = fun1;
	arr[1] = fun2;
	arr[2] = fun3;
	
	for(iCounter = 0; iCounter < 3; iCounter++)
	{
		ptr = arr[iCounter](&iNo);
		printf("Fun%d Array1: %c\n", iCounter+1, **ptr); 	
		printf("Fun%d Array2: %c\n\n", iCounter + 1, *((*ptr)+1));
	}

	return 0;
}

char (*fun1(int *ptr))[2]
{
	static char Array1[2];
	
	Array1[0] = 'A';
	Array1[1] = 'B';
	
	printf("Fun1(iNo): %d\n",  *ptr);
	return &Array1;
}

char (*fun2(int *ptr))[2]
{
	static char Array2[2];
	
	Array2[0] = 'C';
	Array2[1] = 'D';
	
	printf("Fun2(iNo): %d\n",  *ptr);
	return &Array2;
}

char (*fun3(int *ptr))[2]
{
	static char Array3[2];

	Array3[0] = 'E';
	Array3[1] = 'F';
	
	printf("Fun3(iNo): %d\n",  *ptr);
	return &Array3;
}
