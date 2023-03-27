#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS 1

#define LEN sizeof(struct node)

typedef struct node
{
	int* data;                   //数据域指针
	struct node* next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
	Node* front;                   //队头
	Node* rear;                    //队尾
	size_t length;            //队列长度
} LQueue;
typedef enum
{
	FALSE = 0, TRUE = 1
} Status;

int get_int(int* data);
void show();
void InitLQueue(LQueue* Q);
void DestoryLQueue(LQueue* Q);
Status IsEmptyLQueue(LQueue* Q);
Status GetHeadLQueue(LQueue* Q, int* e);
int LengthLQueue(LQueue* Q);
Status EnLQueue(LQueue* Q, int data);
Status DeLQueue(LQueue* Q);
void ClearLQueue(LQueue* Q);
Status TraverseLQueue(LQueue* Q, void (*foo)(int* q));
void LPrint(int* q);
JudgeInt(char string[]);
TranslateInt(char string[]);

int main()
{

	show();
	return 0;
}
void show()
{
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	
	InitLQueue(Q);

	while (1)
	{
		int a = 0;
		int* data = &a;
		int flag;
		flag = 0;
		printf("You can do these function:\n");
		printf("1.Check whether the queue is empty or not;\n");
		printf("2.Get the number of the queue head;\n");
		printf("3.Add a number into the queue;\n");
		printf("4.Get a number out of the queue;\n");
		printf("5.Read all the node of the queue;\n");
		printf("6.Get the length of the queue;\n");
		printf("7.Delete the queue and quit;\n");
		printf("8.Clear the queue;\n");
		printf("Now please give me the number to finish the function:\n");
		scanf_s("%d", &flag);
		switch (flag)
		{
		case(1):
			if (IsEmptyLQueue(Q))
				printf("The queue is empty now!You should add something!\n");
			else
				printf("The queue is not empty now.\n");
			break;
		case(2):
			if (GetHeadLQueue(Q, data))
			{
				printf("%d\n", *data);
				LPrint(data);
			}
			else
				printf("The queue is empty now!You should add something!\n");
			break;
		case(3):
				EnLQueue(Q, get_int(data));
				TraverseLQueue(Q, LPrint);
			break;
		case(4):
			if (DeLQueue(Q))
				printf("We have get the node out of the queue.\n");
			else
				printf("The queue is empty now!\n");
			break;
		case(5):
			TraverseLQueue(Q, LPrint);
			break;
		case(6):
			if (LengthLQueue(Q))
				printf("The length of the queue is %d.\n", Q->length);
			else
			{
				printf("The queue now is empty.\n");
			}
			break;
		case(7):
			DestoryLQueue(Q);
			free(Q);
			exit(0);
			break;
		case(8):
			if (IsEmptyLQueue(Q))
			{
				printf("The queue now is empty.\n");
			}
			else
			{
				ClearLQueue(Q);
			}
			break;
		default:
			printf("Please give me the right number.\n");
			break;
		}
		//清屏
	/*	system("pause");
		system("cls");*/


	}

}