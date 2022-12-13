#include "postfix.h"

//�� �Լ��� �뵵 ������ ������Ͽ� ����

char priority(char data1, char data2) {
	char tmp1, tmp2;
	if ((data1 == '+') || (data1 == '-') || (data1 == '('))
		tmp1 = 1;
	else
		tmp1 = 2;
	if ((data2 == '+') || (data2 == '-') || (data2 == '('))
		tmp2 = 1;
	else
		tmp2 = 2;
	return tmp2 - tmp1;
	//tmp2 = ���� ������ ž, tmp1 = ���� ���� ��
	//���� ������ ž�� �켱������ �� ū ���, ������ ž�� ť�� �־���
}

char isOperator(char op) {
	char res = 0;
	if (op == '+')
		res = op;
	else if (op == '-')
		res = op;
	else if (op == '*')
		res = op;
	else if (op == '/')
		res = op;
	else if (op == '(')
		res = op;
	else if (op == ')')
		res = op;
	else
		res = 0;
	return res; //res�� 0�� �ƴϸ� �����ڶ�� ���̴�. 
}

queue* toPostFix() {
	stack* stk = (stack*)malloc(sizeof(stack)); //�����͸� �а� �ϴ� ������ ���� 
	queue* post = (queue*)malloc(sizeof(queue)); //postfix ������� ���� ������ ���� 
	FC* cur; //���� ������ �� (���� ���� ���ڰ� ���� ���, cur = insertVal(cur, ������)�� �̾�� 
	//�� �ܿ��� cur = head_insert(cur, ������)�� cur�� �ʱ�ȭ����)
	//���� ���� 123+456�� ���, cur�� �Ʒ��� ���� ���Ѵ�. 
	//1�� ���� head�� ����, ��� �����̹Ƿ� 2, 3�� �޾� cur->d = 1�̰� cur = 1 -> 2 -> 3 -> NULL �� ���Ḯ��Ʈ�� ��, 
	//+�� ���� head�� ����, cur->d = +�̰� cur = + -> NULL �� ���Ḯ��Ʈ�� ��.
	//4�� ���� head�� ����, ��� �����̹Ƿ� 5, 6�� �޾� cur->d = 4�̰� cur = 4 -> 5 -> 6 -> NULL�� ���Ḯ��Ʈ�� ��. 

	FC* popData; //������ ž�� ���Ѱ� ������ ����
	char word, pre = '\0'; //word�� ���ο� ������, pre�� �ٷ� ���� ������
	initStack(stk); //�ʱ⼳��
	initQueue(post); //�ʱ⼳�� 

	while (scanf("%c", &word) == 1) { //�����͸� �о�ͼ� word�� ������ 
		if (word == '\n') continue; //�ٳѱ��� �н���Ŵ
		if ((pre != '\0' && isdigit(pre) > 0) && isdigit(word) > 0 || word == '.' || pre == '.') {
			//���� �����Ͱ� ���ڿ��� �̹� �����͵� ���ڶ�� ���Ḯ��Ʈ�� �̾ �����Ŵ || �Ҽ��� �̾ �����ؾ��ϹǷ� .�� üũ����
			cur = insertVal(cur, word);
		}
		else {
			if (isOperator(word)) { // ���� �����ڶ�� 
				FC* tmp = (FC*)malloc(sizeof(FC));
				if (word == ')') { // �ݴ� ��ȣ�� �Էµ� ���
					while (1) {
						popData = stack_pop(stk); //���� ��ȣ�� ���ö����� �˽�Ŵ
						if (popData->data == '(') {
							break;
						}
						else {
							queue_push(popData, post); //�� ��Ų�� ť�� ����
						}
					}
				}
				else if (word == '(') { //���� ��ȣ�� �Էµ� ���
					cur = head_insert(tmp, word); //���� �־��ְ�
					stack_push(tmp, stk); //���ÿ� Ǫ�ý�Ŵ
				}
				else { // ��ȣ ���� �������� ����� 
					while (1) {
						if (stk->top == NULL) { // ������ ������� ���, �׳� �־���
							cur = head_insert(tmp, word);
							stack_push(tmp, stk);
							break;
						}
						else { // ������� ���� ���, top�κ��ϰ� �켱���� �񱳸� �ؾ���
							popData = stack_pop(stk);
							if (priority(popData->data, word) == 1 || popData->data == '(') { //���� word�� �켱������ �� ũ�ų�, top�κ��� (�� ���
								stack_push(popData, stk);
								cur = head_insert(tmp, word);
								stack_push(tmp, stk); // �Ѵ� ���ÿ� �ٽ� �־��ְ� break
								break;
							}
							else {
								queue_push(popData, post); //�ƴ� ���� ť�� top �κ��� �־��� 
								//[-, +]�� ��� -�� �׳� �־��ش�. 
								//while�� �̹Ƿ� [+]��� +�� �־��� 
							}
						}
					}
				}
			}
			else { //�����ڰ� �ƴ϶� ������ ���
				FC* tmp = (FC*)malloc(sizeof(FC));
				cur = head_insert(tmp, word); //���� ��带 �����
				queue_push(tmp, post); //ť�� �־��� 
			}
		}
		pre = word;
	}

	while (stk->top != NULL) { //������ ����ش�.
		popData = stack_pop(stk);
		queue_push(popData, post);
	}

	return post; // postfix�� ��ȯ���ش�. 
}