#include"duLinkedList.h"
void DestroyList_DuL(DuLinkedList *L)
{
	if((*L)==NULL)
	{
		printf("还未创建链表！");
	}
	else
	{
		DuLinkedList p,q;
		p=(*L)->next;
		while(p)
		{
			q=p->next;
			free(p);
			p=q;
		}
		(*L)=NULL;
		printf("删除成功！");
	}
}
