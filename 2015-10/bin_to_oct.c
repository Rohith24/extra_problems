#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char* string;
struct testcases{
	string bin, oct;
}testcasearray[10] = {
	{ "111111", "77" },
	{ "1101011", "153" },
	{ "10101011", "253" },
	{ "101100011110", "5436" },
	{ "1110101011110011100001010111101011100001111011101", "16536341275341735" },
	{ "","" },
	{ "0", "0" },
	{ "267777776781", "" },
	{"01,010,101,111",""},
	{ "101000010101010","5025" }
};

void start();
int validate(string str);
void method1(struct testcases tc);
string strsubstring(string str, int strsub_start_index, int strsub_last_index);
char bin_to_num(char *str, int len);
int power(int i);
void method2(struct testcases tc);
int bin_to_oct(string bin);

void main(){
	start();
	getch();
}

void start(){
	int counter = 0;
	for (counter = 0; counter < 10; counter++){
		if (validate(testcasearray[counter].bin)){
			method1(testcasearray[counter]);
			method2(testcasearray[counter]);
		}
		else
		{
			printf("Invalid input\n");
		}
	}
}

int validate(string str){
	int counter = 0;
	while (str[counter] != '\0'){
		if (str[counter] < '0' || str[counter] > '1'){
			return 0;
		}
		counter++;
	}
	return 1;
}


void method1(struct testcases tc){
	string octnum, substr, str2;
	octnum = (string)malloc(sizeof(char));
	int strlength = strlen(tc.bin), counter = 0, strstrlengthlen=0;
	while (strlength - 2 > 0)
	{
		substr = strsubstring(tc.bin, strlength - 3, strlength-1);
		octnum[counter++] = bin_to_num(substr, 3);
		strlength -= 3;
	}
	if (strlength==2){
		substr = strsubstring(tc.bin, strlength - 2, strlength - 1);
		octnum[counter++] = bin_to_num(substr, 2);
	}
	else if (strlength == 1){
		substr = strsubstring(tc.bin, strlength - 1, strlength - 1);
		octnum[counter++] = bin_to_num(substr, 1);
	}
	
	octnum[counter] = '\0';
	octnum = strrev(octnum);
	//printf("%s,%s", octnum, tc.oct);
	if (strcmp(octnum, tc.oct) == 0){
		printf("Success\t");
	}
	else
	{
		printf("Fail\t");
	}
}
string strsubstring(string str, int strsub_start_index, int strsub_last_index){
	int counter = 0;
	string resultstr = (string)malloc(3 * sizeof(char));
	while (strsub_start_index <= strsub_last_index)
		resultstr[counter++] = str[strsub_start_index++];
	resultstr[counter] = '\0';
	return resultstr;
}
char bin_to_num(char *str, int len){
	int s, j;
	char sum = '0';
	for (j = 0, s = len - 1; s >= 0; s--, ++j){
		if (str[s] == '1'){
			sum = sum + power(j);
		}
	}
	return sum;
}
int power(int i){
	int sum = 1, j;
	for (j = 0; j<i; j++)
		sum *= 2;
	return sum;
}
void method2(struct testcases tc){
	string oct;
	oct= bin_to_oct(tc.bin);
	//printf("%s,%s", oct,tc.oct);
	if (strcmp(oct, tc.oct)==0){
		printf("Success\n");
	}
	else
	{
		printf("Fail\n");
	}
}
int bin_to_oct(string bin){
	string oct = (string)malloc(sizeof(char));
	int counter1 = 0, counter2 = 0;
	while (bin[counter1]){
		++counter1;
	}
	--counter1;
	while (counter1 - 2 >= 0){
		oct = (string)realloc(oct, counter2 + 1 * sizeof(char));
		oct[counter2++] = ((bin[counter1 - 2] - '0') * 4 + (bin[counter1 - 1] - '0') * 2 + (bin[counter1] - '0')) + '0';
		counter1 -= 3;
	}

	if (counter1 == 1)
		oct[counter2++] = ((bin[counter1 - 1] - '0') * 2 + (bin[counter1] - '0')) + '0';
	else if (counter1 == 0)
		oct[counter2++] = bin[counter1];
	oct[counter2] = '\0';
	return strrev(oct);
}

