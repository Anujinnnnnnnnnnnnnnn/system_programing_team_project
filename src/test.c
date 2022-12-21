#include "postfix.h"
#include "multiply.h"
#include "minus.h"

LINK evaluate(queue* postfix);

int main(void) {
	queue* postfix = toPostFix(); //ť������ postfix�� �������
	digit_matching(postfix); //�ڸ��� ������
	LINK result = evaluate(postfix);
	print_list_test(result);
	//print_queue(postfix); //�׽�Ʈ��
	return 0;
}

LINK evaluate(queue* postfix) {
	stack* stk = (stack*)malloc(sizeof(stack));
	initStack(stk);
	LINK res = (LINK)malloc(sizeof(LINK));
	for (LINK p = postfix->front; p != NULL; p = p->next_rear) {
		if (p->d == '+' && p->cnt > 0 || p->d == '-' && p->cnt > 0) {
			stack_push(p, stk);
		}
		else {
			LINK d1;
			LINK d2;
			d2 = stack_pop(stk);
			d1 = stack_pop(stk);
			if (p->d == '+') {
				//res = ���ϱ�(d1, d2);
			}
			else if (p->d == '-') {
				res = minus(d1, d2);
			}
			else if (p->d == '*') {
				res = multiply(d1, d2);
			}
			else if (p->d == '/') {
				//res = ������(d1, d2);
			}
			stack_push(res, stk);
		}
		print_list_test(res);
	}
	res = stack_pop(stk);

	return res;
}