#include "C:/Users/AURORA/Desktop/QG/训练营第二周/QG工作室2022训练营第二周/队列/代码和头文件/head/LQueue.h"

/**
*  @name        : void InitLQueue(LQueue *Q)
*    @description : 初始化队列
*    @param         Q 队列指针Q
*  @notice      : None
*/
void InitLQueue(LQueue *Q)
{
	Node *s=(Node*)malloc(sizeof(Node)); /* 为头结点申请空间 */
	if (s==NULL)
	{
		printf("创建失败！\n");
	}
	else
	{
		s->next=NULL;
		Q->front=s;
		Q->rear=s;
		Q->length=0;
		printf("创建成功！\n");
	}
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	if(Q->front!=Q->rear) /* 队列非空就先清空再销毁 */
		ClearLQueue(Q);
	/* 释放头结点 */
	free(Q->front);
	/* 将管理结点中的头指针和尾指针都指向空 */
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
	printf("队列销毁成功！\n");

}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->length==0)
		return TRUE;
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
Status GetHeadLQueue(LQueue *Q, void *e)
{
	int datasize; /* 用来接受传进来的数据所占字节数 */
	if(datatype[0]=='i') /* datatype[0]存放的即为队列头数据的类型 */
		datasize=sizeof(int);
	else if(datatype[0]=='d')
		datasize=sizeof(double);
	else if(datatype[0]=='c')
		datasize=sizeof(char);
	else if(datatype[0]=='t')
		datasize=sizeof(char*);
	if(IsEmptyLQueue(Q))
		return FALSE;
	else
	{
		memcpy(e, Q->front->next->data, datasize); /* memcpy函数用于将Q->front->next->data的地址里面datasize长度的数据复制到e */
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
int LengthLQueue(LQueue *Q)
{
	return (int)Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{
	Node *p = (Node*)malloc(sizeof(Node)); /* p是新传进的结点 */
	int datasize;
	if(type=='i')
		datasize=sizeof(int);
	else if(type=='d')
		datasize=sizeof(double);
	else if(type=='c')
		datasize=sizeof(char);
	else if(type=='t')
		datasize=sizeof(datatype); 
	p->data = (void*)malloc(datasize);
	memcpy(p->data, data, datasize); /* memcpy函数用于将data的地址里面datasize长度的数据复制到p->data */
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	Node *p=NULL;
	p=(Node*)malloc(sizeof(Node)); /* p用于表示要传出的结点 */
	p=Q->front->next;
	Q->front->next=p->next;
	if(Q->rear==p) /* 意为传出的为最后一个有数据结点 */
		Q->rear=Q->front; /* 传完后队列为空 */
	free(p);
	Q->length--;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	if(Q->front == Q->rear)
	{
		printf("队列已为空队列，不必进行清空操作！\n");
	}
	else
	{
		/* 获取队头的第一个有效结点 */
		Node *p = Q->front->next;
		/* 遍历队列中的有效结点 */
		while(p != NULL)
		{
			/* 移除结点 */
			Q->front->next = p->next;
			/* 释放结点 */
			free(p);
			/* 指向下一个结点 */
			p = Q->front->next;
			Q->length--;
		}
		Q->rear = Q->front;
		printf("队列清空成功！\n");
	}
}
/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	Node *p=NULL; /* p为成员结点 */
	type='0';
	printf("现有队列如下：\n");
	for(p=Q->front->next; p!=NULL; p=p->next,type++)
		foo(p->data); /* foo函数其实就是LPrint函数，用于打印队列成员结点 */
	printf("\n");
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void *q)
{
	if(datatype[type-'0']=='i') /* datatype[type-'0']存放即为当前传入的结点的类型 */
		printf("%d",*(int*)q);
	if(datatype[type-'0']=='c')
		printf("%c",*(char*)q);
	if(datatype[type-'0']=='d')
		printf("%lf",*(double*)q);
	if(datatype[type-'0']=='t')
		printf("%s",*(char**)q);
	printf("\n");
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
//#endif // LQUEUE_H_INCLUDED


