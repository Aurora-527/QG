#include"linkedList.h"
Status InsertList(LNode *p, LNode *q)
{
	int i,test;
	printf("��������Ҫ�ڴ���ӵĽڵ�����");
	test=scanf("%d",&i);
	while(test==0)
	{
		printf("���벻�Ϸ��������밢�������֣�\n");
		fflush(stdin);/* ������뻺�����Ĵ������� */
		test = scanf("%d",&i);
	}
	q->data = i;
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}
