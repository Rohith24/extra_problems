#include<stdio.h>
#include<stdlib.h>

typedef char * string;

struct testcase
{
	string str;
	char delimiter;
	string *result;
};

void start();
int initialize_testcase();
int splict(string str, char delimiter);
int compare_2_stringArrays(string *strarray1, string *strarray2);

void main(){
	start();
	getch();
}

void start(){
	struct testcase *testcasearray = initialize_testcase();
	string *res;
	int counter = 4;
	for (counter = 0; counter < 5; counter++){
		res = splict(testcasearray[counter].str, testcasearray[counter].delimiter);
		if (compare_2_stringArrays(testcasearray[counter].result, res) == 1){
			printf("Success\n\n");
		}
		else{
			printf("Fail\n\n");
		}
	}
}
int initialize_testcase(){
	struct testcase *testcasearray;
	testcasearray = (struct testcase *)malloc(10 * sizeof(struct testcase));
	testcasearray[0].result = (string)malloc(3 * sizeof(struct testcase));
	testcasearray[0].str = "Rohith/Reddy/Challa";
	testcasearray[0].delimiter = '/';
	testcasearray[0].result[0] = "Rohith";
	testcasearray[0].result[1] = "Reddy";
	testcasearray[0].result[2] = "Challa";
	testcasearray[1].result = (string)malloc(3 * sizeof(struct testcase));
	testcasearray[1].str = "123.345.679";
	testcasearray[1].delimiter = '.';
	testcasearray[1].result[0] = "123";
	testcasearray[1].result[1] = "345";
	testcasearray[1].result[2] = "679";
	testcasearray[2].result = (string)malloc(1 * sizeof(struct testcase));
	testcasearray[2].str = "";
	testcasearray[2].delimiter = ';';
	testcasearray[2].result[0] = "";
	testcasearray[3].result = (string)malloc(1 * sizeof(struct testcase));
	testcasearray[3].str = "                    ";
	testcasearray[3].delimiter = 'k';
	testcasearray[3].result[0] = "";
	testcasearray[4].result = (string)malloc(4 * sizeof(struct testcase));
	testcasearray[4].str = "?????????????Challa??????Reddy???????????Challa?????????????????.";
	testcasearray[3].delimiter = '?';
	testcasearray[4].result[0] = "Challa";
	testcasearray[4].result[1] = "Reddy";
	testcasearray[4].result[2] = "Challa";
	testcasearray[4].result[3] = ".";
	return testcasearray;
}


int splict(string str,char delimiter){
	int counter = 0, counter1 = 0, counter2 = 0;
	string *result = (string *)malloc(sizeof(string));
	result[counter2] = (string)malloc(sizeof(char));
	while (str[counter] == delimiter)
		counter++;
	while (str[counter] != '\0'){
		if (str[counter] != delimiter){
			result[counter2] = (string)realloc(result[counter2], (counter1 + 1)*sizeof(char));
			result[counter2][counter1] = str[counter];
			counter++;
			counter1++;
		}
		else
		{
			result[counter2][counter1] = '\0';
			counter++;
			counter1 = 0;
			counter2++;
			result[counter2] = (string)malloc(sizeof(char));
		}
	}
	result[counter2][counter1] = '\0';

	return result;
}


int compare_2_stringArrays(string *strarray1, string *strarray2){
	int counter1, counter2 = 0, length = (sizeof(strarray2) / sizeof(strarray2[0]));
	for (counter1 = 0; counter1 < length; counter1++){
		while (strarray1[counter1][counter2] != '\0'&&strarray2[counter1][counter2] == '\0'){
			if (strarray1[counter1][counter2] != strarray2[counter1][counter2])
				return 0;
		}
	}
	return 1;
}
