#include "postfix.h"

int main(void) {
	queue* postfix = toPostFix(); //ť������ postfix�� �������
	print_queue(postfix); //�׽�Ʈ��
	return 0;
}
