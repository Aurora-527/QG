#include"linkedList.h"
Status DeleteList(LNode *p, ElemType *e)
{
	LinkedList q=NULL;
	if(p==NULL||p->next==NULL)
		return ERROR;
	else
	{
		if(p->next->next==NULL) /* ֻ��һ��������ݵĽڵ� */
		{
			e=&(p->next)->data;
			q=p->next;
			p->next=NULL;
		}
		else /*�ж��������ݽ��*/
		{
			e=&(p->next)->data;
			q=p->next;
			p->next=p->next->next;
		}
		free(q);
		return SUCCESS;
	}
}
