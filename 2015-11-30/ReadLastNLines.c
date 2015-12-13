#include <stdio.h>
#include<malloc.h>
void printLastNLines(FILE *fp,int n)
{
	char  **buffer;
	buffer = (char **)malloc(n*sizeof(char *));
	for (int i = 0; i < n; i++){
		buffer[i] = (char *)malloc(4096 * sizeof(char));
	}
	int index = 0, count;
	while (fgets(buffer[index % n], 4096, fp) != NULL)
		index++;
	count = index % n;
	do
	{
		printf("%s\n", buffer[index % n]);
		index++;
	} while (count != index % n);
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("usage: ReadLastNLines filename No_of_Lines");
		getchar();
		return 0;
	}
	FILE *fp;
	int n = atoi(argv[2]);
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		printf("File Not Exist\n");
	else
		printLastNLines(fp,n);
	getchar();
	return 0;
}