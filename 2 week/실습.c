// 작성자 201621142 유지호
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 // 1번
#define MAX_ARR 10

int arr[MAX_ARR] = { 0, };

void Set_Rand_ARR() {
	int i, j;
	srand(time(NULL));
	for (i = 0; i < MAX_ARR; i++) {
		arr[i] = rand() % 10+1;
		for (j = 0; j < i; j++) // 중복 방지
			if (arr[i] == arr[j]) {
				i--;
				break;
			}
	}
	printf("초기화:");
	for (i = 0; i < MAX_ARR; i++)
		printf("%2d ", arr[i]);
	printf("\n");
}

void bubbleSort(int A[]) {
	int i, j, tmp;
	for (i = 0; i < MAX_ARR; i++) {
		for (j = i+1; j < MAX_ARR; j++)
			if (A[i] > A[j]) {
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
	}
}

// 2번
#define MAX_ARR1 4
#define MAX_ARR2 5

int arr1[MAX_ARR1] = {5, 7, 24, 56};
int arr2[MAX_ARR2] = {19, 45, 61, 79, 92};
int arr3[MAX_ARR1+MAX_ARR2] = { 0, };

typedef int element;
typedef struct {
	element data;
	struct ListNode* link;
} ListNode;

// 배열 병합 및 정렬
void initArr(int A[]) {
	int i, j, tmp;

	for (int i = 0; i < MAX_ARR1+MAX_ARR2; i++) {
		if (i < MAX_ARR1)
			arr3[i] = arr1[i];
		else
			arr3[i] = arr2[i - MAX_ARR1];
	}
	for (i = 0; i < MAX_ARR1+MAX_ARR2; i++) {
		for (j = i + 1; j < MAX_ARR1+MAX_ARR2; j++)
			if (A[i] > A[j]) {
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
	}
}

// 리스트 삽입
ListNode* insert(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d -> ", p->data);
	printf("NULL");
}

void merge(ListNode* a, ListNode* b) {
	ListNode* p, * q;
	ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
	for (p = a; p != NULL; p = p->link)
		if (p->link == NULL) {
			p->link = b;
			break;
		}
	for (p = a; p != NULL; p = p->link) {
		for (q = p->link; q != NULL; q = q->link) {
			if (p->data < q->data) {
				tmp->data = p->data;
				p->data = q->data;
				q->data = tmp->data;
			}
		}
	}
}

// 3번
int cnt = 0;
void hanoi(int n, char from, char tmp, char to) {
	if (n == 1) {
		printf("원판 1 : %c -> %c\n", from, to);
		cnt++;
	}
	else {
		hanoi(n - 1, from, to, tmp);
		printf("원판 %d : %c -> %c\n", n, from, to);
		cnt++;
		hanoi(n - 1, tmp, from, to);
	}
}

int main() {
	int x, n;
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	printf("=========================\n\t문제 번호\n");
	printf("1). 버블 정렬\n");
	printf("2). 배열/연결리스트 병합\n");
	printf("3). 하노이 동작 카운트\n");
	printf("4). 종료\n");
	printf("=========================\n\n");

	while (1) {
		printf("문제 선택: "); scanf("%d", &x);
		switch (x) {

		case 1:
			Set_Rand_ARR();
			bubbleSort(arr);

			printf("결과  :");
			for (int i = 0; i < MAX_ARR; i++) {
				printf("%2d ", arr[i]);
			}
			printf("\n\n");
			break;

		case 2:
			initArr(arr3);
			printf("배열\n");
			for (int i = 0; i < MAX_ARR1 + MAX_ARR2; i++)
				printf(" %d", arr3[i]);

			for (int i = 0; i < MAX_ARR1; i++)
				head1 = insert(head1, arr1[i]);
			for (int i = 0; i < MAX_ARR2; i++)
				head2 = insert(head2, arr2[i]);

			printf("\n연결리스트\n");
			print_list(head1); printf("\n");
			print_list(head2); printf("\n");
			merge(head1, head2);
			print_list(head1);
			printf("\n\n");
			break;

		case 3:
			printf("옮길 디스크 개수: "); scanf("%d", &n);
			hanoi(n, 'A', 'B', 'C');
			printf("동작 횟수: %d\n", cnt);
			cnt = 0;
			printf("\n\n");
			break;

		case 4:
			exit(0);

		default:
			printf("1~4만 입력하세요.\n");
			break;
		}
	}

	return 0;
}