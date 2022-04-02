#include"duLinkedList.h"
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
	DuLinkedList q=NULL;
	if(p==NULL||p->next==NULL)
		return ERROR;
	else
	{
		if(p->next->next==NULL) /* 只有一个带数据结点 */
		{
			e=&(p->next)->data;
			q=p->next;
			p->next=NULL;
		}
		else /* 有多个带数据结点 */
		{
			e=&(p->next)->data;
			q=p->next;
			p->next=p->next->next;
		}
		free(q);
		return SUCCESS;
	}
}
