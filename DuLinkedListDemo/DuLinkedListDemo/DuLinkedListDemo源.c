/***************************************************************************************
 *	File Name				:	duLinkedList.h
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
#define LEN sizeof(struct DuLNode)//��LEN����ṹ�峤��

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior, * next;
} DuLNode, * DuLinkedList;

// define status
typedef enum Status {
	ERROR,//ERROR��ʾ0
	SUCCESS,//SUCCESS��ʾ1
} Status;

/**************************************************************
*	Prototype Declare Section
**************************************************************/
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
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L)
{
	*L = (DuLinkedList)malloc(LEN);
	(*L)->prior = NULL;
	(*L)->next = NULL;
	printf("�����ʼ���ɹ���\n");
	return SUCCESS;
};

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
Status DestroyList_DuL(DuLinkedList* L)
{

	if ((*L)->prior != NULL)
	{
		printf("�������ڣ�\n");
		return ERROR;
	}
	DuLinkedList p1, p2;
	p1 = p2 = *L;//��p1��p2��ָ��ͷָ��
	while (p1->next)
	{
		p2 = p1->next;
		free(p1);
		p1 = p2->next;
	}
	L = NULL;//���ʹͷָ��ָ��գ������������
	if (L == NULL)
		return SUCCESS;
};
/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	if (p == NULL) //pָ��գ�����
	{
		printf("����\n");
		return ERROR;
	}
	else
	{
		if (p->prior != NULL)//˵��p���ǵ�һ���ڵ㣬��Ҫ����
		{
			DuLNode* pr = NULL;//���Դ洢����ǰp����һ���ڵ�
			pr = p->prior;
			pr->next = q;
			q->next = p;
			p->prior = q;
			q->prior = pr;
			printf("����ɹ���\n");
			return SUCCESS;

		}
		if (p->prior == NULL)//˵��pΪ��һ���ڵ㣬��q��Ϊ��һ���ڵ㼴��
		{
			p->prior = q;
			q->next = p;
			printf("����ɹ���\n");
			return SUCCESS;


		}
	}
}
;

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	if (p == NULL) //pָ��գ�����
	{
		printf("����\n");
		return ERROR;
	}
	else
	{
		if (p->next != NULL)//˵��p�������һ���ڵ�
		{
			DuLNode* ne = NULL;//���Դ洢����ǰp����һ���ڵ�
			ne = p->next;
			ne->prior = q;
			q->next = ne;
			p->next = q;
			q->prior = p;

			return SUCCESS;
		}
		if (p->next == NULL)//˵��pΪ���һ���ڵ㣬��q��Ϊ���һ���ڵ㼴��
		{
			p->next = q;
			q->prior = p;
			q->next = NULL;
			printf("����ɹ���\n");
			return SUCCESS;

		}
	}
};

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	if (p == NULL)
	{
		printf("����\n");
		return ERROR;
	}
	DuLinkedList q = p->next;//����qָ��p����һ�ڵ�
	if (q->next == NULL)//q�ĺ�ָ��ָ��գ���ζ��qΪ���һ���ڵ�
	{
		e = &(q->data);//e�洢data
		p->next = NULL;//��p��Ϊ����Ľ�β��������p�ĺ�ָ��ָ��ռ���
		printf("ɾ���ɹ���e�洢����ֵΪ%d\n", *e);
		return SUCCESS;
	}
	if (q->next != NULL)//��p�����¸��ڵ����ʱ
	{
		DuLinkedList ne = NULL;
		ne = q->next;//����һ��ָ������ָ��p�����¸��ڵ�
		p->next = ne;//p�ĺ�ָ��ָ��ne
		ne->prior = p;//ne��ǰָ��ָ��p��ʹq�ڵ��������ʧ
		e = &(q->data);//e�洢��ɾ���Ľڵ��ֵ
		free(q);//�ͷ�q�ڵ�
		printf("ɾ���ɹ���e�洢����ֵΪ%d\n", *e);
		return SUCCESS;
	}

};

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void visitData(ElemType* e)//���ʵ�ǰ�ڵ������
{
	if (e != NULL)
		printf("��ǰ���ʵ��������£�%d\n", *e);
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType* e))
{
	ElemType* e = NULL;
	if (L->prior != NULL)
	{
		printf("����Ϊ�գ����������ݺ��ٳ��Ա�����\n");//�������
	}
	else
	{
		DuLNode* q = L->next;//��һ��
		if (q->prior == NULL)
		{
			while (q != NULL)//��L��ָ���ʱ
			{
				visit(&(q->data));
				q = q->next;
			}
		}
	}


};

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
	printf("*       ˫�������ܲ���          *\n");
	printf("*     0.�˳�                      *\n");
	printf("*     1.��ʼ������                *\n");
	printf("*     2.��������                  *\n");
	printf("*     3.��p�ڵ�ǰ����             *\n");
	printf("*     4.��p�ڵ�����             *\n");
	printf("*     5.ɾ��ָ���ڵ��Ľڵ�      *\n");
	printf("*     6.����˫��������������    *\n");
	printf("***********************************\n");
	printf("��ѡ��>");
	int option;//�û�������ѡ��
	scanf("%d", &option);
	return option;

}
/**
 *  @name        : DuLNode* GetQ(void)
 *	@description : get the data of q
 *	@param		 : void
 *	@return		 : DuLNode*
 *  @notice      : None
 */
DuLNode* GetQ(char string[])
{
	char useless[100] = "0";//�����̵��س���
	gets(useless);
	string[100] = "0";
	DuLNode* q = (DuLNode*)malloc(LEN);
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
 *  @name        : DuLNode* GetP(void)
 *	@description : get the data of q
 *	@param		 : DuLinkedList *head
 *	@return		 : DuLNode*
 *  @notice      : None
 */
DuLNode* GetP(DuLinkedList* head)
{
	char string[100] = "0";//���ڴ洢�����data
	int jud = 0;//�ж��Ƿ��ҵ���Ӧ�Ľڵ�
	if (*head == NULL)
	{
		printf("�������ڣ�\n");
		return NULL;
	}
	if ((*head)->next == NULL && (*head)->prior == NULL)//˵��ֻ����ͷָ��
	{
		printf("������ͷָ��,�ѽ��ղŵ���ֵ��Ϊ��һ���ڵ��ţ�\n");
		return *head;
	}
	if ((*head)->next != NULL)
	{
		DuLinkedList tem = *head;//��һ��temָ����ָ��ͷָ��
		printf("������p�ڵ��data��\n");
		gets(string);
		if (judge(string))
		{

			while (tem)
			{
				if ((tem)->data == translate(string))
				{

					jud = 1;
					return tem;
				}
				tem = (tem)->next;
			}
			if (jud == 0)
			{
				printf("δ�ҵ�����ֵ��Ӧ�Ľڵ㣬����\n");
			}
		}
	}
}


void main()
{
	DuLinkedList* head = (DuLinkedList*)malloc(LEN);//����ͷָ��
	*head = NULL;
	char string[100] = "0";//���ڴ洢�����data
	DuLNode* p = (DuLNode*)malloc(LEN);//����ͷָ��
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
			InitList_DuL(head);
			break;
		case 2:
			DestroyList_DuL(head);
			break;
		case 3:
			InsertBeforeList_DuL(GetP(head), GetQ(string));
			break;
		case 4:
			InsertAfterList_DuL(GetP(head), GetQ(string));
			break;
		case 5:
			DeleteList_DuL(GetP(head), e);
			break;
		case 6:
			TraverseList_DuL(*head, visitData);
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