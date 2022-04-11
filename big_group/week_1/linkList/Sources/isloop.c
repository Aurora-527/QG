#include"linkedList.h"
Status IsLoopList(LinkedList L)
{
	/* 判断是否循环 */
	LinkedList q=NULL,p=NULL; /* p为快指针，q为慢指针 */
	int i=0;
	q=p=L;
	while(q->next!=NULL&&q->next->next!=NULL)
	{
		p=p->next;
		q=q->next->next;
		if(p==q)
		{
			i=1;
			break;
		}
	}
	return i;

}
