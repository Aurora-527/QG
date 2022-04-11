#include "C:/Users/AURORA/Desktop/QG/训练营第二周/QG工作室2022训练营第二周/栈以及栈的应用/栈/代码和头文件/head/LinkStack.h"
//链栈

//初始化栈
Status initLStack(LinkStack *s)
{
	s->top = NULL;
	s->count=0;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s)
{
	if (s->top==NULL) /*已有栈，但是没有结点 */
		return SUCCESS;
	else
		return ERROR;
}

//得到栈顶元素
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

//清空栈
Status clearLStack(LinkStack *s)
{
	LinkStackPtr p=NULL; /* 用于标志结点，便于释放 */
	while(s->top)
	{
		p = s->top;
		s->top = s->top->next;
		s->count--;
		free(p);
	}
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack *s)
{
	clearLStack(s);
	free(s); /* 先清空结点释放内存再销毁整个栈 */
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length)
{
	*length=s->count;
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data)
{
	if(s->top==NULL) /* 此时还是空栈，里面没有结点，故数据传给第一个结点 */
	{
		s->top=(LinkStackPtr)malloc(sizeof(StackNode));
		s->top->data=data;
		s->top->next=NULL;
		s->count++;
	}
	else /* 非空栈，数据传给下一个结点 */
	{
		LinkStackPtr S=(LinkStackPtr)malloc(sizeof(StackNode));
		S->data=data;
		S->next=s->top; 
		s->top=S;
		s->count++;
	}
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data)
{
	LinkStackPtr p;
	if(isEmptyLStack(s)) /* 检测栈里是否有数据 */
		return ERROR;
	*data=s->top->data;
	p=s->top;
	s->top=s->top->next;
	free(p);
	s->count--;
	return SUCCESS;
}


//#endif
