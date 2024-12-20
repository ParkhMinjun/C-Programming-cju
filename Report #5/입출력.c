#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 과목을 열거형으로 정의 (국어=0, 영어=1, 수학=2, 탐구=3)
enum Subject 
{
    KOREAN,     // 국어 과목
    ENGLISH,    // 영어 과목
    MATH,       // 수학 과목
    RESEARCH,   // 탐구 과목
    SUBJECT_COUNT   // 총 과목 수를 나타내는 상수
};

// 학생 정보를 저장하기 위한 구조체 정의
typedef struct 
{
    char name[50];      // 학생 이름
    int class;          // 분반 번호
    int studentId;      // 학번
    int scores[SUBJECT_COUNT];    // 과목별 점수 배열
    float average;      // 평균 점수
    int classRank;      // 분반 내 등수
    int totalRank;      // 전체 등수
} Student;

// 파일에서 학생 데이터를 읽어오는 함수
void readStudentData(Student* students, int* count, const char* filename, int classNum) 
{
    FILE* file;
    errno_t err = fopen_s(&file, filename, "r");
    if (err != 0) 
    {
        printf("%s 파일을 열 수 없습니다.\n", filename);
        return;
    }

    // 현재까지 읽은 학생 수를 저장
    int startCount = *count;
    char name[50];
    int studentId, korean, english, math;

    // 파일에서 한 줄씩 읽어서 학생 정보 저장
    while (fscanf_s(file, "%s %d %d %d %d",
        name, (unsigned)sizeof(name),
        &studentId,
        &korean,
        &english,
        &math) == 5) 
    {

        // 읽은 데이터를 구조체에 저장
        strcpy_s(students[*count].name, sizeof(students[*count].name), name);
        students[*count].studentId = studentId;
        students[*count].class = classNum;
        students[*count].scores[KOREAN] = korean;
        students[*count].scores[ENGLISH] = english;
        students[*count].scores[MATH] = math;
        students[*count].scores[RESEARCH] = 0;  // 탐구 점수는 현재 미사용
        (*count)++;
    }

    printf("%d분반 데이터 읽기 완료: %d명\n", classNum, *count - startCount);
    fclose(file);
}

// 각 학생의 평균 점수를 계산하는 함수
void calculateAverage(Student* students, int count) 
{
    for (int i = 0; i < count; i++) 
    {
        // 국어, 영어, 수학 3과목의 평균 계산
        float sum = students[i].scores[KOREAN] +
            students[i].scores[ENGLISH] +
            students[i].scores[MATH];
        students[i].average = sum / 3.0f;
    }
}

// 분반 등수와 전체 등수를 계산하는 함수
void calculateRanks(Student* students, int count) 
{
    // 전체 등수 계산
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

    // 분반 등수 계산
    for (int i = 0; i < count; i++) 
    {
        students[i].classRank = 1;
        for (int j = 0; j < count; j++) 
        {
            // 같은 분반 내에서만 등수 계산
            if (students[j].class == students[i].class &&
                students[j].average > students[i].average) 
            {
                students[i].classRank++;
            }
        }
    }
}

// 분반별 결과를 파일로 출력하는 함수
void writeResults(Student* students, int count, int classNum) 
{
    FILE* file;
    char filename[50];
    sprintf_s(filename, sizeof(filename), "students_%d_results.txt", classNum);

    errno_t err = fopen_s(&file, filename, "w");
    if (err != 0) 
    {
        printf("%s 파일을 생성할 수 없습니다.\n", filename);
        return;
    }

    // 헤더 출력 (칸 맞춤 적용)
    fprintf(file, "%-8s %-10s %6s %6s %6s %8s %10s %10s\n",
        "학번", "이름", "국어", "영어", "수학", "평균", "분반등수", "전체등수"); 
    fprintf(file, "=================================================================\n");

    // 해당 분반 학생들의 성적 정보 출력
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

    printf("%s 파일이 생성되었습니다.\n", filename);
    fclose(file);
}

// 전체 결과를 파일로 출력하는 함수
void writeClassResults(Student* students, int count) 
{
    FILE* file;
    errno_t err = fopen_s(&file, "class_results.txt", "w");
    if (err != 0) 
    {
        printf("class_results.txt 파일을 생성할 수 없습니다.\n");
        return;
    }

    // 분반별 평균 계산을 위한 변수
    float class1Sum = 0, class2Sum = 0;
    int class1Count = 0, class2Count = 0;

    // 분반별 평균 계산
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

    // 분반별 성적 분석 결과 출력
    fprintf(file, "분반별 성적 분석 결과\n");
    fprintf(file, "====================\n\n");
    fprintf(file, "1분반 평균: %8.2f\n", class1Sum / class1Count);
    fprintf(file, "2분반 평균: %8.2f\n", class2Sum / class2Count);
    fprintf(file, "전체 평균: %8.2f\n\n", (class1Sum + class2Sum) / count);

    // 전체 등수 순위표 출력
    fprintf(file, "전체 등수 순위표\n");
    fprintf(file, "==============\n");
    fprintf(file, "%-6s %-10s %6s %8s\n", "순위", "이름", "분반", "평균");
    fprintf(file, "--------------------------------\n");

    // 등수별로 학생 정보 출력
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

    printf("class_results.txt 파일이 생성되었습니다.\n");
    fclose(file);
}

int main() 
{
    Student students[20];  // 최대 20명의 학생 데이터를 저장할 배열
    int totalCount = 0;    // 전체 학생 수를 저장할 변수

    printf("\n=== 학생 성적 관리 프로그램 시작 ===\n\n");

    // 1반과 2반의 학생 데이터 읽기
    readStudentData(students, &totalCount, "students_1.txt", 1);
    readStudentData(students, &totalCount, "students_2.txt", 2);

    printf("\n전체 %d명의 학생 데이터를 읽었습니다.\n\n", totalCount);

    // 평균과 등수 계산
    calculateAverage(students, totalCount);
    calculateRanks(students, totalCount);

    // 결과 파일 생성
    writeResults(students, totalCount, 1);
    writeResults(students, totalCount, 2);
    writeClassResults(students, totalCount);

    printf("\n=== 프로그램이 성공적으로 완료되었습니다 ===\n");
    return 0;
}
