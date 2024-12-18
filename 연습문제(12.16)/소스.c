#include<stdio.h>

int main(void)
{
	FILE* fp;

	fp = fopen_s(&fp,"test_read.txt", "r");

	if (fp == NULL)
	{
		printf("Cannot open file.. please check the file path..\n");
		return 1;
	}

	printf("Success::file open!\n");
	fclose(fp);
	
	return 0;

}