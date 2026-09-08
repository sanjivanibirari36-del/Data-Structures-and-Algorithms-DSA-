//void **(*p)(int *, int **(*)(int *, int **));

#include <stdio.h>

void ** fun1(int *, int ** (*)(int *, int **));
int ** fun2(int *, int **);

int main(void)
{
	void ** (*fptr1)(int *, int ** (*)(int *, int **)) = NULL;
	int ** (*fptr2)(int *, int **) = NULL;
	void **vptr = NULL;
	int iNo1 = 10;
	
	fptr1 = fun1;
	fptr2 = fun2;
	
	vptr = fptr1(&iNo1, fptr2);
	printf("Fun1 return's: %d\n", **(int **)vptr);
	 
	return 0;
}

void ** fun1(int *iNo1, int ** (*fptr2)(int *, int **))
{
	 static int iNo2 = 20;
	 int **p2 = NULL;
	 int *p1 = &iNo2;
	 static void *vptr1 = &iNo2;
	 void **vptr2 = &vptr1;
	 
	 printf("I am fun1.\n");
	 printf("iNo1: %d\n\n", *iNo1);
	 
	 p2 = fptr2(&iNo2, &p1);
	 printf("Fun2 return's: %d\n\n", **p2);
	 
	 return vptr2;
}

int ** fun2(int *iNo2, int **p1)
{
	static int iNo3 = 30;
	static int *p3 = &iNo3;
	int **p4 = &p3;
	
	printf("I am fun2.\n");
	printf("iNo2 : %d\n", *iNo2);
	printf("p1: %d\n", **p1);
	
	return p4;
}
