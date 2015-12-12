#include<stdio.h>
#include<stdlib.h>
typedef char *dateele;
struct datestruct{
	dateele d,resulttextdate;
};
typedef struct datestruct *test;
void start();
void checktestcases(test);
test* initializetestcases();
void strconcat(dateele textdate,dateele str);
int validate(dateele *str);
int strcompare(char *str1,char* str2);
void dateday(dateele textdate,char ch[2]);
void dateteen(dateele textdate,char ch);
void datemonth(dateele textdate,char ch[2]);
void dateyear(dateele textdate,char ch[2]);
void datety(dateele textdate,char ch[2]);
void checktest(dateele td,dateele tr);
main(){
	start();
}
void start(){
	test *tc;
	int idx;
	tc=initializetestcases();
	for(idx=0;idx<8;idx++){
		printf("Test case-%d:\t",idx+1);
		checktestcases(tc[idx]);
		
	}
}
void checktestcases(test tc){
	int c=0,i,j=0,k=0,l=0;
	dateele textdate,str[3];
	str[0]=(char*)malloc(2*sizeof(char));
	str[1]=(char*)malloc(2*sizeof(char));
	str[2]=(char*)malloc(4*sizeof(char));
	textdate=(char *)calloc(70,sizeof(char));
	for(i=0;i<10;i++){
		if(tc->d[i]=='/')
			c++;
		if(c==0)
			str[c][j++]=tc->d[i];
		if(c==1)
			str[c][k++]=tc->d[i+1];
		if(c==2)
			str[c][l++]=tc->d[i+1];
	}
	str[0][2]='\0';
	str[1][2]='\0';
	str[2][4]='\0';
	if(validate(str)==1){
		dateday(textdate,str[0]);
		if(str[0][1]!='0'&&str[0][1]!='1'&&str[0][1]!='2')
			strconcat(textdate,"th ");
		datemonth(textdate,str[1]);
		dateyear(textdate,str[2]);
		checktest(textdate,tc->resulttextdate);
	}
	else
		printf("Date is Wrong\n");
		free(textdate);
}
void strconcat(dateele textdate,dateele str){
	int i=0,j=0;
	while(textdate[i]!='\0')
		i++;
	while(str[j]!='\0'){
		textdate[i]=str[j];
		j++;
		i++;
	}
	textdate[i]='\0';
}
test* initializetestcases(){
	test *tc=(test *)malloc(10*sizeof(struct testcases *));
	int i;
	for(i=0;i<8;i++){
		tc[i]=(test)malloc(sizeof(struct testcases *));
		tc[i]->d=(dateele)malloc(10*sizeof(char));
		tc[i]->resulttextdate=(char *)calloc(70,sizeof(char));
	}
	tc[0]->d="31/02/1967";
	tc[0]->resulttextdate=" ";
	tc[1]->d="01/09/1999";
	tc[1]->resulttextdate="first September of nineteen ninety nine";
	tc[2]->d="15/10/1997";
	tc[2]->resulttextdate="fivteen th October of nineteen ninety seuen";
	tc[3]->d="30/12/1867";
	tc[3]->resulttextdate="thirtyDecember of eighteen sixty seven";
	tc[4]->d="24/05/1786";
	tc[4]->resulttextdate="twentyfourfourth May of seventeen eighty seven";
	tc[5]->d="34/08/1677";
	tc[5]->resulttextdate=" ";
	tc[6]->d="09/04/1887";
	tc[6]->resulttextdate="nineth April of eighteen eighty seven";
	tc[7]->d="07/03/2015";
	tc[7]->resulttextdate="seventh March of twentyone ty fiv";
	return tc;
}
int validate(dateele *str){
	
	if(strcompare(str[1],"01")==0){
		if(strcompare(str[0],"31")>0)
			return 0;
	}
	else if(strcompare(str[1],"02")==0){
		if(strcompare(str[0],"28")>0)
			return 0;
	}
	else if(strcompare(str[1],"03")==0){
		if(strcompare(str[0],"31")>0)
			return 0;
	}
	else if(strcompare(str[1],"04")==0){
		if(strcompare(str[0],"30")>0)
			return 0;
	}
	else if(strcompare(str[1],"05")==0){
		if(strcompare(str[0],"31")>0)
			return 0;
	}
	else if(strcompare(str[1],"06")==0){
		if(strcompare(str[0],"30")>0)
			return 0;
	}
	else if(strcompare(str[1],"07")==0){
		if(strcompare(str[0],"31")>0)
			return 0;
	}
	else if(strcompare(str[1],"08")==0){
		if(strcompare(str[0],"31")>0)
			return 0;
	}
	else if(strcompare(str[1],"09")==0){
		if(strcompare(str[0],"30")>0)
			return 0;
	}
	else if(strcompare(str[1],"10")==0){
		if(strcompare(str[0],"31")>0)
			return 0;
	}
	else if(strcompare(str[1],"11")==0){
		if(strcompare(str[0],"30")>0)
			return 0;
	}
	else if(strcompare(str[1],"12")==0){
		if(strcompare(str[0],"31")>0)
			return 0;
	} 
	else
		return 0;
	return 1;
}
int strcompare(char *s1, char *s2){
	int n1=strlen(s1),n2=strlen(s2),i;
	int g,c=0;
	if (n1<n2)
		g=n2;
	else if(n1>n2)
		g=n1;
	else
		g=n1;
	for (i=0;i<g;i++) {
		if(s1[i]==s2[i])
			c++;
		else 
			return (s1[i]-s2[i]);
	}
	if(c!=0)
		return 0;
}
void dateday(dateele textdate,char ch[2]){
	if(ch[0]=='0'){
		if(ch[1]=='1')
			strconcat(textdate,"first ");
		else if(ch[1]=='2')
			strconcat(textdate,"second ");
		else if(ch[1]=='3')
			strconcat(textdate,"third ");
		else
			dateteen(textdate,ch[1]);
	}		
	else if(ch[0]=='1'){
		if(ch[1]=='0')
			strconcat(textdate,"tenth ");
		else if(ch[1]=='1')
			strconcat(textdate,"eleven");
		else if(ch[1]=='2')
			strconcat(textdate,"twleve");
		else if(ch[1]=='3')
			strconcat(textdate,"thirteen");
		else{
		dateteen(textdate,ch[1]);
		strconcat(textdate,"teen ");
		}
	}
	
	else if(ch[0]=='2'){
		datety(textdate,ch);
		if(ch[1]=='1')
			strconcat(textdate,"first ");
		else if(ch[1]=='2')
			strconcat(textdate,"second ");
		else if(ch[1]=='3')
			strconcat(textdate,"third ");
		else{
		dateteen(textdate,ch[1]);
		}
	}
	else if(ch[0]=='3'){
		strconcat(textdate,"thirty");
		if(ch[1]=='1')
			strconcat(textdate,"first ");
		else if(ch[1]=='2')
			strconcat(textdate,"second ");
	}
}
void dateteen(dateele textdate,char ch){
	switch(ch){
		case '1':
			strconcat(textdate,"one ");
			break;
		case '2':
			strconcat(textdate,"two ");
			break;
		case '3':
			strconcat(textdate,"three ");
			break;
		case '4':
			strconcat(textdate,"four");
			break;
		case '5':
			strconcat(textdate,"fiv");
			break;
		case '6':
			strconcat(textdate,"six");
			break;
		case '7':
			strconcat(textdate,"seven");
			break;
		case '8':
			strconcat(textdate,"eigh");
			break;
		case '9':
			strconcat(textdate,"nine");
			break;
	}
}
void datemonth(dateele textdate,char ch[2]){
	if(ch[0]=='0'){
		switch(ch[1]){
		case '1':
			strconcat(textdate,"January");
			break;
		case '2':
			strconcat(textdate,"February");
			break;
		case '3':
			strconcat(textdate,"March");
			break;
		case '4':
			strconcat(textdate,"April");
			break;
		case '5':
			strconcat(textdate,"May");
			break;
		case '6':
			strconcat(textdate,"June");
			break;
		case '7':
			strconcat(textdate,"July");
			break;
		case '8':
			strconcat(textdate,"August");
			break;
		case '9':
			strconcat(textdate,"September");
			break;
		}
	}
	else{
		switch(ch[1]){
		case '0':
			strconcat(textdate,"October");
			break;
		case '1':
			strconcat(textdate,"November");
			break;
		case '2':
			strconcat(textdate,"December");
			break;
		}
	}
}
void dateyear(dateele textdate,char ch[4]){
	char year2[2];
	strconcat(textdate," of ");
	dateday(textdate,ch);
	year2[0]=ch[2];
	year2[1]=ch[3];
	datety(textdate,year2);
}
void datety(dateele textdate,char ch[2]){
	if(ch[0]=='2')
		strconcat(textdate,"twenty");
	else if(ch[0]=='3')
		strconcat(textdate,"thirty");
	else{
	dateteen(textdate,ch[0]);
	strconcat(textdate,"ty ");
	}
	dateteen(textdate,ch[1]);
	textdate[40]=textdate[40]-1;
}
void checktest(dateele td,dateele tr){
	int i,c=0;
	for(i=0;i<strlen(td);i++){
		if(tr[i]!=td[i]){
			c++;
		}
	}
	if(c==0){
		printf("Success\n");
	}
	else
		printf("Fail\n");
}
