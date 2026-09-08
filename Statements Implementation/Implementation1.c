//void *(*(*arr[3])())();

#include <stdio.h>

void * (* fun1())();
void * (* fun2())();
void * (* fun3())();
void * fun4();
void * fun5();
void * fun6();

int main(void)
{
	void * (*(* arr[3])())();
	void * (*fp)() = NULL;
	void * Vp = NULL;
	int iCounter;
	
	arr[0] = fun1;
	arr[1] = fun2;
	arr[2] = fun3;
		
	for(iCounter = 0; iCounter < 3; iCounter++)
	{
		fp = arr[iCounter]();
		Vp = fp();
		printf("Fun%d: %d\n\n", iCounter+1, *(int *)Vp);
	}		
	
	return 0;
}

void * (* fun1())()
{
	void * (*fp1)() = NULL;
	
	printf("I am fun1\n");
	
	fp1 = fun4;
	
	return fp1;
}

void * (* fun2())()
{
	void * (*fp2)() = NULL;
	
	printf("I am fun2\n");
	
	fp2 = fun5;
	
	return fp2;
}

void * (* fun3())()
{
	void * (*fp3)() = NULL;
	
	printf("I am fun3\n");
	
	fp3 = fun6;
	
	return fp3;
}

void * fun4()
{
	static int iNo = 10;
	void *p1 = &iNo;
	printf("I am fun4!\n");
	
	return p1;
}

void * fun5()
{
	static int iNo = 20;
	void *p2 = &iNo;
	printf("I am fun5!\n");
	
	return p2;
}
	
void * fun6()
{
	static int iNo = 30;
	void *p3 = &iNo;
	printf("I am fun6!\n");
	
	return p3;
}
