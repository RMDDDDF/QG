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

void get_type(char* type);
int get_int(int *data);
void get_float(void* data);
void get_char(void* data);
void show();
char type;
char datatype[30];
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
JudgeFloat(char string[]);
TranslateInt(char string[]);
double atof(const char* str);


void get_type(char* type)
{
	while (1)
	{
		printf("Please give me what kind of the data you want to keep:\n");
		printf("'i' means int, 'f' means float while 'c' means char!\n");
		scanf_s("%c", type);
		if ((*type) == 'i' || (*type) == 'f' || (*type) == 'c')
			break;
		else
		{
			system("cls");
			printf("Please don't give me others!\n");
		}
	}
	/*return type;*/
}
//void get_data(void* data)
//{
//	if (type == 'i')
//		get_int(data);
//	else if (type == 'f')
//		get_float(data);
//	else if (type == 'c')
//		get_char(data);
//}
// 
//判断用户输入的是否是整数
int JudgeInt(char string[])
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
//判断用户输入的是否是浮点数
int JudgeFloat(char string[])
{

	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] >= '0' && (string[i] <= '9') || (string[i] == '.'))
		{
			return 1;
		}
	}
	return 0;
}
//将字符串内容转化为整型
int TranslateInt(char string[])
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


int get_int(int * data)
{
	while (1)
	{
		printf("Please give me a int number:\n");
		char string[100] = { '0' };
		gets_s(string, 100);
		gets_s(string, 100);
		if (JudgeInt(string))
		{
			int num = TranslateInt(string);
			data = &num;
			return *data;
		}
		else
		{
			printf("Please give me the right number.\n");
		}
	}
	
}

void get_float(void* data)
{
	while (1)
	{
		printf("Please give me a float number:\n");
		char string[100] = { '0' };
		gets_s(string, 100);
		gets_s(string, 100);
		if (JudgeFloat(string))
		{
			float num = /*(float)*/atof(string);
			data = &num;
			return;
		}
		else
		{
			printf("Please give me the right number.\n");
		}
	}

	/*float* p = (float*)malloc(sizeof(float));
	*p = 0.0;
	scanf_s("%f", p);*/

}

void get_char(void* data)
{
	printf("Please give me a char:\n");
	char* p = (char*)malloc(sizeof(char));
	*p = '0';
	scanf_s("%c", p);
	while (getchar() != '\n');
	data = (void*)(p);
}
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
	//申请一片新空间
	Node* p = (Node*)malloc(LEN);
	p->next = NULL;
	//令头指针和尾指针指向头节点，初始化完成
	Q->front = Q->rear = p;
	Q->length = 0;

}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) {
	//队列若为空
	if (IsEmptyLQueue(Q))
	{
		return;
	}
	else
	{
		//先令指针记录头指针的位置
		Node* p = Q->front->next;
		Node* q = Q->front->next;
		while (p)
		{
			q = p;
			p = p->next;
			free(q);
		}
		printf("The queue has been destroied.\n");

	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(LQueue* Q) {
	//当队列未初始化或者队列为空时
	if (Q == NULL || Q->front == Q->rear)
	{
		return TRUE;
	}
	else
		return FALSE;

}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, int* e) {

	//当队列未初始化时，报错
	if (IsEmptyLQueue(Q))
	{
		return FALSE;
	}
	if(IsEmptyLQueue(Q)==0)
	{
		//赋值
		*e = *(Q->front->next->data);
		return TRUE;
	}

}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) {

	int* tem = 0;
	if (IsEmptyLQueue(Q))
	{
		//说明未初始化或者队列为空
		return 0;
	}
	else
	{
		return Q->length;
	}

}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, int data) {
	//判断队列是否初始化
	if (Q != NULL)
	{

		Node* p = (Node*)malloc(LEN);
		p->data = (int*)malloc(sizeof(int));
		memcpy(p->data, &data,sizeof(int));
		p->next = NULL;
		Q->rear->next = p;
		Q->rear = p;
		//每存入一次节点队列长度就加一
		Q->length++;
		printf("We have add it into the queue!\n");
		return TRUE;
	}

}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) {
	//判断队列是否为空
	if (IsEmptyLQueue(Q))
	{
		return FALSE;
	}
	else
	{
		Node* p = Q->front->next;
		Q->front->next = p->next;
		//处理仅仅存在一个节点的情况
		if (Q->rear == p)
		{
			Q->rear = Q->front;
		}
		free(p);
		Q->length--;
		return TRUE;
	}

}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q) {
	////队列若为空
	//if (IsEmptyLQueue(Q))
	//{
	//	printf("The queue is empty!");
	//	return;
	//}
	/*else
	{*/
	//先令指针记录头指针的位置
	Node* p = Q->front->next;
	Node* q = Q->front->next;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	Q->length = 0;
	printf("The queue is empty now.\n");

	/*};*/

}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */


Status TraverseLQueue(LQueue* Q, void (*foo)(int * q)) {
	//队列若为空
	if (IsEmptyLQueue(Q))
	{
		printf("The queue is empty!");
		return;
	}
	else
	{
		Node* p = Q->front->next;
		while (p)
		{
			LPrint(p->data);
			p = p->next;
		}
		return TRUE;

	}

}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(int* q) {
	printf("the data here is %d", *q);

}