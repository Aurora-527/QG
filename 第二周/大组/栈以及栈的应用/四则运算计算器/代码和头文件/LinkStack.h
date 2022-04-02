#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

typedef enum Status
{
    ERROR = 0,
    SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct Stack_num /* ����ջ */
{
	int num;
	struct Stack_num *next;
}Stack_num,*LinkStack_num_ptr;
typedef struct LinkStack_num
{
	struct Stack_num* top;
	int count;
}LinkStack_num;
typedef struct Stack_opt /* ����ջ */
{
	char opt;
	struct Stack_opt *next;
}Stack_opt,*LinkStack_opt_ptr;
typedef struct LinkStack_opt
{
	struct Stack_opt* top;
	int count;
}LinkStack_opt;



//��ջ
Status Push_num(LinkStack_num *S,ElemType data); /* ������ջ */
Status Pop_num(LinkStack_num *S,ElemType *data); /* ���ֳ�ջ */
Status Push_opt(LinkStack_opt *S,char e); /* �ַ���ջ */
Status Pop_opt(LinkStack_opt *S,char *e); /* �ַ���ջ */
int Priority(char ch); 


#endif

