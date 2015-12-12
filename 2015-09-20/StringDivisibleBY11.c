#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char * string;

struct testcases{
	string str;
}testcasearray[12] = {
	{ "292215" },
	{ "121" },
	{ "." },
	{ "       123467          " },
	{ "" },
	{ "1" },
	{ "0" },
	{ "String" },
	{ "1234vcv1234" },
	{ "760672" },
	{ "245609" },
	{ "21635291436543185674398165017650416581073567436501657156716584365987164075610786503416574167" }

};

void start();
int validate(string str);
void method1(string str);
void method2(string str);
int strlength(string str);
int divisibleby11(string str);
int diff_even_odd_sum(int evensum, int oddsum);
int diffrence(string str1, string str2);
void check_with_zero(char ch);

void main(){
	start();
	getch();
}

void start(){
	int counter = 0;
	for (counter = 0; counter < 12; counter++){
		if (validate(testcasearray[counter].str)){
			method1(testcasearray[counter].str);
			method2(testcasearray[counter].str);
		}
		else{
			printf("Invalid number");
		}
		printf("\n");
	}
}

void method1(string str){
	if (divisibleby11(str) == 1){
		printf("Success\t");
	}
	else
	{
		printf("Fail\t");
	}
}

int validate(string str){
	int counter = 0;
	if (str[0] == '\0')
		return 0;
	while (str[counter] != '\0'){
		if (counter > 10000){
			printf("String length should be less than 10000\n");
			return 0;
		}
		if (str[counter] < '0' || str[counter] > '9'){
			return 0;
		}
		counter++;
	}
	return 1;
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

int strlength(string str){
	int counter = 0;
	while (str[counter] != '\0')
		counter++;
	return counter;
}


void method2(string str){
	string str1, str2, diffstr;
	int counter = 0;
	str1 = (string)malloc((strlength(str) - 1)*sizeof(char));
	str2 = (string)malloc(2 * sizeof(char));
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