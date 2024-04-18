#if 0
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
} ArrayListType;

void error(const char* message) { //오류처리함수
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType* L) { //list 초기화
	L->size = 0;
}

int is_empty(ArrayListType* L) { //list가 비어있으면 1(T)을 반환한다고..합니다. 아니면 0(F)
	return L->size == 0;
}
int is_full(ArrayListType* L) { //여는 차있으면 1(T)을, 아니면 0(F)..을 이 아닐까 ㅇ왜 1이지..?
	return L->size == MAX_LIST_SIZE;//SIZE가 MAX와 같다.. 무슨 뜻일까요?
}
element get_entry(ArrayListType* L, int pos) { //자리 지정일까요?
	if (pos < 0 || pos >= L->size) {
		error("위치 오류");
	}return L->array[pos];
}
void print_list(ArrayListType* L) {
	int i;
	for (i = 0; i < L->size; i++) {
		printf("%d->", L->array[i]);
	}printf("\n");
}
void insert_last(ArrayListType* L, element item) { //맨 끝에 item 삽입
	if (L->size >= MAX_LIST_SIZE) {
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item; //항목 1 추가
}
void insert(ArrayListType* L, int pos, element item) {
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) { //not(비어있으면 F), 즉 비워있거나 and pos가 양수 and size보단 작아야하니까.
		for (int i = (L->size - 1); i >= pos; i--) {	 //무튼 참이면 size가 이미 늘어난 것 같고 size-1부터
			L->array[i + 1] = L->array[i];				 //한 칸씩 커지기
		}
		L->array[pos] = item;							//item 넣어주고, size 왜 여기서 늘어났지..? 애초에 한 칸 더 많이 시작했나..?
		L->size++;
	}
}
element remove(ArrayListType* L, int pos) {
	element item;
	if (pos < 0 || pos >= L->size) { 
		error("위치 오류");
	}
	item = L->array[pos];							//item이 담겨 있었음.
	for (int i = pos; i < (L->size - 1); i++) {		//pos에 있는 item 삭제, pos 뒤부터 한 칸씩 앞으로 옴.
		L->array[i] = L->array[i + 1];
	}
	L->size--;										//size 줄어듦.
	return item;
}

#elif 0
#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link; //자기참조 구조체를 이용하여 정의
} ListNode;

int main() {
	ListNode* head = NULL; //head node 생성
	head = (ListNode*)malloc(sizeof(ListNode));
	head->data = 10; //구조체(head node)에 10, link 걸어줌
	head->link = NULL;

	ListNode* p; 
	p = (ListNode*)malloc(sizeof(ListNode));
	p->data = 20;
	p->link = NULL; //아직 안 이어져 있으니까 일단 null로 채워놓는 듯
	head->link = p;// 1,2 node 연결

	free(p);
	free(head);
}

#elif 1
#include <stdio.h>
#include <stdlib.h>

//시작부분에 삽입,삭제//중간 삽입, 삭제//출력
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;
//시작 삽입
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value; //값달아주기
	p->link = head; //link 노드에 이어주기
	head = p;		//덧씌어주기 //head에 첫번째 씌어주는 것?
	return head;
}
// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;//담아주는게 이어주는 것 아닐까..
	return head;
}
//맨 앞 노드 삭제
ListNode* remove_first(ListNode* head) {
	ListNode* removed; //리무브 구조체
	if (head == NULL) return NULL; //끝이자낭?
	removed = head; //복사(헤드에 처음 노드 내용이 담김
	head = removed->link; //link가 다음거 이으고 있으니까 head도 똑같이!
	free(removed); //지워주고~
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
	// ArrayListType를 정적으로 생성하고 ArrayListType를 가리키는 포인터를 함수의 매개변수로 전달한다.
	ArrayListType list;
	init(&list);
	//insert(&list, 0, 10); // 구현되지 않은 insert_first 형태로 사용중
	insert_first(&list, 10);
	print_list(&list);// 0번째 위치에 10 추가
	//insert(&list, 0, 20);
	insert_first(&list, 20);
	print_list(&list);// 0번째 위치에 20 추가
	//insert(&list, 0, 30);
	insert_first(&list, 30);
	print_list(&list);// 0번째 위치에 30 추가
	insert_last(&list, 40);
	print_list(&list);// 맨 끝에 40 추가
	remove(&list, 0);
	print_list(&list);// 0번째 항목 삭제
	*/

	ListNode* head = NULL;
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i); //계속 첫 번째에 생성
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