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

}tests[7] = {
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
		{ 1, 2, 3, 19, 15, 11 }, { 1, 2, 3, 11, 15, 19 }
	},
	{
		{ 1, 9, 8, 7 }, { 1, 7, 8, 9 }
	},
	{
		{ 1, 2, 3, 4, 5, 6 }, { 1, 2, 3, 4, 5, 6 }
	}
};

void testcaseCheck();
void Result(int input, int output);
sll sortAscDesc(sll head);
sll reverse(sll head);
sll createLinkedList(int* num);
sll createNode(int num);
int compare(sll result, sll head);

void main(){
	testcaseCheck();
	getchar();
}

void testcaseCheck(){
	sll result = sortAscDesc(NULL);
	printf("Method1:\tMethod2:\n");
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
	result = sortAscDesc(head1);
	compare(result, head2);
}

sll sortAscDesc(sll head){

	sll temp = head;
	sll prev = NULL;
	if (head == NULL)
		return head;
	while (temp->next != NULL && temp->num < temp->next->num){
		prev = temp;
		temp = temp->next;
	}
	if (prev != NULL)
		prev->next = reverse(temp);
	else{
		head = reverse(temp);
	}
	return head;
}

sll reverse(sll head)
{
	sll temp1 = NULL, temp2 = NULL;
	while (head != NULL)
	{
		temp2 = head->next;
		head->next = temp1;
		temp1 = head;
		head = temp2;
	}
	return temp1;
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