#include "postfix.h"

int main(void) {
	queue* postfix = toPostFix(); //ť������ postfix�� �������
	digit_matching(postfix);
	printf("%d", postfix->cnt);
	print_queue(postfix); //�׽�Ʈ��
	return 0;
}
