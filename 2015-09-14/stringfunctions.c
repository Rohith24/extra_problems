#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef char* string;
struct testcases
{
	string str1, str2, strcat, strsub, strtrim;
	int strlen, strcmp,strsub_start_index,strsub_last_index;
}testcasearray[7] = {
	{ "Rohith    Reddy ", "challa", "Rohith    Reddy challa", "hi", "Rohith Reddy", 16, -17, 2, 3 },
	{ "  Rohith   ", " Reddy", "  Rohith    Reddy", "hith ", "Rohtih", 11, -50, 4, 7 },
	{ "   Challa  ", "Reddy", "   Challa  Reddy", "Challa", "Challa", 11, -50, 3, 13 },
	{ "", "", "", "", "", 0, 0, 0, 0 },
	{ " ", " ", "  ", " ", "", 1, 0, 0, 0 },
	{ "123", "345", "123345", "12", "123", 3, -2, 0, 1 },
	{ ";.;.;.;.;", "::", ";.;.;.;", ".;.", "", 9, 0, 1, 3 }
};


void start();
int strlength(string str);
string strcatination(string str1, string str2);
string strsubstring(string str, int strsub_start_index, int strsub_last_index);
int strcompare(string str1, string str2);
string strtrim(string str);
void check(int r);

void main(){
	start();
	getch();
}

void start(){
	int counter, res = 0;
	for (counter = 0; counter < 7; counter++){
		res = 0;
		if (strlength(testcasearray[counter].str1) == testcasearray[counter].strlen)
			res = 1;
		res += compare_2_strings(strcatination(testcasearray[counter].str1, testcasearray[counter].str2), testcasearray[counter].strcat);
		res += compare_2_strings(strsubstring(testcasearray[counter].str1, testcasearray[counter].strsub_start_index, testcasearray[counter].strsub_last_index), testcasearray[counter].strsub);
		if (strcompare(testcasearray[counter].str1, testcasearray[counter].str2) == testcasearray[counter].strcmp)
			res += 1;
		res += compare_2_strings(strtrim(testcasearray[counter].str1),testcasearray[counter].strtrim);
		check(res);
	}
}

int strlength(string str){
	int counter = 0;
	while (str[counter] != '\0')
		counter++;
	return counter;
}

string strcatination(string str1, string str2){
	int counter1 = 0, counter2 = 0;
	string resultstring = (string)malloc(sizeof(char));
	while (str1[counter1] != '\0'){
		resultstring[counter1] = str1[counter1++];
	}
	while (str2[counter2] != '\0'){
		resultstring[counter1++] = str2[counter2++];
	}
	resultstring[counter1] = '\0';
	return resultstring;
}

string strsubstring(string str, int strsub_start_index, int strsub_last_index){
	int counter = 0;
	string resultstr = (string)malloc(sizeof(char));
	while (strsub_start_index <= strsub_last_index)
		resultstr[counter++] = str[strsub_start_index++];
	resultstr[counter] = '\0';
	return resultstr;
}

int strcompare(string str1, string str2){
	int length1 = strlen(str1), length2 = strlen(str2), counter;
	int length, counter2 = 0;
	if (length1<length2)
		length = length2;
	else if (length1>length2)
		length = length1;
	else
		length = length1;
	for (counter = 0; counter<length; counter++) {
		if (str1[counter] == str2[counter])
			counter2++;
		else
			return (str1[counter] - str2[counter]);
	}
	if (counter2 == length)
		return 0;
}

string strtrim(string str){
	int counter1 = 0, counter2 = 0, spacelen = 0;
	string resultstr = (string)malloc(sizeof(char));
	while (str[counter1] == ' ')
		counter1++;
	while (str[counter1]!='\0'){
		resultstr[counter2] = str[counter1];
		if (str[counter1] == ' ' && (str[counter1 + 1] == ' ' || str[counter1 + 1] == '\0'))
			spacelen++;
		if (spacelen > 1){
			if (str[counter1 + 1] != ' '&&str[counter1 + 1] != '\0')
				spacelen = 0;
			counter2--;
		}
		counter1++;
		counter2++;
	}
	if (str[0] == '\0')
		resultstr[0] = '\0';
	resultstr[counter2] = '\0';
	return resultstr;
}

int compare_2_strings(string str1, string str2){
	int counter1= 0;
	while (str1[counter1] != '\0'&&str2[counter1] == '\0'){
		if (str1[counter1] != str2[counter1])
			return 0;
		counter1++;
	}
	return 1;
}

void check(int r){
	if (r == 5)
		printf("Success\n\n");
	else
		printf("Fail\n\n");
}