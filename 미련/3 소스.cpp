/*
#if 0 //��(1): ����		����(0): �������� ����
#elif 0 //���� ���� ���ΰ� ����
#else //������ �� ����
#endif
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define NUM 0

#if NUM==1 //11����-1 �����
int main(void) {
	int x, y, r = 1;

	printf("��� ���� �Է��Ͻÿ� : ");
	scanf("%d %d", &x, &y);

	for (int i = 1; i <= y; i++) {

		for (int i = 1; i <= x; i++) {
			printf("%4d", r);
			r++;
		}//f2
		printf("\n");
	}//f1
}
#elif NUM==2 //11����-1t
int main(void) {
	int a, b, count = 1;

	printf("��� ���� �Է� : ");
	scanf("%d %d", &a, &b);

	for (int i = 1; i <= b; i++) {
		for (int i = 1; i <= a; i++) {
			if (count < 10) {
				printf("   %d", count);
			}//if
			else {
				printf("  %d", count);
			}
			count++;
		}//fo2
		printf("\n");
	}//for1
}
#elif NUM==3 //11 #2 ��, Ÿ��
int main(void) {
	int r = 10;

	for (int i = -r; i < r; i++) {		//��
		for (int j = -r; j < r; j++) {	//��
			if (i * i + j * j <= r * r) {
				printf("*");
			}
			else { printf(" "); }
		}//for2
		printf("\n");
	}//for1
}
#elif NUM==4 //11 #2-2
int main(void) {
	int r = 10;

	for (int i = -2 * r; i < 2 * r; i += 2) {
		for (int j = -r; j < r; j++) {
			if (i * i + j * j <= r * r)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}//for2
		printf("\n");
	}//for1
}
#elif NUM==5 //12 #1 �̤Ѥ� �Լ��� ������ �ʾҴ�!!
int main(void) {
	int a, b, temp;
	int sum = 0;
	printf("a,b�� �Է� : ");
	scanf("%d %d", &a, &b);
	if (b < a)
	{
		temp = b;
		b = a;
		a = temp;
	}
	for (int i = a; i <= b; i++) {
		sum += i;
	}
	printf("a~b �� ���� �� : %d", sum);
}
#elif NUM==6 //12 #1
int sumbetweennumber(int a, int b) {
	int start, end, sum = 0;
	if (a < b) {
		start = a;
		end = b;
	}
	if (b < a) {
		start = b;
		end = a;
	}
	for (int i = start; i <= end; i++) {
		sum += i;
	}
	return sum;
}

int main(void) {
	int a, b;

	printf("a,b�� �Է� : ");
	scanf("%d %d", &a, &b);
	printf("%d", sumbetweennumber(a, b));
}
#endif

/*
#if 0 //��(1): ����		����(0): �������� ����
#elif 0 //���� ���� ���ΰ� ����
#else //������ �� ����
#endif
*/
#if 0 //12 #2 //(���� �ʹ� �����!!) ���� �ȳ��õ�!
int sumOddEven(int n, int flag) {  //����Լ��� ������� �ʾҽ���
	int sum = 0;
	if (flag == 1) {
		for (int i = flag; i <= n; i += 2) {//Ȧ��
			sum += i;
		}//for Ȧ��
	}//if

	return sum;
}
int sumOddEvenTT(int n, int flag) { //T
	if (n <= 0) {
		return 0;
	}//if
	if ((n % 2 == 0) == flag) {  //�� 1 ���� 0
		return sumOddEvenTT(n - 1, flag);
	}//if
	return n + sumOddEvenTT(n - 1, flag);
}
int main(void) {
	int n;
	printf("n�� �Է��Ͻÿ�: ");
	scanf("%d", &n);

	if (n % 2 == 0)
	{
		printf("¦�� �� : %d", sumOddEvenTT(n, 0));
	}//if
	else
	{
		printf("Ȧ�� �� : %d", sumOddEvenTT(n, 1));
	}//if
}
#elif 0 //12 #3
int judge(int userChoice, int computerChoice) {
	if (userChoice == computerChoice) {
		return 0;
	}
	else if ((userChoice == 1 && computerChoice == 3)
		|| (userChoice == 2 && computerChoice == 1)
		|| (userChoice == 3 && computerChoice == 2)) {
		return 1;
	}
	else {
		return -1;
	}
}
int main(void) {
	int userChoice;
	int computerChoice;

	printf(" ���� ���� �� ���� �Դϴ�.\n");
	printf("(1. ���� _ 2. ���� _ 3. �� _ 0. ����)\n\n");
	while (1)
	{
		printf("�Է����ּ��� : ");
		scanf("%d", &userChoice);

		if (userChoice == 0) {
			printf("������ �����մϴ�. \n");
			break;
		}//if
		if (userChoice < 1 || userChoice>3)
		{
			printf("�߸��� �Է��Դϴ�. �ٽ��Է����ּ��� \n");
			continue;
		}//error
		//���� 3�� �̴� ���(����!!)
		computerChoice = rand() % 3 + 1;
		printf("��ǻ�� : %d\n ����� : %d\n\n", computerChoice, userChoice);

		int result = judge(userChoice, computerChoice);
		if (result == 0)
		{
			printf("�����ϴ�.\n");
		}
		else if (result == 1)
		{
			printf("�̰���ϴ�.\n");
		}
		else
		{
			printf("�����ϴ�.\n");
		}
	}

}//main

#elif 0 //13 #1 �迭!
int main(void) {
	int num[5];
	int n;

	printf("5���� �й��� �Է����ּ���\n");
	for (int i = 0; i < 5; i++) {
		scanf("%d", &num[i]);
	}
	printf("�й� �Է��Ͻø�, ��� ��ġ�ϴ��� ����մϴ�.\n");
	scanf("%d", &n);

	for (int i = 0; i < 5; i++) {
		if (num[i] == n)
		{
			printf("%d�� °�� ����Ǿ� �ֽ��ϴ�.\n", i + 1);
		}
	}
}
#elif 0 //13 #2
int maxFunc();
int meanFunc();

int sum = 0;
int score[5];
int max = 0;
double mean;

int main(void) {
	printf("�л� 5���� ������ ���ʷ� �Է��ϼ���.\n");

	for (int i = 0; i < 5; i++) {
		scanf("%d", &score[i]);
	}
	maxFunc();
	meanFunc();
	printf("�л� 5���� ��� ������ : %.2f, �ְ������� %d �Դϴ�.\n", mean, max);
}


int maxFunc() {
	for (int i = 0; i < 5; i++) {
		if (score[i] > max) {
			max = score[i];
		}
	}
	return max;
}

int meanFunc() {
	for (int i = 0; i < 5; i++) {
		sum += score[i];
	}
	mean = (double)sum / 5;
	return mean;
}
#elif 0 //13 #3 ��й�ȣ ������
int main(void) {
	char passwd[20];
	int flag1 = 0, flag2 = 0, flag3 = 0;
	int passLen = strlen(passwd);

	while ((flag1 + flag2 + flag3 != 3) || passLen < 10) {
		printf("��й�ȣ�� �Է��Ͻÿ� : \n");
		scanf("%s", passwd);
		passLen = strlen(passwd);
		for (int i = 0; i < passLen; i++) {

			if (passwd[i] > 0x30 && passwd[i] <= 0x39) { //����
				flag1 = 1;
			}
			if (passwd[i] > 0x61 && passwd[i] <= 0x7A) { //�ҹ���
				flag2 = 1;
			}
			if (passwd[i] > 0x41 && passwd[i] <= 0x5A) { //�빮��
				flag3 = 1;
			}
		}
	}
	printf("������ ��й�ȣ ��Ģ�� �����Ͽ����ϴ�.");
}
#elif 0 //13 #4 ȸ��
int main(void) {
	char text[20];
	int count = 0; //�ݺ��� ������ �������� ������ count x
	int textLen = strlen(text);

	while (count != textLen) {
		printf("text�� �Է��Ͻÿ� : \n");
		scanf("%s", text);
		textLen = strlen(text);
		count = 0;

		for (int i = 0; i < textLen; i++)
		{
			if (text[i] != text[textLen - 1 - i]) {
				printf("ȸ���� �ƴմϴ�. \n");
				break;
			}//if
			else
			{
				count++;
			}
		}//for
	}
	printf("ȸ���Դϴ�. \n");
}
#elif 1 //14 #1

#else
#endif

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
#elif 1 //15 #1 ������
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