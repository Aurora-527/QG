#include"duLinkedList.h"
Status InitList_DuL(DuLinkedList *L)
{
	//��ʼ��˫����
	*L =(DuLinkedList)malloc(sizeof(DuLNode));
    (*L) ->next = NULL;
    (*L) ->prior = NULL;
    return SUCCESS;
}
