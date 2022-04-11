#include"linkedList.h"
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	//±éÀú
	LinkedList p;
	p=(LinkedList)malloc(sizeof(LNode));
	p=NULL;
	for(p=L->next; p!=NULL; p=p->next)
		printf("%d ",p->data);
}


