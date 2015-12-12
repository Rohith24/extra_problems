#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef char * string;

struct testcases{
	string p;
	int k;
}testcasearray[14] = {
	{ "111", 3 },
	{ "123", 4 },
	{ "121", 0 },
	{ "", 7 },
	{ "0", 1 },
	{ "-123", 4 },
	{ "123", -34 },
	{ "12", 9 },
	{ "568", 6 },
	{ "568", 7 },
	{ "", 0 } ,
	{ "16499205854376",5 },
	{ "1649920585437",5 },
	{ "544742170842168",2 }
};

void start();
string formnumber(string, int);
int validate(string str);
int divisibleby3(string str);
int divisiblityby3(int);
void method1(struct testcases tc);
void method2(struct testcases tc);
void method3(struct testcases tc);
int countnot3mul(string str);
string int2str(int num);

void main(){
	start();
	getch();
}

void start(){
	int counter;
	printf("Testcase:\tMethod 1\tMethod2\t\tMethod3\n");
	for (counter = 0; counter < 14; counter++){
		printf("%5d\t\t", counter + 1);
		method1(testcasearray[counter]);
		method2(testcasearray[counter]);
		method3(testcasearray[counter]);
	}
}
void method1(struct testcases tc){
	string q;
	q = formnumber(tc.p, tc.k);
	if (validate(q)){
		if (divisibleby3(q) == 1){
			printf("Divisible by 3\t");
		}
		else
		{
			printf("Not Divisible by 3\t");
		}
	}
	else{
		printf("Invalid Input\t");
	}
}
void method2(struct testcases tc){
	if (validate(tc.p) && tc.k > 0) {
		if (divisibleby3(tc.p) == 1 || tc.k % 3 == 0){
			printf("Divisible by 3\t");
		}
		else
		{
			printf("Not Divisible by 3\t");
		}
	}
	else{
		printf("Invalid Input\t");
	}
}
void method3(struct testcases tc){
	if (validate(tc.p) && tc.k > 0){
		if (countnot3mul(tc.p) == 1 || tc.k % 3 == 0){
			printf("Divisible by 3\n");
		}
		else{
			printf("Not Divisible by 3\n");
		}
	}
	else{
		printf("Invalid Input\n");
	}
}

int countnot3mul(string str){
	int counter = 0, counter1 = 0, counter2 = 0;
	int diff;
	string diffstr;
	while (str[counter] != '\0'){
		if (str[counter] == '1' || str[counter] == '4' || str[counter] == '7'){
			counter1++;
		}
		if (str[counter] == '2' || str[counter] == '5' || str[counter] == '8'){
			counter2++;
		}
		counter++;
	}
	diff = counter1 - counter2;
	diffstr = int2str(diff);
	if (diff <= 9){
		return divisiblityby3(diff);
	}
	else{
		countnot3mul(diffstr);
	}
}

string formnumber(string p, int k){
	string q = (string)malloc(sizeof(char));
	int counter1 = 0, counter2;
	while (k>0){
		counter2 = 0;
		while (p[counter2] != '\0'){
			q = (string)realloc(q, counter1 + 1 * sizeof(char));
			q[counter1++] = p[counter2++];
		}
		k--;
	}
	q[counter1] = '\0';
	return q;
}

int validate(string str){
	int counter = 0;
	if (str[0] == '\0')
		return 0;
	while (str[counter] != '\0'){
		if (str[counter] < '0' || str[counter] > '9'){
			return 0;
		}
		counter++;
	}
	return 1;
}

int divisibleby3(string str){
	int counter = 0, sum = 0;
	char *sumstr;// = (string)malloc(10 * sizeof(char));
	while (str[counter] != '\0'){
		sum += (str[counter++] - '0');
	}
	sumstr=int2str(sum);
	if (sum <= 9){
		return divisiblityby3(sum);
	}
	return divisibleby3(sumstr);

}

int divisiblityby3(int num){
	if (num == 0 || num == 3 || num == 6 || num == 9){
		return 1;
	}
	return 0;
}

string int2str(int num){
	string str = (string)malloc(sizeof(char));
	int counter = 0,num2=num;
	while (num2 > 0){
		num2 /= 10;
		counter++;
	}
	str[counter] = '\0';
	while (num > 0){
		str[--counter] = (num % 10) + '0';
		num /= 10;
	}
	return str;
}