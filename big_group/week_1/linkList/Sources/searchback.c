#include"linkedList.h"
Status SearchList(LinkedList L, ElemType e)
{
	/* ����e�ҵ������нڵ�������֮��ͬ�ĵ�һ���ڵ� */
	LinkedList p;
	ElemType i=0,f=0;
	if(L->data==e)
	{
		i=1;
		f=1;
		return i;
	}
	else
	{
		for(p=L; p!=NULL; i++)
		{
			if(p->data==e)
			{
				f=1;
				break;
			}
			if(p->next==NULL)
				break;
			p=p->next;
		}
		if(f)
			return i+1;
		else 
			return 0;
	}
}
