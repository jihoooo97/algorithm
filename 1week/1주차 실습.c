// 작성자 201621142 유지호
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

 //실습문제 1번 (최대값) 
#define MAX_ARR_SIZE 10

int max = 0;
int arr[MAX_ARR_SIZE] = { 0, };

// 배열 랜덤 초기화 함수
void Set_Rand_ARR() {
	int i, j;
	srand(time(NULL));
	for (i = 0; i < MAX_ARR_SIZE; i++) {
		arr[i] = rand() % 20;   // 0 ~ 19의 범위로 초기화
		for (j = 0; j < i; j++) { // 중복 방지
			if (arr[i] == arr[j]) {
				i--;
				break;
			}
		}
	}
	printf("초기화된 배열: ");
	for (i = 0; i < MAX_ARR_SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// 1-(2)순환 호출을 사용한 최대값
int Get_MAX_Recursive(int n) {
	if (arr[n] > max) {
		max = arr[n];
	}
	if (n == 0)
		return max;
	return Get_MAX_Recursive(n - 1);
}

int main() {

	// 배열 랜덤 초기화
	Set_Rand_ARR();

	// 1-(1) 반복문장을 사용한 최대값
	for (int i = 0; i < MAX_ARR_SIZE; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	printf("반복문)   %d입니다.\n", max);
	max = 0;
	printf("순환호출) %d입니다.\n", Get_MAX_Recursive(MAX_ARR_SIZE));


	return 0;
}


 /*//실습문제 2번 (십진 정수n을 b진수로)

char str[17] = "0123456789ABCDEF";

// 2-(1) 반복문
void Change(int dec, int num)
{
	int r;			   // 각 자리별 나머지
	char result[16];   // 변환된 문자열이 저장될 배열
	int idx = 0;       // 변환된 문자가 저장될 배열의 인덱스

	//dec(몫)이 0이 될 때 까지 반복
	for (; dec > 0; dec /= num) {
		// num 으로 나눈 나머지
		r = dec % num;

		// 각 자리의 나머지를 배열에 저장
		result[idx++] = str[r];
	}

	// 배열을 역순으로 출력한다.
	for (int i = idx - 1; i >= 0; i--)
		printf("%c", result[i]);
	printf("(%d)\n", num);
}

// 2-(2) 순환 호출
void Change_Recursive(int dec, int num)
{
	int q = dec / num;
	int r = dec % num;

	if (q == 0) {
		printf("%c", str[r]);
		return;
	}
	Change_Recursive(q, num);
	printf("%c", str[r]);
}


int main() {
	int dec, num;

	for (int i = 0; i < 3; i++) {
		printf("십진 정수 n: "); scanf("%d", &dec);
		printf("진법(2~16): "); scanf("%d", &num);

		if (!(num >= 2 && num <= 16)) {
			printf("2~16진법만 가능합니다.\n");
			i--;
			continue;
		}
		printf("변환 결과\n");
		Change(dec, num);
		Change_Recursive(dec, num);
		printf("(%d)\n", num);

	}
}*/

/*
//실습문제 3번 (원점에서부터 평면의 좌표의 거리 구하기) 

#define MAX 3

typedef struct {
	double x, y;
	double dis;
} Dot;

Dot d[MAX] = { {1, 1, 0}, {-2, -2, 0}, {4, 3, 0} };

double sum = 0;

double Cal_Dis(double x, double y) {
	return sqrt(x * x + y * y);
}

// 배열
// 3-(1) 반복문
double Cal_Avg() {
	for (int i = 0; i < MAX; i++) {
		sum += d[i].dis;
	}
	return sum / MAX;
}

// 3-(2) 순환 호출
double Cal_Avg_Recur(int n) {
	sum += d[n - 1].dis;
	if (n == 1)
		return sum / MAX;
	return Cal_Avg_Recur(n - 1);
}

// 연결리스트

typedef struct {
	Dot data;
	struct ListNode* link;
} ListNode;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_node(ListNode* head, Dot value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;

	return head;
}

ListNode* delete_node(ListNode* head) {
	ListNode* target;
	if (head == NULL) return NULL;
	target = head;
	head = target->link;
	free(target);

	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) 
		printf("%.1lf->", p->data.dis);

	printf("NULL\n");
}
// 3-(3) 반복문
double Cal_Avg_List(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		sum += p->data.dis;

	return sum / MAX;
}
// 3-(4) 순환 호출
double Cal_Avg_Recur_List(ListNode* head) {
	if (head != NULL) {
		sum += head->data.dis;
		Cal_Avg_Recur_List(head->link);
	}
	return sum / MAX;
}

int main() {
	for (int i = 0; i < MAX; i++) {
		d[i].dis = Cal_Dis(d[i].x, d[i].y);
	}

	// 배열
	printf("평균(배열, 반복문): %.1lf\n", Cal_Avg());
	sum = 0;
	printf("평균(배열, 순환): %.1lf\n", Cal_Avg_Recur(MAX));

	// 연결리스트
	ListNode* head = NULL;

	for (int i = 0; i < MAX; i++) {
		head = insert_node(head, d[i]);
		print_list(head);
	}
	sum = 0;
	printf("평균(연결리스트, 반복문): %.1lf\n", Cal_Avg_List(head));
	sum = 0;
	printf("평균(연결리스트, 순환): %.1lf\n", Cal_Avg_Recur_List(head));

	return 0;
}*/