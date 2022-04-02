#include"duLinkedList.h"
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
	int i,test;/* test用于输入异常检测 */
	printf("请输入你要在此添加的节点数据");
	test=scanf("%d",&i);
	while(test==0)
	{
		printf("输入不合法，请输入阿拉伯数字！\n");
		fflush(stdin);//清除输入缓冲区的错误数据
		test = scanf("%d",&i);
	}
	if(p->next!=NULL) /* 结点p不是尾节点 */
	{
		q->data = i;
		q ->prior = p;
		q->next = p->next;
		p->next->prior = q;
		p->next = q;
	}
	else /* 结点p是尾节点 */
	{
		q->data = i;
		q ->prior = p;
		q ->next =NULL;
		p ->next=q;
	}
	return SUCCESS;
}
