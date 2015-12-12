#include<stdio.h>
#include<malloc.h>

struct testcases{

	int input, output;
}tests[5] = {
	{ 0, 0 }, { 12345, 54321 }, { 11111, 11111 }, { 9872146, 6412789 }, { 2, 2 }
};

struct node
{
	int num;
	struct node * next;
};

typedef struct node * sll;

void testcaseCheck();
void Result(int input, int output);
void Reverse(sll head, sll **newHead, sll pre);
sll Reverse2(sll head);
sll getResult(sll head);
sll createLinkedList(int num);
sll createNode(int num);
void main(){
	testcaseCheck();
	getchar();
}
void testcaseCheck(){
	printf("Method1:\tMethod2:");
	Result(NULL, NULL);
	for (int i = 0; i < 5; i++){
		Result(tests[i].input, tests[i].output);
	}
}
void Result(int input,int output){
	sll result;
	sll head1 = createLinkedList(input);
	sll head2 = createLinkedList(output);
	printf("\n");
	result = getResult(head1);
	compare(result, head2);
	printf("\t\t");
	head1 = createLinkedList(input);
	result = Reverse2(head1);
	compare(result, head2);
}

sll getResult(sll head){
	sll newHead;
	if (head == NULL)
		return NULL;
	else if (head->next == NULL){
		return head;
	}
	Reverse(head, &newHead, NULL);
	return newHead;
}

void Reverse(sll head, sll **newHead, sll pre){
	if (head->next != NULL){
		*newHead = head->next;
		Reverse(head->next, newHead, head);
	}
	head->next = pre;
}

sll Reverse2(sll head){
	sll temp1 = NULL, temp2 = NULL;
	while (head != NULL){
		temp2 = head->next;
		head->next = temp1;
		temp1 = head;
		head = temp2;
	}
	return temp1;
}

sll createLinkedList(int num){
	sll head = NULL;
	do {
		sll newNode = createNode(num % 10);
		newNode->next = head;
		head = newNode;
		num /= 10;
	} while (num > 0);
	return head;
}

sll createNode(int num){
	sll temp = (struct node *)malloc(sizeof(struct node));
	temp->num = num;
	temp->next = NULL;
	return temp;
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
