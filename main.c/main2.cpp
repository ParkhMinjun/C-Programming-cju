// #define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void)
{
	char strName[20]; // ���ڿ�
	char chMaleFemale; // ����
	int nAge=0;
	double dHeight=0.0;

	printf("Input your information(age, male/female, name, height):\n");
	scanf_s("%d %c %s %lf", &nAge, &chMaleFemale, sizeof(chMaleFemale), strName, sizeof(strName), &dHeight); // ���ڿ����� & �Ⱥ���
	printf("Result(age, male/female, name, height):(%d, %c, %s, %.1lf)\n", nAge, chMaleFemale, strName, dHeight);

	return 0;
}