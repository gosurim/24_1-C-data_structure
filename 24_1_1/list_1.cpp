#if 0
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
} ArrayListType;

void error(const char* message) { //����ó���Լ�
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType* L) { //list �ʱ�ȭ
	L->size = 0;
}

int is_empty(ArrayListType* L) { //list�� ��������� 1(T)�� ��ȯ�Ѵٰ�..�մϴ�. �ƴϸ� 0(F)
	return L->size == 0;
}
int is_full(ArrayListType* L) { //���� �������� 1(T)��, �ƴϸ� 0(F)..�� �� �ƴұ� ���� 1����..?
	return L->size == MAX_LIST_SIZE;//SIZE�� MAX�� ����.. ���� ���ϱ��?
}
element get_entry(ArrayListType* L, int pos) { //�ڸ� �����ϱ��?
	if (pos < 0 || pos >= L->size) {
		error("��ġ ����");
	}return L->array[pos];
}
void print_list(ArrayListType* L) {
	int i;
	for (i = 0; i < L->size; i++) {
		printf("%d->", L->array[i]);
	}printf("\n");
}
void insert_last(ArrayListType* L, element item) { //�� ���� item ����
	if (L->size >= MAX_LIST_SIZE) {
		error("����Ʈ �����÷ο�");
	}
	L->array[L->size++] = item; //�׸� 1 �߰�
}
void insert(ArrayListType* L, int pos, element item) {
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) { //not(��������� F), �� ����ְų� and pos�� ��� and size���� �۾ƾ��ϴϱ�.
		for (int i = (L->size - 1); i >= pos; i--) {	 //��ư ���̸� size�� �̹� �þ �� ���� size-1����
			L->array[i + 1] = L->array[i];				 //�� ĭ�� Ŀ����
		}
		L->array[pos] = item;							//item �־��ְ�, size �� ���⼭ �þ��..? ���ʿ� �� ĭ �� ���� �����߳�..?
		L->size++;
	}
}
element remove(ArrayListType* L, int pos) {
	element item;
	if (pos < 0 || pos >= L->size) { 
		error("��ġ ����");
	}
	item = L->array[pos];							//item�� ��� �־���.
	for (int i = pos; i < (L->size - 1); i++) {		//pos�� �ִ� item ����, pos �ں��� �� ĭ�� ������ ��.
		L->array[i] = L->array[i + 1];
	}
	L->size--;										//size �پ��.
	return item;
}

#elif 0
#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link; //�ڱ����� ����ü�� �̿��Ͽ� ����
} ListNode;

int main() {
	ListNode* head = NULL; //head node ����
	head = (ListNode*)malloc(sizeof(ListNode));
	head->data = 10; //����ü(head node)�� 10, link �ɾ���
	head->link = NULL;

	ListNode* p; 
	p = (ListNode*)malloc(sizeof(ListNode));
	p->data = 20;
	p->link = NULL; //���� �� �̾��� �����ϱ� �ϴ� null�� ä������ ��
	head->link = p;// 1,2 node ����

	free(p);
	free(head);
}

#elif 1
#include <stdio.h>
#include <stdlib.h>

//���ۺκп� ����,����//�߰� ����, ����//���
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;
//���� ����
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value; //���޾��ֱ�
	p->link = head; //link ��忡 �̾��ֱ�
	head = p;		//�������ֱ� //head�� ù��° �����ִ� ��?
	return head;
}
// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;//����ִ°� �̾��ִ� �� �ƴұ�..
	return head;
}
//�� �� ��� ����
ListNode* remove_first(ListNode* head) {
	ListNode* removed; //������ ����ü
	if (head == NULL) return NULL; //�����ڳ�?
	removed = head; //����(��忡 ó�� ��� ������ ���
	head = removed->link; //link�� ������ ������ �����ϱ� head�� �Ȱ���!
	free(removed); //�����ְ�~
	return head;
}
ListNode* remove(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}
int main() {
	/*
	// ArrayListType�� �������� �����ϰ� ArrayListType�� ����Ű�� �����͸� �Լ��� �Ű������� �����Ѵ�.
	ArrayListType list;
	init(&list);
	//insert(&list, 0, 10); // �������� ���� insert_first ���·� �����
	insert_first(&list, 10);
	print_list(&list);// 0��° ��ġ�� 10 �߰�
	//insert(&list, 0, 20);
	insert_first(&list, 20);
	print_list(&list);// 0��° ��ġ�� 20 �߰�
	//insert(&list, 0, 30);
	insert_first(&list, 30);
	print_list(&list);// 0��° ��ġ�� 30 �߰�
	insert_last(&list, 40);
	print_list(&list);// �� ���� 40 �߰�
	remove(&list, 0);
	print_list(&list);// 0��° �׸� ����
	*/

	ListNode* head = NULL;
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i); //��� ù ��°�� ����
		print_list(head);
	}

	ListNode* pre = head->link;
	insert(head, pre, 100);
	print_list(head);
	remove(head, pre);
	print_list(head);

	for (int i = 0; i < 5; i++) {
		head = remove_first(head);
		print_list(head);
	}
	return 0;
}
#elif 1
#endif