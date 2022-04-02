#include "C:/Users/AURORA/Desktop/QG/训练营第二周/QG工作室2022训练营第二周/栈以及栈的应用/四则运算计算器/代码和头文件/LinkStack.h"
/* 字符入栈 */
Status Push_opt(LinkStack_opt *s,char e)
{
	if(s->top==NULL) /* 此时还是空栈，里面没有结点，故数据传给第一个结点 */
	{
		s->top=(LinkStack_opt_ptr)malloc(sizeof(Stack_opt));
		s->top->opt=e;
		s->top->next=NULL;
		s->count++;
	}
	else /* 非空栈，数据传给下一个结点 */
	{
		LinkStack_opt_ptr S=(LinkStack_opt_ptr)malloc(sizeof(Stack_opt));
		S->opt=e;
		S->next=s->top; 
		s->top=S;
		s->count++;
	}
	return SUCCESS;
} 

/* 字符出栈*/
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

/* 数字入栈 */
Status Push_num(LinkStack_num *s,ElemType data)
{
	if(s->top==NULL) /* 此时还是空栈，里面没有结点，故数据传给第一个结点 */
	{
		s->top=(LinkStack_num_ptr)malloc(sizeof(Stack_num));
		s->top->num=data;
		s->top->next=NULL;
		s->count++;
	}
	else /* 非空栈，数据传给下一个结点 */
	{
		LinkStack_num_ptr S=(LinkStack_num_ptr)malloc(sizeof(Stack_num));
		S->num=data;
		S->next=s->top; 
		s->top=S;
		s->count++;
	}
	return SUCCESS;
}

/* 数字出栈 */
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
