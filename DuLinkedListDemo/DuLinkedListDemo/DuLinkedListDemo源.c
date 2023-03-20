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

#define _CRT_SECURE_NO_WARNINGS 1//不要报warning
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1
#define LEN sizeof(struct DuLNode)//用LEN代替结构体长度

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
	ERROR,//ERROR表示0
	SUCCESS,//SUCCESS表示1
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
	int x = 1;//控制个十百千位数
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
	printf("链表初始化成功！\n");
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

	if ((*L)==NULL)
	{
		printf("链表不存在！\n");
		return ERROR;
	}
	if ((*L) != NULL && (*L)->next != NULL)
	{
		DuLinkedList p1, p2;
		p1 = p2 = (*L)->next;//令p1和p2先指向头指针
		while (p1)
		{
			p2 = p1->next;
			free(p1);
			p1 = p2;
		}
		(*L) = NULL;//最后使头指针指向空，链表销毁完毕
		printf("链表销毁完毕！\n");
	}
	
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
	DuLNode* p1 = p;
	if (p1 == NULL||(p1->next ==NULL&&p1->prior==NULL)) //p为头指针或者链表没初始化
	{
		printf("错误\n");
		return ERROR;
	}
	else 
	{
		DuLNode* pr = NULL;//用以存储插入前p的上一个节点
		pr = p1->prior;
		pr->next = q;
		q->next = p1;
		p1->prior = q;
		q->prior = pr;
		printf("插入成功！\n");
		return SUCCESS;
	}
	//if (p1 != NULL && p1->next == NULL)//说明此节点为链表的末尾节点
	//{
	//	
	//	printf("插入成功！\n");
	//	return SUCCESS;
	//}
	//if (p1->next != NULL)//说明此节点不是最后一个节点
	//{
	//	DuLNode* pr = NULL;//用以存储插入前p的上一个节点
	//	pr = p1->prior;
	//	pr->next = q;
	//	q->next = p1;
	//	p1->prior = q;
	//	q->prior = pr;
	//	printf("插入成功！\n");
	//	return SUCCESS;

	//}
		
		
	
}
;

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)//未测试
{
	DuLNode* p1 = p;

	if (p1 == NULL)//链表还未初始化
	{
		printf("错误!\n");
		return ERROR;
	}
	else 
	{
		if (p1->next == NULL)//当p1为链表的最后一个节点时，ne->prior是不存在的
		{
			DuLNode* ne;//用以存储插入前head的下一个节点
			ne = p1->next;
			p1->next = q;
			q->next = ne;
			q->prior = p1;
			printf("插入完成！\n");
			p = p1;
			return SUCCESS;
		}
		else
		{
			DuLNode* ne;//用以存储插入前head的下一个节点
			ne = p1->next;
			p1->next = q;
			q->next = ne;
			ne->prior = q;
			q->prior = p1;
			printf("插入完成！\n");
			p = p1;
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
		printf("错误\n");
		return ERROR;
	}
	DuLinkedList q = p->next;//创建q指向p的下一节点
	if (q->next == NULL)//q的后指针指向空，意味着q为最后一个节点
	{
		e = &(q->data);//e存储data
		p->next = NULL;//将p变为链表的结尾，仅需令p的后指针指向空即可
		printf("删除成功！e存储的数值为%d\n", *e);
		return SUCCESS;
	}
	if (q->next != NULL)//当p的下下个节点存在时
	{
		DuLinkedList ne = NULL;
		ne = q->next;//创建一个指针用于指向p的下下个节点
		p->next = ne;//p的后指针指向ne
		ne->prior = p;//ne的前指针指向p，使q节点从链表消失
		e = &(q->data);//e存储被删除的节点的值
		free(q);//释放q节点
		printf("删除成功！e存储的数值为%d\n", *e);
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
void visitData(ElemType* e)//访问当前节点的数据
{
	if (e != NULL)
		printf("当前访问的数据如下：%d\n", *e);
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType* e))
{
	ElemType* e = NULL;
	if (L==NULL||L->next ==NULL)//未初始化
	{
		printf("链表为空，请输入数据后再尝试遍历！\n");//报错机制
	}
	else
	{
		DuLNode* q = L->next;//第一个
		while (q != NULL)//当L不指向空时
		{
			visit(&(q->data));
			q = q->next;
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
	printf("*       双向链表功能测试          *\n");
	printf("*     0.退出                      *\n");
	printf("*     1.初始化链表                *\n");
	printf("*     2.销毁链表                  *\n");
	printf("*     3.在p节点前插入             *\n");
	printf("*     4.在p节点后插入             *\n");
	printf("*     5.删除指定节点后的节点      *\n");
	printf("*     6.遍历双向链表并访问内容    *\n");
	printf("***********************************\n");
	printf("请选择>");
	int option;//用户做出的选择
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
	char useless[100] = "0";//用来吞掉回车键
	gets(useless);
	string[100] = "0";
	DuLNode* q = (DuLNode*)malloc(LEN);
	printf("请输入要插入的节点data：\n");
	gets(string);
	while (!judge(string))//当输入的数据超出范围时提醒重新输入
	{
		printf("输入错误\n");
		printf("请输入data：\n");
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
	DuLinkedList* L = head;//传入的是指向链表头指针的指针
	char string[100] = "0";//用于存储输入的data
	int jud = 0;//判断是否找到对应的节点
	DuLNode* p = NULL;
	if ((*L) == NULL)//链表没有初始化
	{
		printf("链表不存在！");
		return NULL;
	}
	if ((*L)->next == NULL)//说明无节点
	{
		printf("链表为空！");
		return *head;
	}
	if ((*L)->next != NULL)//说明头指针指向的地方有节点，链表存在
	{
		printf("请输入p节点的data：\n");
		gets(string);
		if (judge(string))
		{
			DuLNode* Travel = (*L)->next;//创建遍历指针
			int tem = translate(string);//用于存储转换后的数据data
			while (Travel)
			{
				if (Travel->data == tem)
				{
					jud = 1;
					return Travel;//返回找到的指针
				}
				Travel = Travel->next;
			}
			printf("未找到该数值对应的节点\n");
			return NULL;

		}

	}
}


void main()
{
	DuLinkedList* head = (DuLinkedList*)malloc(LEN);//创建头指针
	*head = NULL;
	char string[100] = "0";//用于存储输入的data
	DuLNode* p = (DuLNode*)malloc(LEN);//创建头指针
	ElemType* e = NULL;
	bool isDone = false;
	while (!isDone)
	{
		//根据具体的功能处理//
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
			printf("输入错误，请重新输入\n");
			break;
		}
		//清屏
		system("pause");
		system("cls");
	}

	return 0;
}