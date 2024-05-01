#if 0
//단어를 저장할 수 있는 링크드리스트 만들기
#define _CRT_SECURE_NO_WARNINGS //? 왠지는 모르겠으나? strcpy에 필요한 듯 함?
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[100];
}element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	/*
	if (p == NULL) { // 메모리 할당 검사
		fprintf(stderr, "메모리 할당 오류\n");
		return head;
	}*/
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%s->", p->data.name);
	}printf("NULL \n");
}

int main(void) {

	ListNode* head = NULL;
	element data;
	 
	strcpy(data.name, "APPLE");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "KIWI");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "BANANA");
	head = insert_first(head, data);
	print_list(head);
	/*
	ListNode* temp;
	while (head != NULL) {
		temp = head;
		head = head->link;
		free(temp);
}*/

	return 0;
}
#elif 0
//특정 값을 탐색하는 함수 추가
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}printf("NULL \n");
}

ListNode* search(ListNode* head, element x) {
	ListNode* p = head;
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (p->data == x) {
			printf("리스트에서 %d를 찾았다!", x);
			return p;
		}
	}return NULL;
}

int main(void) {
	ListNode* head = NULL;
	for (int i = 10; i <= 30; i += 10) {
		head = insert_first(head, i);
		print_list(head);
	}search(head, 30);
	return 0;
}
#elif 0
//2개 리스트 합하는 함수 추가
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* concat_list(ListNode* head1, ListNode* head2) {
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return NULL;
	else {
		ListNode* p;
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}printf("NULL \n");
}

int main(void) {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	ListNode* head3 = NULL;
	for (int i = 3; i >= 1; i-- ) {
		head1 = insert_first(head1, i*10);	
	}
	print_list(head1);
	for (int i = 6; i >= 4; i--) {
		head2 = insert_first(head2, i * 10);
	}
	print_list(head2);
	head3 = concat_list(head1, head2);
	print_list(head3);
	return 0;
}
#elif 0
//역순의 리스트를 리턴하는 함수
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}printf("NULL \n");
}

ListNode* reverse(ListNode* head) {
	ListNode* p, * q, * r;

	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}return q;
}

int main(void) {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	for (int i = 4; i >= 1; i--) {
		head1 = insert_first(head1, i * 10);
	}print_list(head1);
	head2 = reverse(head1);
	print_list(head2);
	return 0;
}
#elif 1
//stack 블록탑
#define _CRT_SECURE_NO_WARNINGS //가장 위에 위치하도록.. 주의..하자..
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10 

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return(s->top == -1);
}

int is_full(StackType* s) {
	return(s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 overflow\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 underflow\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int main() {
	int infinity = 987654321;
	int problem_num = 0;
	scanf("%d", &problem_num);
	for (int problem = 0; problem < problem_num; problem++) {
		int query_num = 0;
		scanf("%d", &query_num);

		StackType min_stack;
		StackType max_stack;
		init_stack(&min_stack);
		init_stack(&max_stack);
		push(&min_stack, infinity);
		push(&max_stack, -infinity);

		for (int query = 0; query < query_num; query++) {
			int input1, input2, new_block = 0;
			scanf("%d", &input1);
			switch (input1) {
			case 1:
				scanf("%d", &input2);
				new_block = input2;
				if (min_stack.data[min_stack.top] > new_block)
					push(&min_stack, new_block);
				else
					push(&min_stack, min_stack.data[min_stack.top]);
				if (min_stack.data[max_stack.top] < new_block)
					push(&max_stack, new_block);
				else
					push(&max_stack, max_stack.data[max_stack.top]);
				printf("%d %d\n", min_stack.data[min_stack.top], max_stack.data[max_stack.top]);
				break;
			case 2:
				if (min_stack.top != infinity)
					pop(&min_stack);
				if (max_stack.top != -infinity)
					pop(&max_stack);
				break;
			}
		}
	}return 0;
}

#endif