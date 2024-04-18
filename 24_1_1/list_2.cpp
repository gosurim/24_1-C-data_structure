#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char element[100]; //char[100]�� element�� typedef
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;
//�׸����
void print_list(ListNode* head) {
	ListNode* p;
	if (head == NULL) {
		printf("empty\n");
		return;
	}
	p = head->link;
	do {
		printf("%s->", p->data);
		//printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
	printf("\n");
}
//�� �� ����
ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	//node->data = data;
	strcpy(node->data, data);
	//������ �� ���ڸ� �����Ͽ� string2�� string1���� ������ ��ġ�� ����
	if (head == NULL) {
		head = node;
		node -> link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}
//�� �� ����
ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	strcpy(node->data, data);
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}
ListNode* remove_first(ListNode* head) {
	if (head == NULL) return NULL;
	ListNode* removed;
	if (head == head->link) {
		removed = head;
		head = NULL;
	}
	else {
		removed = head->link;
		head->link = removed->link;
	}
	free(removed);
	return head;
}
ListNode* remove_last(ListNode* head) {
	if (head == NULL) return NULL;

	if (head->link == head) {
		free(head);
		return NULL;
	}
	ListNode* current = head->link;
	while (current->link != head) {
		current = current->link;
	}
	current->link = head->link; 
	head = current;

	return head;
}
int main() {
	ListNode* head = NULL;
	element data;
	
}
#elif 1
#include<stdio.h>
#include <stdlib.h>
//Doubly linked list�� �����ô�~
typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;
void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}
void print_dlist(DListNode* phead) {
	if (phead->llink == phead && phead->rlink == phead) {
		printf("empty\n");
		return;
	}
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}
void dinsert_right(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}
void dinsert_left(DListNode* after, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->rlink = after;
	newnode->llink = after->llink;
	after->llink->rlink = newnode;
	after->llink = newnode;
}
void dremove(DListNode* head, DListNode* removed) {
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}
int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("�߰� �ܰ�\n");

	DListNode* p;
	for (int i = 0; i < 6; i++) {
		if (i % 2) dinsert_left(head, i);
		else dinsert_right(head, i);
		print_dlist(head);
	}
	printf("\n���� �ܰ�\n");
	for (int i = 0; i < 7; i++) {
		print_dlist(head);
		dremove(head, head->rlink);
	}
	free(head);
	return 0;
}
#elif 1
#elif 1
#endif