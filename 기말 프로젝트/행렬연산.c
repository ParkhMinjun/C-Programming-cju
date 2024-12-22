#include <stdio.h>    // ����� �Լ� ����� ���� ���
#include <stdlib.h>   // ���� �޸� �Ҵ��� ���� ���
#include <math.h>     // ���� �Լ� ����� ���� ���


// ��� ���� �� �޸� �Ҵ� �Լ�
int** CreateMatrix(int rows, int cols)
{
    int** matrix = (int**)malloc(rows * sizeof(int*)); // �� ������ �迭 ����
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int*)malloc(cols * sizeof(int)); // �� �࿡ ���� �� �޸� �Ҵ�
    }
    return matrix;
}

// double Ÿ�� ��� ����
double** CreateMatrixDouble(int rows, int cols)
{
    double** matrix = (double**)malloc(rows * sizeof(double*));  // �Ǽ��� ����� ���� �޸� �Ҵ�
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

// ��� �Է� �Լ�
void InputMatrix(int** matrix, int rows, int cols)
{
    printf("��� ���Ҹ� �Է��ϼ���:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf_s("%d", &matrix[i][j]);  // �� ���Ҹ� �������� ����
        }
    }
}

// ��� ��� �Լ�
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

// double Ÿ�� ��� ���
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

// �⺻ ��� ���� �Լ���
void AddMatrix(int** matrix1, int** matrix2, int** result, int rows, int cols)  // ��� ����
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void SubtractMatrix(int** matrix1, int** matrix2, int** result, int rows, int cols) // ��� ����
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void MultiplyMatrix(int** matrix1, int** matrix2, int** result, int rows1, int cols1, int cols2) // ��� ����
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++)   // ù��° ����� �� ����ŭ �ݺ�
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];  // ����� i��° ��� j��° ���� ����
            }
        }
    }
}

int** TransposeMatrix(int** matrix, int rows, int cols)  // ����� ��ġ
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

void ScalarMultiply(int** matrix, int** result, int rows, int cols, int scalar)  // ����� ��Į�� ��
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}

// ��� ��� ���� �Լ���
int Determinant2x2(int** matrix) // ��Ľ�
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

void Inverse2x2(int** matrix, double** result) // �����
{
    int det = Determinant2x2(matrix);
    if (det == 0)
    {
        printf("������� �������� �ʽ��ϴ�.\n");  // ��Ľ��� 0�̸� ������� �������� �ʴ´�
        return;
    }

    result[0][0] = matrix[1][1] / (double)det;
    result[0][1] = -matrix[0][1] / (double)det;
    result[1][0] = -matrix[1][0] / (double)det;
    result[1][1] = matrix[0][0] / (double)det;
}

void Eigenvalues2x2(int** matrix, double* eigenvals) // ������
{  // Ư�� ������ ���: ��^2 + b�� + c
    double a = 1;  // ��^2�� ���
    double b = -(matrix[0][0] + matrix[1][1]);  // ���� ��� (�밢�� ������ ���� ����)
    double c = Determinant2x2(matrix);  // ����� (��Ľ�)

    // �Ǻ��� �˻�
    double discriminant = b * b - 4 * a * c;  // b^2 - 4ac

    // ���Ҽ� ������ �˻�
    if (discriminant < 0)
    {
        printf("���Ҽ� �������� �����մϴ�.\n");  // �Ǽ� �������� ó���ϱ� ����
        return;
    }

    // ���� �������� ������ ���
    eigenvals[0] = (-b + sqrt(discriminant)) / (2 * a);
    eigenvals[1] = (-b - sqrt(discriminant)) / (2 * a);
}

void Eigenvectors2x2(int** matrix, double eigenval, double* eigenvector)  // ���� ����
{  // Ư�������� (A - ��I)v = 0 ����
    double a11 = matrix[0][0] - eigenval;  // ù ��° �밢 ���ҿ��� �������� ��
    double a12 = matrix[0][1];  // ù ��° �� �� ��° �� ����

    // ���������� Ǯ��
    if (a11 != 0)
    {
        eigenvector[0] = 1; // x1 = 1
        eigenvector[1] = -a11 / a12; // x2 = -a11/a12 ���
    }
    else if (a12 != 0)
    {
        eigenvector[0] = -a12 / a11;  // x1 = -a12/a11
        eigenvector[1] = 1;  // x2 = 1�� ����
    }
    else
    {
        eigenvector[0] = 1;  // Ư���� ��� ó������
        eigenvector[1] = 0;
    }

    // �������� ����ȭ (�������ͷ� ��ȯ)
    double norm = sqrt(eigenvector[0] * eigenvector[0] + eigenvector[1] * eigenvector[1]);  // ���� ũ�� ���
    eigenvector[0] /= norm;  // ����ȭ
    eigenvector[1] /= norm;  // ����ȭ
}

int CalculateRank2x2(int** matrix) // ���(��ũ)
{
    if (Determinant2x2(matrix) != 0) // ��Ľ��� 0�� �ƴϸ� ��ũ�� 2 (��� ���� ���� ����)
    {
        return 2;
    }
    // ��� ���Ұ� 0���� Ȯ���ϱ� ���� ���� �ʱ�ȭ
    int allZero = 1; // 1�� ��� ���Ұ� 0�̶�� ����

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (matrix[i][j] != 0) // �ϳ��� 0�� �ƴ� ���Ұ� ������ allZero�� 0���� ���� 
            {
                allZero = 0;
            }
        }
    }
    if (allZero)  // ��� ���Ұ� 0�̸� ��ũ�� 0
    {
        return 0;
    }
    // ��Ľ��� 0�̰� ��� ���Ұ� 0�� �ƴϸ� ��ũ�� 1
    return 1;
}

// �޸� ���� �Լ�
void FreeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);  //�� ���� �޸� ����
    }
    free(matrix);  // �� ������ �迭 �޸� ����
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
    int run = 1;  // while�� ���� ���� ����
    while (run)  // ����ڰ� ������ ������ �ݺ�
    {
        int choice;

        printf("\n��� ��� ���α׷�\n");
        printf("1. �⺻ ��� ����\n");
        printf("2. ��� ��� ����\n");
        printf("����: ");
        scanf_s("%d", &choice);

        if (choice == 1)
        {
            printf("\n�⺻ ��� ����\n");
            printf("1. ��� ����\n");
            printf("2. ��� ����\n");
            printf("3. ��� ����\n");
            printf("4. ��� ��ġ\n");
            printf("5. ��Į�� ��\n");
            printf("������ �����ϼ���: ");
            scanf_s("%d", &choice);

            int rows1, cols1, rows2, cols2;  // ��� ũ�� ���� ����
            int** matrix1 = NULL;  // ù ��° ��� ������, �ʱ�ȭ ���� NULL ����
            int** matrix2 = NULL;  // �� ��° ��� ������
            int** result = NULL;   // ��� ��� ������

            switch (choice)
            {
            case 1: // ����
            {
                printf("\n����� ũ�� �Է� (�� ��): ");
                scanf_s("%d %d", &rows1, &cols1);
                rows2 = rows1;
                cols2 = cols1;

                matrix1 = CreateMatrix(rows1, cols1);
                matrix2 = CreateMatrix(rows2, cols2);
                result = CreateMatrix(rows1, cols1);

                printf("ù ��° ���:\n");
                InputMatrix(matrix1, rows1, cols1);
                printf("�� ��° ���:\n");
                InputMatrix(matrix2, rows2, cols2);

                AddMatrix(matrix1, matrix2, result, rows1, cols1);

                printf("���:\n");
                PrintMatrix(result, rows1, cols1);

                FreeMatrix(matrix1, rows1);
                FreeMatrix(matrix2, rows2);
                FreeMatrix(result, rows1);
                break;
            }
            case 2: // ����
            {
                printf("\n����� ũ�� �Է� (�� ��): ");
                scanf_s("%d %d", &rows1, &cols1);
                rows2 = rows1;
                cols2 = cols1;

                matrix1 = CreateMatrix(rows1, cols1);
                matrix2 = CreateMatrix(rows2, cols2);
                result = CreateMatrix(rows1, cols1);

                printf("ù ��° ���:\n");
                InputMatrix(matrix1, rows1, cols1);
                printf("�� ��° ���:\n");
                InputMatrix(matrix2, rows2, cols2);

                SubtractMatrix(matrix1, matrix2, result, rows1, cols1);

                printf("���:\n");
                PrintMatrix(result, rows1, cols1);

                FreeMatrix(matrix1, rows1);
                FreeMatrix(matrix2, rows2);
                FreeMatrix(result, rows1);
                break;
            }
            case 3: // ����
            {
                printf("\nù ��° ����� ũ�� �Է� (�� ��): ");
                scanf_s("%d %d", &rows1, &cols1);
                printf("�� ��° ����� ũ�� �Է� (�� ��): ");
                scanf_s("%d %d", &rows2, &cols2);

                if (cols1 != rows2)
                {
                    printf("��� ������ �Ұ����մϴ�!\n");
                    return 1;
                }

                matrix1 = CreateMatrix(rows1, cols1);
                matrix2 = CreateMatrix(rows2, cols2);
                result = CreateMatrix(rows1, cols2);

                printf("ù ��° ���:\n");
                InputMatrix(matrix1, rows1, cols1);
                printf("�� ��° ���:\n");
                InputMatrix(matrix2, rows2, cols2);

                MultiplyMatrix(matrix1, matrix2, result, rows1, cols1, cols2);

                printf("���:\n");
                PrintMatrix(result, rows1, cols2);

                FreeMatrix(matrix1, rows1);
                FreeMatrix(matrix2, rows2);
                FreeMatrix(result, rows1);
                break;
            }
            case 4: // ��ġ(transpose)
            {
                printf("\n����� ũ�� �Է� (�� ��): ");
                scanf_s("%d %d", &rows1, &cols1);

                matrix1 = CreateMatrix(rows1, cols1);
                printf("��� �Է�:\n");
                InputMatrix(matrix1, rows1, cols1);

                int** transposed = TransposeMatrix(matrix1, rows1, cols1);
                printf("��ġ ���:\n");
                PrintMatrix(transposed, cols1, rows1);

                FreeMatrix(matrix1, rows1);
                FreeMatrix(transposed, cols1);
                break;
            }
            case 5: // ��Į�� ��
            {
                printf("\n����� ũ�� �Է� (�� ��): ");
                scanf_s("%d %d", &rows1, &cols1);

                matrix1 = CreateMatrix(rows1, cols1);
                result = CreateMatrix(rows1, cols1);
                int scalar;

                printf("��� �Է�:\n");
                InputMatrix(matrix1, rows1, cols1);
                printf("��Į�� �� �Է�: ");
                scanf_s("%d", &scalar);

                ScalarMultiply(matrix1, result, rows1, cols1, scalar);
                printf("���:\n");
                PrintMatrix(result, rows1, cols1);

                FreeMatrix(matrix1, rows1);
                FreeMatrix(result, rows1);
                break;
            }
            }
        }
        else if (choice == 2)
        {
            printf("\n��� ��� ����\n");
            printf("1. ��Ľ� ���\n");
            printf("2. ����� ���\n");
            printf("3. �������� �������� ���\n");
            printf("4. ����� ���(rank) ���\n");
            printf("������ �����ϼ���: ");
            scanf_s("%d", &choice);

            int size;
            printf("\n��� ũ�� �Է�(2),��Ľ�(2 �Ǵ� 3): ");
            scanf_s("%d", &size);

            int** matrix = CreateMatrix(size, size);
            InputMatrix(matrix, size, size);

            switch (choice)
            {
            case 1: // ��Ľ� 
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
                printf("��Ľ� = %d\n", det);
                break;
            }

            case 2: // ����� 
            {
                if (size == 2)
                {
                    double** inverse = CreateMatrixDouble(2, 2);
                    Inverse2x2(matrix, inverse);
                    printf("�����:\n");
                    PrintMatrixDouble(inverse, 2, 2);
                    FreeMatrixDouble(inverse, 2);
                }
                break;
            }

            case 3: // �������� �������� 
            {
                if (size == 2)
                {
                    double eigenvals[2];
                    Eigenvalues2x2(matrix, eigenvals);
                    printf("������: %.4f, %.4f\n", eigenvals[0], eigenvals[1]);

                    for (int i = 0; i < 2; i++)
                    {
                        double eigenvector[2];
                        Eigenvectors2x2(matrix, eigenvals[i], eigenvector);
                        printf("�������� %d: [%.4f, %.4f]\n", i + 1, eigenvector[0], eigenvector[1]);
                    }
                }
                break;
            }

            case 4: // ���(��ũ)
            {
                if (size == 2)
                {
                    int rank = CalculateRank2x2(matrix);
                    printf("����� ���(rank) = %d\n", rank);
                }
                break;
            }
            }
            FreeMatrix(matrix, size);
        }
        printf("\n����Ͻðڽ��ϱ�? (���: 1, ����: 0): ");
        scanf_s("%d", &run);  // 1�� ������ ��� �۵�,0�̸� ����
    }
    printf("���α׷��� �����մϴ�.\n");
    return 0;
}