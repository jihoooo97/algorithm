#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

// 배열 랜덤 초기화
void setRandARR(int* arr, int size) {
	int i, j;
	srand(time(NULL));
	for (i = 0; i < size; i++) {
		arr[i] = rand() % 98 + 1;
		for (j = 0; j < i; j++) // 중복 방지
			if (arr[i] == arr[j]) {
				i--;
				break;
			}
	}
	printf("Initial Array:");
	for (i = 0; i < size; i++)
		printf(" %d", arr[i]);
	printf("\n\n");
}

void selectionSort(int *arr, int size) {
	int i, j, min, tmp, cnt=0, Tcnt=0;

	for (i = 0; i < size-1; i++) {
		min = i;
		for (j = 0; j < i; j++)
			printf("   ");
		printf("(%d)", arr[i]);
		for (j = i + 1; j < size; j++) {
			if (arr[j] < arr[min])
				min = j;

			cnt++;
			printf(" %2d", arr[j]);
		}
		printf(" [%d]", cnt);
		Tcnt += cnt;
		cnt = 0;

		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;

		printf("\n");
	}
	printf("\n\n");

	printf("Sorted Array: ");
	for (i = 0; i < size; i++) {
			printf("%2d ", arr[i]);
	}
	printf("\n총 비교 횟수: %d\n", Tcnt);

}

typedef int element;
typedef struct {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* initNode(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;

	return head;
}
void seclectionSortNode(ListNode* head) {
	ListNode* p, * q, * min;
	ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
	int cnt = 0, Tcnt = 0;

	for (p = head; p->link != NULL; p = p->link) {
		min = p;
		printf("(%2d) ", min->data);
		for (q = p->link; q != NULL; q = q->link) {
			if (q->data < min->data)
				min = q;

			cnt++;
			printf("| %2d | -> ", q->data);
		}
		printf("NULL [%d]\n", cnt);
		Tcnt += cnt;
		cnt = 0;

		tmp->data = p->data;
		p->data = min->data;
		min->data = tmp->data;
	}
	printf("\n총 비교 횟수: %d\n", Tcnt);
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("| %d | -> ", p->data);
	printf("NULL\n\n");
}

int main() {
	int key, n;
	int* arr;
	ListNode* head = NULL;

	printf("========= 선택 =========\n");
	printf("1) 배열\n");
	printf("2) 연결리스트\n");
	printf("3) 종료\n");
	printf("========================\n");

	while (1) {
		printf("key: ");  scanf_s("%d", &key);

		switch (key) {

		case 1:
			printf("배열 크기: "); scanf_s("%d", &n);
			if (n <= 0) {
				printf("잘못된 입력.\n");
				return 1;
			}
			arr = (int*)malloc(sizeof(int) * n);
			setRandARR(arr, n);
			selectionSort(arr, n);
			break;

		case 2:
			printf("리스트 크기: "); scanf_s("%d", &n);
			if (n <= 0) {
				printf("잘못된 입력.\n");
				return 1;
			}
			arr = (int*)malloc(sizeof(int) * n);
			setRandARR(arr, n);
			for (int i = 0; i < n; i++)
				head = initNode(head, arr[i]);

			printf("Initial List\n");
			print_list(head);
			seclectionSortNode(head);

			printf("Sorted List\n");
			print_list(head);

			break;

		case 3:
			printf("프로그램 종료\n");
			exit(0);

		default:
			printf("1~3만 입력하세요.\n");
			break;
		}
		printf("\n-------------------------------\n");
	}

	return 0;
}