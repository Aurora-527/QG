#include"duLinkedList.h"
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
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
	q->data = i;
	p->prior->next = q;
	q->prior=p->prior;
	p->prior=q;
	q->next=p;

	return SUCCESS;
}
