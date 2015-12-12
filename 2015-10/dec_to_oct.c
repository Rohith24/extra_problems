#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char * string;
struct testcases{
	int decnum, octalnum;
}testcasearray[10] = {
	{212,324},
	{ 142124761, 1036123331 },
	{-56,10},
	{-87,651},
	{-6243,63635},
	{0,0},
	{9999,999},
	{100,144},
	{07,7}

};
void start();
void method1(struct testcases tca);
string dec_to_bin(int number);
int dec_to_octal(int number);
string twoscomplement(int number);
int bin_to_dec(string dec);
int power(int i);
void method2(struct testcases tca);

void main(){
	start();
	getch();
}

void start(){
	int counter;
	for (counter = 0; counter<9; counter++){
		method1(testcasearray[counter]);
		method2(testcasearray[counter]);
	}	
}
void method1(struct testcases tca){
	int res_octalnum = dec_to_octal(tca.decnum);
	if (res_octalnum == tca.octalnum){
		printf("Success\t");
	}
	else{
		printf("Fail\t");
	}
}
int dec_to_octal(int number){
	int *a = (int *)malloc(sizeof(int)), c = 0, octalnum=0;
	if (number < 0){
		number *= -1;
		number = bin_to_dec(twoscomplement(number));
	}
	while (number > 0){
		a = (int *)realloc(a, (c + 1)*sizeof(int));
		a[c] = number % 8;
		number = number / 8;
		c++;
	}
	while (c > 0){
		octalnum = octalnum * 10 + a[--c];
	}
	//printf("%d", octalnum);
	return octalnum;
}

string twoscomplement(int number){
	string dec=dec_to_bin(number);
	int counter = 0, counter1 = 0;
	while (dec[counter] != '\0')
		counter++;

	while (dec[counter] != '1'){
		counter--;
		//counter1++;
	}
	if (dec[counter] == '1')
		counter--;
	while (counter>=0){
		if (dec[counter] == '0'){
			dec[counter--] = '1';
		}
		else
		{
			dec[counter--] = '0';
		}
	}
	dec = strrev(dec);
	counter = strlen(dec);
	if (counter % 3 == 1){
		dec[counter++] = '1';
		dec[counter++] = '1';
	}
	else if (counter % 3 == 2)
	{
		dec[counter++] = '1';
	}
	dec[counter] = '\0';
	dec = strrev(dec);
	return dec;
}

int bin_to_dec(string dec){
	int s;
	int j;
	int sum=0;
	for (j = 0, s = strlen(dec) - 1; s >= 0; s--, ++j){
		if (dec[s] == '1'){
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

string dec_to_bin(int number){
	string bin = (string)malloc(sizeof(char));
	int counter = 0;
	while (number != 0){
		bin = (string)realloc(bin, counter + 1 * sizeof(char));
		bin[counter++] = number % 2 + '0';
		number = number / 2;
	}
	
	bin[counter] = '\0';
	bin=strrev(bin);
	return bin;
}

void method2(struct testcases tca){
	int res_octalnum;
	if (tca.decnum >= 0){
		res_octalnum = decimal_to_oct(tca.decnum);
		if (res_octalnum == tca.octalnum){
			printf("Success\n");
		}
		else{
			printf("Fail\n");
		}
	}
	else
	{
		printf("Negative number\n");
	}
}

int decimal_to_oct(int num){
	int mul8 = 1,oct=0,temp=0;
	mul8 = 1;
	while (num > mul8){
		mul8 *= 8;
	}
	while (num > 0){
		mul8 /= 8;
		temp = num / mul8;
		oct = oct * 10 + temp;
		num = num - mul8*temp;
	}
	return oct;
}