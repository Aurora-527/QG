#include "C:/Users/AURORA/Desktop/QG/ѵ��Ӫ�ڶ���/QG������2022ѵ��Ӫ�ڶ���/����/�����ͷ�ļ�/head/LQueue.h"

/**
*  @name        : void InitLQueue(LQueue *Q)
*    @description : ��ʼ������
*    @param         Q ����ָ��Q
*  @notice      : None
*/
void InitLQueue(LQueue *Q)
{
	Node *s=(Node*)malloc(sizeof(Node)); /* Ϊͷ�������ռ� */
	if (s==NULL)
	{
		printf("����ʧ�ܣ�\n");
	}
	else
	{
		s->next=NULL;
		Q->front=s;
		Q->rear=s;
		Q->length=0;
		printf("�����ɹ���\n");
	}
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	if(Q->front!=Q->rear) /* ���зǿվ������������ */
		ClearLQueue(Q);
	/* �ͷ�ͷ��� */
	free(Q->front);
	/* ���������е�ͷָ���βָ�붼ָ��� */
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
	printf("�������ٳɹ���\n");

}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
	int datasize; /* �������ܴ�������������ռ�ֽ��� */
	if(datatype[0]=='i') /* datatype[0]��ŵļ�Ϊ����ͷ���ݵ����� */
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
		memcpy(e, Q->front->next->data, datasize); /* memcpy�������ڽ�Q->front->next->data�ĵ�ַ����datasize���ȵ����ݸ��Ƶ�e */
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
int LengthLQueue(LQueue *Q)
{
	return (int)Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data)
{
	Node *p = (Node*)malloc(sizeof(Node)); /* p���´����Ľ�� */
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
	memcpy(p->data, data, datasize); /* memcpy�������ڽ�data�ĵ�ַ����datasize���ȵ����ݸ��Ƶ�p->data */
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	Node *p=NULL;
	p=(Node*)malloc(sizeof(Node)); /* p���ڱ�ʾҪ�����Ľ�� */
	p=Q->front->next;
	Q->front->next=p->next;
	if(Q->rear==p) /* ��Ϊ������Ϊ���һ�������ݽ�� */
		Q->rear=Q->front; /* ��������Ϊ�� */
	free(p);
	Q->length--;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	if(Q->front == Q->rear)
	{
		printf("������Ϊ�ն��У����ؽ�����ղ�����\n");
	}
	else
	{
		/* ��ȡ��ͷ�ĵ�һ����Ч��� */
		Node *p = Q->front->next;
		/* ���������е���Ч��� */
		while(p != NULL)
		{
			/* �Ƴ���� */
			Q->front->next = p->next;
			/* �ͷŽ�� */
			free(p);
			/* ָ����һ����� */
			p = Q->front->next;
			Q->length--;
		}
		Q->rear = Q->front;
		printf("������ճɹ���\n");
	}
}
/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	Node *p=NULL; /* pΪ��Ա��� */
	type='0';
	printf("���ж������£�\n");
	for(p=Q->front->next; p!=NULL; p=p->next,type++)
		foo(p->data); /* foo������ʵ����LPrint���������ڴ�ӡ���г�Ա��� */
	printf("\n");
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(void *q)
{
	if(datatype[type-'0']=='i') /* datatype[type-'0']��ż�Ϊ��ǰ����Ľ������� */
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


