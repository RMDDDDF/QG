#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 1
#define LEN sizeof(struct StackNode)


typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack* s) {
	StackNode* p = (StackNode*)malloc(LEN);
	p->next = NULL;
	s->top = p;
	s->count = 0;
	return SUCCESS;

}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) {
	//��ջû�г�ʼ������Ϊ��������ʱ�ж�Ϊ��
	if (s->top==NULL||s->top->next == NULL) {
		return SUCCESS;
	}
	else
		return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (isEmptyLStack(s))
	{
		return ERROR;
	}
	if (isEmptyLStack(s) != 0) 
	{
		*e = s->top->data;
		return SUCCESS;
	}

}

//���ջ
Status clearLStack(LinkStack* s) {
	StackNode* p = s->top->next;
	StackNode* q = s->top->next;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	//��ͷָ��ָ���
	s->top->next = NULL;
	s->count = 0;
	return SUCCESS;

}

//����ջ
Status destroyLStack(LinkStack* s) {
	StackNode* p = s->top->next;
	StackNode* q = s->top->next;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	//��topָ��ָ���
	s->top = NULL;
	s->count = 0;
}

//���ջ����
Status LStackLength(LinkStack* s, int* length) {
	*length = s->count;
	printf("the length of the stack now is %d", (*length));
	return SUCCESS;
	if (length == NULL)
	{
		return ERROR;
	}
}

//��ջ
Status pushLStack(LinkStack* s, ElemType data) 
{
	if (s->top == NULL)
	{
		printf("ERROR\n");
		return ERROR;
	}
	if (s->top != NULL)
	{
		if (s->top->next == NULL) 
		{
			StackNode* p = (StackNode*)malloc(LEN);
			p->data = data;
			p->next = NULL;
			s->top->next = p;
			//���ȼ�һ
			s->count++;
			return SUCCESS;
		}
		else
		{
			StackNode* p = (StackNode*)malloc(LEN);
			p->data = data;
			p->next = s->top->next;
			s->top->next = p;
			//���ȼ�һ
			s->count++;
			return SUCCESS;
		}
	}

}

//��ջ
Status popLStack(LinkStack* s, ElemType* data) 
{
	StackNode* p = s->top->next;
	s->top->next = p->next;
	*data = p->data;
	free(p);
	s->count--;
	return SUCCESS;

}

//�������
Status LPrint(LinkStack* s, ElemType* data)
{
	printf("�ýڵ������Ϊ%d\n", (*data));
	return SUCCESS;
}
//�ж��û�������Ƿ�������
int judge(char string[])
{

	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] < '0' || (string[i] > '9'))
		{
			return 0;
		}
	}
	return 1;
}
//���ַ�������ת��Ϊ����
int translate(char string[])
{
	int arr[100] = { 0 };
	int ret = 0;
	int i = 0;
	int j;
	for (i = 0, j = strlen(string); i < strlen(string); i++, j--)
	{
		arr[j - 1] = string[i] - 48;
	}
	int x = 1;//���Ƹ�ʮ��ǧλ��
	for (int o = 0; o < i; o++)
	{
		ret += arr[o] * x;
		x *= 10;
	}

	return ret;
}