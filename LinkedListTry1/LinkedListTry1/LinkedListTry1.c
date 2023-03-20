/***************************************************************************************
 *	File Name				:	linkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#define _CRT_SECURE_NO_WARNINGS 1//��Ҫ��warning
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1
#define LEN sizeof(struct LNode)//���峣��LEN��ʾһ���ڵ�ĳ���

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/
/**
 *  @name        : int menu(void)
 *	@description : create a menu
 *	@param		 : void
 *	@return		 : int
 *  @notice      : None
 */
int menu(void)
{
	printf("***********************************\n");
	printf("*       ���������ܲ���          *\n");
	printf("*     0.�˳�                      *\n");
	printf("*     1.��ʼ������                *\n");
	printf("*     2.��������                  *\n");
	printf("*     3.��p�ڵ�����             *\n");
	printf("*     4.ɾ��ָ���ڵ��һ���ڵ�    *\n");
	printf("*     5.���������������        *\n");
	printf("*     6.��Ѱĳһ�ڵ�              *\n");
	printf("*     7.��ת����                  *\n");
	printf("*     8.�ж��Ƿ���ѭ������        *\n");
	printf("***********************************\n");
	printf("��ѡ��>");
	int option;//�û�������ѡ��
	scanf("%d", &option);
	return option;

}
/**
 *  @name        : int judge(char string[])
 *	@description : judge whether the data is right
 *	@param		 : char string[]
 *	@return		 : int
 *  @notice      : None
 */
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
/**
 *  @name        : int translate(char string[])
 *	@description : translate the string into a number whose form is int
 *	@param		 : char string[]
 *	@return		 : int
 *  @notice      : None
 */
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
/**
 *  @name        : LNode* GetQ(void)
 *	@description : get the data of q
 *	@param		 : void
 *	@return		 : LNode*
 *  @notice      : None
 */
LNode* GetQ(char string[])
{
	char useless[100] = "0";//�����̵��س���
	gets(useless);
	string[100] = "0";
	LNode* q = (LNode*)malloc(LEN);
	printf("������Ҫ����Ľڵ�data��\n");
	gets(string);
	while (!judge(string))//����������ݳ�����Χʱ������������
	{
		printf("�������\n");
		printf("������data��\n");
		gets(string);
	}
	q->data = translate(string);
	return q;
}
/**
 *  @name        : LNode* GetP(void)
 *	@description : get the data of q
 *	@param		 : LinkedList *head
 *	@return		 : LNode*
 *  @notice      : None
 */
LNode* GetP(LinkedList* head)
{
	LinkedList* L = head;//�������ָ������ͷָ���ָ��
	char string[100] = "0";//���ڴ洢�����data
	int jud = 0;//�ж��Ƿ��ҵ���Ӧ�Ľڵ�
	LNode* p = NULL;
	if ((*L) == NULL)//����û�г�ʼ��
	{
		printf("�������ڣ�");
		return NULL;
	}
	if ((*L)->next == NULL)//˵���޽ڵ�
	{
		printf("����Ϊ�գ�");
		return *head;
	}
	if ((*L)->next != NULL)//˵��ͷָ��ָ��ĵط��нڵ㣬�������
	{
		printf("������p�ڵ��data��\n");
		gets(string);
		if (judge(string))
		{
			LNode* Travel = (*L)->next;//��������ָ��
			int tem = translate(string);//���ڴ洢ת���������data
			while (Travel)
			{
				if (Travel->data == tem)
				{
					jud = 1;
					return Travel;//�����ҵ���ָ��
				}
				Travel = Travel->next;
			}
			printf("δ�ҵ�����ֵ��Ӧ�Ľڵ�\n");
			return NULL;
			
		}
		
	}
}
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */

Status InitList(LinkedList* L)
{
	*L = (LinkedList)malloc(LEN);
	(*L)->next = NULL;
	printf("�����ʼ���ɹ���\n");
	return SUCCESS;
};


/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList* L)
{
	if (( * L) == NULL)
	{
		printf("�������ڣ�\n");

	}
	if((*L)!=NULL&&(*L)->next !=NULL)
	{
		LinkedList p1, p2;
		p1 = p2 = (* L)->next;//��p1��p2��ָ��ͷָ��
		while (p1)
		{
			p2 = p1->next;
			free(p1);
			p1 = p2;
		}
		(* L) = NULL;//���ʹͷָ��ָ��գ������������
		printf("����������ϣ�\n");
	}
};

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode* p, LNode* q)
{
	LNode* p1 = p;

	if (p1 == NULL)//����δ��ʼ��
	{
		printf("����!\n");
		return ERROR;
	}
	else
	{
		LNode* ne;//���Դ洢����ǰhead����һ���ڵ�
		ne = p1->next;
		p1->next = q;
		q->next = ne;
		printf("������ɣ�\n");

		return SUCCESS;
	}

};

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode* p, ElemType* e)
{
	if (p == NULL)//����δ��ʼ��
	{
		printf("����!\n");
		return ERROR;
	}
	if (p->next == NULL)//pΪ���һ��
	{
		printf("����!\n");
		return ERROR;
	}
	if (p->next != NULL)
	{
		LNode* ne;//����qָ��ָ��p����һ���ڵ�
		ne = p->next;
		p->next = ne->next;//ʹp��nextָ��ָ��q����һ���ڵ�
		*e = ne->data;//�����ݽ���e
		printf("�ڵ�ɾ���ɹ�������Ϊ%d\n", *e);
		free(ne);
		return SUCCESS;

	}

};

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */

void visitData(ElemType* e)//���ʵ�ǰ�ڵ������
{
	if (e != NULL)
		printf("��ǰ���ʵ��������£�%d\n", *e);
}

void TraverseList(LinkedList L, void (*visit)(ElemType* e))
{
	ElemType* e = NULL;
	if (L==NULL||L->next == NULL)//��һ���ڵ�Ϊ�ջ���ͷָ��Ϊ��
	{
		printf("����Ϊ�գ����������ݺ��ٳ��Ա�����\n");//�������
	}
	else
	{
		LNode* q = L->next;//��һ��
		while (q)//��L��ָ���ʱ
		{
			visit(&(q->data));
			q = q->next;
		}

	}


};


/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */

Status SearchList(LinkedList L, ElemType e)
{

	if (L != NULL) //��ͷָ��ָ���λ�ô�������ʱ
	{
		int judge = 0;//�ж��Ƿ��ҵ�
		LinkedList p1 = L;
		while (p1) //���������ʱ
		{
			if (e == p1->data) {
				printf("���ڸýڵ�");
				judge = 1;
				return SUCCESS;
			}
			p1 = p1->next;
		}
		if (judge == 0)
		{
			printf("�����ڸýڵ㣡");
			return ERROR;

		}
	}
	else {
		printf("����Ϊ�գ�\n");
		return ERROR;
	}

};

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L) {

	if ((*L)!=NULL&&(* L)->next != NULL)//�����д��ڽڵ�
	{
		LinkedList  beg = NULL;
		LinkedList  mid = (* L)->next;
		LinkedList  end = (*L)->next->next;
		while (SUCCESS)//һֱ����
		{

			mid->next = beg;//ʹmid����һ���ڵ�ָ��beg

			if (end == NULL) //�ж� end �Ƿ�Ϊ NULL������������˳�ѭ��
				break;
			beg = mid;//����ƶ�һ���ڵ�
			mid = end;
			end = end->next;
		}
		(* L)->next = mid;//���ʹͷָ��ָ��mid
		printf("��ת������ɣ�\n");
		return SUCCESS;
	}
	else
	{
		printf("�������ڣ�\n");
		return ERROR;

	}
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L)
{
	if ((L != NULL) && (L->next != NULL))
	{
		LinkedList p1, p2;
		p1 = L;
		p2 = L->next;
		int judge = 0;//�ж��Ƿ���ѭ������0Ϊû�У�1Ϊ��

		while ((p2 != NULL) && (p2->next != NULL))//�жϴ�ʱp2��p2����һ�ڵ��Ƿ�Ϊ��ָ��
		{
			p2 = p2->next->next;//p2��p1�ߵÿ�
			p1 = p1->next;
			if (p1 == p2)
				judge = 1;
			return SUCCESS;
		}
		if (judge == 0)
		{
			printf("��������ѭ������\n");
			return ERROR;
		}

	}
	else
	{
		printf("�������ڣ�\n");
		return ERROR;
	}
};

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/

void main(void)
{
	LinkedList* head = (LinkedList*)malloc(LEN);//����ͷָ��
	*head = NULL;
	char string[100] = "0";//���ڴ洢�����data
	ElemType* e = NULL;
	bool isDone = false;
	while (!isDone)
	{
		//���ݾ���Ĺ��ܴ���//
		switch (menu())
		{
		case 0:
			isDone = true;
			break;
		case 1:
			InitList(head);
			break;
		case 2:
			DestroyList(head);
			break;
		case 3:
			InsertList(GetP(head), GetQ(string));
			break;
		case 4:
			DeleteList(GetP(head), e);
			break;
		case 5:
			TraverseList(*head, visitData);
			break;
		case 6:
			printf("������Ҫ��ѯ�Ľڵ��data��");
			gets(string);
			gets(string);
			int data;
			if (judge(string))
			{
				data = translate(string);
			}
			SearchList(*head, data);
			break;
		case 7:
			ReverseList(head);
			break;
		case 8:
			IsLoopList(*head);
			break;
		default:
			printf("�����������������\n");
			break;
		}
		//����
		system("pause");
		system("cls");
	}


	return 0;

}