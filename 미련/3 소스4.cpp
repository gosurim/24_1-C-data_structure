#if 0 //14 #1 �迭, �Լ�

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

    printf("���� %d ���� ������ �Է��Ͻÿ�(���� ����). : ", MEMBER);
    for (int i = 0; i < MEMBER; i++) {
        scanf("%d", &basic[i]);
    }
    printf("���� %d���� ���ʽ��� �Է��Ͻÿ�(���� ����). : ", MEMBER);
    for (int i = 0; i < MEMBER; i++)
    {
        scanf("%d", &plus[i]);
    }

    memberSum(basic, plus, sumTotal, MEMBER);
    printf("�� �������� ���޹��� �Ѿ�\n");

    for (int i = 0; i < MEMBER; i++)
    {
        printf("����%d : %d\n", i + 1, sumTotal[i]);
    }
}
void memberSum(int Basic[], int Plus[], int Total[], int member) {
    for (int i = 0; i < MEMBER; i++)
    {
        Total[i] = Basic[i] + Plus[i];
    }
}
#elif 0 //14 #2 2���� �迭 arr[4][5]
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

    printf("�迭�� ���ҿ� ������ �� : ");
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

    printf("NxN ��� ���� Program�Դϴ�.. N: ");
    scanf("%d", &n);


    printf("������ ù��° �迭�� ���ڸ� �Է��Ͻÿ�. \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d x %d ���� �Է� : ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("������ �ι�° �迭�� ���ڸ� �Է��Ͻÿ�. \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d x %d ���� �Է� : ", i, j);
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
#elif 0 //15 #1 ������
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

    printf("%d�� ������ ���� %d\n", num, squardFunc(&num));
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
    printf("���� 3���� �Է��Ͻÿ�. : ");
    scanf("%d %d %d", &a, &b, &c);

    printf("�ٲٱ� �� : %d %d %d\n", a, b, c);
    changer(&a, &b, &c);
    printf("�ٲ� �� : %d %d %d\n", a, b, c);

    sumx(a, b, c, &sum, &x);
    printf("�� ������ �� : %d\n", sum);

    printf("�� ������ �� : %d\n", x);
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

    printf("���� 10���� ������ �Է��Ͻÿ�(���� �� ��): ");
    for (int i = 0; i < MEMBER; i++) {
        scanf("%d", &basic[i]);
    }
    printf("���� 10���� ���ʽ��� �Է��Ͻÿ�(���� �� ��): ");
    for (int i = 0; i < MEMBER; i++) {
        scanf("%d", &plus[i]);
    }
    dnjfrmq(basic, plus, total, MEMBER);
    printf("�� �������� ���޹��� ���� �Ѿ�\n");

    for (int i = 0; i < MEMBER; i++) {
        printf("���� %d : %\n", i + 1, total[i]);
    }
}
void dnjfrmq(int* basic, int* plus, int* total, int member) {
    for (int i = 0; i < member; i++) {
        total[i] = basic[i] + plus[i];
    }
}
#elif 0 //15 #4 ���Է� �ð�
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

    printf("��ȯ�Ϸ��� �ʸ� �Է����ּ��� : ");
    scanf("%d", &sec);
    change_time(sec, &h, &m, &s);

    printf("%d�ʴ� %d�ð� %d�� %d�� �Դϴ�.", sec, h, m, s);
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

    printf("�迭 �ȿ� �� ���� 5���� �Է��Ͻÿ�\n");
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

    printf("�ִ�: %d, ���� : %d", max, num);
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