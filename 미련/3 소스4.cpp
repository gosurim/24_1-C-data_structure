#if 0 //14 #1 배열, 함수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h.>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MEMBER 10

void memberSum(int Basic[], int Plus[], int Total[], int member);

int main(void) {

    int basic[MEMBER];
    int plus[MEMBER];
    int sumTotal[MEMBER];

    printf("직원 %d 명의 월급을 입력하시오(단위 만원). : ", MEMBER);
    for (int i = 0; i < MEMBER; i++) {
        scanf("%d", &basic[i]);
    }
    printf("직원 %d명의 보너스를 입력하시오(단위 만원). : ", MEMBER);
    for (int i = 0; i < MEMBER; i++)
    {
        scanf("%d", &plus[i]);
    }

    memberSum(basic, plus, sumTotal, MEMBER);
    printf("각 직원들의 지급받을 총액\n");

    for (int i = 0; i < MEMBER; i++)
    {
        printf("직원%d : %d\n", i + 1, sumTotal[i]);
    }
}
void memberSum(int Basic[], int Plus[], int Total[], int member) {
    for (int i = 0; i < MEMBER; i++)
    {
        Total[i] = Basic[i] + Plus[i];
    }
}
#elif 0 //14 #2 2차원 배열 arr[4][5]
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
void fill_2d_array(int parr[4][5], int n);

int main(void) {
    int parr[4][5];
    int num;

    printf("배열의 원소에 저장할 값 : ");
    scanf("%d", &num);
    fill_2d_array(parr, num);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf(" %d", parr[i][j]);
        }
        printf("\n");
    }

}//main

void fill_2d_array(int parr[4][5], int n) {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            parr[i][j] = n;
        }
    }
}
#elif 0 //14 #3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main(void) {
    int n;
    int matrix1[20][20];
    int matrix2[20][20];
    int mul;

    printf("NxN 행렬 곱셉 Program입니다.. N: ");
    scanf("%d", &n);


    printf("이차원 첫번째 배열의 숫자를 입력하시오. \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d x %d 정수 입력 : ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("이차원 두번째 배열의 숫자를 입력하시오. \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d x %d 정수 입력 : ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mul = 0;
            for (int k = 0; k < n; k++)
            {
                mul += (matrix1[i][k] * matrix2[k][j]);
            }
            printf("%d", mul);
        }
        printf("\n");
    }
}
#elif 0 //15 #1 포인터
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
int squardFunc(int* ptr) {
    return (*ptr) * (*ptr);
}
int main(void) {
    int num;

    printf("num : ");
    scanf("%d", &num);

    printf("%d를 제곱한 값은 %d\n", num, squardFunc(&num));
}
#elif 0 //15 #2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
int changer(int* a, int* b, int* c) {
    int temp = *c;
    *c = *b;
    *b = *a;
    *a = temp;
    return *a, * b, * c;
}
int sumx(int a, int b, int c, int* sum, int* x) {
    *sum = a + b + c;
    *x = a * b * c;
    return *sum, * x;
}

int main(void) {
    int a, b, c;
    int sum, x;
    printf("숫자 3개를 입력하시오. : ");
    scanf("%d %d %d", &a, &b, &c);

    printf("바꾸기 전 : %d %d %d\n", a, b, c);
    changer(&a, &b, &c);
    printf("바꾼 후 : %d %d %d\n", a, b, c);

    sumx(a, b, c, &sum, &x);
    printf("세 정수의 합 : %d\n", sum);

    printf("세 정수의 곱 : %d\n", x);
}
#elif 0 //15
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MEMBER 10

void dnjfrmq(int* basic, int* plus, int* total, int member);

int main(void) {
    int basic[MEMBER];
    int plus[MEMBER];
    int total[MEMBER];

    printf("직원 10명의 월급을 입력하시오(단위 만 원): ");
    for (int i = 0; i < MEMBER; i++) {
        scanf("%d", &basic[i]);
    }
    printf("직원 10명의 보너스를 입력하시오(단위 만 원): ");
    for (int i = 0; i < MEMBER; i++) {
        scanf("%d", &plus[i]);
    }
    dnjfrmq(basic, plus, total, MEMBER);
    printf("각 직원들의 지급받을 월급 총액\n");

    for (int i = 0; i < MEMBER; i++) {
        printf("직원 %d : %\n", i + 1, total[i]);
    }
}
void dnjfrmq(int* basic, int* plus, int* total, int member) {
    for (int i = 0; i < member; i++) {
        total[i] = basic[i] + plus[i];
    }
}
#elif 0 //15 #4 초입력 시간
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
void change_time(int sec, int* h, int* m, int* s) {
    *h = sec / 3600;
    *m = (sec - (*h * 3600)) / 60;
    *s = (sec - (*h * 3600) - (*m * 60));
}

int main(void) {
    unsigned int sec;
    int h = 0, m = 0, s = 0;

    printf("변환하려는 초를 입력해주세요 : ");
    scanf("%d", &sec);
    change_time(sec, &h, &m, &s);

    printf("%d초는 %d시간 %d분 %d초 입니다.", sec, h, m, s);
}
#elif 0 //16 #1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define SIZE 5

int rev_array(int* p, int size);

int main(void) {
    int data[5];

    printf("배열 안에 들어갈 숫자 5개를 입력하시오\n");
    for (int i = 0; i < 5; i++){
        scanf("%d", &data[i]);
    }

    int* p;
    p = data;
    rev_array(p, SIZE);
}
int rev_array(int* p, int size) {
    for (int i = 0; i < size; i++)
    {
        printf(" %d", *(p + size - 1 - i));
    }
    return 0;
}
#elif 0 //16 #2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(void) {
    int arr[9];
    int* p = arr;
    int max = 0, num = 0;

    for (int i = 0; i < 9; i++){
        scanf("%d", &*p);
        if (max < *p) {
            max = *p;
            num = i + 1;
            p++;
        }
    }

    printf("최댓값: %d, 순서 : %d", max, num);
}
#elif 1 //16 #3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int changeStr(char* p, int len);

int main(void) {
    char s[20];
    int n;
    int len;
    scanf("%s", s);
    scanf("%d", &n);
    len = strlen(s);
    for (int i = 0; i < n; i++)
    {
        changeStr(s, len);
    }
    printf("%s", s);
}
int changeStr(char* p, int len) {
    for (int i = 0; i < len - 1; i++) {
        char temp = *p;
        *p = *(p + 1);
        *(p + 1) = temp;
        p++;
    }
    return 0;
}


#endif