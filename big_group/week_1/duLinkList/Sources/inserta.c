#include"duLinkedList.h"
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
	int i,test;/* test���������쳣��� */
	printf("��������Ҫ�ڴ���ӵĽڵ�����");
	test=scanf("%d",&i);
	while(test==0)
	{
		printf("���벻�Ϸ��������밢�������֣�\n");
		fflush(stdin);//������뻺�����Ĵ�������
		test = scanf("%d",&i);
	}
	if(p->next!=NULL) /* ���p����β�ڵ� */
	{
		q->data = i;
		q ->prior = p;
		q->next = p->next;
		p->next->prior = q;
		p->next = q;
	}
	else /* ���p��β�ڵ� */
	{
		q->data = i;
		q ->prior = p;
		q ->next =NULL;
		p ->next=q;
	}
	return SUCCESS;
}
