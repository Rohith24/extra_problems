#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char * string;

struct testcases{
	string p;
	int k;
}testcasearray[10] = {
	{ "292215", 2 },
	{ "21",11 },
	{ "123", 4 },
	{ "121", 0 },
	{ "", 7 },
	{ "0", 1 },
	{ "-123", 4 },
	{ "123", -34 },
	{ "1", 9 },
	{ "1",22 }
};

void start();
string formnumber(string, int);
int validate(string str);
void method1(string q);
void method2(string q);
void method3(string p, int k);
int divisibleby11(string str);
int diff_even_odd_sum(int evensum, int oddsum);
void check_with_zero(char ch);
int strlength(string str);

void main(){
	start();
	getch();
}

void start(){
	int counter;
	string q;
	for (counter = 0; counter < 10; counter++){
		if (validate(testcasearray[counter].p)){
			q = formnumber(testcasearray[counter].p, testcasearray[counter].k);
			if (validate(q)){
				//printf("%s\n", q);
				method1(q);
				method2(q);
				method3(testcasearray[counter].p, testcasearray[counter].k);
			}
			else{
				printf("Invalid Input\n");
			}
		}
		else{
			printf("Invalid Input\n");
		}
	}
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

string formnumber(string p, int k){
	string q = (string)malloc(sizeof(char));
	int counter1 = 0, counter2;
	while (k>0){
		counter2 = 0;
		while (p[counter2] != '\0'){
			q[counter1++] = p[counter2++];
		}
		k--;
	}
	q[counter1] = '\0';
	return q;
}

int strlength(string str){
	int counter = 0;
	while (str[counter] != '\0')
		counter++;
	return counter;
}

void method1(string q){
	if (divisibleby11(q) == 1){
		printf("Success\t");
	}
	else
	{
		printf("Fail\t");
	}
}

int divisibleby11(string str){
	int counter = 0;
	int evensum = 0, oddsum = 0;
	while (str[counter] != '\0'){
		if (counter % 2 == 0){
			evensum += str[counter] - '0';
		}
		else
		{
			oddsum += str[counter] - '0';
		}
		counter++;
	}
	return diff_even_odd_sum(evensum, oddsum);
}

int diff_even_odd_sum(int evensum, int oddsum){
	char str[10], diff;
	diff = evensum - oddsum;
	if (diff < 0)
		diff *= -1;
	itoa(diff, str, 10);
	if (diff == 0){
		return 1;
	}
	if (diff < 10){
		return 0;
	}
	else
		return divisibleby11(str);
}

void method2(string str){
	string str1, str2, diffstr;
	int counter = 0;
	str1 = (string)malloc((strlength(str)-1)*sizeof(char));
	str2 = (string)malloc(2*sizeof(char));
	if (strlength(str) > 1){
		while (str[counter + 1] != '\0'){
			str1[counter] = str[counter++];
		}
		str1[counter] = '\0';
		str2[0] = str[counter];
		str2[1] = '\0';
		diffstr = diffrence(str1, str2);
		if (diffstr[0] < '10'&&diffstr[1] == '\0'){
			check_with_zero(diffstr[0]);
		}
		else{
			method2(diffstr);
		}
	}
	else {
		check_with_zero(str[0]);
	}
	
}

int diffrence(string str1, string str2){
	string res;
	int len1 = strlength(str1), len2 = strlength(str2);
	int counter1, counter2;
	res = (string)malloc(len1*sizeof(char));
	res[len1] = '\0';
	res = strcpy(res, str1);
	while (len1 > 0 && len2 > 0){
		res[len1 - 1] = str1[len1 - 1] - str2[len2 - 1];
		if (res[len1 - 1] < 0){
			res[len1 - 1] = 10 + res[len1 - 1] + '0';
			if (len1 - 2 >= 0){
				res[len1 - 2] -= 1;
			}
		}
		else{
			res[len1 - 1] += '0';
		}
		len1--;
		len2--;
	}
	return res;
}

void check_with_zero(char ch){
	if (ch == '0')
		printf("Success\t");
	else
	{
		printf("Fail\t");
	}
}

void method3(string str, int k){
	int true = 0;
	if (strlength(str) % 2 == 0){
		true = divisibleby11(str);
	}
	else{
		true = divisibleby11(formnumber(str, 2));
		k = k - 1;
	}
	if (true == 1 || k % 11 == 0){
		printf("Success\n");
	}
	else{
		printf("Fail\n");
	}
}