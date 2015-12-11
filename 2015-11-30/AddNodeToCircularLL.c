#include<stdio.h>
#include<malloc.h>

struct testcases{

	int input, addData, output;
}tests[4] = {		//negative number for end of sequence
	{ 12,3,123 },
	{ 12345,3,123345 },
	{ 5,3,35 },
	{ 1111,1,11111 }
};

struct node
{
	int num;
	struct node * next;
};

typedef struct node * cll;

void testcaseCheck();
cll createCLinkedList(int num);
cll createNode(int num);
void Result(cll input, int addData, cll output);
int compare(cll result, cll testresult);
cll addNodeToCll(cll head, int num);
void main(){
	
	testcaseCheck();
	getchar();

}
void testcaseCheck(){

	cll head1, head2;
	Result(NULL, 0, createCLinkedList(0));
	for (int i = 0; i < 4; i++){
		printf("\n");
		Result(createCLinkedList(tests[i].input), tests[i].addData, createCLinkedList(tests[i].output));
	}
}

void Result(cll input, int addData, cll output){
	cll head = addNodeToCll(input, addData);

	if (compare(head, output))
		printf("Success");
	else
		printf("Fail");
	free(head);
}

cll addNodeToCll(cll head, int num){

	cll temp = head;
	cll newNode = createNode(num);

	if (temp == NULL){
		newNode->next = newNode;
		return newNode;
	}
	if (num < temp->num){
		while (temp->next != head)
			temp = temp->next;
		temp->next = newNode;
		newNode->next = head;
		return newNode;
	}
	else{
		while (temp->next->num < num && temp->next != head)
			temp = temp->next;
		newNode->next = temp->next;
		temp->next = newNode;
		return head;
	}
}

cll createCLinkedList(int num) {
	cll start = NULL, newNode, end = NULL;
	newNode = createNode(num % 10);
	newNode->next = start;
	start = end = newNode;
	num /= 10;
	while (num)
	{
		newNode = createNode(num % 10);
		newNode->next = start;
		start = newNode;
		num /= 10;
	}
	end->next = start;
	return start;
}
cll createNode(int num){
	cll temp = (cll)malloc(sizeof(struct node));
	temp->num = num;
	temp->next = NULL;
	return temp;
}

int compare(cll result, cll output) {
	int hd1, hd2;
	hd1 = result->num;
	hd2 = output->num;
	do {
		output = output->next;
		result = result->next;
	} while (output->num == result->num && output->num != hd1  && result->num != hd2);
	return output->num == result->num;
}