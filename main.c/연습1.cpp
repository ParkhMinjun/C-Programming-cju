/*#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void)
{
	int nbot; // 밑면
	int nheight; // 높이
	int nradius; // 반지름
	double trangle_extend; // 삼각형 넓이 변수
	double qu_extend; // 사각형 넓이 변수
	double circle_extend; // 원 넓이 변수
	double sphere_surface_area; // 구 면적 변수
	double sphere_volume; // 구 부피 변수



	//넓이(A) = (밑변 × 높이) ÷ 2
	//(반지름)×(반지름)×(원주율)
	//4*원주율*반지름
	//(4 / 3) × π × 반지름(r) ^ 3





	printf("Input data (bot,height,radius ):\n");
	scanf("%d %d %d", &nbot, &nheight, &nradius);
	trangle_extend = nbot * nheight * 0.5;
	qu_extend = nbot * nheight;
	circle_extend = nradius * nradius * 3.14;
	sphere_surface_area = 4 * 3.14 * nradius;
	sphere_volume = (4 / 3) * 3.14 * nradius * nradius * nradius;
	printf("삼격형 넓이는: %.2lf\n", trangle_extend);
	printf("사각형 넓이는: %.2lf\n", qu_extend);
	printf("원의 넓이는: %.2lf\n", circle_extend);
	printf("구의 표면적은: %.2lf\n", sphere_surface_area);
	printf("구의 체적은: %.2lf\n", sphere_volume);
	return 0;
}*/
