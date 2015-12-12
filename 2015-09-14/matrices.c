#include<stdio.h>
#include<stdlib.h>

struct matrices{
	int rows, columns;
	int **array;
};
typedef struct matrices matrix;

struct testcases{
	matrix m1, m2;
	matrix result;
}testcasearray[3] = {
	{ { 2, 2, (int[2][2]) { (int[2]){ 1, 0 }, (int[2]){ 0, 1 } } }, { 2, 2, (int[2][2]) { (int[2]){ 1, 2 }, (int[2]){ 3, 4 } } }, { 2, 2, (int[2][2]) { (int[2]){ 1, 2 }, (int[2]){ 3, 4 } } } },
	{ { 3, 2, (int[3][2]) { (int[2]){ 1, 0 }, (int[2]){ 0, 1 }, (int[2]){ 1, 1 } } }, { 3, 2, (int[3][2]) { (int[2]){ 1, 2 }, (int[2]){ 3, 4 },(int[2]){ 1, 2 } } }, { 0, 0 } },

	{ { 3, 3, (int[3][3]) { (int[3]){ -1, 6, 8 }, (int[3]){ 8, 9, 7 }, (int[3]){ -9, -1, -7 } } }, { 3, 3, (int[3][3]) { (int[3]){ 1, 2, 3 }, (int[3]){ 3, 4, -8 }, (int[3]){ 1, 2, 0 } } }, 
		{ 3, 3, (int[3][3]) { (int[3]){ 25, 38,-51 }, (int[3]){ 42, 66, -48 }, (int[3]){ -19, -36, -19 } } } 
	},
};

void start();
int ** allocate_memory(int rows, int cols);
int check_matrix(matrix m1, matrix m2);
matrix multiply_2_matrices(matrix, matrix);
int compare_2_matrices(matrix m1, matrix m2);

main(){
	start();
	getch();
}

void start(){
	int counter;
	matrix result;
	for (counter = 0; counter < 3; counter++){
		if (check_matrix(testcasearray[counter].m1, testcasearray[counter].m2) == 1){
			result = multiply_2_matrices(testcasearray[counter].m1, testcasearray[counter].m2);
			if (compare_2_matrices(testcasearray[counter].result, result) == 1)
				printf("Success\n\n");
			else
				printf("Fail\n\n");
		}
		else
			printf("matrix multiplication not possible.\n\n");
	}
}

int check_matrix(matrix m1, matrix m2){
	if (m1.columns == m2.rows)
		return 1;
	return 0;
}

matrix multiply_2_matrices(matrix m1, matrix m2){
	matrix result;
	int counter1, counter2, counter3;
	result.rows = m1.rows;
	result.columns = m2.columns;
	result.array = allocate_memory(result.rows, result.columns);
	for (counter1 = 0; counter1 < result.rows; counter1++){
		for (counter2 = 0; counter2 < result.columns; counter2++){
			for (counter3 = 0; counter3 < m1.rows; counter3++)
				result.array[counter1][counter2] += m1.array[counter1][counter3] * m2.array[counter3][counter2];
		}
	}
	return result;
}

int ** allocate_memory(int rows, int cols){
	int ** array,counter;
	array = (int **)malloc(rows*sizeof(int*));
	for (counter = 0; counter < rows;counter++){
		array[counter] = (int *)calloc(cols,sizeof(int));
	}
	return array;
}

int compare_2_matrices(matrix m1, matrix m2){
	int counter1, counter2;
	if (m1.rows == m2.rows&&m1.columns==m2.columns){
		for (counter1 = 0; counter1 < m1.rows; counter1++){
			for (counter2 = 0; counter2 < m1.columns; counter2++){
				if (m1.array[counter1][counter2] != m2.array[counter1][counter2])
					return 0;
			}
		}
		return 1;
	}
	else{
		return 0;
	}
	
}