#include <stdio.h>

// 3���� ���͸� ǥ���ϴ� ����ü ����
struct Vector3D 
{
    int x;  // x ��ǥ
    int y;  // y ��ǥ
    int z;  // z ��ǥ
};

// ���� ��� �Լ�: �� ������ �� ������ ���ϰ� ����
int dotProduct(struct Vector3D v1, struct Vector3D v2) 
{
    // �� ������ ���ϰ� ���Ͽ� ���� ���
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

// ���� ��� �Լ�: �� ������ ������ ����Ͽ� ��� ���� ��ȯ
struct Vector3D crossProduct(struct Vector3D v1, struct Vector3D v2) 
{
    struct Vector3D result;  // ����� ������ ���� ����

    // ���� ���Ŀ� ���� �� ���� ���
    result.x = v1.y * v2.z - v1.z * v2.y;  // x���� ���
    result.y = v1.z * v2.x - v1.x * v2.z;  // y���� ���
    result.z = v1.x * v2.y - v1.y * v2.x;  // z���� ���

    return result;  // ���� ���� ���� ��ȯ
}

int main() 
{
    // ���� ���� ����
    struct Vector3D v1;        // ù ��° ����
    struct Vector3D v2;        // �� ��° ����
    struct Vector3D result;    // ���� ����� ������ ����

    // ù ��° ���� �Է� �ޱ�
    printf("ù ��° ���� �Է� (x y z): ");
    scanf_s("%d %d %d", &v1.x, &v1.y, &v1.z);

    // �� ��° ���� �Է� �ޱ�
    printf("�� ��° ���� �Է� (x y z): ");
    scanf_s("%d %d %d", &v2.x, &v2.y, &v2.z);

    // ���� ��� �� ���
    int dot = dotProduct(v1, v2);
    printf("\n���� ���: %d\n", dot);

    // ���� ��� �� ���
    result = crossProduct(v1, v2);
    printf("���� ���: (%d, %d, %d)\n", result.x, result.y, result.z);

    return 0;
}

