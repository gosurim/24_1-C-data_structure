#if 0	
#elif 1

ArrayListType list;
init(&list);
insert_first(&list, 10);
//print_list(&list); // 0��° ��ġ�� 10 �߰�
insert_first(&list, 20);
//print_list(&list); // 0��° ��ġ�� 20 �߰�
insert_first(&list, 30);
//print_list(&list); // 0��° ��ġ�� 30 �߰�
insert_last(&list, 40);
//print_list(&list); // �� ���� 40 �߰�
remove(&list, 0);
//print_list(&list); // 0��° �׸� ����
#elif 1
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101
typedef struct {
	float coef; //���
	int degree;
}polynomial;

polynomial terms[MAX_TERMS] = { {8,3},{7,1},{1,0}, {10,3},{3,2},{1,0} };
int avail = 6;

char compare(int a, int b) {

}

void attach(float coef, int degree) {
	if (avail > MAX_TERMS) {
		fprintf(stderr, "���� ������ �ʹ� ����\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].degree= degree
}

#elif 1
//1. ������� �迭�� ����, ���׽� �ϳ� �� �� ���� �迭
#define MAX(a,b) (a>b?a:b)
#define MAX_DEGREE
typedef struct {
	int degree;//���� 
	// polynomial a = { 5, {3,6,0,0,0,10} };
	// polynomial b = { 4,{7,0,5,0,1} }; �䷸�� ������ ����
	float coef[MAX_DEGREE]; //��� ??���� �� �𸣰��� �� �غ���!
} polynomial;

polynomial poly_add1(polynomial A, polynomial B) { //�� ��� �ڷ���??��Ϸ���?
	polynomial C;//��� ���׽�
	int Apos = 0, Bpos = 0, Cpos = 0; //�迭 �ε��� ���� ���� ��� ��ġ
	int degree_a = A.degree; //������ �ϳ�.
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) { //������ a�� �� ũ�� c(L���� ���)�� ����
			C.coef[Cpos++] = A.coef[Apos++]; //����ϰ� ��� �ε��� �÷�!!
			degree_a--; //������ �ϳ��� �ٿ����鼭 ����ؾ��ϴϱ�!
		}// �� ������ ���ؾ� �ؼ� if�� ���ϴµ��� ����
		else if (degree_a == degree_b) { //�Ȱ����� ��� ���ϱ�
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--; //�ϰ� �Ѵ� ���� �����ֱ�--
		}
		else { //b�� ���� ��..
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

int factorial(int n) { //���
	printf("Recursion\n");
	printf("%d\n", n);
	if (n <= 1) return 1;
	else {
		return (n * factorial(n-1)); //�Լ�ȣ�� n��
		//��ʹ� �����ּҰ� ���ÿ� ���� �ǰ�
		// ȣ��Ǵ� �Լ��� ���� �Ű������� ���������� ���ÿ��� �Ҵ��������
		// �����۾���
		//int return_value = factorial(n - 1);
		//printf("return_value : %d\n", return_value);
		//return (n * return_value);
	}
}

int factorial_iter(int n) {
	printf("Iteration\n");
	int k, v = 1;
	for (k = n; k > 0; k--) { //i=n n�� �ݺ�
		v = v * k;
	}
	return v;
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
//�ϳ��� ž-��Ͱ� �� ����
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
#elif 1
#define MAX_ELEMENTS 100
int scores[MAX_ELEMENTS];             // �ڷᱸ�� 
int get_max_score(int n)      // �л��� ���ڴ� n 
{
	int i, largest;
	largest = scores[0]; //ù��° �� ����
	for (i = 1; i < n; i++) {
		if (scores[i] > largest) { //�ϳ��� �����鼭 ū �� ����
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
	printf("����ð��� %f�� �Դϴ�.\n", duration);
	return 0;
}

#endif