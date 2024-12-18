#include <stdio.h>
#include <math.h>

// 3���� �� ����ü ���� Point3D
typedef struct 
{
    double x;
    double y;
    double z;
} Point3D;

// ��Ŭ����� �Ÿ� ����ϴ� �Լ�
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

    // ù ��° ���� ��ǥ �Է�
    printf("ù ��° ���� ��ǥ (x y z): ");
    scanf_s("%lf %lf %lf", &point1.x, &point1.y, &point1.z);

    // �� ��° ���� ��ǥ �Է�
    printf("�� ��° ���� ��ǥ (x y z): ");
    scanf_s("%lf %lf %lf", &point2.x, &point2.y, &point2.z);

    // �Լ� ȣ�� �� ���
    double distance = CalculateDistance(point1, point2);
    printf("�� �� ������ �Ÿ�: %lf\n", distance);

    return 0;
}
