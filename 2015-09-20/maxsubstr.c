#include<stdio.h>
#include<stdlib.h>

typedef char * string;

struct testcase
{
	string str1, str2,maxsub;
};	

void start();
int initializetestcase();
string findmaxsubstr(string, string);
string method2(string, string);
string maxsubstr(string *subarray,int len);
string strsubstring(string str, int strsub_start_index, int strsub_last_index);
void compare_2_strings(string str1, string str2);
int strlength(string str);

void main(){
	start();
	getch();
}

void start(){
	struct testcase *testcasearray = initializetestcase();
	int counter;
	string res;
	for (counter = 0; counter < 7; counter++){
		if (validate(testcasearray[counter].str1) && validate(testcasearray[counter].str2)){
			res = findmaxsubstr(testcasearray[counter].str1, testcasearray[counter].str2);
			compare_2_strings(res, testcasearray[counter].maxsub);
			res = method2(testcasearray[counter].str1, testcasearray[counter].str2);
			compare_2_strings(res, testcasearray[counter].maxsub);
			printf("\n");
		}
		else
		{
			printf("Invalid String\n");
		}
	}
}

int initializetestcase(){
	struct testcase *tca = (struct testcase *)malloc(10 * sizeof(struct testcase));
	tca[0].str1 = "RoRohith";
	tca[0].str2 = "CHRohireddy";
	tca[0].maxsub = "Rohi";
	tca[1].str1 = "RohithReddy";
	tca[1].str2 = "CHRohithReddyChalla";
	tca[1].maxsub = "RohithReddy";
	tca[2].str1 = "RohitRohith";
	tca[2].str2 = "CHRohithreddy";
	tca[2].maxsub = "Rohith";
	tca[3].str1 = "RohithReddy";
	tca[3].str2 = "CHRohithReddyChalla";
	tca[3].maxsub = "RohithReddy";
	tca[4].str1 = "";
	tca[4].str2 = "CHRohireddy";
	tca[4].maxsub = "";
	tca[5].str1 = "12345";
	tca[5].str2 = " ";
	tca[5].maxsub = " ";
	tca[6].str1 = "1234123123456";
	tca[6].str2 = "12457123456";
	tca[6].maxsub = "123456";
	return tca;
}

int validate(string str){
	int counter = 0;
	while (str[counter] != '\0'){
		counter++;
	}
	if (counter == 0)
		return 0;
	else
	{
		return 1;
	}
}

string findmaxsubstr(string str1, string str2){
	int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0, counter = 0;
	string *subarray = (string*)malloc(1*sizeof(string)); 
	subarray[counter] = (string)malloc(sizeof(char));
	for (counter = 0; counter < strlen(str1); counter++){
		counter1 = counter;
		counter2 = 0;
		while (str1[counter1] != '\0'&&str2[counter2] != '\0'){
			if (str1[counter1] == str2[counter2]){
				subarray[counter3] = (string)realloc(subarray[counter3], counter4 + 1 * sizeof(char));
				subarray[counter3][counter4] = str1[counter1];
				counter1++;
				counter4++;
			}
			else{
				if (counter4 > 0){
					subarray[counter3][counter4] = '\0';
					counter3++;
					counter2 = -1;
					//subarray = (string*)realloc(subarray,counter3+1 * sizeof(string));
					subarray[counter3] = (string)malloc(sizeof(char));
					counter5++;
				}
				counter4 = 0;
			}
			counter2++;
		}
		if (counter5 == 0){
			subarray[counter3][counter4] = '\0';
		}
	}
	return maxsubstr(subarray,counter3);	
}

string maxsubstr(string *subarray,int len){
	int counter = 0, maxstr = 0;
	for (counter = 1; counter < len-1; counter++){
		//printf("%s\t%s,", subarray[counter], subarray[maxstr]);
		if (strlen(subarray[counter]) > strlen(subarray[maxstr]))
			maxstr = counter;
	}
	return subarray[maxstr];
}

string method2(string str1, string str2){
	int counter1 = 0, counter2 = 0,sum=0; //m,n
	int m = strlen(str1), n = strlen(str2);
	int array[20][20];
	string res = (string)malloc(sizeof(char));
	//res = "";
	for (counter1 = 0; str1[counter1]!='\0'; counter1++){
		for (counter2 = 0; str2[counter2] != '\0'; counter2++){
			if (str1[counter1] == str2[counter2]){
				if (counter1 == 0 || counter2 == 0){
					array[counter1][counter2] = 1;
				}
				else{
					array[counter1][counter2] = array[counter1 - 1][counter2 - 1] + 1;
				}
				if (array[counter1][counter2] > sum){
					sum = array[counter1][counter2];
					res = strsubstring(str1, counter1 - sum+1, counter1);
				}
				else if (array[counter1][counter2] == sum){
					res = strcat(res, strsubstring(str1, counter1 - sum +1, counter1));
				}
			}
			else
				array[counter1][counter2] = 0;
		}	
	}
	//printf("%s\t", res);
	return res;
}
	
string strsubstring(string str, int strsub_start_index, int strsub_last_index){
	int counter = 0;
	string resultstr = (string)malloc(3 * sizeof(char));
	while (strsub_start_index <= strsub_last_index)
		resultstr[counter++] = str[strsub_start_index++];
	resultstr[counter] = '\0';
	return resultstr;
}

void compare_2_strings(string str1, string str2){
	int counter1 = 0;
	if (strlength(str1) == strlength(str2)){
		if (str1[counter1] != '\0')
		while (str1[counter1] != '\0'){
			if (str1[counter1] == str2[counter1])
				counter1++;
		}
		if (counter1 == strlength(str1)){
			printf("Sucesss\t");
			return;
		}
	}
	printf("Fail\t");
	return;
}

int strlength(string str){
	int counter = 0;
	while (str[counter] != '\0')
		counter++;
	return counter;
}