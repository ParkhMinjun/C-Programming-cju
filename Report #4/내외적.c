#include <stdio.h>

// 3차원 벡터를 표현하는 구조체 정의
struct Vector3D 
{
    int x;  // x 좌표
    int y;  // y 좌표
    int z;  // z 좌표
};

// 내적 계산 함수: 두 벡터의 각 성분을 곱하고 더함
int dotProduct(struct Vector3D v1, struct Vector3D v2) 
{
    // 각 성분을 곱하고 더하여 내적 계산
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

// 외적 계산 함수: 두 벡터의 외적을 계산하여 결과 벡터 반환
struct Vector3D crossProduct(struct Vector3D v1, struct Vector3D v2) 
{
    struct Vector3D result;  // 결과를 저장할 벡터 선언

    // 외적 공식에 따라 각 성분 계산
    result.x = v1.y * v2.z - v1.z * v2.y;  // x성분 계산
    result.y = v1.z * v2.x - v1.x * v2.z;  // y성분 계산
    result.z = v1.x * v2.y - v1.y * v2.x;  // z성분 계산

    return result;  // 계산된 외적 벡터 반환
}

int main() 
{
    // 벡터 변수 선언
    struct Vector3D v1;        // 첫 번째 벡터
    struct Vector3D v2;        // 두 번째 벡터
    struct Vector3D result;    // 외적 결과를 저장할 벡터

    // 첫 번째 벡터 입력 받기
    printf("첫 번째 벡터 입력 (x y z): ");
    scanf_s("%d %d %d", &v1.x, &v1.y, &v1.z);

    // 두 번째 벡터 입력 받기
    printf("두 번째 벡터 입력 (x y z): ");
    scanf_s("%d %d %d", &v2.x, &v2.y, &v2.z);

    // 내적 계산 및 출력
    int dot = dotProduct(v1, v2);
    printf("\n내적 결과: %d\n", dot);

    // 외적 계산 및 출력
    result = crossProduct(v1, v2);
    printf("외적 결과: (%d, %d, %d)\n", result.x, result.y, result.z);

    return 0;
}

