#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y, result;

	printf("�ΰ��� ������ �Է��Ͻÿ�: ");
	scanf("%d %d", &x, &y);	// 2���� ������ ���ÿ� �Է¹޴´�.

	result = x + y;		// ���� ������ �Ͽ��� ����� result�� ����
	printf("%d + %d = %d\n", x, y, result);

	result = x - y;		// ���� ����
	printf("%d - %d = %d\n", x, y, result);

	result = x * y;		// ���� ����
	printf("%d * %d = %d\n", x, y, result);

	result = x / y;		// ������ ����
	printf("%d / %d = %d\n", x, y, result);

	result = x % y;		// ������ ����
	printf("%d %% %d = %d\n", x, y, result);	// %�� ����Ϸ��� %%�Ͽ��� ��

	return 0;
}
