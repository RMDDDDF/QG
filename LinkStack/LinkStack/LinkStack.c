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
//链栈

//初始化栈
Status initLStack(LinkStack* s) {
	StackNode* p = (StackNode*)malloc(LEN);
	p->next = NULL;
	s->top = p;
	s->count = 0;
	return SUCCESS;

}

//判断栈是否为空
Status isEmptyLStack(LinkStack* s) {
	//当栈没有初始化或者为插入数据时判断为空
	if (s->top==NULL||s->top->next == NULL) {
		return SUCCESS;
	}
	else
		return ERROR;
}

//得到栈顶元素
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

//清空栈
Status clearLStack(LinkStack* s) {
	StackNode* p = s->top->next;
	StackNode* q = s->top->next;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	//令头指针指向空
	s->top->next = NULL;
	s->count = 0;
	return SUCCESS;

}

//销毁栈
Status destroyLStack(LinkStack* s) {
	StackNode* p = s->top->next;
	StackNode* q = s->top->next;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	//令top指针指向空
	s->top = NULL;
	s->count = 0;
}

//检测栈长度
Status LStackLength(LinkStack* s, int* length) {
	*length = s->count;
	printf("the length of the stack now is %d", (*length));
	return SUCCESS;
	if (length == NULL)
	{
		return ERROR;
	}
}

//入栈
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
			//长度加一
			s->count++;
			return SUCCESS;
		}
		else
		{
			StackNode* p = (StackNode*)malloc(LEN);
			p->data = data;
			p->next = s->top->next;
			s->top->next = p;
			//长度加一
			s->count++;
			return SUCCESS;
		}
	}

}

//出栈
Status popLStack(LinkStack* s, ElemType* data) 
{
	StackNode* p = s->top->next;
	s->top->next = p->next;
	*data = p->data;
	free(p);
	s->count--;
	return SUCCESS;

}

//输出内容
Status LPrint(LinkStack* s, ElemType* data)
{
	printf("该节点的数据为%d\n", (*data));
	return SUCCESS;
}
//判断用户输入的是否是整数
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
//将字符串内容转化为整型
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
	int x = 1;//控制个十百千位数
	for (int o = 0; o < i; o++)
	{
		ret += arr[o] * x;
		x *= 10;
	}

	return ret;
}