#include"linkedList.h"
void DestroyList(LinkedList *L)
{
	if((*L)==NULL)
	{
		printf("��δ��������");
	}
	else
	{
		LinkedList p,q;
		p=(*L)->next;
		while(p)
		{
			q=p->next;
			free(p);
			p=q;
		}
		(*L)=NULL;
		printf("ɾ���ɹ���");
	}
}
