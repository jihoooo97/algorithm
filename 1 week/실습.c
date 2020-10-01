// �ۼ��� 201621142 ����ȣ
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

 //�ǽ����� 1�� (�ִ밪) 
#define MAX_ARR_SIZE 10

int max = 0;
int arr[MAX_ARR_SIZE] = { 0, };

// �迭 ���� �ʱ�ȭ �Լ�
void Set_Rand_ARR() {
	int i, j;
	srand(time(NULL));
	for (i = 0; i < MAX_ARR_SIZE; i++) {
		arr[i] = rand() % 20;   // 0 ~ 19�� ������ �ʱ�ȭ
		for (j = 0; j < i; j++) { // �ߺ� ����
			if (arr[i] == arr[j]) {
				i--;
				break;
			}
		}
	}
	printf("�ʱ�ȭ�� �迭: ");
	for (i = 0; i < MAX_ARR_SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// 1-(2)��ȯ ȣ���� ����� �ִ밪
int Get_MAX_Recursive(int n) {
	if (arr[n] > max) {
		max = arr[n];
	}
	if (n == 0)
		return max;
	return Get_MAX_Recursive(n - 1);
}

int main() {

	// �迭 ���� �ʱ�ȭ
	Set_Rand_ARR();

	// 1-(1) �ݺ������� ����� �ִ밪
	for (int i = 0; i < MAX_ARR_SIZE; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	printf("�ݺ���)   %d�Դϴ�.\n", max);
	max = 0;
	printf("��ȯȣ��) %d�Դϴ�.\n", Get_MAX_Recursive(MAX_ARR_SIZE));


	return 0;
}


 /*//�ǽ����� 2�� (���� ����n�� b������)

char str[17] = "0123456789ABCDEF";

// 2-(1) �ݺ���
void Change(int dec, int num)
{
	int r;			   // �� �ڸ��� ������
	char result[16];   // ��ȯ�� ���ڿ��� ����� �迭
	int idx = 0;       // ��ȯ�� ���ڰ� ����� �迭�� �ε���

	//dec(��)�� 0�� �� �� ���� �ݺ�
	for (; dec > 0; dec /= num) {
		// num ���� ���� ������
		r = dec % num;

		// �� �ڸ��� �������� �迭�� ����
		result[idx++] = str[r];
	}

	// �迭�� �������� ����Ѵ�.
	for (int i = idx - 1; i >= 0; i--)
		printf("%c", result[i]);
	printf("(%d)\n", num);
}

// 2-(2) ��ȯ ȣ��
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
		printf("���� ���� n: "); scanf("%d", &dec);
		printf("����(2~16): "); scanf("%d", &num);

		if (!(num >= 2 && num <= 16)) {
			printf("2~16������ �����մϴ�.\n");
			i--;
			continue;
		}
		printf("��ȯ ���\n");
		Change(dec, num);
		Change_Recursive(dec, num);
		printf("(%d)\n", num);

	}
}*/

/*
//�ǽ����� 3�� (������������ ����� ��ǥ�� �Ÿ� ���ϱ�) 

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

// �迭
// 3-(1) �ݺ���
double Cal_Avg() {
	for (int i = 0; i < MAX; i++) {
		sum += d[i].dis;
	}
	return sum / MAX;
}

// 3-(2) ��ȯ ȣ��
double Cal_Avg_Recur(int n) {
	sum += d[n - 1].dis;
	if (n == 1)
		return sum / MAX;
	return Cal_Avg_Recur(n - 1);
}

// ���Ḯ��Ʈ

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
// 3-(3) �ݺ���
double Cal_Avg_List(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		sum += p->data.dis;

	return sum / MAX;
}
// 3-(4) ��ȯ ȣ��
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

	// �迭
	printf("���(�迭, �ݺ���): %.1lf\n", Cal_Avg());
	sum = 0;
	printf("���(�迭, ��ȯ): %.1lf\n", Cal_Avg_Recur(MAX));

	// ���Ḯ��Ʈ
	ListNode* head = NULL;

	for (int i = 0; i < MAX; i++) {
		head = insert_node(head, d[i]);
		print_list(head);
	}
	sum = 0;
	printf("���(���Ḯ��Ʈ, �ݺ���): %.1lf\n", Cal_Avg_List(head));
	sum = 0;
	printf("���(���Ḯ��Ʈ, ��ȯ): %.1lf\n", Cal_Avg_Recur_List(head));

	return 0;
}*/