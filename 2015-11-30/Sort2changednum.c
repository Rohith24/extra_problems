#include<stdio.h>
#include<malloc.h>

struct node
{
	int num;
	struct node * next;
};

typedef struct node * sll;

struct testcases{

	int input[20];
	int output[20];

}tests[8] = {
	{
		{ 4 }, { 4 }
	},
	{
		{ 3, 2 }, { 2, 3 }
	},
	{
		{ 1, 2, 4, 6, 7, 10, 9 }, { 1, 2, 4, 6, 7, 9, 10 }
	},
	{ 
		{ 1, 2, 3, 15, 10, 4 }, { 1, 2, 3, 4, 10, 15 }
	},
	{ 
		{ 1, 2, 3, 19, 15, 11}, { 1, 2, 3, 11, 15, 19 }
	},
	{
		{ 1, 1, 2, 4, 2 }, { 1, 1, 2, 2, 4 }
	},
	{
		{ 1, 1, 1, 1, 1, 3, 1 }, { 1, 1, 1, 1, 1, 1, 3 }
	}
};

void testcaseCheck();
void Result(int input, int output);
sll Sort2changednum(sll head);
sll Sort2changednum2(sll head);
void swap(int *a, int *b);
sll createLinkedList(int* num);
sll createNode(int num);
int compare(sll result, sll head);

void main(){
	testcaseCheck();
	getchar();
}

void testcaseCheck(){
	sll result = Sort2changednum(NULL);
	printf("Method1:\tMethod2:\n");
	compare(result, NULL);
	printf("\t\t");
	result = Sort2changednum2(NULL);
	compare(result, NULL);
	for (int i = 0; i < 7; i++){
		Result(tests[i].input, tests[i].output);
	}
}

void Result(int input, int output){
	sll result;
	sll head1 = createLinkedList(input);
	sll head2 = createLinkedList(output);
	printf("\n");
	result = Sort2changednum(head1);
	compare(result, head2);
	printf("\t\t");
	head1 = createLinkedList(input);
	result = Sort2changednum2(head1);
	compare(result, head2);
}

sll Sort2changednum(sll head){
	sll start = head;
	int *a = NULL, *b = NULL;
	if (start!=NULL&&start->next != NULL){
		while (start != NULL)
		{
			if (start->next->num < start->num)
				break;
			start = start->next;
		}
		a = &start->num;
		while (start != NULL&&start->num <= *a)
		{
			b = &start->num;
			start = start->next;
		}
		if (a != NULL&&b != NULL)
			swap(a, b);
	}
	return head;
}

sll Sort2changednum2(sll head){

	sll node1 = NULL;
	sll node2 = NULL;
	sll temp = head;
	int flag1 = 0, flag2 = 0;
	if (head != NULL){
		while (temp->next != NULL){
			if (temp->num > temp->next->num && flag1 != 1){
				node1 = temp;
				flag1 = 1;
			}
			else if (temp->num > temp->next->num && flag1 == 1 && flag2 != 1){
				node2 = temp->next;
				flag2 = 1;
				break;
			}
			temp = temp->next;
		}
		if (flag2 == 0 && flag1 == 1){
			flag2 = 1;
			node2 = node1->next;
		}
		if (flag1 && flag2)
			swap(node1, node2);
	}
	return head;
}

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

sll createNode(int num) {
	sll newNode = (sll)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

sll createLinkedList(int* num) {
	sll head = NULL;
	sll temp = NULL;
	int i = 0;

	while (num[i]>0) {
		sll newNode = createNode(num[i]);
		if (head == NULL)
			head = temp = newNode;
		else{
			temp->next = newNode;
			temp = temp->next;
		}
		i++;
	}
	return head;
}

int compare(sll result, sll head) {
	while (head != NULL && result != NULL && head->num == result->num) {
		head = head->next;
		result = result->next;
	}
	if (!head && !result)
		printf("success");
	else
		printf("Fail");
}