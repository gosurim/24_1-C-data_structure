#if 0	
#elif 1

ArrayListType list;
init(&list);
insert_first(&list, 10);
//print_list(&list); // 0번째 위치에 10 추가
insert_first(&list, 20);
//print_list(&list); // 0번째 위치에 20 추가
insert_first(&list, 30);
//print_list(&list); // 0번째 위치에 30 추가
insert_last(&list, 40);
//print_list(&list); // 맨 끝에 40 추가
remove(&list, 0);
//print_list(&list); // 0번째 항목 삭제
#elif 1
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101
typedef struct {
	float coef; //계수
	int degree;
}polynomial;

polynomial terms[MAX_TERMS] = { {8,3},{7,1},{1,0}, {10,3},{3,2},{1,0} };
int avail = 6;

char compare(int a, int b) {

}

void attach(float coef, int degree) {
	if (avail > MAX_TERMS) {
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].degree= degree
}

#elif 1
//1. 계수값을 배열로 저장, 다항식 하나 당 한 개의 배열
#define MAX(a,b) (a>b?a:b)
#define MAX_DEGREE
typedef struct {
	int degree;//차수 
	// polynomial a = { 5, {3,6,0,0,0,10} };
	// polynomial b = { 4,{7,0,5,0,1} }; 요렇게 선언할 거임
	float coef[MAX_DEGREE]; //계수 ??여기 잘 모르겠음 더 해보자!
} polynomial;

polynomial poly_add1(polynomial A, polynomial B) { //읭 어떻게 자료형??어떡하려고?
	polynomial C;//결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0; //배열 인덱스 변수 현재 계수 위치
	int degree_a = A.degree; //차수는 하나.
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) { //차수가 a가 더 크면 c(L부터 계산)에 넣음
			C.coef[Cpos++] = A.coef[Apos++]; //계산하고 계수 인덱스 올려!!
			degree_a--; //차수는 하나씩 줄여가면서 계산해야하니까!
		}// 또 차수를 비교해야 해서 if문 비교하는데에 쓰임
		else if (degree_a == degree_b) { //똑같으면 계수 더하기
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--; //하고 둘다 차수 내려주기--
		}
		else { //b만 있을 때..
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}return C;
}

void print_poly(polynomial p) {
	for (int i = p.degree; i > 0; i--) {
		printf("%3.1fx^%d +", p.coef[p.degree - i], i);
	}printf("%e.1f \n", p.coef[p.degree]);
}




#elif 1
typedef struct stdentTag{
	char name[10];
	int age;
	double gpa;
} student;



#elif 1
#include <stdlib.h>
#include <stdio.h>

int factorial(int n) { //재귀
	printf("Recursion\n");
	printf("%d\n", n);
	if (n <= 1) return 1;
	else {
		return (n * factorial(n-1)); //함수호출 n번
		//재귀는 복귀주소가 스택에 저장 되고
		// 호출되는 함수를 위한 매개변수와 지역변수를 스택에서 할당받음으로
		// 사전작업과
		//int return_value = factorial(n - 1);
		//printf("return_value : %d\n", return_value);
		//return (n * return_value);
	}
}

int factorial_iter(int n) {
	printf("Iteration\n");
	int k, v = 1;
	for (k = n; k > 0; k--) { //i=n n번 반복
		v = v * k;
	}
	return v;
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
//하노이 탑-재귀가 더 빠름
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
#elif 1
#define MAX_ELEMENTS 100
int scores[MAX_ELEMENTS];             // 자료구조 
int get_max_score(int n)      // 학생의 숫자는 n 
{
	int i, largest;
	largest = scores[0]; //첫번째 값 저장
	for (i = 1; i < n; i++) {
		if (scores[i] > largest) { //하나씩 돌리면서 큰 값 저장
			largest = scores[i];
		}
	}
	return largest;
}


#elif 1
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

#endif