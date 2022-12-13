#include "queue.h"

//�� �Լ��� �뵵 ������ ������Ͽ� ����

int queEmpty(queue* que) {
	return que->cnt == 0; //���� ť�� ����ִ� �����ͼ��� 0�̶�� 1, �ƴ϶�� 0�� ��ȯ
}

void queue_push(FC* d, queue* que) {
	if (queEmpty(que)) {
		que->front = d; //���࿡ ť�� ����ִٸ� front�� ������.
	}
	else {
		que->rear->next_rear = d; //���ݱ����� �ڰ� ���� �ڸ� ����Ű�� ���� (������ ���� ���ŵ��� ���� ����)
	}
	que->rear = d; //ť�� �ڿ� ���� ������. (���� ����)
	que->cnt++; //ť�� ����ִ� ������ ���� ������Ŵ
}

FC* queue_pop(queue* que) {
	if (queEmpty(que))
		return NULL; //ť�� ����ִµ� ���� �ҷ��ϹǷ� NULL�� ������
	FC* tmp = que->front; // ���� front ���� ������ 
	que->front = tmp->next_rear; // front �� ����  
	que->cnt--; // ������ ���� ����
	return tmp; // front ���� ���� ��ȯ���� 
}

void initQueue(queue* que) {
	que->front = que->rear = NULL; // �ʱ�����̹Ƿ� front, rear ��� NULL 
	que->cnt = 0; //�ʱ� �����̹Ƿ� ������ ���� 0��
}

void print_queue(queue* que) {
	for (queue* p = que; que->front != NULL; p->front = p->front->next_rear) { //ť�� front�� NULL�� �ɶ����� �� �����
		print_list(p->front); //����Ʈ�� ����� 
	}
}