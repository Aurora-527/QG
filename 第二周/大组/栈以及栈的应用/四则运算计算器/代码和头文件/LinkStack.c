#include "C:/Users/AURORA/Desktop/QG/ѵ��Ӫ�ڶ���/QG������2022ѵ��Ӫ�ڶ���/ջ�Լ�ջ��Ӧ��/�������������/�����ͷ�ļ�/LinkStack.h"
/* �ַ���ջ */
Status Push_opt(LinkStack_opt *s,char e)
{
	if(s->top==NULL) /* ��ʱ���ǿ�ջ������û�н�㣬�����ݴ�����һ����� */
	{
		s->top=(LinkStack_opt_ptr)malloc(sizeof(Stack_opt));
		s->top->opt=e;
		s->top->next=NULL;
		s->count++;
	}
	else /* �ǿ�ջ�����ݴ�����һ����� */
	{
		LinkStack_opt_ptr S=(LinkStack_opt_ptr)malloc(sizeof(Stack_opt));
		S->opt=e;
		S->next=s->top; 
		s->top=S;
		s->count++;
	}
	return SUCCESS;
} 

/* �ַ���ջ*/
Status Pop_opt(LinkStack_opt *s,char *e)
{
	LinkStack_opt_ptr p;
	*e=s->top->opt;
	p=s->top;
	s->top=s->top->next;
	free(p);
	s->count--;
	return SUCCESS;
}

/* ������ջ */
Status Push_num(LinkStack_num *s,ElemType data)
{
	if(s->top==NULL) /* ��ʱ���ǿ�ջ������û�н�㣬�����ݴ�����һ����� */
	{
		s->top=(LinkStack_num_ptr)malloc(sizeof(Stack_num));
		s->top->num=data;
		s->top->next=NULL;
		s->count++;
	}
	else /* �ǿ�ջ�����ݴ�����һ����� */
	{
		LinkStack_num_ptr S=(LinkStack_num_ptr)malloc(sizeof(Stack_num));
		S->num=data;
		S->next=s->top; 
		s->top=S;
		s->count++;
	}
	return SUCCESS;
}

/* ���ֳ�ջ */
Status Pop_num(LinkStack_num *s,ElemType *data)
{
	LinkStack_num_ptr p;
	*data=s->top->num;
	p=s->top;
	s->top=s->top->next;
	free(p);
	s->count--;
	return SUCCESS;
}


//#endif
