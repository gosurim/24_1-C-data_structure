#if 0
#include <stdio.h>

typedef struct studentTag {
	char name[10];
	int age;
	double gpa;
} student;

int main(void) {
	student a = { "kim", 20, 4.3 };
	student b = { "park", 21, 4.2 };
	return 0;
}

#elif 0
#define MAX_DEGREE 101
typedef struct {
	int degree;		//차수-변수
	float coef[MAX_DEGREE];	//계수
} polynomial;

polynomial a = { 5, {10,0,0,0,6,3} };

#elif 0
#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

polynomial poly_add1(polynomial A, polynomial B) {
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0; //배열 인덱스 변수?
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); //차수

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p) {
	for (int i = p.degree; i > 0; i--) {
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	}printf("%3.1f \n", p.coef[p.degree]);
}

int main(void) {
	polynomial a = { 5, {3,6,0,0,0,10} };
	polynomial b = { 4,{7,0,5,0,1} };
	polynomial c;

	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b);
	printf("--------------");
	print_poly(c);
	return 0;
}
#elif 1
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
typedef struct {
	float coef;
	int expon;
} polynomial;
polynomial terms[MAX_TERMS] = { {8,3},{7,1},{1,0}, {10,3},{3,2},{1,0} };
int avail = 6;

char compare(int a, int b) {
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

void attach(float coef, int expon) {
	if (avail > MAX_TERMS) {
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}


#elif 1
#elif 1
#elif 1
#elif 1
#endif
