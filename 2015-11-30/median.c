#include<stdio.h>
#include<malloc.h>

struct testcases{

	int input;
	int med;
}tests[7] = {
	{ NULL, }, { 0, 0 }, { 3, 3 }, { 89, 9 }, { 987652, 6 }, { 431207549, 0 }, { 7812, 1 }
};

struct node
{
	int num;
	struct node * next;
};

struct node * createLinkedList(int num);
struct node * createNode(int num);
void testcaseCheck();
void checkResult(int m, int n);
struct node* Median1(struct node* head);
int Median2(struct node *second, struct node *first);


void main(){
	testcaseCheck();
	getchar();
}

void testcaseCheck(){

	struct node* head;

	printf("Method1:\tMethod2:");
	for (int i = 0; i < 7; i++){
		head = createLinkedList(tests[i].input);
		printf("\n");
		checkResult(Median1(head)->num,tests[i].med);
		printf("\t\t");
		checkResult(Median2(head, head), tests[i].med);
	}


}
void checkResult(int m,int n){
	if (m == n)
		printf("success");
	else
		printf("Fail");
}

struct node * createLinkedList(int num){
	struct node *head=NULL;
	do {
		struct node *newNode = createNode(num % 10);
		newNode->next = head;
		head = newNode;
		num /= 10;
	} while (num > 0);
	return head;
}
struct node * createNode(int num){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->num = num;
	temp->next = NULL;
	return temp;
}


struct node* Median1(struct node* head){

	struct node* first;
	struct node* second;
	if (head == NULL)
		return NULL;
	first = second = head;
	while (first != NULL && first->next != NULL){
		second = second->next;
		first = first->next->next;
	}
	return second;

}

int Median2(struct node *second, struct node *first){
	int n;
	if (first!=NULL&&first->next != NULL)
	{
		second = second->next;
		first = first->next->next;
		return Median2(second, first);
	}
	else
	{
		n = second->num;
		return n;
	}
}
