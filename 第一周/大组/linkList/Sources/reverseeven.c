#include"linkedList.h"
LNode* ReverseEvenList(LinkedList *L)
{
	LinkedList p,p1,p2;
	p1=(*L);
	p2=(*L)->next;
	p=p1;
	while(p->next!=NULL)
	{
		p1 = p->next;
		p2 = p1->next;
		p->next = p2;
		p1->next = p2->next;
		/* ���е�������ż���ڵ�ĵ��� */
		p2->next = p1;
		p=p1;
		/* ��ǵ�����ɺ�p1��λ�� */
	}
}
