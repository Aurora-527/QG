#include"linkedList.h"
LNode* FindMidNode(LinkedList *L)
{
	LinkedList fast=NULL; /* ��ָ�� */
	LinkedList low=NULL; /*  ��ָ�� */	
	fast=*L;
	low=*L;

	while(fast&&fast->next)
	{
		fast=fast->next->next;
		low=low->next;
	}

	return low;

}
