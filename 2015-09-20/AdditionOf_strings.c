#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char *string;
struct testcases{
	string str1, str2,sumstr;
}testcasearray[10] = {
	{ "123", "123", "246" },
	{ "876549876", "3456", "876553332" },
	{ "1234,234", "32453", "" },
	{ "0", "12345", "12345" },
	{ "", "12", "12" },
	{ "46782641", "99999999999999","100000046782640" },
	{ "", "", "" },
	{ "        345436    ", " 343546578", "" },
};
void start();
int validate(string str);
void method1(struct testcases tc);
void method2(struct testcases tc);
int addstrings(string str1, string str2);
int addstringsL2R(string str1, string str2);
string add(string str1, string str2);
string strsubstring(string str, int strsub_start_index, int strsub_last_index);

void main(){
	start();
	getch();
}

void start(){
	int counter;
	for (counter = 0; counter < 8; counter++){
		if (validate(testcasearray[counter].str1) && validate(testcasearray[counter].str2)){
			method1(testcasearray[counter]);
			method2(testcasearray[counter]);
		}
		else{
			printf("Invalid Input\n");
		}
	}
	
}
void method1(struct testcases tc){
	string result;
	result = addstrings(tc.str1, tc.str2);
	//printf("%s\t", result);
	if (compare_2_strings(tc.sumstr, result) == 1)
		printf("Success\t");
	else
	{
		printf("Fail\t");
	}
}
void method2(struct testcases tc){
	string result;
	result = addstringsL2R(tc.str1, tc.str2);
	if (compare_2_strings(tc.sumstr, result) == 1)
		printf("Success\n");
	else
	{
		printf("Fail\n");
	}	
}
int validate(string str){
	int counter = 0;
	while (str[counter] != '\0'){
		if (str[counter] < '0' || str[counter] > '9'){
			return 0;
		}
		counter++;
	}
	return 1;
}

int addstrings(string str1, string str2){
	int length1 = strlength(str1), length2 = strlength(str2), reslength;
	string result, strcarry;
	int sum = 0, carry = 0;
	reslength = (length1 < length2) ? length2 : length1;
	result = (string)malloc(sizeof(char)*reslength);
	strcarry = (string)malloc(1*sizeof(char));
	result[reslength] = '\0';
	while (length1 > 0 && length2 > 0)
	{
		sum = str1[--length1] + str2[--length2] - '0' - '0' + carry;
		result[--reslength] = sum % 10 + '0';
		carry = sum / 10;
	}
	while (length1 > 0){
		sum = str1[--length1] - '0' + carry;
		result[--reslength] = sum % 10 + '0';
		carry = sum / 10 ;
	}
	while (length2 > 0){
		sum = str2[--length2] - '0' + carry;
		result[--reslength] = sum % 10 + '0';
		carry = sum / 10 ;
	}
	if (carry != 0){
		strcarry[0] = carry + '0';
		strcarry[1] = '\0';
		result=strcat(strcarry,result);
	}
	return result;
}
int addstringsL2R(string str1,string str2){
	int counter1, counter2;
	if (strlength(str1)>strlength(str2)){
		return add(str1, str2);
	}
	else{
		return add(str2, str1);
	}
}
string add(string str1, string str2){
	int counter1, counter2, sum = 0; //
	string s1 = (string)malloc(strlen(str1)*sizeof(char)); //
	string s2 = (string)malloc(strlen(str2)*sizeof(char));
	if (isstringzero(str2) == 1){ //
		strcpy(s1, str1);			//
		strcpy(s2, str2);
		counter1 = strlength(str1) - strlength(str2);
		if (counter1 >= 0){
			counter2 = 0;
			while (str1[counter1] != '\0'&&str2[counter2] != '\0'){
				sum = str1[counter1] + str2[counter2] - '0' - '0';
				//str1[counter1] = sum % 10 + '0'; //
				s1[counter1] = sum % 10 + '0';
				//str2[counter2] = sum / 10 + '0'; //
				s2[counter2] = sum / 10 + '0';
				counter1++;
				counter2++;
			}
			//str2[counter2++] = '0'; //
			s2[counter2++] = '0';
			//str2[counter2] = '\0'; //
			s2[counter2] = '\0';

			//return add(str1, str2);
			return add(s1, s2);
		}
		else
		{
			if (s2[0] != '0'){
				s2[1] = '\0';
				return strcat(s2, s1);
			}
		}
	}
	return str1;
}
int isstringzero(string str){
	int counter = 0,counter1=0;
	while (str[counter] != '\0'){
		if (str[counter] == '0')
			str = strsubstring(str, 1, strlength(str));
		else
			break;
	}
	if (strlength(str)!=0)
		return 1;
	return 0;
}
string strsubstring(string str, int strsub_start_index, int strsub_last_index){
	int counter = 0;
	string resultstr = (string)malloc(3 * sizeof(char));
	while (strsub_start_index <= strsub_last_index)
		resultstr[counter++] = str[strsub_start_index++];
	resultstr[counter] = '\0';
	return resultstr;
}
int compare_2_strings(string str1, string str2){
	int counter1 = 0;
	if (strlength(str1) == strlength(str2)){
		if (str1[counter1] != '\0')
		while (str1[counter1] != '\0'){
			if (str1[counter1] == str2[counter1])
				counter1++;
			else
			{
				break;
			}
		}
		if (counter1 == strlength(str1))
			return 1;
	}
	return 0;
}

int strlength(string str){
	int counter = 0;
	while (str[counter] != '\0')
		counter++;
	return counter;
}