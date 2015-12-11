#include<stdio.h>
#include<malloc.h>

struct testcases{

	int input1,input2;
	int merge;
}tests[4] = {
	{ 0, 0, 0 }, { 1, 12345, 12345 }, {1256,2347,1234567}, { 89, 127,12789 }
};

struct node
{
	int num;
	struct node * next;
};

typedef struct node * sll;
void start();
struct node * createLinkedList(int num);
struct node * createNode(int num);
void testcaseCheck();
sll merge(sll, sll);
sll merge2(sll, sll);
sll append(sll head, int e);
int compare(struct node *result, int num);
void Result(sll, sll, int);
void main(){
	testcaseCheck();
	getchar();
}

void testcaseCheck(){

	sll head1,head2;
	printf("Method1:\tMethod2:");
	Result(NULL, NULL,NULL);
	Result(NULL, createLinkedList(12345), createLinkedList(12345));
	Result(createLinkedList(12345), NULL, createLinkedList(12345));
	for (int i = 0; i < 4; i++){
		head1 = createLinkedList(tests[i].input1);
		head2 = createLinkedList(tests[i].input2);
		Result(head1, head2, createLinkedList(tests[i].merge));
	}
}
void Result(sll head1,sll head2,int testresult){
	sll result;
	printf("\n");
	result = merge(head1, head2);
	compare(result, testresult);
	printf("\t\t");
	result = merge2(head1, head2);
	compare(result, testresult);
}
void start(){
	sll l1, l2,result;
	l1 = createLinkedList(123456);
	l2 = createLinkedList(12334);
	result = merge(l1, l2);
	while (result!=NULL)
	{
		printf("%d", result->num);
		result = result->next;
	}
}

struct node * createLinkedList(int num){
	struct node *head = NULL;
	do {
		struct node *newNode = createNode(num % 10);
		newNode->next = head;
		head = newNode;
		num /= 10;
	} while (num > 0);
	return head;
}

sll append(sll head, int e)
{
	sll temp = head, newNode;
	newNode = createNode(e);
	if (head == NULL)
		head = newNode;
	else
	{
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}	
	return head;
}

struct node * createNode(int num){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->num = num;
	temp->next = NULL;
	return temp;
}

sll merge(sll l1, sll l2)
{
	sll p = l1, q = l2;
	sll mergedlist = NULL;
	int k, e;
	while (p != NULL && q != NULL)
	{
		k = p->num - q->num;
		if (k<0)
		{
			e = p->num;
			mergedlist = append(mergedlist, e);
			p = p->next;
		}
		else if (k>0)
		{
			e = q->num;
			mergedlist = append(mergedlist, e);
			q = q->next;
		}
		else
		{
			e = p->num;
			mergedlist = append(mergedlist, e);
			p = p->next;
			q = q->next;
		}
	}
	while (p != NULL)
	{
		e = p->num;
		mergedlist = append(mergedlist, e);
		p = p->next;
	}
	while (q != NULL)
	{
		e = q->num;
		mergedlist = append(mergedlist, e);
		q = q->next;
	}
	return mergedlist;
}
int compare(sll result, sll head) {
	while (head!=NULL && result!=NULL && head->num == result->num) {
		head = head->next;
		result = result->next;
	}
	if(!head && !result)
		printf("success");
	else
		printf("Fail");
}

sll merge2(sll head1, sll head2){
	sll head;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else if (head1->num < head2->num){
		head1->next = merge2(head1->next, head2);
		return head1;
	}
	else if (head1->num > head2->num){
		head2->next = merge2(head1, head2->next);
		return head2;
	}
	else
	{
		head2->next = merge2(head1->next, head2->next);
		return head2;
	}
}