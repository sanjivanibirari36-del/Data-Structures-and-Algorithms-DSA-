//void ** ((*(*p)[3])(void(*(*)[2])(void)))

#include <stdio.h>

void fun1(void);
void fun2(void);

void ** fun3(void(*(*)[2])(void));
void ** fun4(void(*(*)[2])(void));
void ** fun5(void(*(*)[2])(void));

int main(void)
{
	void (*Array1[2])(void);
	void (*(*p1)[2])(void) = NULL;
	
	void ** (*Array2[3])(void(*(*)[2])(void));
	void ** (*(*p2)[3])(void(*(*)[2])(void)) = NULL;
	void **vptr = NULL;
	int iCounter;
	
	Array1[0] = fun1;
	Array1[1] = fun2;
	p1 = &Array1;
	
	Array2[0] = fun3;
	Array2[1] = fun4;
	Array2[2] = fun5;
	p2 = &Array2;
	
	for(iCounter = 0; iCounter < 3; iCounter++)
	{
		vptr = Array2[iCounter](p1);
		printf("Return value: %d\n\n", **(int **)vptr);
	}
	
	return 0;
}

void ** fun3(void(*(*p1)[2])(void))
{
	static int iNo1 = 10;
	static void *voidp = &iNo1;
	void **voidpp = &voidp;
	
	printf("Fun3:\n");
	(*p1)[0]();
	(*p1)[1]();
	
	return voidpp;
}

void ** fun4(void(*(*p1)[2])(void))
{
	static int iNo2 = 20;
	static void *voidp = &iNo2;
	void **voidpp = &voidp;

	printf("Fun4:\n");
	(*p1)[0]();
	(*p1)[1]();
	
	return voidpp;
}

void ** fun5(void(*(*p1)[2])(void))
{
	static int iNo3 = 30;
	static void *voidp = &iNo3;
	void **voidpp = &voidp;

	printf("Fun5:\n");
	(*p1)[0]();
	(*p1)[1]();
	
	return voidpp;
}

void fun1(void)
{
	printf("I am fun1.\n");
}

void fun2(void)
{
	printf("I am fun2.\n");
}
