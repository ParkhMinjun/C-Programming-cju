#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ������ ���������� ���� (����=0, ����=1, ����=2, Ž��=3)
enum Subject 
{
    KOREAN,     // ���� ����
    ENGLISH,    // ���� ����
    MATH,       // ���� ����
    RESEARCH,   // Ž�� ����
    SUBJECT_COUNT   // �� ���� ���� ��Ÿ���� ���
};

// �л� ������ �����ϱ� ���� ����ü ����
typedef struct 
{
    char name[50];      // �л� �̸�
    int class;          // �й� ��ȣ
    int studentId;      // �й�
    int scores[SUBJECT_COUNT];    // ���� ���� �迭
    float average;      // ��� ����
    int classRank;      // �й� �� ���
    int totalRank;      // ��ü ���
} Student;

// ���Ͽ��� �л� �����͸� �о���� �Լ�
void readStudentData(Student* students, int* count, const char* filename, int classNum) 
{
    FILE* file;
    errno_t err = fopen_s(&file, filename, "r");
    if (err != 0) 
    {
        printf("%s ������ �� �� �����ϴ�.\n", filename);
        return;
    }

    // ������� ���� �л� ���� ����
    int startCount = *count;
    char name[50];
    int studentId, korean, english, math;

    // ���Ͽ��� �� �پ� �о �л� ���� ����
    while (fscanf_s(file, "%s %d %d %d %d",
        name, (unsigned)sizeof(name),
        &studentId,
        &korean,
        &english,
        &math) == 5) 
    {

        // ���� �����͸� ����ü�� ����
        strcpy_s(students[*count].name, sizeof(students[*count].name), name);
        students[*count].studentId = studentId;
        students[*count].class = classNum;
        students[*count].scores[KOREAN] = korean;
        students[*count].scores[ENGLISH] = english;
        students[*count].scores[MATH] = math;
        students[*count].scores[RESEARCH] = 0;  // Ž�� ������ ���� �̻��
        (*count)++;
    }

    printf("%d�й� ������ �б� �Ϸ�: %d��\n", classNum, *count - startCount);
    fclose(file);
}

// �� �л��� ��� ������ ����ϴ� �Լ�
void calculateAverage(Student* students, int count) 
{
    for (int i = 0; i < count; i++) 
    {
        // ����, ����, ���� 3������ ��� ���
        float sum = students[i].scores[KOREAN] +
            students[i].scores[ENGLISH] +
            students[i].scores[MATH];
        students[i].average = sum / 3.0f;
    }
}

// �й� ����� ��ü ����� ����ϴ� �Լ�
void calculateRanks(Student* students, int count) 
{
    // ��ü ��� ���
    for (int i = 0; i < count; i++) 
    {
        students[i].totalRank = 1;
        for (int j = 0; j < count; j++) 
        {
            if (students[j].average > students[i].average) 
            {
                students[i].totalRank++;
            }
        }
    }

    // �й� ��� ���
    for (int i = 0; i < count; i++) 
    {
        students[i].classRank = 1;
        for (int j = 0; j < count; j++) 
        {
            // ���� �й� �������� ��� ���
            if (students[j].class == students[i].class &&
                students[j].average > students[i].average) 
            {
                students[i].classRank++;
            }
        }
    }
}

// �йݺ� ����� ���Ϸ� ����ϴ� �Լ�
void writeResults(Student* students, int count, int classNum) 
{
    FILE* file;
    char filename[50];
    sprintf_s(filename, sizeof(filename), "students_%d_results.txt", classNum);

    errno_t err = fopen_s(&file, filename, "w");
    if (err != 0) 
    {
        printf("%s ������ ������ �� �����ϴ�.\n", filename);
        return;
    }

    // ��� ��� (ĭ ���� ����)
    fprintf(file, "%-8s %-10s %6s %6s %6s %8s %10s %10s\n",
        "�й�", "�̸�", "����", "����", "����", "���", "�йݵ��", "��ü���"); 
    fprintf(file, "=================================================================\n");

    // �ش� �й� �л����� ���� ���� ���
    for (int i = 0; i < count; i++) 
    {
        if (students[i].class == classNum) 
        {
            fprintf(file, "%-8d %-10s %6d %6d %6d %8.2f %10d %10d\n",
                students[i].studentId,
                students[i].name,
                students[i].scores[KOREAN],
                students[i].scores[ENGLISH],
                students[i].scores[MATH],
                students[i].average,
                students[i].classRank,
                students[i].totalRank);
        }
    }

    printf("%s ������ �����Ǿ����ϴ�.\n", filename);
    fclose(file);
}

// ��ü ����� ���Ϸ� ����ϴ� �Լ�
void writeClassResults(Student* students, int count) 
{
    FILE* file;
    errno_t err = fopen_s(&file, "class_results.txt", "w");
    if (err != 0) 
    {
        printf("class_results.txt ������ ������ �� �����ϴ�.\n");
        return;
    }

    // �йݺ� ��� ����� ���� ����
    float class1Sum = 0, class2Sum = 0;
    int class1Count = 0, class2Count = 0;

    // �йݺ� ��� ���
    for (int i = 0; i < count; i++) 
    {
        if (students[i].class == 1) 
        {
            class1Sum += students[i].average;
            class1Count++;
        }
        else 
        {
            class2Sum += students[i].average;
            class2Count++;
        }
    }

    // �йݺ� ���� �м� ��� ���
    fprintf(file, "�йݺ� ���� �м� ���\n");
    fprintf(file, "====================\n\n");
    fprintf(file, "1�й� ���: %8.2f\n", class1Sum / class1Count);
    fprintf(file, "2�й� ���: %8.2f\n", class2Sum / class2Count);
    fprintf(file, "��ü ���: %8.2f\n\n", (class1Sum + class2Sum) / count);

    // ��ü ��� ����ǥ ���
    fprintf(file, "��ü ��� ����ǥ\n");
    fprintf(file, "==============\n");
    fprintf(file, "%-6s %-10s %6s %8s\n", "����", "�̸�", "�й�", "���");
    fprintf(file, "--------------------------------\n");

    // ������� �л� ���� ���
    for (int rank = 1; rank <= count; rank++) 
    {
        for (int i = 0; i < count; i++) 
        {
            if (students[i].totalRank == rank) 
            {
                fprintf(file, "%-6d %-10s %6d %8.2f\n",
                    rank,
                    students[i].name,
                    students[i].class,
                    students[i].average);
            }
        }
    }

    printf("class_results.txt ������ �����Ǿ����ϴ�.\n");
    fclose(file);
}

int main() 
{
    Student students[20];  // �ִ� 20���� �л� �����͸� ������ �迭
    int totalCount = 0;    // ��ü �л� ���� ������ ����

    printf("\n=== �л� ���� ���� ���α׷� ���� ===\n\n");

    // 1�ݰ� 2���� �л� ������ �б�
    readStudentData(students, &totalCount, "students_1.txt", 1);
    readStudentData(students, &totalCount, "students_2.txt", 2);

    printf("\n��ü %d���� �л� �����͸� �о����ϴ�.\n\n", totalCount);

    // ��հ� ��� ���
    calculateAverage(students, totalCount);
    calculateRanks(students, totalCount);

    // ��� ���� ����
    writeResults(students, totalCount, 1);
    writeResults(students, totalCount, 2);
    writeClassResults(students, totalCount);

    printf("\n=== ���α׷��� ���������� �Ϸ�Ǿ����ϴ� ===\n");
    return 0;
}
