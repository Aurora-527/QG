#include"linkedList.h"
Status DeleteList(LNode *p, ElemType *e)
{
	LinkedList q=NULL;
	if(p==NULL||p->next==NULL)
		return ERROR;
	else
	{
		if(p->next->next==NULL) /* 只有一个存放数据的节点 */
		{
			e=&(p->next)->data;
			q=p->next;
			p->next=NULL;
		}
		else /*有多个存放数据结点*/
		{
			e=&(p->next)->data;
			q=p->next;
			p->next=p->next->next;
		}
		free(q);
		return SUCCESS;
	}
}
