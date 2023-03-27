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

Status initLStack(LinkStack* s);
Status isEmptyLStack(LinkStack* s);
Status getTopLStack(LinkStack* s, ElemType* e);
Status clearLStack(LinkStack* s);
Status destroyLStack(LinkStack* s);
Status LStackLength(LinkStack* s, int* length);
Status pushLStack(LinkStack* s, ElemType data);
Status popLStack(LinkStack* s, ElemType* data);
LPrint(LinkStack* s, ElemType* data);
judge(char string[]);
translate(char string[]);


void menu()
{
	LinkStack* s = (LinkStack*)malloc(sizeof(struct  LinkStack));
	s->top = NULL;
	initLStack(s);
	int flag = 0;
	int tem = 1;
	int* length = &tem;
	char data[100] = {'0'};
	ElemType* e = &tem;
	
	while (1)
	{
		while (1)
		{
			flag = 0;
			printf("请选择功能：\n");
			printf("1.检查栈是否为空\n");
			printf("2.得到栈顶元素\n");
			printf("3.清空栈\n");
			printf("4.销毁栈并退出\n");
			printf("5.检测栈长度\n");
			printf("6.入栈\n");
			printf("7.出栈\n");
			printf("请选择>");
			scanf_s("%d", &flag);
			while (getchar() != '\n');
			if (flag < 1 || flag>7)
			{
				system("cls");
				printf("Please give me the right number!");
			}
			else
				break;
		}
			switch (flag)
			{
			case(1):
				if (isEmptyLStack(s))
					printf("The stack is empty now!You should add something!\n");
				else
					printf("The stack is not empty now.\n");
				break;
			case(2):
				if (isEmptyLStack(s))
				{
					printf("The stack is empty now!You should add something!\n");
				}
				else
				{
					getTopLStack(s, e);
					LPrint(s, e);
				}
				break;
			case(3):
				if (isEmptyLStack(s))
					printf("The stack is empty now!You should add something!\n");
				else
				{
					clearLStack(s);
					printf("The stack is cleared.\n");
				}
				break;
			case(4):
				if (isEmptyLStack(s))
					printf("The stack is empty now!You should add something!\n");
				else
				{
					destroyLStack(s);
					printf("The stack has been destroied.\n");
					exit(0);
				}
				break;
			case(5):
				if (isEmptyLStack(s))
					printf("The stack is empty now!You should add something!\n");
				else
				{
					LStackLength(s, length);
					printf("the length of the stack now is %d", *length);
				}
				break;
			case(6):
				printf("Please give me the int-type number that you want to push:\n");
				gets_s(data, 100);
				if (judge(data))
				{
					pushLStack(s, translate(data));
					printf("The data has been pushed to the stack.\n");
				}
				break;
			case(7):
				if (isEmptyLStack(s))
					printf("The stack is empty now!You should add something!\n");
				else
					popLStack(s, e);
				//输出所删节点的数据
				printf("the node has been deleted,the data of if is %d", *e);
				break;
			}
		
	}

}
void main(void)
{

	menu();
	return;

}
