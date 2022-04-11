#include"linkedList.h"
Status InitList(LinkedList *L)
{
	*L =(LinkedList)malloc(sizeof(LNode));
	(*L) ->next = NULL;
	return SUCCESS;
}
