#pragma once
#include "stack.h"
#include "queue.h"

char priority(char data1, char data2); //������ �켱���� üũ��
char isOperator(char op); //���������� �ƴ��� �Ǵ���
queue* toPostFix(); //�Է� ���� �����͸� �޾Ƽ� queue ������ postfix�� ��ȯ��