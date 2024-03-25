#define num 4

#if num==1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 100
int scores[MAX_ELEMENTS];

int get_max_score(int n) {//�����, ��鼺, ���Ѽ�,��ȿ�� 
	int i, largest;
	largest = scores[0];
	for (i = 1; i < n; i++) {
		if (scores[i] > largest) {
			largest = scores[i]; //�ְ� ���� ����
		}
	}return largest;
}

#elif num==2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
	clock_t start, stop;
	double duration;
	start = clock();
	for (int i = 0; i < 1000000; i++);

	stop = clock();
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("����ð��� %f�� �Դϴ�.\n", duration);
	return 0;
}
#elif num==3
#define CRT_WECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int factorial(int n) {
	if (n <= 1) {	//���
		return 1;
	}
	else return n* factorial(n - 1); //n�� �Լ� ȣ��
	/*�����ּҰ� �ý��� ���ÿ� ����ǰ�, ȣ��Ǵ� �Լ��� ���� 
	�Ű������� ���������� ���ÿ��� �Ҵ�����Ƿ�
	���� �۾��� ������ �޸𸮰� �ʿ�. �� �� ����.*/

	int k, v = 1;	//n�� �ݺ�
	for (k = n; k > 0; k--) {
		v = v * k;
		return(v);
	}
}
int main(void) {
	printf("%d", factorial(5));
}

//�ŵ�����-��Ͱ� �� ����
double slow_power(double x, int n) {	//�ݺ�
	int i;
	double result = 1.0;
	for (i = 0; i < n; i++) result *= x; //x ��� ��
	return result;
}
double power(double x, int n) {
	if (n == 0) return 1;
	else if ((n % 2) == 0) return power(x * x, n / 2); //¦��
	else return x * power(x * x, (n - 1) / 2);
}

//�Ǻ���ġ ����-�ݺ��� �� ����
int fib(int n) { //���
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 1) + fib(n - 2));
}
int fib_iter(int n) { //�ݺ�
	if (n == 0) return 0;
	if (n == 1) return 1;

	int pp = 0;
	int p = 1;
	int result = 0;

	for (int i = 2; i <= n; i++) {
		result = p + pp;
		pp = p;
		p = result;
	}
	return result;
}
#elif num==4
//�ϳ��� ž-��Ͱ� �� ����
#include <stdio.h>
void hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1) printf("���� 1�� %c���� %c�� �ű��. \n", from, to);
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("���� %d�� %c���� %c�� �ű��.\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}
int main() {
	hanoi_tower(4, 'A', 'B', 'C');
	return 0;
}
#endif