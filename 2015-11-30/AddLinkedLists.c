#include <stdio.h>
#include <stdlib.h>
struct node
{
	int num;
	struct node *next;
};

struct testcases
{
	int input1,input2;
	int result;
}test[6] = {
	{ 0, 0, 0 },
	{ 0, 1, 1 },
	{ 4, 0, 4 },
	{ 135, 246, 381 },
	{ 1478, 389, 1867 },
	{ 947, 9892, 10839 }
};

typedef struct node * sll;
void testcaseCheck();
sll createLinkedList(int num);
sll createNode(int num);
sll linkedListAdder(sll head1, sll head2, int carry);
sll reverse(sll head);
int compare(sll result, int num);
void Result(sll, sll, sll);

int main()
{
	testcaseCheck();
	getchar();
}

void testcaseCheck()
{
	int i;
	sll head1, head2, result;
	for (i = 0; i<6; i++)
	{
		head1 = createLinkedList(test[i].input1);
		head2 = createLinkedList(test[i].input2);
		result = createLinkedList(test[i].result);
		Result(reverse(head1), reverse(head2), result);
	}
}

void Result(sll head1, sll head2, int testresult){
	sll result;
	int carry = 0;
	result = linkedListAdder(head1, head2, carry);
	compare(reverse(result), testresult);
	printf("\n");
}

sll linkedListAdder(sll head1, sll head2, int carry)
{
	sll node;
	if (head1 != NULL&&head2 != NULL)
	{
		node = createNode((head1->num + head2->num + carry) % 10);
		carry = (head1->num + head2->num + carry) / 10;
		node->next = linkedListAdder(head1->next, head2->next, carry);
		return node;
	}
	else if (head1 == NULL&&head2 == NULL)
	{
		if (carry > 0)
		{
			node = createNode(carry);
			node->next = NULL;
			return node;
		}
		else
			return NULL;
	}
	else
	{
		if (head2 == NULL)
		{
			node = createNode((head1->num + carry) % 10);
			carry = (head1->num + carry) / 10;
			node->next = linkedListAdder(head1->next, head2, carry);
			return node;
		}
		else
		{
			node = createNode((head2->num + carry) % 10);
			carry = (head2->num + carry) / 10;
			node->next = linkedListAdder(head1, head2->next, carry);
			return node;
		}
	}
	return NULL;
}

sll reverse(sll head)
{
	sll t1 = NULL, t2 = NULL;
	while (head != NULL)
	{
		t2 = head->next;
		head->next = t1;
		t1 = head;
		head = t2;
	}
	return t1;
}

sll createLinkedList(int num){
	struct node *head = NULL;
	do {
		struct node *newNode = createNode(num % 10);
		newNode->next = head;
		head = newNode;
		num /= 10;
	} while (num > 0);
	return head;
}

sll createNode(int num){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
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