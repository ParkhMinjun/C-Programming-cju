#include <stdio.h>
#include <math.h>

// 3차원 점 구조체 선언 Point3D
typedef struct 
{
    double x;
    double y;
    double z;
} Point3D;

// 유클리디안 거리 계산하는 함수
double CalculateDistance(Point3D p1, Point3D p2) 
{
    double dx = p2.x - p1.x;  // (x2-x1)
    double dy = p2.y - p1.y;  // (y2-y1)
    double dz = p2.z - p1.z;  // (z2-z1)

    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() 
{
    Point3D point1, point2;

    // 첫 번째 점의 좌표 입력
    printf("첫 번째 점의 좌표 (x y z): ");
    scanf_s("%lf %lf %lf", &point1.x, &point1.y, &point1.z);

    // 두 번째 점의 좌표 입력
    printf("두 번째 점의 좌표 (x y z): ");
    scanf_s("%lf %lf %lf", &point2.x, &point2.y, &point2.z);

    // 함수 호출 및 출력
    double distance = CalculateDistance(point1, point2);
    printf("두 점 사이의 거리: %lf\n", distance);

    return 0;
}
