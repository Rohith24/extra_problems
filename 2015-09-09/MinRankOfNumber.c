#include<stdio.h>
#include<stdlib.h>
struct testcases{
	unsigned int number,index;
};
typedef struct testcases *test;
struct permitationarray{
	int *perarr,nper,n,*array;
};
typedef struct permitationarray *perarray;
void start();
test* initializetestcases();
void checktest(test tc);
perarray makenullperarray();
int validate(int number);
int divide(unsigned int a,int * );
void sort(int* array,int n);
void permutations(perarray,int);
void swap(int *x,int *y);
void perArray(perarray);
int indexof(int *per,int nper,int b);
main(){
	start();
}
void start(){
	test *tc;
	int i;
	tc=initializetestcases();
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
	tc[0]->number=213;
	tc[0]->index=2;
	tc[1]->number=1234;
	tc[1]->index=0;
	tc[2]->number=9087;
	tc[2]->index=22;
	tc[3]->number=756;
	tc[3]->index=5;
	tc[4]->number=22;
	tc[4]->index=0;
	tc[5]->number=865;
	tc[5]->index=2;
	tc[6]->number=0;
	tc[6]->index=0;
	tc[7]->number=43;
	tc[7]->index=1;
	return tc;
}
void checktest(test tc){
	perarray per=makenullperarray();
	if(validate(tc->number)==1){
		per->n=divide(tc->number,per->array);
		sort(per->array,per->n);
		permutations(per,0);
		if(tc->index==indexof(per->perarr,per->nper,tc->number))
			printf("Success\n");
		else
			printf("Fail\n");
		free(per->array);
		free(per->perarr);
		free(per);
	}
	else
		printf("Invalid number.\n");
}
perarray makenullperarray(){
	perarray per;
	per=(perarray)malloc(sizeof(struct permitationarray));
	per->nper=0;
	per->n=0;
	per->array=(int*)malloc(per->n*sizeof(int));
	per->perarr=(int*)malloc(per->nper*sizeof(int));
	return per;
}
int validate(int number){
	int i,j,n,*a=(int *)malloc(sizeof(int));
	n=divide(number,a);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]==a[j])
				return 0;
	return 1;	
}
int divide(unsigned int number,int *array){
	int n=0;
	while(number>0){
		array[n++]=number%10;
		number=number/10;
	}
	return n;
}
void sort(int* array,int n){
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(array[i]>array[j]){
				int t=array[i];
				array[i]=array[j];
				array[j]=t;
			}
}
void permutations(perarray per,int i) {
  int j = i;
  if (per->n == i){
     perArray(per);
     return;
  }
  for (j = i; j < per->n; j++) { 
     swap(&per->array[i],&per->array[j]);
     permutations(per,i+1);
     swap(&per->array[i],&per->array[j]);
  }
  return;
}
void swap(int *x,int *y){
	int t=*x;
	*x=*y;*y=t;
}
void perArray(perarray per){
	int i,sum=0;
	for(i=0;i<per->n;i++)
		sum=sum*10+per->array[i];
	per->perarr[per->nper++]=sum;
	per->perarr=(int *)realloc(per->perarr,per->nper*sizeof(int));
}
int indexof(int *per,int nper,int b){
	int i;
	for(i=0;i<nper;i++){
		if(per[i]==b)
			return i;
	}
	return -1;
}
