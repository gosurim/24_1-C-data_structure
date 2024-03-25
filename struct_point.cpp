#define num 2
#if num==1
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

#elif num==2
#define MAX_DEGREE 101
typedef struct {
	int degree;		//차수-변수
	float coef[MAX_DEGREE];	//계수
} polynomial;

polynomial a = { 5, {10,0,0,0,6,3} };

#elif num==3
#endif
