#include<stdio.h>
#include<stdlib.h>

struct testcases
{
	int *array, length, num1, num2;
}testcasearray[10] = {
	{
		(int[5]){
		3, 6, -68, 86, 1
	}, 5, 3, 1
	},
	{
		(int[5]){
			10, -13, 43, 14, 23,
		}, 5, 10, 14
	},
	{
		(int[10]){
			3, 5, 68, 86, 1, 43, 53, 23, 41, 0
		}, 10, 0, 1
	},
	{
		(int[4]){
			27, 42, -42, 156
		}, 4, 27, -42
	},
	{
		(int[5]){
			0, 0, 0, 0, 0
		}, 5, 0, 0
	},
	{
		(int[7]){
			0, 23, -12, 12, -32, 32, 32
		}, 7, 32, 32
	},
	{
		(int[1]){1}, 1, 0, 0
	}

};
void start();
void mindiffpair(struct testcases*);
void check_result(struct testcases*, int num1, int num2);


void main()
{
	start();
	getch();
}

void start()
{
	int counter;
	for (counter = 0; counter < 7; counter++){						//counter less than no of test casees
		mindiffpair(&testcasearray[counter]);
		printf("\n");
	}
}


void mindiffpair(struct testcases *tcarray)
{
	int counter1, counter2, diff, num1 = 0, num2 = 1, min_diff;
	if (tcarray->length >= 2){
		min_diff = tcarray->array[0] - tcarray->array[1];
		if (min_diff < 0)
			min_diff *= -1;
		for (counter1 = 0; counter1 < tcarray->length - 1; counter1++){
			for (counter2 = counter1 + 1; counter2 < tcarray->length; counter2++){
				diff = tcarray->array[counter1] - tcarray->array[counter2];
				if (diff < 0)
					diff *= -1;
				if (min_diff>diff){
					min_diff = diff;
					num1 = counter1;
					num2 = counter2;
				}

			}
		}
		check_result(tcarray, num1, num2);
	}
	else{
		printf("Array size is atleast 2\n");
	}
}


void check_result(struct testcases *tcarray, int num1, int num2){
	if (tcarray->num1 == tcarray->array[num1] && tcarray->num2 == tcarray->array[num2]){
		printf("Success");
	}
	else
	{
		printf("Fail.");
	}
}