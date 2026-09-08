//void * (*p)(char, int(*)())

#include <stdio.h>

int fun1();
void * fun2(char, int(*)());

int main(void)
{
	char ch1 = 'A';
	void *ptr = NULL;
	int (*pfun1)() = NULL;
	void * (*pfun2)(char, int(*)()) = NULL;
	
	pfun1 = fun1;
	
	pfun2 = fun2;
	ptr = pfun2(ch1, pfun1);
	printf("Void pointer: %d\n", *(int *)ptr);
	
	return 0;
}

void * fun2(char ch1, int(*pfun1)())
{
	int iNo1;
	static int iNo2 = 20;
	void *ptr = &iNo2;
	
	printf("I am fun2.\n\n");
	iNo1 = pfun1();
	printf("iNo1: %d\n\n", iNo1);
	
	return ptr;
}

int fun1()
{
	int iNo = 10;
	printf("I am fun1\n");
	
	return iNo;
}
