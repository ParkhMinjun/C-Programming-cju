#include <stdio.h>    // 입출력 함수 사용을 위한 헤더
#include <stdlib.h>   // 동적 메모리 할당을 위한 헤더
#include <math.h>     // 수학 함수 사용을 위한 헤더


// 행렬 생성 및 메모리 할당 함수
int** CreateMatrix(int rows, int cols)
{
    int** matrix = (int**)malloc(rows * sizeof(int*)); // 행 포인터 배열 생성
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int*)malloc(cols * sizeof(int)); // 각 행에 대한 열 메모리 할당
    }
    return matrix;
}

// double 타입 행렬 생성
double** CreateMatrixDouble(int rows, int cols)
{
    double** matrix = (double**)malloc(rows * sizeof(double*));  // 실수형 행렬을 위한 메모리 할당
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

// 행렬 입력 함수
void InputMatrix(int** matrix, int rows, int cols)
{
    printf("행렬 원소를 입력하세요:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf_s("%d", &matrix[i][j]);  // 각 원소를 공백으로 구분
        }
    }
}

// 행렬 출력 함수
void PrintMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// double 타입 행렬 출력
void PrintMatrixDouble(double** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// 기본 행렬 연산 함수들
void AddMatrix(int** matrix1, int** matrix2, int** result, int rows, int cols)  // 행렬 덧셈
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void SubtractMatrix(int** matrix1, int** matrix2, int** result, int rows, int cols) // 행렬 뺄셈
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void MultiplyMatrix(int** matrix1, int** matrix2, int** result, int rows1, int cols1, int cols2) // 행렬 곱셈
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++)   // 첫번째 행렬의 열 수만큼 반복
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];  // 행렬의 i번째 행과 j번째 열을 곱함
            }
        }
    }
}

int** TransposeMatrix(int** matrix, int rows, int cols)  // 행렬의 전치
{
    int** result = CreateMatrix(cols, rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

void ScalarMultiply(int** matrix, int** result, int rows, int cols, int scalar)  // 행렬의 스칼라 곱
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}

// 고급 행렬 연산 함수들
int Determinant2x2(int** matrix) // 행렬식
{
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

int Determinant3x3(int** matrix)
{
    int det = 0;
    det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
        - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
        + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    return det;
}

void Inverse2x2(int** matrix, double** result) // 역행렬
{
    int det = Determinant2x2(matrix);
    if (det == 0)
    {
        printf("역행렬이 존재하지 않습니다.\n");  // 행렬식이 0이면 역행렬은 존재하지 않는다
        return;
    }

    result[0][0] = matrix[1][1] / (double)det;
    result[0][1] = -matrix[0][1] / (double)det;
    result[1][0] = -matrix[1][0] / (double)det;
    result[1][1] = matrix[0][0] / (double)det;
}

void Eigenvalues2x2(int** matrix, double* eigenvals) // 고유값
{  // 특성 방정식 계수: λ^2 + bλ + c
    double a = 1;  // λ^2의 계수
    double b = -(matrix[0][0] + matrix[1][1]);  // λ의 계수 (대각선 원소의 합의 음수)
    double c = Determinant2x2(matrix);  // 상수항 (행렬식)

    // 판별식 검사
    double discriminant = b * b - 4 * a * c;  // b^2 - 4ac

    // 복소수 고유값 검사
    if (discriminant < 0)
    {
        printf("복소수 고유값이 존재합니다.\n");  // 실수 고유값만 처리하기 위해
        return;
    }

    // 근의 공식으로 고유값 계산
    eigenvals[0] = (-b + sqrt(discriminant)) / (2 * a);
    eigenvals[1] = (-b - sqrt(discriminant)) / (2 * a);
}

void Eigenvectors2x2(int** matrix, double eigenval, double* eigenvector)  // 고유 벡터
{  // 특성방정식 (A - λI)v = 0 구성
    double a11 = matrix[0][0] - eigenval;  // 첫 번째 대각 원소에서 고유값을 뺌
    double a12 = matrix[0][1];  // 첫 번째 행 두 번째 열 원소

    // 연립방정식 풀이
    if (a11 != 0)
    {
        eigenvector[0] = 1; // x1 = 1
        eigenvector[1] = -a11 / a12; // x2 = -a11/a12 계산
    }
    else if (a12 != 0)
    {
        eigenvector[0] = -a12 / a11;  // x1 = -a12/a11
        eigenvector[1] = 1;  // x2 = 1로 가정
    }
    else
    {
        eigenvector[0] = 1;  // 특수한 경우 처리위해
        eigenvector[1] = 0;
    }

    // 고유벡터 정규화 (단위벡터로 변환)
    double norm = sqrt(eigenvector[0] * eigenvector[0] + eigenvector[1] * eigenvector[1]);  // 벡터 크기 계산
    eigenvector[0] /= norm;  // 정규화
    eigenvector[1] /= norm;  // 정규화
}

int CalculateRank2x2(int** matrix) // 계수(랭크)
{
    if (Determinant2x2(matrix) != 0) // 행렬식이 0이 아니면 랭크는 2 (모든 열이 선형 독립)
    {
        return 2;
    }
    // 모든 원소가 0인지 확인하기 위한 변수 초기화
    int allZero = 1; // 1은 모든 원소가 0이라고 가정

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (matrix[i][j] != 0) // 하나라도 0이 아닌 원소가 있으면 allZero를 0으로 설정 
            {
                allZero = 0;
            }
        }
    }
    if (allZero)  // 모든 원소가 0이면 랭크는 0
    {
        return 0;
    }
    // 행렬식이 0이고 모든 원소가 0이 아니면 랭크는 1
    return 1;
}

// 메모리 해제 함수
void FreeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);  //각 행의 메모리 해제
    }
    free(matrix);  // 행 포인터 배열 메모리 해제
}

void FreeMatrixDouble(double** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
    int run = 1;  // while문 제어 변수 선언
    while (run)  // 사용자가 종료할 때까지 반복
    {
        int choice;

        printf("\n행렬 계산 프로그램\n");
        printf("1. 기본 행렬 연산\n");
        printf("2. 고급 행렬 연산\n");
        printf("선택: ");
        scanf_s("%d", &choice);

        if (choice == 1)
        {
            printf("\n기본 행렬 연산\n");
            printf("1. 행렬 덧셈\n");
            printf("2. 행렬 뺄셈\n");
            printf("3. 행렬 곱셈\n");
            printf("4. 행렬 전치\n");
            printf("5. 스칼라 곱\n");
            printf("연산을 선택하세요: ");
            scanf_s("%d", &choice);

            int rows1, cols1, rows2, cols2;  // 행렬 크기 저장 변수
            int** matrix1 = NULL;  // 첫 번째 행렬 포인터, 초기화 위해 NULL 설정
            int** matrix2 = NULL;  // 두 번째 행렬 포인터
            int** result = NULL;   // 결과 행렬 포인터

            switch (choice)
            {
            case 1: // 덧셈
            {
                printf("\n행렬의 크기 입력 (행 열): ");
                scanf_s("%d %d", &rows1, &cols1);
                rows2 = rows1;
                cols2 = cols1;

                matrix1 = CreateMatrix(rows1, cols1);
                matrix2 = CreateMatrix(rows2, cols2);
                result = CreateMatrix(rows1, cols1);

                printf("첫 번째 행렬:\n");
                InputMatrix(matrix1, rows1, cols1);
                printf("두 번째 행렬:\n");
                InputMatrix(matrix2, rows2, cols2);

                AddMatrix(matrix1, matrix2, result, rows1, cols1);

                printf("결과:\n");
                PrintMatrix(result, rows1, cols1);

                FreeMatrix(matrix1, rows1);
                FreeMatrix(matrix2, rows2);
                FreeMatrix(result, rows1);
                break;
            }
            case 2: // 뺄셈
            {
                printf("\n행렬의 크기 입력 (행 열): ");
                scanf_s("%d %d", &rows1, &cols1);
                rows2 = rows1;
                cols2 = cols1;

                matrix1 = CreateMatrix(rows1, cols1);
                matrix2 = CreateMatrix(rows2, cols2);
                result = CreateMatrix(rows1, cols1);

                printf("첫 번째 행렬:\n");
                InputMatrix(matrix1, rows1, cols1);
                printf("두 번째 행렬:\n");
                InputMatrix(matrix2, rows2, cols2);

                SubtractMatrix(matrix1, matrix2, result, rows1, cols1);

                printf("결과:\n");
                PrintMatrix(result, rows1, cols1);

                FreeMatrix(matrix1, rows1);
                FreeMatrix(matrix2, rows2);
                FreeMatrix(result, rows1);
                break;
            }
            case 3: // 곱셈
            {
                printf("\n첫 번째 행렬의 크기 입력 (행 열): ");
                scanf_s("%d %d", &rows1, &cols1);
                printf("두 번째 행렬의 크기 입력 (행 열): ");
                scanf_s("%d %d", &rows2, &cols2);

                if (cols1 != rows2)
                {
                    printf("행렬 곱셈이 불가능합니다!\n");
                    return 1;
                }

                matrix1 = CreateMatrix(rows1, cols1);
                matrix2 = CreateMatrix(rows2, cols2);
                result = CreateMatrix(rows1, cols2);

                printf("첫 번째 행렬:\n");
                InputMatrix(matrix1, rows1, cols1);
                printf("두 번째 행렬:\n");
                InputMatrix(matrix2, rows2, cols2);

                MultiplyMatrix(matrix1, matrix2, result, rows1, cols1, cols2);

                printf("결과:\n");
                PrintMatrix(result, rows1, cols2);

                FreeMatrix(matrix1, rows1);
                FreeMatrix(matrix2, rows2);
                FreeMatrix(result, rows1);
                break;
            }
            case 4: // 전치(transpose)
            {
                printf("\n행렬의 크기 입력 (행 열): ");
                scanf_s("%d %d", &rows1, &cols1);

                matrix1 = CreateMatrix(rows1, cols1);
                printf("행렬 입력:\n");
                InputMatrix(matrix1, rows1, cols1);

                int** transposed = TransposeMatrix(matrix1, rows1, cols1);
                printf("전치 행렬:\n");
                PrintMatrix(transposed, cols1, rows1);

                FreeMatrix(matrix1, rows1);
                FreeMatrix(transposed, cols1);
                break;
            }
            case 5: // 스칼라 곱
            {
                printf("\n행렬의 크기 입력 (행 열): ");
                scanf_s("%d %d", &rows1, &cols1);

                matrix1 = CreateMatrix(rows1, cols1);
                result = CreateMatrix(rows1, cols1);
                int scalar;

                printf("행렬 입력:\n");
                InputMatrix(matrix1, rows1, cols1);
                printf("스칼라 값 입력: ");
                scanf_s("%d", &scalar);

                ScalarMultiply(matrix1, result, rows1, cols1, scalar);
                printf("결과:\n");
                PrintMatrix(result, rows1, cols1);

                FreeMatrix(matrix1, rows1);
                FreeMatrix(result, rows1);
                break;
            }
            }
        }
        else if (choice == 2)
        {
            printf("\n고급 행렬 연산\n");
            printf("1. 행렬식 계산\n");
            printf("2. 역행렬 계산\n");
            printf("3. 고유값과 고유벡터 계산\n");
            printf("4. 행렬의 계수(rank) 계산\n");
            printf("연산을 선택하세요: ");
            scanf_s("%d", &choice);

            int size;
            printf("\n행렬 크기 입력(2),행렬식(2 또는 3): ");
            scanf_s("%d", &size);

            int** matrix = CreateMatrix(size, size);
            InputMatrix(matrix, size, size);

            switch (choice)
            {
            case 1: // 행렬식 
            {
                int det;
                if (size == 2)
                {
                    det = Determinant2x2(matrix);
                }
                else
                {
                    det = Determinant3x3(matrix);
                }
                printf("행렬식 = %d\n", det);
                break;
            }

            case 2: // 역행렬 
            {
                if (size == 2)
                {
                    double** inverse = CreateMatrixDouble(2, 2);
                    Inverse2x2(matrix, inverse);
                    printf("역행렬:\n");
                    PrintMatrixDouble(inverse, 2, 2);
                    FreeMatrixDouble(inverse, 2);
                }
                break;
            }

            case 3: // 고유값과 고유벡터 
            {
                if (size == 2)
                {
                    double eigenvals[2];
                    Eigenvalues2x2(matrix, eigenvals);
                    printf("고유값: %.4f, %.4f\n", eigenvals[0], eigenvals[1]);

                    for (int i = 0; i < 2; i++)
                    {
                        double eigenvector[2];
                        Eigenvectors2x2(matrix, eigenvals[i], eigenvector);
                        printf("고유벡터 %d: [%.4f, %.4f]\n", i + 1, eigenvector[0], eigenvector[1]);
                    }
                }
                break;
            }

            case 4: // 계수(랭크)
            {
                if (size == 2)
                {
                    int rank = CalculateRank2x2(matrix);
                    printf("행렬의 계수(rank) = %d\n", rank);
                }
                break;
            }
            }
            FreeMatrix(matrix, size);
        }
        printf("\n계속하시겠습니까? (계속: 1, 종료: 0): ");
        scanf_s("%d", &run);  // 1을 넣으면 계속 작동,0이면 종료
    }
    printf("프로그램을 종료합니다.\n");
    return 0;
}