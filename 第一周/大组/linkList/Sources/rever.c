#include"linkedList.h"
Status ReverseList(LinkedList *L)
{
	//反转
	LinkedList p=NULL,q=NULL,r=NULL;
	int i=1;
	if((*L)->next==NULL)
		i=0;
	else if((*L)->next->next==NULL)/* 只有一个结点 */
	{
		p=(*L)->next;
		(*L)->next=NULL;
		p->next=(*L);
		*L=p;
		for(; (*L)->next!=NULL; *L=(*L)->next)
		{
			printf("%d ",(*L)->data);
		}
		*L=p;
	}
	else /* 有多个结点 */
	{
		p=*L;
		q=(*L)->next;
		r=(*L)->next->next;
		p->next=NULL;
		while(1)
		{
			q->next=p;
			p=q;
			q=r;
			if(q->next==NULL)
			{
				r->next=p;
				break;
			}
			r=r->next;
		}
		for(*L=r; r->next!=NULL; r=r->next)
			printf("%d ",r->data);
	}
	return i;

}
