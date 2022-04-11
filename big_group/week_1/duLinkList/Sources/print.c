#include"duLinkedList.h"
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	DuLinkedList tmpHead;
	tmpHead=(DuLinkedList)malloc(sizeof(DuLNode));
	tmpHead=NULL;
	tmpHead=L;
	printf("链表正向遍历如下：\n");
	while( tmpHead->next != NULL )
	{
		tmpHead = tmpHead->next;		/* 头结点数据域为空，因此直接从头结点的下一结点开始遍历 */
		printf("%d\t",tmpHead->data);
	}
	/*  此时tmpHead 的地址在链表的最后一个结点处 */
	printf("\n链表反向遍历如下：\n");
	while( tmpHead->prior->prior != NULL )
	{
		printf("%d\t",tmpHead->data);
		tmpHead = tmpHead->prior;
	}
	printf("%d\n",tmpHead->data);
}
