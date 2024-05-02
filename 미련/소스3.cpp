#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int sum(int x, int y);
int main(void) {
	int x, y;

	printf("x,y: ");
	scanf("%d %d", &x, &y);
	printf("x,y: %d", sum(x, y));

}
int sum(int x, int y) {
	return x + y;
}
#elif 0
void total(int* basic, int* plus, int* total) {
	for (int i = 0; i < 10; i++)
	{
		total[i] = basic[i] + plus[i];
	}
}

int main(void) {
	int basic[10];
	int plus[10];
	int total[10];

	printf("기본급: ");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &basic[i]);
	}
	printf("보너스:  ");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &plus[i]);
	}
	total(basic, plus, total);

}
#elif 0
void dnjfrmq(int* basic, int* plus, int* total) {
	for (int i = 0; i < 10; i++)
	{
		total[i] = basic[i] + plus[i];
	}
}
int main(void) {
	int basic[10];
	int plus[10];
	int total[10];


	printf("기본급: ");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &basic[i]);
	}
	printf("보너스:  ");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &plus[i]);
	}
	dnjfrmq(basic, plus, total);
	for (int i = 0; i < 10; i++)
	{
		printf("%d : %d", i + 1, total[i]);
	}
}
#elif 0
void cha(int sec, int* s, int* m, int* h) {
	*h = sec / 3600;
	*m = (sec - (*h * 3600)) / 60;
	*s = sec - (*h * 3600) - (*m * 60);
}

int main(void) {
	unsigned int sec;
	int s = 0, m = 0, h = 0;

	printf("시간: ");
	scanf("%d", &sec);
	cha(sec, &s, &m, &h);
	printf("%d시간 %d분, %d초", s, m, h);
}
#elif 0
void cha(int* p) {
	for (int i = 0; i < 5; i++)
	{
		printf(" %d", *(p + 5 - 1 - i));
	}
}
int main(void) {
	int num[5];
	printf("n: ");
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &num[i]);
	}
	int* p;
	p = num;
	cha(p);
}
#elif 0

int main(void) {
	unsigned int num[9];
	int max = 0;
	int n = 0;
	printf("n: ");
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &num[i]);
	}
	unsigned int* p;
	p = num;

	for (int i = 0; i < 9; i++)
	{
		if (max < *(p + i))
		{
			max = *(p + i);
			n = i + 1;
		}
	}

	printf("최댓값: %d, %d번 쨰", max, n);
}
#elif 0
void cha(char* p, int slen) {
	for (int i = 0; i < slen - 1; i++) {
		int temp = *p;
		*p = *(p + 1);
		*(p + 1) = temp;
		p++;
	}
}
int main(void) {
	char s[20];
	int n;
	int slen = strlen(s);
	printf("s, n : ");
	scanf("%s", s);
	scanf("%d", &n);
	slen = strlen(s);


	for (int i = 0; i < n; i++)
	{
		cha(s, slen);

	}
	printf("값: %s", s);

}
#elif 0
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
#elif 0
int main(void) {
	int n;
	int m1[20][20];
	int m2[20][20];
	int mul = 0;
	printf("n: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &m1[i][j]);
		}
	}for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &m2[i][j]);
		}
	}for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mul = 0;
			for (int k = 0; k < n; k++)
			{
				mul += m1[i][k] * m2[k][j];
			}
			printf("n: ");
		}
	}
}
#elif 0
void fill_2d_array(int num, int arr[4][5]) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = num;
		}

	}
}

int main(void) {
	int arr[4][5];
	int num;

	printf("n: ");
	scanf("%d", &num);

	fill_2d_array(num, arr);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void) {
	int a, b, c = 1;

	printf("a, b:");
	scanf("%d %d", &a, &b);

	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < a; j++)
		{
			printf("%4d", c);
			c++;
		}
		printf("\n");
	}
}

#elif 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(void) {
	int r = 10;
	for (int i = -2 * r; i < 2 * r; i += 2)
	{
		for (int j = -r; j < r; j++)
		{
			if (i * i + j * j <= r * r)
			{
				printf("*");
			}
			else { printf(" "); }
		}
		printf("\n");
	}
}
#elif 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
void cha(int a, int b) {
	int s, e;
	if
}
int main(void) {
	int a, b;

}
#elif 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
int judge(int u, int c) {
	if (u == c)
	{
		return 0;
	}
	else if ((u == 1 && c == 2) || (u == 2 && c == 3) || (u == 3 && c == 1))
	{
		return 1;
	}
	else { return 2; }
}
int main(void) {
	int u, c;
	printf(" 가위 바위 보 게임 입니다.\n");
	printf("(1. 가위 _ 2. 바위 _ 3. 보 _ 0. 종료)\n\n");
	scanf("%d", &u);
	c = rand() % 3 + 1;
	printf("%d", &c);
	int r = judge(u, c);
	if (r == 0)
	{
		printf("비겼슴");
	}
	else if (r == 1)
	{
		printf("wuT슴");
	}


}
#elif 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(void) {

}
#endif