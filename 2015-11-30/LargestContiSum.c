#include<stdio.h>
#include<malloc.h>
struct testcases
{
	int *Array;
	int len;
	int *resultArray;
	int sum;
}tests[3] = {
	{ (int[10]){ 2, -4, 1, 2, 3, -5, 0, 6, -2, 1 }, 10, (int[6]){ 1, 2, 3, -5, 0, 6 }, 7 }, 
	{ (int[7]){1, 2, 3, 5, -10, 20, 40}, 7, (int[7]){ 1, 2, 3, 5, -10, 20, 40 }, 61 },
	{ (int[4]){ -1, -2, -3, -4 }, 4, (int[1]){ -1 },-1 }
};

void testcaseCheck();
void compare(int a1, int a2, int *output, int *result);
int largerstcontiSum(int* Array, int len);
void main(){
	testcaseCheck();
	getchar();
}

void testcaseCheck(){
	int result = largerstcontiSum(NULL,0,NULL);
	int *output = (int *)malloc(sizeof(int));
	compare(result, -2147483,NULL,NULL);
	for (int i = 0; i < 3; i++){
		result=largerstcontiSum(tests[i].Array, tests[i].len,output);
		compare(result,tests[i].sum,output,tests[i].resultArray);
	}
}
int largerstcontiSum(int* Array, int len,int *output){
	int sum = -2147483;
	int tempSum = 0;
	int a, b, s, i;
	if (Array != NULL){
		a = b = s = 0;
		for (i = 0; i < len; i++) {
			tempSum += Array[i];
			if (tempSum > sum) {
				sum = tempSum;
				a = s;
				b = i;
			}
			if (tempSum < 0) {
				tempSum = 0;
				s = i + 1;
			}
		}
		i = 0;
		while (a<=b){
			output = realloc(output, sizeof(int)*(i + 1));
			output[i] = Array[a];
			i++; a++;
		}
		output[i] = i;
	}
	return sum;
}
void compare(int a1, int a2,int *output,int *result) {
	if (a1 == a2){
		if (output != NULL&&result != NULL){
			for (int i = 0; i != output[i]; i++){
				if (output[i] != result[i]){
					printf("Fail\n");
					break;
				}
			}
		}
		printf("success\n");
	}
	else
		printf("Fail\n");
}