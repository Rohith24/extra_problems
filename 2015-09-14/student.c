#include<stdio.h>
#include<stdlib.h>

struct Student_Details
{
	char *student_ID;
	char *student_name;
	char *department;
	char *section;
};
typedef struct Student_Details *student;

void start();
void read_student_details(student);
student allocate_memory();
int is_student_new(student *,int);
void check_student(student *std, int no_of_studnets);

void main(){
	start();
	getch();
}

void start(){
	student *std=NULL;
	int counter, no_of_studnets, no_of_testcases;
	printf("Enter no.of testcases:");
	scanf("%d", &no_of_testcases);
	while (no_of_testcases > 0){
		printf("\n\nTestcase:\n\nEnter no of students:");
		scanf("%d", &no_of_studnets);
		std = (student *)malloc(no_of_studnets * sizeof(student));
		for (counter = 0; counter < no_of_studnets; counter++)
		{
			printf("\n\nEnter student-%d details:\n\n", counter);
			std[counter] = allocate_memory();
			printf("Enter Student ID:");
			scanf("%s", std[counter]->student_ID);
			if (is_student_new(std, counter) == 1){
				read_student_details(std[counter]);
			}
			else{
				printf("\n***** This Id already exist..****\n\n");
				counter--;
			}
		}
		check_student(std, no_of_studnets);
		no_of_testcases--;
	}
}

void read_student_details(student std){
		printf("Enter Student Name:");
		scanf("%s", std->student_name);
		printf("Enter Deparment:");
		scanf("%s", std->department);
		printf("Enter Section:");
		scanf("%s", std->section);
}

student allocate_memory(){
	student std;
	std = (student *)malloc(sizeof(student));
	std->student_name = (char *)malloc(30 * sizeof(char));
	std->student_ID = (char *)malloc(10 * sizeof(char));
	std->department = (char *)malloc(30 * sizeof(char));
	std->section = (char *)malloc(3 * sizeof(char));
	return std;
}

int is_student_new(student *std, int index){
	int counter;
	for (counter = 0; counter < index; counter++){
		if (strcmp(std[counter]->student_ID, std[index]->student_ID) == 0)
			return 0;
	}
	return 1;
}

void check_student(student *std, int no_of_studnets){
	char *ID = (char *)malloc(10 * sizeof(char));
	int counter;
	printf("\n\nEnter Student Id to check and print details:");
	scanf("%s", ID);
	for (counter = 0; counter <no_of_studnets; counter++){
		if (strcmp(std[counter]->student_ID, ID) == 0){
			printf("Student ID:%s\nStudent Name:%s\nDepartment:%s\nSection:%s\n", std[counter]->student_ID, std[counter]->student_name, std[counter]->department, std[counter]->section);
			return;
		}
	}
	printf("Student does not exist.");
}

