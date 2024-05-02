#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
int main(void) {
	int arr1[20];
	int arr2[20];
	int a, b;
	int c;
	printf("배열 크기 입력: ");
	scanf("%d", &a);
	printf("배열 크기 입력: ");
	scanf("%d", &b);
	printf("배열 입력: ");
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &arr1[i]);
	}
	printf("배열 입력: ");
	for (int i = 0; i < b; i++)
	{
		scanf("%d", &arr2[i]);
	}
	if (a<b)
	{
		c = b;
	}
	else if (b<a)
	{
		c = a;
	}
	for (int i = 0; i < c; i++)
	{
		if (arr1[i]==arr2[i])
		{
			printf("%d, ", arr1[i]);
		}
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
	int n[20];
	int s;
	int max=0;
	int c;
	//s 배열
	printf("크기 입력: ");
	scanf("%d", &s);
	printf("입력: ");
	for (int i = 0; i < s; i++)
	{
		scanf("%d", &n[i]);
	}
	for (int i = 0; i < s; i++)
	{
		if (max<n[i])
		{
			max = n[i];
			c = i;
		}
	}printf("%d번째, %d", c + 1, max);
}
#elif 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
void cha(int* p) {
	for (int i = 0; i < 5; i++)
	{
		printf("%d  ", *(p + 5 - 1 - i));
	}
}
int main(void) {
	int n[5];
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &n[i]);
	}
	int* p = n;

	cha(n);
}
#elif 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
int main(void) {
	int n;
	int a1[20][20];
	int a2[20][20];
	int m = 0;
	printf("n: ");
	scanf("%d", &n);
	printf("1: ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			scanf("%d", &a1[i][j]);
		}
	}
	printf("2: ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			scanf("%d", &a2[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			m = 0;
			for (int k = 0; k < n; k++)
			{
				m += (a1[i][k] * a2[k][j]);

			}printf("  %d", m);

		}printf("\n");
	}
}
#elif 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
int x(int* p) {
	return *p * *p;
}
int main(void) {
	int n;
	printf("n: ");
	scanf("%d", &n);
	printf("%d", x(&n));
}
#endif

