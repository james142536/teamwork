#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y, result;

	printf("두개의 정수를 입력하시오: ");
	scanf("%d %d", &x, &y);	// 2개의 정수를 동시에 입력받는다.

	result = x + y;		// 덧셈 연산을 하여서 결과를 result에 대입
	printf("%d + %d = %d\n", x, y, result);

	result = x - y;		// 뺄셈 연산
	printf("%d - %d = %d\n", x, y, result);

	result = x * y;		// 곱셈 연산
	printf("%d * %d = %d\n", x, y, result);

	result = x / y;		// 나눗셈 연산
	printf("%d / %d = %d\n", x, y, result);

	result = x % y;		// 나머지 연산
	printf("%d %% %d = %d\n", x, y, result);	// %을 출력하려면 %%하여야 함

	return 0;
}
