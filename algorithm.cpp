#define num 4

#if num==1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 100
int scores[MAX_ELEMENTS];

int get_max_score(int n) {//입출력, 명백성, 유한성,유효성 
	int i, largest;
	largest = scores[0];
	for (i = 1; i < n; i++) {
		if (scores[i] > largest) {
			largest = scores[i]; //최고 점수 저장
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
	printf("수행시간은 %f초 입니다.\n", duration);
	return 0;
}
#elif num==3
#define CRT_WECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int factorial(int n) {
	if (n <= 1) {	//재귀
		return 1;
	}
	else return n* factorial(n - 1); //n번 함수 호출
	/*복귀주소가 시스템 스택에 저장되고, 호출되는 함수를 위한 
	매개변수와 지역변수를 스택에서 할당받으므로
	사전 작업과 여분의 메모리가 필요. 즉 더 느림.*/

	int k, v = 1;	//n번 반복
	for (k = n; k > 0; k--) {
		v = v * k;
		return(v);
	}
}
int main(void) {
	printf("%d", factorial(5));
}

//거듭제곱-재귀가 더 빠름
double slow_power(double x, int n) {	//반복
	int i;
	double result = 1.0;
	for (i = 0; i < n; i++) result *= x; //x 계속 곱
	return result;
}
double power(double x, int n) {
	if (n == 0) return 1;
	else if ((n % 2) == 0) return power(x * x, n / 2); //짝수
	else return x * power(x * x, (n - 1) / 2);
}

//피보나치 수열-반복이 더 빠름
int fib(int n) { //재귀
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 1) + fib(n - 2));
}
int fib_iter(int n) { //반복
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
//하노이 탑-재귀가 더 빠름
#include <stdio.h>
void hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1) printf("원판 1을 %c에서 %c로 옮긴다. \n", from, to);
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("원판 %d을 %c에서 %c로 옮긴다.\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}
int main() {
	hanoi_tower(4, 'A', 'B', 'C');
	return 0;
}
#endif