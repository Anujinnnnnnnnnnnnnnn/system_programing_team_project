#include "list.h"

//�� �Լ��� �뵵 ������ ������Ͽ� ����

FC* head_insert(FC* head, char value) {
	head->data = value;
	head->cnt = 0;
	head->dot = -1;
	return head;
}

FC* insertVal(FC* pre, char value) {
	FC* p = (FC*)malloc(sizeof(FC));
	p->data = value;
	pre->next = p; //���� ���� ����Ʈ ������ ����� �̾� ���� 
	return p; // �̾� ���� ����Ʈ ������ ��ȯ�� 
}

void digit_matching_list(FC* head) {
	int cnt = head->cnt;
	int dot = head->dot != -1 ? head->dot : cnt + 1; //���� ���� ��� �׳� �������ִ� ���̹Ƿ�, cnt - (cnt - dot) - n�� cnt - 1 -  n�� �Ǿ� cnt, cnt -1, cnt -2 ó�� �ǰ� ��.
	int n = 1;
	for (FC* p = head; p != NULL; p = p->next) {
		p->digit = dot - n++; // ���� cnt - (cnt - dot) - n�̴�. ���ø� ��� 123.12�� cnt = 5, dot = 3�̹Ƿ� 1�� �ڸ����� 5 - (5 - 3) - 1 = 2�̴�. �׷��Ƿ� 123.12�� ���� ���� �ڸ����� 2 1 0 -1 -1 -2�̴�.  
		if (p->data == '.') n--; //�Ҽ��� �Ʒ� ù��° ���� �ڸ����� -1�̾�� �ϹǷ�
	}
}

void print_list(FC* head)
{
	printf("[%d %d]   ", head->cnt, head->dot);
	for (FC* p = head; p != NULL; p = p->next)	{ //����Ʈ ������ �����
		printf("%c[%d] -> ", p->data, p->digit);
	}
	printf("NULL \n");
}