#include"linkedList.h"
Status InsertList(LNode *p, LNode *q)
{
	int i,test;
	printf("请输入你要在此添加的节点数据");
	test=scanf("%d",&i);
	while(test==0)
	{
		printf("输入不合法，请输入阿拉伯数字！\n");
		fflush(stdin);/* 清除输入缓冲区的错误数据 */
		test = scanf("%d",&i);
	}
	q->data = i;
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}
