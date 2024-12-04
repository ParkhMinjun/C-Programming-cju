#include <stdio.h>

// define ���� �迭 ������ ���� 

void SetArray(double* pDArr, int nArrSize)
{
	// for debugging
	printf("Input:size(%d) array\n", nArrSize);
	
	// setting array with scanf function
	for (unsigned int i = 0; i < nArrSize; i++)
	{
		scanf_s("%lf", pDArr + i);
	}
}

// printing array with size
void PrintArray(double* pDArr, int nArrSize)
{
	printf("using pointer..");
	printf("Input:size(%d) array\n", nArrSize);
	for (unsigned int i = 0; i < nArrSize; i++)
	{
		printf("[%d](%u,%.4lf)\n", i , pDArr ,  *(pDArr + i) );
	}
}


// calculating maximum value in array
double CalcMaxValArray(double* pDArr, int nArrSize)
{
	double dRes = *(pDArr + 0);  // double dRes = pDArr[0]
	for (unsigned int i = 0; i < nArrSize; i++)
	{
		if (*(pDArr + i) > dRes)
			dRes = *(pDArr + i);
	}
	return dRes;
}

// main function
int main(void)
{
	// initializing variables          // �迭�� ũ�� �� const int = nArrSz = 6; double dArr[nArrSz] = {}; ����, const ���� int������ �ȵ�
	double dArr[5] = {};
	double* pDArr = dArr;
	const int nArrSize = sizeof(dArr) / sizeof(dArr[0]);

	//setting array with size
	SetArray(dArr, nArrSize);
	PrintArray(pDArr, nArrSize);
	
	// for debugging
	printf("\n");
	printf("using array..\n");
	for (unsigned int i = 0; i < nArrSize; i++)
	{
		printf("[%d](%u,%.4lf)\n", i , &dArr[i], dArr[i]);
		
	}

	// for debugging
	printf("\n");
	printf("using compatability..\n");
	for (unsigned int i = 0; i < nArrSize; i++)
	{
		printf("[%d](%u,%.4lf)\n", i, &dArr[i], dArr[i]);
		printf("[%d](%u,%.4lf)\n", i, dArr + i, *(dArr + i));
		printf("[%d](%u,%.4lf)\n", i, &pDArr[i], pDArr[i]);
		printf("[%d](%u,%.4lf)\n", i, pDArr + i, *(pDArr + i));               // �ּ�,��
	}

	// calculating maximum value
	printf("[MaxVal](%.4lf)\n",CalcMaxValArray(pDArr,nArrSize));
	return 0;
}