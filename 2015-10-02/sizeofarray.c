#include<stdio.h>
#include<stdlib.h>

struct testcases
{
	int *array;
	int size;
	int len;
}testcasearray[10] = {
	{ (int[18]){ 1, 2, 3, 4, 5, 6, 7, 8, 9, 3, 0, 0, 0, 0, 0, 0, 0, 0 },18, 8 },
	{ (int[12]){ 1, 2, 3, 4, 5, 6, 1, 0, 0, 0, 0, 0 },12, 5 },
	{ (int[5]){1, 2, 0, 0, 0},5, -1 },
	{ (int[1]){0},1, -2 },
	{ (int[26]){-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6,7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0},26,12 },
	{ {0},1, 0 },
	{ (int[38]){-8,-7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0} ,38,18},
	{ (int[12]){ 1, 2, 3, 4, 5, 6, 1, 0, 0, 0, 0, 0 }, 12, 5 },
};
void start();
int validate(int *array,int size);
void method1(struct testcases tc);
void method2(struct testcases tc);
void method3(struct testcases tc);
int binarysearch(int *a, int start, int last);
int count(int *array, int num, int counter);
void main(){
	start();
	getch();
}

void start(){
	int counter1;
	for (counter1 = 0; counter1 < 8; counter1++){
		if (validate(testcasearray[counter1].array,testcasearray[counter1].size)){
			method1(testcasearray[counter1]);
			method2(testcasearray[counter1]);
			method3(testcasearray[counter1]);
		}
		else
		{
			printf("Invalid array\n");
		}
	}
}

int validate(int *array,int size){
	int counter = 0, numsize = 1, zerosize = 0;
	if (size > 1){
		while (array[counter] < array[counter + 1] && counter < size){
			numsize++;
			counter++;
		}
		counter++;
		if (array[counter] != 0 && counter < size){
			counter++;
			while (counter < size&&array[counter] == 0){
				zerosize++;
				counter++;
			}
		}
		else{
			return 0;
		}
		if (numsize - 1 == zerosize){
			return 1;
		}
	}
	return 0;;
}

void method1(struct testcases tc){
	int counter = 0, len = 0;
	while (tc.array[counter]<tc.array[counter + 1]){
		len++;
		counter++;
	}
	if (len == tc.len){
		printf("Success\t");
	}
	else
	{
		printf("Fail\t");
	}
}

void method2(struct testcases tc){
	int counter = 0, sum = 1;
	if (tc.array[counter + 1] > tc.array[counter]){
		counter++;
		sum = tc.array[counter];
	}
	while (sum != 0){
		counter *= 2;
		if (tc.array[counter] == 0 && tc.array[counter+1] !=0)
			continue;
		sum *= tc.array[counter];
	}
	if (binarysearch(tc.array, counter / 2, counter) - 1 == tc.len){
		printf("Success\t");
	}
	else
	{
		printf("Fail\t");
	}

}

int binarysearch(int *a, int start, int last){
	int middle = (start + last) / 2;
	if (start <= last){
		if (a[middle] > 0)
			start = middle + 1;
		else 
			last = middle - 1;
		return binarysearch(a, start, last);
	}
	else
		return middle;
}

void method3(struct testcases tc){
	int counter = 1, sum = 1;
	while (sum != 0){
		counter *= 2;
		sum *= tc.array[counter];
	}
	if (count(tc.array,0,counter) == tc.len){
		printf("Success\n");
	}
	else
	{
		printf("Fail\n");
	}
}

int count(int *array, int num,int counter){
	int counter1 = 1, len = 1;
	while (array[counter - counter1] == 0 && array[counter + counter1] == 0){
		len += 2; 
		counter1++;
	}
	while (array[counter - counter1] == 0){
		len++;
		counter1++;
	}
	while (array[counter + counter1] == 0){
		len++;
		counter1++;
	}
	return len;
}

