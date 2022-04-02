#include"duLinkedList.h"
Status InitList_DuL(DuLinkedList *L)
{
	//³õÊ¼»¯Ë«Á´±í
	*L =(DuLinkedList)malloc(sizeof(DuLNode));
    (*L) ->next = NULL;
    (*L) ->prior = NULL;
    return SUCCESS;
}
