#include"duLinkedList.h"
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	DuLinkedList tmpHead;
	tmpHead=(DuLinkedList)malloc(sizeof(DuLNode));
	tmpHead=NULL;
	tmpHead=L;
	printf("��������������£�\n");
	while( tmpHead->next != NULL )
	{
		tmpHead = tmpHead->next;		/* ͷ���������Ϊ�գ����ֱ�Ӵ�ͷ������һ��㿪ʼ���� */
		printf("%d\t",tmpHead->data);
	}
	/*  ��ʱtmpHead �ĵ�ַ����������һ����㴦 */
	printf("\n������������£�\n");
	while( tmpHead->prior->prior != NULL )
	{
		printf("%d\t",tmpHead->data);
		tmpHead = tmpHead->prior;
	}
	printf("%d\n",tmpHead->data);
}
