#include<stdio.h>
#include<malloc.h>

struct testcases{

	int *input, addData, *output;
}tests[4] = {		//negative number for end of sequence
	{ (int[3]){ 1, 2, -1 }, 3, (int[4]){ 1, 2, 3, -1 } },
	{ (int[5]){0, 1, 18, 20,-1}, 10, (int[6]){ 0, 1, 10, 18, 20,-1 } },
	{ (int[2]){1,-1}, 2, (int[3]){ 1, 2,-1 } },
	{ (int[5]){1, 1, 1, 1,-1}, 1, (int[6]){ 1, 1, 1, 1, 1,-1} }
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
	Result(NULL, 0, createCLinkedList((int[1]){0}));
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

cll createCLinkedList(int* num) {
	cll head = NULL;
	cll temp = NULL;
	int i = 0;
	
	while (num[i]>=0) {
		cll newNode = createNode(num[i]);

		if (head == NULL)
			head = temp = newNode;
		else{
			temp->next = newNode;
			temp = temp->next;
		}
		i++;
	}
	temp->next = head;

	return head;
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