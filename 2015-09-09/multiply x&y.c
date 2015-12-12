#include <stdio.h>
#include<stdlib.h>
struct testcases{
	int x,y,result;
};
typedef struct testcases *test;
void start();
test* initializetestcases();
void checktest(test tc);
int multiply(int,int,int);
int multiply2(int a,int b,int c);
int add(int,int);
main(){
	start();
}
void start(){
     test *tc;
	int i;
	tc=initializetestcases();
	printf("Testcase no.\tMethod-1 \tMethod-2\n");
	printf("----------------------------------------------\n");
	for(i=0;i<8;i++){
		printf("Test case-%d:\t",i+1);
		checktest(tc[i]);
	}
}
test* initializetestcases(){
	test *tc=(test *)malloc(10*sizeof(struct testcases *));
	int i;
	for(i=0;i<8;i++){
		tc[i]=(test)malloc(sizeof(struct testcases *));
	}
	tc[0]->x=100;
	tc[0]->y=45;
	tc[0]->result=4500;
	tc[1]->x=67;
	tc[1]->y=7;
	tc[1]->result=469;
	tc[2]->x=98;
	tc[2]->y=12;
	tc[2]->result=1176;
	tc[3]->x=46;
	tc[3]->y=0;
	tc[3]->result=0;
	tc[4]->x=182;
	tc[4]->y=4;
	tc[4]->result=728;
	tc[5]->x=471;
	tc[5]->y=23;
	tc[5]->result=10833;
	tc[6]->x=6;
	tc[6]->y=7;
	tc[6]->result=46;	//result=42
	tc[7]->x=99;
	tc[7]->y=6;
	tc[7]->result=594;
	return tc;
}
void checktest(test tc){
		if(tc->result==multiply(tc->x,tc->y,0))
			printf("Scuccess\t");
		else
			printf("Fail\t\t");
		
		if(tc->result==multiply2(tc->x,tc->y,0))
			printf("Scuccess\n");
		else
			printf("Fail\n");
}
int multiply(int a,int b,int c){
	while(b!=0)
	{
		if (b&01){
			c=add(c,a);
		}
        a<<=1;
        b>>=1; 
	}
	return c;
}
int multiply2(int a,int b,int c){
	if(b==0)
		return c;
	if(b&01)
		return multiply2(a<<1,b>>1,add(c,a));
	else
		return multiply2(a<<1,b>>1,c);
}
int add(int x,int y){
    if (y==0)
        return x;
    else
        return add(x^y,(x&y)<<1);
}
