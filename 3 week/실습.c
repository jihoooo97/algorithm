#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

// 배열 랜덤 초기화
void setRandARR(int *arr, int size) {
	int i, j, tmp;
	srand(time(NULL));
	for (i = 0; i < size; i++) {
		arr[i] = rand() % 98 + 1;
		for (j = 0; j < i; j++) // 중복 방지
			if (arr[i] == arr[j]) {
				i--;
				break;
			}
	}
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++)
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
	}
	printf("배열:");
	for (i = 0; i < size; i++)
		printf("%2d ", arr[i]);
	printf("\n\n");
}

// 이진탐색 순환호출
int cnt = 0;   // 시행횟수
void recurBinSearch(int *arr, int num, int low, int high) {
	int middle = (low + high) / 2;
	printf("[%d ~ %d], 중간 위치: %d, 비교값: %d\n", low, high, middle, num);
	if (num < arr[low] || num > arr[high] || low > high) {
		cnt++;
		printf("(횟수 %d) 해당 값이 존재하지 않습니다.\n", cnt);
		return;
	}
	else {
		cnt++;
		if (num < arr[middle]) {
			recurBinSearch(arr, num, low, middle - 1);
		}
		else if (num > arr[middle]) {
			recurBinSearch(arr, num, middle + 1, high);
		}
		else {
			printf("(횟수 %d) 검색값: %d\n\n", cnt, arr[middle]);
			return;
		}
	}
}

// 이진탐색 반복문
void repeBinSearch(int *arr, int num, int low, int high) {
	while (high >= low) {
		int middle = (low + high) / 2;
		printf("[%d ~ %d], 중간 위치: %d, 비교값: %d\n", low, high, middle, num);
		if (num < arr[low] || num > arr[high] || low > high) {
			cnt++;
			printf("(횟수 %d) 해당 값이 존재하지 않습니다.\n", cnt);
			return;
		}
		cnt++;
		if (num < arr[middle]) {
			high = middle - 1;
		}
		else if (num > arr[middle]) {
			low = middle + 1;
		}
		else {
			printf("(횟수 %d) 검색값: %d\n\n", cnt, arr[middle]);
			return;
		}
	}
}

// 피보나치
int fib(int n) {
	if (n == 1 || n == 2) {
		cnt++;
		printf("[fib(%d) 호출]\n", n);
		return 1;
	}
	cnt++;
	printf("[fib(%d) 호출]\n", n);
	return fib(n - 1) + fib(n - 2);
}

int main() {
	int n, key;  // switch문, 탐색 값
	int *arr, size, max=0;  // 배열 사이즈, 최대 횟수
	double c=0;  // 횟수 평균

	printf("배열 크기: "); scanf_s("%d", &size);
	if (size <= 0) {
		printf("잘못된 입력.\n");
		return 1;
	}
	arr = (int*)malloc(sizeof(int) * size);  // 배열 크기만큼 동적할당
	
	setRandARR(arr, size);  // 배열 초기화

	printf("1). 순환호출 이진탐색\n");
	printf("2). 순환호출 횟수계산\n");
	printf("3). 반복문 이진탐색\n");
	printf("4). 반복문 횟수계산\n");
	printf("5). 피보나치\n");
	printf("6). 종료\n");
	printf("=======================\n");
	while (1) {
		printf("선택: ");  scanf_s("%d", &n);
		switch (n) {

		case 1:
			printf("검색할 값: "); scanf_s("%d", &key);
			recurBinSearch(arr, key, 0, size - 1);
			cnt = 0;
			break;

		case 2:
			for (int i = 0; i < size; i++) {
				key = arr[i];
				recurBinSearch(arr, key, 0, size - 1);
				if (max < cnt)
					max = cnt;
				c += cnt;
				cnt = 0;
			}
			printf("총 횟수: %.lf,  평균: %.2lf,  최고 횟수: %d\n\n", c, c / size, max);
			c = 0;  max = 0;
			break;

		case 3:
			printf("검색할 값: "); scanf_s("%d", &key);
			repeBinSearch(arr, key, 0, size - 1);
			cnt = 0;
			break;

		case 4:
			for (int i = 0; i < size; i++) {
				key = arr[i];
				repeBinSearch(arr, key, 0, size - 1);
				if (max < cnt)
					max = cnt;
				c += cnt;
				cnt = 0;
			}
			printf("총 횟수: %.lf,  평균: %.2lf,  최고 횟수: %d\n\n", c, c / size, max);
			c = 0; max = 0;
			break;

		case 5:
			printf("정수 입력: ");  scanf_s("%d", &key);
			printf("(총 %d회 호출) 피보나치 수열 결과: %d\n\n", cnt, fib(key));
			cnt = 0;
			break;

		case 6:
			exit(0);

		default:
			printf("1~6의 값만 입력하세요.\n");
			break;
		}
	}
	free(arr);
	return 0;
}