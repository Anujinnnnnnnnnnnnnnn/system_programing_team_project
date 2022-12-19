#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//FileContents�� �Է� ���� ���� �����ϴ� ���Ḯ��Ʈ�̴�.
typedef struct FileContents {
	char data; //������
	int digit; //�ڸ���
	int cnt; //�� ����� ����Ʈ ����
	int dot; //�� ��ġ (-1�Ͻ� ���� ���ٴ� ��)

	struct FileContents* next; // ���� �� ��ġ�� ���� 
	struct FileContents* prev; // ���� �� ��ġ�� ����

	struct FileContents* next_top; // ������ ���� �ڽ��� �˵Ǿ��� ��, ���� ž ��ġ�� ����� (ex) ���ð� [1,2,3]�϶�, 2�� 1�� ��ġ�� ����ϰ�, 3�� 2�� ��ġ�� ����ϴ� ���� )
	struct FileContents* next_rear; // ť�� ���� �ڽ��� �˵Ǿ��� ��, ���� ���� ��ġ�� ����� (ex) ť�� [1,2,3]�϶�, 1�� 2�� ��ġ�� ����ϰ�, 2�� 3�� ��ġ�� ����ϴ� ����)
}FC;

//���� ��� 12345+3456�� ���� ���
//1,+,3�� head_insert
//�������� insertVal�� �̾ �޴´�.

FC* head_insert(FC* head, char value); //���� FC�� �̾��ϴ� ���� �ƴ϶� ���ο� FC�� �����ϰ� ���� ���� �� �����
FC* insertVal(FC* pre, char value); //���� FC�� �̾��ϴ� ��쿡 �����
void digit_matching_list(FC* head); //�ڸ��� ��Ī���ִ� �Լ�
void print_list(FC* head); //���(�׽�Ʈ��)