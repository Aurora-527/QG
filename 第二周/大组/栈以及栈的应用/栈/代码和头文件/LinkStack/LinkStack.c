#include "C:/Users/AURORA/Desktop/QG/ѵ��Ӫ�ڶ���/QG������2022ѵ��Ӫ�ڶ���/ջ�Լ�ջ��Ӧ��/ջ/�����ͷ�ļ�/head/LinkStack.h"
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s)
{
	s->top = NULL;
	s->count=0;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s)
{
	if (s->top==NULL) /*����ջ������û�н�� */
		return SUCCESS;
	else
		return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e)
{
	if (s->top == NULL)
		return ERROR;
	else
	{
		*e = s->top->data; 
		return SUCCESS;
	}
}

//���ջ
Status clearLStack(LinkStack *s)
{
	LinkStackPtr p=NULL; /* ���ڱ�־��㣬�����ͷ� */
	while(s->top)
	{
		p = s->top;
		s->top = s->top->next;
		s->count--;
		free(p);
	}
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s)
{
	clearLStack(s);
	free(s); /* ����ս���ͷ��ڴ�����������ջ */
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length)
{
	*length=s->count;
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data)
{
	if(s->top==NULL) /* ��ʱ���ǿ�ջ������û�н�㣬�����ݴ�����һ����� */
	{
		s->top=(LinkStackPtr)malloc(sizeof(StackNode));
		s->top->data=data;
		s->top->next=NULL;
		s->count++;
	}
	else /* �ǿ�ջ�����ݴ�����һ����� */
	{
		LinkStackPtr S=(LinkStackPtr)malloc(sizeof(StackNode));
		S->data=data;
		S->next=s->top; 
		s->top=S;
		s->count++;
	}
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data)
{
	LinkStackPtr p;
	if(isEmptyLStack(s)) /* ���ջ���Ƿ������� */
		return ERROR;
	*data=s->top->data;
	p=s->top;
	s->top=s->top->next;
	free(p);
	s->count--;
	return SUCCESS;
}


//#endif
