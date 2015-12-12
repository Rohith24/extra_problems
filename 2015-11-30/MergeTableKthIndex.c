#include <stdio.h>
#include <stdlib.h>

struct testcases
{
	int n1;
	int n2;
	int k;
	int r;
}test[8] = {
	{ 0, 1, 4, 4 },
	{ 12, 0, 6, 72 }, 
	{ 0, 0, 21, 0 },
	{ 3, 4, 10, 20 },
	{ 42, 33, 22, 420 },
	{ 22, 22, 44, 968 },
	{ -2, 9, 100, -1 },
	{ 2, -2, 200, -1 }
};

int GCD(int a, int b);
void testcaseCheck();
int getKthIndex(int n1, int n2, int k);

int main()
{
	testcaseCheck();
	getch();
}

void testcaseCheck(){
	int i, result;
	for (i = 0; i<8; i++){
		result = getKthIndex(test[i].n1, test[i].n2, test[i].k);
		if (result == test[i].r)
			printf("Success\n");
		else
			printf("fail\n");
	}
}

int getKthIndex(int n1, int n2, int k)
{
	int LCM, result, rem1, rem2;
	if (n1<0 || n2<0)
		return -1;
	if (n1 == 0)
		return n2*k;
	if (n2 == 0)
		return n1*k;

	LCM = (n1*n2) / GCD(n1, n2);

	result = ((k*LCM) / ((LCM / n1) + (LCM / n2) - 1));

	if ((result / n1) + (result / n2) - (result / LCM) < k)
	{
		rem1 = n1 - result%n1;
		rem2 = n2 - result%n2;
		return result + (rem1 < rem2 ? rem1 : rem2);
	}
	else
	{
		rem1 = result%n1;
		rem2 = result%n2;
		return result - (rem1 < rem2 ? rem1 : rem2);
	}
}

int GCD(int a, int b){
	if (b%a == 0)
		return a;
	return GCD(b%a, a);
}