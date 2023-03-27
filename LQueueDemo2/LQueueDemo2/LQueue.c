#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS 1

#define LEN sizeof(struct node)

typedef struct node
{
	int* data;                   //������ָ��
	struct node* next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
	Node* front;                   //��ͷ
	Node* rear;                    //��β
	size_t length;            //���г���
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
//�ж��û�������Ƿ�������
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
//�ж��û�������Ƿ��Ǹ�����
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
//���ַ�������ת��Ϊ����
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
	int x = 1;//���Ƹ�ʮ��ǧλ��
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
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
	//����һƬ�¿ռ�
	Node* p = (Node*)malloc(LEN);
	p->next = NULL;
	//��ͷָ���βָ��ָ��ͷ�ڵ㣬��ʼ�����
	Q->front = Q->rear = p;
	Q->length = 0;

}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) {
	//������Ϊ��
	if (IsEmptyLQueue(Q))
	{
		return;
	}
	else
	{
		//����ָ���¼ͷָ���λ��
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(LQueue* Q) {
	//������δ��ʼ�����߶���Ϊ��ʱ
	if (Q == NULL || Q->front == Q->rear)
	{
		return TRUE;
	}
	else
		return FALSE;

}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue* Q, int* e) {

	//������δ��ʼ��ʱ������
	if (IsEmptyLQueue(Q))
	{
		return FALSE;
	}
	if(IsEmptyLQueue(Q)==0)
	{
		//��ֵ
		*e = *(Q->front->next->data);
		return TRUE;
	}

}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) {

	int* tem = 0;
	if (IsEmptyLQueue(Q))
	{
		//˵��δ��ʼ�����߶���Ϊ��
		return 0;
	}
	else
	{
		return Q->length;
	}

}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue* Q, int data) {
	//�ж϶����Ƿ��ʼ��
	if (Q != NULL)
	{

		Node* p = (Node*)malloc(LEN);
		p->data = (int*)malloc(sizeof(int));
		memcpy(p->data, &data,sizeof(int));
		p->next = NULL;
		Q->rear->next = p;
		Q->rear = p;
		//ÿ����һ�νڵ���г��Ⱦͼ�һ
		Q->length++;
		printf("We have add it into the queue!\n");
		return TRUE;
	}

}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) {
	//�ж϶����Ƿ�Ϊ��
	if (IsEmptyLQueue(Q))
	{
		return FALSE;
	}
	else
	{
		Node* p = Q->front->next;
		Q->front->next = p->next;
		//�����������һ���ڵ�����
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q) {
	////������Ϊ��
	//if (IsEmptyLQueue(Q))
	//{
	//	printf("The queue is empty!");
	//	return;
	//}
	/*else
	{*/
	//����ָ���¼ͷָ���λ��
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */


Status TraverseLQueue(LQueue* Q, void (*foo)(int * q)) {
	//������Ϊ��
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
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(int* q) {
	printf("the data here is %d", *q);

}