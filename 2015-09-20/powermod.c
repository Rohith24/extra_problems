#include<stdio.h>
#include<stdlib.h>
struct testcases{
	unsigned long int x, y, z, result;
};
typedef struct testcases *test;
void start();
test* initializetestcases();
void checktest(test tc);
unsigned int powerxy(unsigned int, unsigned int);
unsigned int powerxy2(unsigned int x, unsigned int y);
unsigned int powermod(unsigned int x, unsigned int y, unsigned int z);
unsigned int powermod2(unsigned int x, unsigned int y, unsigned int z);
void checkres(unsigned int result1, unsigned int result2);

main(){
	start();
	getch();
}
void start(){
	test *tc;
	int i;
	tc = initializetestcases();
	printf("Testcase no.\tMethod-1 \tMethod-2\tMethod-3 \tMethod-4\n");
	for (i = 0; i<8; i++){
		printf("Test case-%d:\t", i + 1);
		checktest(tc[i]);
	}
}
void checktest(test tc){
	long result;
	if (tc->z == 0)
		printf("Unable to find mod.\n");
	else{
		result = ((long)powerxy(tc->x, tc->y) % tc->z);
		checkres(result, tc->result);
		result = ((long)powerxy2(tc->x, tc->y) % tc->z);
		checkres(result, tc->result);
		result = ((long)powermod(tc->x, tc->y, tc->z));
		checkres(result, tc->result);
		result = ((long)powermod2(tc->x, tc->y, tc->z));
		checkres(result, tc->result);
		printf("\n");
	}
}
void checkres(unsigned int result1,unsigned int result2){
	if (result1 == result2)
		printf("Sucuess\t\t");
	else
		printf("Failed\t\t");
}
test* initializetestcases(){
	test *tc = (test *)malloc(10 * sizeof(struct testcases *));
	int i;
	for (i = 0; i<8; i++){
		tc[i] = (test)malloc(sizeof(struct testcases *));
	}
	tc[0]->x = 2;
	tc[0]->y = 4;
	tc[0]->z = 6;
	tc[0]->result = 4;
	tc[1]->x = 6;
	tc[1]->y = 7;
	tc[1]->z = 58;
	tc[1]->result = 28;
	tc[2]->x = 4;
	tc[2]->y = 5;
	tc[2]->z = 8;
	tc[2]->result = 0;
	tc[3]->x = 4;
	tc[3]->y = 2;
	tc[3]->z = 7;
	tc[3]->result = 4;
	tc[4]->x = 7;
	tc[4]->y = 3;
	tc[4]->z = 4;
	tc[4]->result = 3;
	tc[5]->x = 41;
	tc[5]->y = 2;
	tc[5]->z = 0;  //x%0  unable to find
	tc[5]->result = -1;
	tc[6]->x = 0;	//0^7
	tc[6]->y = 7;
	tc[6]->z = 3;
	tc[6]->result = 0;
	tc[7]->x = 3;
	tc[7]->y = 4;		//5^0=1
	tc[7]->z = 3;
	tc[7]->result = 0;
	return tc;
}
unsigned int powerxy(unsigned int x, unsigned int y){
	if (y == 1)
		return x;
	if (y == 0)
		return 1;
	return x*powerxy(x, y - 1);
}
unsigned int powerxy2(unsigned int x, unsigned int y){
	int i, sum = x;
	if (y == 0)
		return 1;
	for (i = 1; i<y; i++)
		sum = sum*x;
	return sum;
}

unsigned int powermod(unsigned int x, unsigned int y,unsigned int z){
	int i, sum = 1;
	if (x == z){
		return 0;
	}
	else{
		for (i = 0; i < y; i++){
			sum = sum*(x%z);
		}
		return sum%z;
	}
}

unsigned int powermod2(unsigned int x, unsigned int y, unsigned int z){
	int i, sum = 1;
	for (i = 0; i < y;i++){
		sum = (sum*x) % z;
	}
	return sum;
}