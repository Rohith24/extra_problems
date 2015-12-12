#include<stdio.h>
#include<stdlib.h>

struct testcases
{
	int *array,length, min, max;
}testcasearray[7] = {					//no of testcase=6
	{
		(int[5]){
		3, 5, -68, 86, 1
	}, 5, -68, 86
	},
	{
		(int[5]){
			10, -13, 43, 14, 23,
		}, 5, -13, 43
	},
	{
		(int[10]){
			3, 5, 68, 86, 1, 43, 53, 23, 41, 0
		}, 10, 0, 7
	},
	{
		(int[4]){
			27, 42, 431, 156
		}, 4, 27, 156
	},
	{
		(int[5]){
			0, 0, 0, 0, 0
		}, 5, 0, 0
	},
	{
		(int[7]){
			0, 23, -12, 12, -32, 32, 32
		}, 7, -32, 32
	},
	{
		(int[1]){
			0
		}, 1, 0, 0
	}

};
void start();
void sort(int *);
void check_result(struct testcases*, int min, int max);
void swap(int *ele1, int *ele2);
int find_min(int *array, int length);
int find_max(int *array, int length);

void main()
{
	start();
	getch();
}

void start()
{
	int counter, rmin, rmax;
	printf("Method:1\tMethod:2\n");
	printf("________________________\n");
	for (counter = 0; counter < 7; counter++){						//counter less than no of test casees
		rmin = find_min(testcasearray[counter].array, testcasearray[counter].length);
		rmax = find_max(testcasearray[counter].array, testcasearray[counter].length);
		check_result(&testcasearray[counter], rmin, rmax);
		sort(testcasearray[counter].array,testcasearray[counter].length);
		rmin = testcasearray[counter].array[0];
		rmax = testcasearray[counter].array[testcasearray[counter].length - 1];
		check_result(&testcasearray[counter], rmin, rmax);
		printf("\n");
	}
}


void sort(int *array,int length)
{
	int counter1, counter2;
	for (counter1 = 0; counter1 <length-1; counter1++){
		for (counter2 = counter1 + 1; counter2 < length; counter2++)
		if (array[counter1] > array[counter2])
			swap(&array[counter1], &array[counter2]);
	}
}

void swap(int *ele1, int *ele2){
	int temp = *ele1;
	*ele1 = *ele2;
	*ele2 = temp;
}

int find_min(int *array, int length){
	int min = array[0], counter;
	for (counter = 1; counter < length; counter++){
		if (array[counter] < min)
			min = array[counter];
	}
	return min;
}

int find_max(int *array, int length){
	int max = array[0], counter;
	for (counter = 1; counter < length; counter++){
		if (array[counter] > max)
			max = array[counter];
	}
	return max;
}

void check_result(struct testcases *tcarray, int min, int max){
	if (tcarray->min == min && tcarray->max == max){
			printf("Success\t\t");
		}
		else
		{
			printf("Fail.\t\t");
		}
}