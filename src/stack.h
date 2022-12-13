#pragma once
#include "list.h"

typedef struct Stack {
	int cnt;
	FC* top; //���� ���� top�� �����
}stack;

void stack_push(FC* d, stack* stk); //���ÿ��� FC* d�� Ǫ���� 
FC* stack_pop(stack* stk); //������ top �����͸� ����
void initStack(stack* stk); //������ �ʱ���� �����
void print_stack(stack* stk); // ������ ����� (�׽�Ʈ ��)