#include "list.h"

//�� �Լ��� �뵵 ������ ������Ͽ� ����

FC* head_insert(FC* head, char value) {
	head->data = value;
	return head;
}

FC* insertVal(FC* pre, char value) {
	FC* p = (FC*)malloc(sizeof(FC));
	p->data = value;
	pre->next = p; //���� ���� ����Ʈ ������ ����� �̾� ���� 
	return p; // �̾� ���� ����Ʈ ������ ��ȯ�� 
}


void print_list(FC* head)
{
	for (FC* p = head; p != NULL; p = p->next) //����Ʈ ������ �����
		printf("%c -> ", p->data);
	printf("NULL \n");
}