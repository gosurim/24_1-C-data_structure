/*
#if 0 //참(1): 실행		거짓(0): 실행하지 않음
#elif 0 //가장 먼저 참인것 실행
#else //거짓일 때 실행
#endif
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define NUM 0

#if NUM==1 //11주차-1 행과열
int main(void) {
	int x, y,r=1;

	printf("행과 열을 입력하시오 : ");
	scanf("%d %d", &x, &y);
	
	for (int i = 1; i <= y; i++) {
		
		for (int i = 1; i <= x; i++) {
			printf("%4d", r);
			r++;
		}//f2
		printf("\n");
	}//f1
}
#elif NUM==2 //11주차-1t
int main(void) {
	int a, b, count = 1;

	printf("행과 열을 입력 : ");
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
#elif NUM==3 //11 #2 원, 타원
int main(void) {
	int r = 10;
	
	for (int i = -r; i < r; i++) {		//열
		for (int j = -r; j < r; j++) {	//행
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
			if (i*i+j*j<=r*r)
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
#elif NUM==5 //12 #1 ㅜㅡㅜ 함수를 만들지 않았다!!
int main(void) {
	int a, b,temp;
	int sum = 0;
	printf("a,b를 입력 : ");
	scanf("%d %d", &a, &b);
	if (b<a)
	{
		temp = b;
		b = a;
		a = temp;
	}
	for (int i = a; i <= b; i++) {
		sum += i;
	}
	printf("a~b 다 더한 값 : %d", sum);
}
#elif NUM==6 //12 #1
int sumbetweennumber(int a, int b) {
	int start, end, sum=0;
	if (a<b){
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

	printf("a,b를 입력 : ");
	scanf("%d %d", &a, &b);
	printf("%d", sumbetweennumber(a,b));
}
#endif

/*
#if 0 //참(1): 실행		거짓(0): 실행하지 않음
#elif 0 //가장 먼저 참인것 실행
#else //거짓일 때 실행
#endif
*/
#if 0 //12 #2 //(꺄악 너무 어려워!!) 시험 안나올듯!
int sumOddEven(int n, int flag) {  //재귀함수를 사용하지 않았슴다
	int sum = 0;
	if (flag == 1) {
		for (int i = flag; i <= n; i += 2) {//홀수
			sum += i;
		}//for 홀수
	}//if

	return sum;
}
int sumOddEvenTT(int n, int flag) { //T
	if (n <= 0) {
		return 0;
	}//if
	if ((n % 2 == 0) == flag) {  //참 1 거짓 0
		return sumOddEvenTT(n - 1, flag);
	}//if
	return n + sumOddEvenTT(n - 1, flag);
}
int main(void) {
	int n;
	printf("n을 입력하시오: ");
	scanf("%d", &n);

	if (n%2==0)
	{
		printf("짝수 합 : %d", sumOddEvenTT(n, 0));
	}//if
	else
	{
		printf("홀수 합 : %d", sumOddEvenTT(n, 1));
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
	
	printf(" 가위 바위 보 게임 입니다.\n");
	printf("(1. 가위 _ 2. 바위 _ 3. 보 _ 0. 종료)\n\n");
	while (1)
	{
		printf("입력해주세요 : ");
		scanf("%d", &userChoice);

		if (userChoice==0){
			printf("게임을 종료합니다. \n");
			break;
		}//if
		if (userChoice<1 || userChoice>3)
		{
			printf("잘못된 입력입니다. 다시입력해주세요 \n");
			continue;
		}//error
		//숫자 3개 뽑는 방법(시험!!)
		computerChoice = rand() % 3 + 1;
		printf("컴퓨터 : %d\n 사용자 : %d\n\n", computerChoice, userChoice);

		int result = judge(userChoice, computerChoice);
		if (result==0)
		{
			printf("비겼습니다.\n");
		}
		else if (result == 1)
		{
			printf("이겼습니다.\n");
		}
		else
		{
			printf("졌습니다.\n");
		}
	}

}//main

#elif 0 //13 #1 배열!
int main(void) {
	int num[5];
	int n;

	printf("5개의 학번을 입력해주세요\n");
	for (int i = 0; i < 5; i++) {
		scanf("%d", &num[i]);
	}
	printf("학번 입력하시면, 어디에 위치하는지 출력합니다.\n");
	scanf("%d", &n);

	for (int i = 0; i < 5; i++) {
		if (num[i]==n)
		{
			printf("%d번 째에 저장되어 있습니다.\n", i + 1);
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
	printf("학생 5명의 성적을 차례로 입력하세요.\n");

	for (int i = 0; i < 5; i++) {
		scanf("%d", &score[i]);
	}
	maxFunc();
	meanFunc();
	printf("학생 5명의 평균 점수는 : %.2f, 최고점수는 %d 입니다.\n", mean, max);
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
#elif 0 //13 #3 비밀번호 생성기
int main(void) {
	char passwd[20];
	int flag1 = 0, flag2 = 0, flag3 = 0;
	int passLen = strlen(passwd);

	while ((flag1 + flag2 + flag3 != 3) || passLen < 10) {
		printf("비밀번호를 입력하시오 : \n");
		scanf("%s", passwd);
		passLen = strlen(passwd);
		for (int i = 0; i < passLen; i++) {

			if (passwd[i] > 0x30 && passwd[i] <= 0x39) { //숫자
				flag1 = 1;
			}
			if (passwd[i] > 0x61 && passwd[i] <= 0x7A) { //소문자
				flag2 = 1;
			}
			if (passwd[i] > 0x41 && passwd[i] <= 0x5A) { //대문자
				flag3 = 1;
			}
		}
	}
	printf("정해진 비밀번호 규칙을 만족하였습니다.");
}
#elif 0 //13 #4 회문
int main(void) {
	char text[20];
	int count = 0; //반복의 조건이 부합하지 않으면 count x
	int textLen = strlen(text);

	while (count != textLen) {
		printf("text를 입력하시오 : \n");
		scanf("%s", text);
		textLen = strlen(text);
		count = 0;

		for (int i = 0; i < textLen; i++)
		{
			if (text[i] != text[textLen - 1 - i]) {
				printf("회문이 아닙니다. \n");
				break;
			}//if
			else
			{
				count++;
			}
		}//for
	}
	printf("회문입니다. \n");
}
#elif 1 //14 #1

#else
#endif