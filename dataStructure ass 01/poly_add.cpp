#if 1
//1. 하나의 다항식을 하나의 배열로 표현하는 방법
#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

polynomial poly_sub1(polynomial A, polynomial B){
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);
	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			C.coef[Cpos++] = A.coef[Apos++] - B.coef[Bpos++];
			degree_a--;
			degree_b--;
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
		if (p.coef[p.degree - i] < 0) {
			printf("(%3.1f)x^%d + ", p.coef[p.degree - i], i);
		}else printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	}
	printf("%3.1f \n", p.coef[p.degree]);
}

int main(void) {
	polynomial a = { 5,{3,6,0,0,0,10} };
	polynomial b = { 4,{7,0,5,0,1} };
	polynomial c;
	print_poly(a);
	print_poly(b);
	c = poly_sub1(a, b);
	printf("-------------------\n");
	print_poly(c);
	return 0;
}
#elif 1
//2. 계수, 차수 형식으로 배열에 저장
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
typedef struct {
	float coef;
	int expon;
}polynomial;
polynomial terms[MAX_TERMS] = { {8,3}, {7,1} ,{1,0},{10,3},{3,2},{1,0} };
int avail = 6;

char compare(int a, int b) {
	if (a > b)return '>';
	else if (a == b)return '=';
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

void poly_sub2(int Astart, int Aend, int Bstart, int Bend, int* Cstart, int* Cend) {
	float tempcoef;
	*Cstart = avail;
	while (Astart <= Aend && Bstart <= Bend) {
		switch (compare(terms[Astart].expon, terms[Bstart].expon)) {
		case '>':
			attach(terms[Astart].coef, terms[Astart].expon);
			Astart++;
			break;
		case '=':
			tempcoef = terms[Astart].coef - terms[Bstart].coef;
			if (tempcoef) attach(tempcoef, terms[Astart].expon);
			Astart++;
			Bstart++;
			break;
		case '<':
			attach(terms[Bstart].coef, terms[Bstart].expon);
			Bstart++;
			break;
		}
	}
	for (; Astart <= Aend; Astart++) {
		attach(terms[Astart].coef, terms[Astart].expon);
	}
	for (; Bstart <= Bend; Bstart++) {
		attach(terms[Bstart].coef, terms[Bstart].expon);
	}
	*Cend = avail - 1;
}
void print_poly(int start, int end) {
	for (int i = start; i < end; i++) {
		if(terms[i].coef<0) printf("(%3.1f)x^%d + ", terms[i].coef, terms[i].expon);
		else printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	}printf("%3.1fx^%d\n", terms[end].coef, terms[end].expon);
}
int main(void) {
	int Astart = 0, Aend = 2, Bstart = 3, Bend = 5, Cstart, Cend;
	poly_sub2(Astart, Aend, Bstart, Bend, &Cstart, &Cend);
	print_poly(Astart, Aend);
	print_poly(Bstart, Bend);
	printf("--------------------\n");
	print_poly(Cstart, Cend);
	return 0;
}

#elif 1
#include <stdio.h>
#include <stdlib.h>
int main() {
	double* p1;
	p1 = (double*)malloc(sizeof(double));
	*p1 = 23.92;
	return 0;
}
#endif