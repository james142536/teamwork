#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* add(char a[], char b[])
{
	// 두 문자열의 길이를 합친 크기의 문자열 변수 선언
	// 동적 메모리 할당을 위해 malloc 함수 사용
	// 처음 a의 길이만큼 a의 문자열을 저장하고
	// 저장된 a 뒤에 b의 길이만큼 b의 문자열 저장
	int len_a = 0, len_b = 0;
	while (a[len_a] != '\0') len_a++;
	while (b[len_b] != '\0') len_b++;

	char* res = (char*)malloc(len_a + len_b + 1);

	for (int i = 0; i < len_a; i++)
	{
		res[i] = a[i];
	}

	for (int i = 0; i < len_b; i++)
	{
		res[len_a + i] = b[i];
	}

	res[len_a + len_b] = '\0';

	return res;
}

void subtract(char a[], char b[])
{
	// 긴 문자열 - 짧은 문자열 + 1만큼 반복하면 모든 케이스만큼 반복 가능
	// 각각의 케이스를 반복하며 b와 비교 후
	// 만약 존재한다면(found 변수 사용)
	// b의 길이만큼 뒤 문자열을 앞으로 당겨서 제거
	int len_a = 0, len_b = 0;
	while (a[len_a] != '\0') len_a++;
	while (b[len_b] != '\0') len_b++;

	for (int i = 0; i < len_a - len_b + 1; i++)
	{
		int not_found = 1;
		for (int j = 0; j < len_b; j++)
		{
			if (a[i + j] != b[j]) {
				not_found = 0;
				break;
			}
		}

		if (not_found) {
			for (int j = i; j <= len_a - len_b; j++) {
				a[j] = a[j + len_b];
			}
			len_a -= len_b;
			i--;
			break;
		}
	}
}

char* multiply(char a[], int c)
{
	// (문자열 길이 * 입력받은 정수) 크기의 문자열 변수 선언
	// 동적 메모리 할당을 위해 malloc 함수 사용
	// 반복하며 문자열을 해당 변수에 저장
	int len_a = 0;
	while (a[len_a] != '\0') len_a++;

	char* res = (char*)malloc(len_a * c + 1);

	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < len_a; j++)
		{
			res[(len_a * i) + j] = a[j];
		}
	}
	res[len_a * c] = '\0';

	return res;
}

int divide(char a[], char b[])
{
	// 긴 문자열 - 짧은 문자열 + 1만큼 반복하면 모든 케이스만큼 반복 가능
	// 각각의 케이스를 반복하며 b와 비교 후
	// 만약 존재한다면(found 변수 사용)
	// 존재할 때마다 str_count에 1씩 더하여 문자열의 개수를 카운팅
	int len_a = 0, len_b = 0;
	while (a[len_a] != '\0') len_a++;
	while (b[len_b] != '\0') len_b++;

	int str_count = 0;
	for (int i = 0; i < len_a - len_b + 1; i++)
	{
		int not_found = 1;
		for (int j = 0; j < len_b; j++)
		{
			if (a[i + j] != b[j]) {
				not_found = 0;
				break;
			}
		}

		if (not_found) {
			str_count++;
		}
	}

	return str_count;
}

int str2int(char str[]);

int main()
{
	char input[500];
	printf("문자열을 입력하세요: ");

	// Input: (_Practice! - tice!) * 4
	fgets(input, 500, stdin);
	input[strcspn(input, "\n")] = '\0';

	int len = strlen(input);

	while (strchr(input, '+') || strchr(input, '-') || strchr(input, '*') || strchr(input, '/')) {
		int start = -1, end = -1;
		for (int i = 0; i < len; i++) {
			if (input[i] == '(') start = i;
			else if (input[i] == ')') {
				end = i;
				break;
			}
		}

		if (start != -1 && end != -1) {
			char inner_expr[500];
			strncpy(inner_expr, input + start + 1, end - start - 1);
			inner_expr[end - start - 1] = '\0';

			char a[500], b[500];
			int i = 0, j = 0;

			while (inner_expr[i] != ' ' && inner_expr[i] != '\0') {
				a[j++] = inner_expr[i++];
			}
			a[j] = '\0';

			char op = inner_expr[i + 1];

			j = 0;
			i += 3;
			while (inner_expr[i] != '\0') {
				b[j++] = inner_expr[i++];
			}
			b[j] = '\0';

			char result[500];
			if (op == '+') {
				char* add_res = add(a, b);
				strcpy(result, add_res);
				free(add_res);
			}
			else if (op == '-') {
				subtract(a, b);
				strcpy(result, a);
			}
			else if (op == '*') {
				int mul = str2int(b);
				char* mul_res = multiply(a, mul);
				strcpy(result, mul_res);
				free(mul_res);
			}
			else if (op == '/') {
				int div_res = divide(a, b);
				sprintf(result, "%d", div_res);
			}

			char new_expr[500];
			strncpy(new_expr, input, start);
			new_expr[start] = '\0';
			strcat(new_expr, result);
			strcat(new_expr, input + end + 1);

			strcpy(input, new_expr);
			len = strlen(input);
		}
		else
		{
			char inner_expr[500];
			strncpy(inner_expr, input, strlen(input));
			inner_expr[strlen(input)] = '\0';

			char a[500], b[500];
			int i = 0, j = 0;

			while (inner_expr[i] != ' ' && inner_expr[i] != '\0') {
				a[j++] = inner_expr[i++];
			}
			a[j] = '\0';

			char op = inner_expr[i + 1];

			j = 0;
			i += 3;
			while (inner_expr[i] != '\0') {
				b[j++] = inner_expr[i++];
			}
			b[j] = '\0';

			char result[500];
			if (op == '+') {
				char* add_res = add(a, b);
				strcpy(result, add_res);
				free(add_res);
			}
			else if (op == '-') {
				subtract(a, b);
				strcpy(result, a);
			}
			else if (op == '*') {
				int mul = str2int(b);
				char* mul_res = multiply(a, mul);
				strcpy(result, mul_res);
				free(mul_res);
			}
			else if (op == '/') {
				int div_res = divide(a, b);
				sprintf(result, "%d", div_res);
			}

			strcpy(input, result);
			len = strlen(input);
		}
	}

	printf("결과: %s\n", input);

	return 0;
}

int str2int(char str[])
{
	int len = 0;
	while (str[len] != '\0') len++;

	int int_str = 0;
	int tmp;
	for (int i = 0; i < len; i++)
	{
		tmp = ((int)str[(len - 1) - i] - 0x30); // number in ascii - 0x30 = real number
		for (int j = 0; j < i; j++)
		{
			tmp *= 10;
		}
		int_str += tmp;
	}

	return int_str;
}