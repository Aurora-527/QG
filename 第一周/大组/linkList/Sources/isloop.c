#include"linkedList.h"
Status IsLoopList(LinkedList L)
{
	/* �ж��Ƿ�ѭ�� */
	LinkedList q=NULL,p=NULL; /* pΪ��ָ�룬qΪ��ָ�� */
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
