#include"duLinkedList.h"
void DestroyList_DuL(DuLinkedList *L)
{
	if((*L)==NULL)
	{
		printf("��δ��������");
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
		printf("ɾ���ɹ���");
	}
}
